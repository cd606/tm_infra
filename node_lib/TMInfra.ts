import { env } from 'process';
import * as Stream from 'stream'
import {v4 as uuidv4} from 'uuid';
const BitSet = require('fast-bitset');

export interface Key<T> {
    id : string;
    key : T;
};
export interface KeyedData<A,B> {
    key : Key<A>;
    data : B;
};
export interface VersionedData<Version,T> {
    version : Version;
    data : T;
};
export interface GroupedVersionedData<GroupID, Version, T> {
    groupID : GroupID;
    version : Version;
    data : T;
};
export interface WithTime<T> {
    timePoint : Date;
    value : T;
    finalFlag : boolean;
};
export interface TimedDataWithEnvironment<Env,T> {
    environment : Env;
    timedData : WithTime<T>;
};
export function keyify<T>(t : T) : Key<T> {
    return {
        id : uuidv4()
        , key : t
    };
}
export enum LogLevel {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Critical
}
export interface EnvBase {
    now : () => Date;
    log : (l : LogLevel, s : string) => void;
    exit : () => void
}
export function pureTimedDataWithEnvironment<Env extends EnvBase,T>(env : Env, t : T, final : boolean = false) : TimedDataWithEnvironment<Env,T> {
    return {
        environment : env
        , timedData : {
            timePoint : env.now()
            , value : t                
            , finalFlag : final
        }
    }
}
export function mapTimedDataWithEnvironment<Env extends EnvBase,T1,T2>(f : (t : T1)=>T2, x : TimedDataWithEnvironment<Env,T1>) : TimedDataWithEnvironment<Env,T2> {
    return {
        environment : x.environment
        , timedData: {
            timePoint : x.timedData.timePoint
            , value : f(x.timedData.value)
            , finalFlag : x.timedData.finalFlag
        }
    };
}

export namespace Kleisli {
    export type F<Env extends EnvBase,T1,T2> = (x : TimedDataWithEnvironment<Env,T1>) => TimedDataWithEnvironment<Env,T2>;
    export type Cont<Env extends EnvBase,T1,T2> = (x : TimedDataWithEnvironment<Env,T1>, f : (t2: TimedDataWithEnvironment<Env,T2>) => void) => void;
    export class Utils {
        public static liftPure<Env extends EnvBase,T,OutT>(f : (a : T) => OutT) : F<Env,T,OutT> {
            return function (x : TimedDataWithEnvironment<Env,T>) : TimedDataWithEnvironment<Env,OutT> {
                return mapTimedDataWithEnvironment<Env,T,OutT>(f, x);
            }
        }
        public static liftMaybe<Env extends EnvBase,T,OutT>(f : (a : T) => OutT) : F<Env,T,OutT> {
            return function (x : TimedDataWithEnvironment<Env,T>) : TimedDataWithEnvironment<Env,OutT> {
                let y = f(x.timedData.value);
                if (y === null) {
                    return null;
                }
                return {
                    environment : x.environment
                    , timedData : {
                        timePoint : x.timedData.timePoint
                        , value : y
                        , finalFlag : x.timedData.finalFlag
                    }
                };
            }
        }
        public static enhancedMaybe<Env extends EnvBase,T,OutT>(f : (d : Date, a : T) => OutT) : F<Env,T,OutT> {
            return function (x : TimedDataWithEnvironment<Env,T>) : TimedDataWithEnvironment<Env,OutT> {
                let y = f(x.timedData.timePoint, x.timedData.value);
                if (y === null) {
                    return null;
                }
                return {
                    environment : x.environment
                    , timedData : {
                        timePoint : x.timedData.timePoint
                        , value : y
                        , finalFlag : x.timedData.finalFlag
                    }
                };
            }
        }
        public static compose<Env extends EnvBase,T1,T2,T3>(f1 : F<Env,T1,T2>, f2 : F<Env,T2,T3>) : F<Env,T1,T3> {
            return function (x : TimedDataWithEnvironment<Env,T1>) : TimedDataWithEnvironment<Env,T3> {
                let y = f1(x);
                if (y === null || y.timedData.value === null) {
                    return null;
                }
                return f2(y);
            }
        }
    }
}

export namespace RealTimeApp {
    export abstract class IExternalComponent<Env extends EnvBase> {
        public abstract start(e : Env) : void;
    }
    export abstract class Importer<Env extends EnvBase,T> extends IExternalComponent<Env> {
        private theStream : Stream.Readable;
        protected env : Env;
        public constructor() {
            super();
            this.theStream = new Stream.Readable({
                read : function() {}
                , objectMode : true
            });
            this.env = null;
        }
        protected publish(data : T, isFinal : boolean = false) {
            this.theStream.push(pureTimedDataWithEnvironment(this.env, data, isFinal));
        }
        protected publishTimedDataWithEnvironment(data : TimedDataWithEnvironment<Env,T>) {
            this.theStream.push(data);
        }
        public stream() : Stream.Readable {
            return this.theStream;
        }
    };
    export class TimeChecker<Env extends EnvBase,T> {
        private now : Date;
        private version : any;
        public constructor() {
            this.now = null;
            this.version = null;
        }
        public check(data : TimedDataWithEnvironment<Env,T>) : boolean {
            if (this.now != null && data.timedData.timePoint < this.now) {
                return false;
            }
            if ((data.timedData.value as any).groupID !== undefined && (data.timedData.value as any).version !== undefined) {
                let groupID = (data.timedData.value as any).groupID;
                let version = (data.timedData.value as any).version;
                if (this.version == null) {
                    this.version = {groupID : version};
                } else if (!(groupID in this.version)) {
                    this.version[groupID] = version;
                } else if (this.version[groupID] < version) {
                    this.version[groupID] = version;
                } else {
                    return false;
                }
            } else if ((data.timedData.value as any).version !== undefined) {
                if (this.version == null || this.version < (data.timedData.value as any).version) {
                    this.version = (data.timedData.value as any).version;
                } else {
                    return false;
                }
            }
            this.now = data.timedData.timePoint;
            return true;
        }
    };
    export abstract class Exporter<Env extends EnvBase,T> extends IExternalComponent<Env> {
        private theStream : Stream.Writable;
        private timeChecker : TimeChecker<Env,T>;
        public abstract handle(data : TimedDataWithEnvironment<Env, T>) : void;
        public constructor() {
            super();
            let thisObj = this;
            this.theStream = new Stream.Writable({
                write : function(chunk : TimedDataWithEnvironment<Env,T>, _encoding : BufferEncoding, callback) {
                    if (thisObj.timeChecker.check(chunk)) {
                        thisObj.handle(chunk);
                    }
                    callback();
                }
                , objectMode : true
            });
            this.timeChecker = new TimeChecker<Env,T>();
        }
        public stream() : Stream.Writable {
            return this.theStream;
        }
    };
    export abstract class Action<Env extends EnvBase,T,OutT> {
        private theStream : Stream.Duplex;
        private timeChecker : TimeChecker<Env, T>;
        public abstract handle(data: TimedDataWithEnvironment<Env, T>) : void;
        protected publish(data : TimedDataWithEnvironment<Env,OutT>) {
            this.theStream.push(data);
        }
        public constructor() {
            let thisObj = this;
            this.theStream = new Stream.Duplex({
                write : function(chunk : TimedDataWithEnvironment<Env,T>, _encoding : BufferEncoding, callback) {
                    if (thisObj.timeChecker.check(chunk)) {
                        thisObj.handle(chunk);
                    }
                    callback();
                }
                , read : function(_s : number) {}
                , objectMode : true
            });
            this.timeChecker = new TimeChecker<Env,T>();
        }
        public stream() : Stream.Duplex {
            return this.theStream;
        }
    }
    export type Either2<T1,T2> = [number, T1|T2];
    //Action3 and above are currently not supported yet, so the Either3 and above types are
    //simply convenience types
    export type Either3<T1,T2,T3> = [number, T1|T2|T3]; 
    export type Either4<T1,T2,T3,T4> = [number, T1|T2|T3|T4]; 
    export type Either5<T1,T2,T3,T4,T5> = [number, T1|T2|T3|T4|T5]; 
    export abstract class Action2<Env extends EnvBase,T1,T2,OutT> {
        private theStream : Stream.Duplex;
        private timeChecker1 : TimeChecker<Env, T1>;
        private timeChecker2 : TimeChecker<Env, T2>;
        public abstract handle(data: TimedDataWithEnvironment<Env,Either2<T1,T2>>) : void;
        protected publish(data : TimedDataWithEnvironment<Env, OutT>) {
            this.theStream.push(data);
        }
        public constructor() {
            let thisObj = this;
            this.theStream = new Stream.Duplex({
                write : function(chunk : TimedDataWithEnvironment<Env,Either2<T1,T2>>, _encoding : BufferEncoding, callback) {
                    if (chunk.timedData.value[0] == 0) {
                        if (thisObj.timeChecker1.check(mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T1)
                            , chunk
                        ))) {
                            thisObj.handle(chunk);
                        }
                    } else {
                        if (thisObj.timeChecker2.check(mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T2)
                            , chunk
                        ))) {
                            thisObj.handle(chunk);
                        }
                    }
                    callback();
                }
                , read : function(_s : number) {}
                , objectMode : true
            });
            this.timeChecker1 = new TimeChecker<Env,T1>();
            this.timeChecker2 = new TimeChecker<Env,T2>();
        }
        public stream() : Stream.Duplex {
            return this.theStream;
        }
    }
    export abstract class OnOrderFacility<Env extends EnvBase,T,OutT> extends IExternalComponent<Env> {
        private theStream : Stream.Duplex;
        private timeChecker : TimeChecker<Env,Key<T>>;
        private requestMap : Map<string, Key<T>>;
        public abstract handle(data: TimedDataWithEnvironment<Env,Key<T>>);
        protected publish(data : TimedDataWithEnvironment<Env,Key<OutT>>) : void {
            let originalKey = this.requestMap.get(data.timedData.value.id);
            if (originalKey === undefined) {
                return;
            }
            this.theStream.push({
                environment : data.environment
                , timedData : {
                    timePoint : data.timedData.timePoint
                    , value : {
                        key : originalKey
                        , data : data.timedData.value.key
                    }
                    , finalFlag : data.timedData.finalFlag
                }
            });
            if (data.timedData.finalFlag) {
                this.requestMap.delete(data.timedData.value.id);
            }
        }
        public constructor() {
            super();
            let thisObj = this;
            this.theStream = new Stream.Duplex({
                write : function(chunk : TimedDataWithEnvironment<Env,Key<T>>, _encoding : BufferEncoding, callback) {
                    if (thisObj.timeChecker.check(chunk)) {
                        thisObj.requestMap.set(chunk.timedData.value.id, chunk.timedData.value);
                        thisObj.handle(chunk);
                    }
                    callback();
                }
                , read : (_s : number) => {}
                , objectMode : true
            });
            this.timeChecker = new TimeChecker<Env,Key<T>>();
            this.requestMap = new Map<string,Key<T>>();
        }
        public stream() : Stream.Duplex {
            return this.theStream;
        }
    }
    export class Source<Env extends EnvBase,T> {
        public stream : Stream.Readable;
        public constructor(s : Stream.Readable) {
            this.stream = s;
        }
    };
    export class Sink<Env extends EnvBase,T> {
        public stream : Stream.Writable;
        public constructor(s : Stream.Writable) {
            this.stream = s;
        }
    };
    export type PubFunc<T> = ((t : T, isFinal : boolean) => void);
    export type Generator<Env extends EnvBase,T> = ((env : Env, pub : PubFunc<T>) => void);
    export type UniformSimpleGenerator<Env extends EnvBase,T> = 
        ((env : Env) => Promise<[boolean, TimedDataWithEnvironment<Env, T>]>);
    export namespace Utils {
        export function simpleImporter<Env extends EnvBase,T>(gen : Generator<Env,T>) : Importer<Env,T> {
            class LocalI extends Importer<Env,T> {
                private genFunc : Generator<Env,T>;
                public constructor() {
                    super();
                    this.genFunc = gen;
                }
                public start(e : Env) : void {
                    this.env = e;
                    let thisObj = this;
                    this.genFunc(e, (t : T, isFinal : boolean) => {
                        thisObj.publish(t, isFinal);
                    });
                }
            };
            return new LocalI();
        }
        export function uniformSimpleImporter<Env extends EnvBase,T>(gen : UniformSimpleGenerator<Env,T>) {
            class LocalI extends Importer<Env,T> {
                private genFunc : UniformSimpleGenerator<Env,T>;
                public constructor() {
                    super();
                    this.genFunc = gen;
                }
                public start(e : Env) : void {
                    this.env = e;
                    let thisObj = this;
                    (async () => {
                        while (true) {
                            let x = await thisObj.genFunc(thisObj.env);
                            if (x[1] !== null) {
                                thisObj.publishTimedDataWithEnvironment(x[1]);
                            }
                            if (!x[0]) {
                                break;
                            }
                        }
                    })();
                }
            };
            return new LocalI();
        }
        export class TriggerImporter<Env extends EnvBase,T> extends Importer<Env,T> {
            public constructor() {
                super();
            }
            public start(e : Env) : void {
                this.env = e;
            }
            public trigger(t : T) : void {
                this.publish(t, false);
            }
        }
        export class ConstTriggerImporter<Env extends EnvBase,T> extends Importer<Env,T> {
            private value : T;
            public constructor(t : T) {
                super();
                this.value = t;
            }
            public start(e : Env) : void {
                this.env = e;
            }
            public trigger() : void {
                this.publish(this.value, false);
            }
        }
        export function constFirstPushImporter<Env extends EnvBase,T>(t : T) : Importer<Env,T> {
            return simpleImporter<Env,T>((_e : Env, pub : PubFunc<T>) => {
                pub(t, true);
            });
        }
        export function constFirstPushKeyImporter<Env extends EnvBase,T>(t : T) : Importer<Env,Key<T>> {
            return simpleImporter<Env,Key<T>>((_e : Env, pub : PubFunc<Key<T>>) => {
                pub(keyify(t), true);
            });
        }
        export function simpleExporter<Env extends EnvBase,T>(f : (a : TimedDataWithEnvironment<Env,T>) => void) : Exporter<Env,T> {
            class LocalE extends Exporter<Env,T> {
                public start(_e : Env) : void {}
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    f(data);
                }
            };
            return new LocalE();
        }
        export function pureExporter<Env extends EnvBase,T>(f : (a : T) => void) : Exporter<Env,T> {
            class LocalE extends Exporter<Env,T> {
                public start(_e : Env) : void {}
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    f(data.timedData.value);
                }
            };
            return new LocalE();
        }
        export function liftPure<Env extends EnvBase,T,OutT>(f : (a : T) => OutT) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, f(data.timedData.value), data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        export function liftMaybe<Env extends EnvBase,T,OutT>(f : (a : T) => OutT) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    let v = f(data.timedData.value);
                    if (v === null) {
                        return;
                    }
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, v, data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        export function enhancedMaybe<Env extends EnvBase,T,OutT>(f : (d : Date, a : T) => OutT) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    let v = f(data.timedData.timePoint, data.timedData.value);
                    if (v === null) {
                        return;
                    }
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, v, data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        export function kleisli<Env extends EnvBase,T,OutT>(f : Kleisli.F<Env,T,OutT>) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    let v = f(data);
                    if (v === null || v.timedData.value === null) {
                        return;
                    }
                    this.publish(v);
                }
            };
            return new LocalA();
        }
        export function liftMulti<Env extends EnvBase,T,OutT>(f : (a : T) => OutT[]) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    let v = f(data.timedData.value);
                    for (let t of v) {
                        this.publish(pureTimedDataWithEnvironment(
                            data.environment, t, data.timedData.finalFlag
                        ));
                    }
                }
            };
            return new LocalA();
        }
        export function enhancedMulti<Env extends EnvBase,T,OutT>(f : (d : Date, a : T) => OutT[]) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    let v = f(data.timedData.timePoint, data.timedData.value);
                    for (let t of v) {
                        this.publish(pureTimedDataWithEnvironment(
                            data.environment, t, data.timedData.finalFlag
                        ));
                    }
                }
            };
            return new LocalA();
        }
        export function kleisliMulti<Env extends EnvBase,T,OutT>(f : (a : TimedDataWithEnvironment<Env,T>) => TimedDataWithEnvironment<Env,OutT[]>) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    let v = f(data);
                    if (v === null || v.timedData.value === null) {
                        return;
                    }
                    for (let i=0; i<v.timedData.value.length; ++i) {
                        this.publish({
                            environment : v.environment
                            , timedData : {
                                timePoint : v.timedData.timePoint
                                , value : v.timedData.value[i]
                                , finalFlag : v.timedData.finalFlag && (i == v.timedData.value.length-1)
                            }
                        });
                    }   
                }
            };
            return new LocalA();
        }
        export function liftPure2<Env extends EnvBase,T1,T2,OutT>(f : (x : Either2<T1,T2>) => OutT) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, f(data.timedData.value), data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        export function liftMaybe2<Env extends EnvBase,T1,T2,OutT>(f : (x: Either2<T1,T2>) => OutT) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    let v = f(data.timedData.value);
                    if (v === null) {
                        return;
                    }
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, v, data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        export function enhancedMaybe2<Env extends EnvBase,T1,T2,OutT>(f : (x : [Date, Either2<T1,T2>]) => OutT) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    let v = f(
                        [data.timedData.timePoint, data.timedData.value]
                    );
                    if (v === null) {
                        return;
                    }
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, v, data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        export function kleisli2<Env extends EnvBase,T1,T2,OutT>(f : (x : TimedDataWithEnvironment<Env,Either2<T1,T2>>) => TimedDataWithEnvironment<Env,OutT>) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    let v = f(
                        data
                    );
                    if (v === null || v.timedData.value === null) {
                        return;
                    }
                    this.publish(v);
                }
            };
            return new LocalA();
        }
        export function liftMulti2<Env extends EnvBase,T1,T2,OutT>(f : (x: Either2<T1,T2>) => OutT[]) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    let v = f(data.timedData.value);
                    if (v === null) {
                        return;
                    }
                    for (let t of v) {
                        this.publish(pureTimedDataWithEnvironment(
                            data.environment, t, data.timedData.finalFlag
                        ));
                    }
                }
            };
            return new LocalA();
        }
        export function enhancedMulti2<Env extends EnvBase,T1,T2,OutT>(f : (x: [Date, Either2<T1,T2>]) => OutT[]) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    let v = f(
                        [data.timedData.timePoint, data.timedData.value]
                    );
                    if (v === null) {
                        return;
                    }
                    for (let t of v) {
                        this.publish(pureTimedDataWithEnvironment(
                            data.environment, t, data.timedData.finalFlag
                        ));
                    }
                }
            };
            return new LocalA();
        }
        export function kleisliMulti2<Env extends EnvBase,T1,T2,OutT>(f : (x: TimedDataWithEnvironment<Env,Either2<T1,T2>>) => TimedDataWithEnvironment<Env,OutT[]>) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                public constructor() {
                    super();
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    let v = f(
                        data
                    );
                    if (v === null || v.timedData.value === null) {
                        return;
                    }
                    for (let i=1; i<v.timedData.value.length; ++i) {
                        this.publish({
                            environment : v.environment
                            , timedData : {
                                timePoint : v.timedData.timePoint
                                , value : v.timedData.value[i]
                                , finalFlag : v.timedData.finalFlag && (i == v.timedData.value.length-1)
                            }
                        });
                    }
                }
            };
            return new LocalA();
        }
        export function continuationAction<Env extends EnvBase,T,OutT>(f : Kleisli.Cont<Env,T,OutT>) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    f(data, this.publish);
                }
            };
            return new LocalA();
        }
        export function delayedImporter<Env extends EnvBase,T1,T2>(i : Importer<Env,T2>) : Action<Env,T1,T2> {
            class LocalA extends Action<Env,T1,T2> {
                private importer : Importer<Env,T2>;
                private started : boolean;
                public constructor() {
                    super();
                    this.importer = i;
                    this.started = false;
                }
                public handle(data : TimedDataWithEnvironment<Env, T1>) : void {
                    if (!this.started) {
                        this.started = true;
                        this.importer.start(data.environment);
                        (async () => {
                            for await (const x of this.importer.stream()) {
                                this.publish(x);
                            }
                        })();
                    }
                }
            }
            return new LocalA();
        }
        export function lazyImporter<Env extends EnvBase,T1,T2>(f : (t1 : T1) => Importer<Env,T2>) : Action<Env,T1,T2> {
            class LocalA extends Action<Env,T1,T2> {
                private importerFactory : (t1 : T1) => Importer<Env,T2>;
                private started : boolean;
                public constructor() {
                    super();
                    this.importerFactory = f;
                    this.started = false;
                }
                public handle(data : TimedDataWithEnvironment<Env, T1>) : void {
                    if (!this.started) {
                        this.started = true;
                        let imp = this.importerFactory(data.timedData.value);
                        imp.start(data.environment);
                        (async () => {
                            for await (const x of imp.stream()) {
                                this.publish(x);
                            }
                        })();
                    }
                }
            }
            return new LocalA();
        }
        export function liftPureOnOrderFacility<Env extends EnvBase,T,OutT>(f : (a : T) => OutT) : OnOrderFacility<Env,T,OutT> {
            class LocalO extends OnOrderFacility<Env,T,OutT> {
                public start(e : Env) : void {
                }
                public handle(data : TimedDataWithEnvironment<Env, Key<T>>) : void {
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment
                        , {
                            id : data.timedData.value.id 
                            , key : f(data.timedData.value.key)
                        }
                        , true
                    ));
                }
            };
            return new LocalO();
        }
    }

    export class Runner<Env extends EnvBase> {
        private env : Env;
        private importers : IExternalComponent<Env>[];
        private exporters : IExternalComponent<Env>[];
        private otherComponents : IExternalComponent<Env>[];
        public constructor(e : Env) {
            this.env = e;
            this.importers = [];
            this.exporters = [];
            this.otherComponents = [];
        }
        public environment() : Env {
            return this.env;
        }
        public importItem<T>(importer : Importer<Env,T>) : Source<Env,T> {
            if (this.importers.indexOf(importer) < 0) {
                this.importers.push(importer);
            }
            return new Source<Env,T>(importer.stream());
        }
        public exportItem<T>(exporter : Exporter<Env,T>, src : Source<Env,T>) : void {
            if (this.exporters.indexOf(exporter) < 0) {
                this.exporters.push(exporter);
            }
            src.stream.pipe(exporter.stream());
        }
        public exporterAsSink<T>(exporter : Exporter<Env,T>) : Sink<Env,T> {
            if (this.exporters.indexOf(exporter) < 0) {
                this.exporters.push(exporter);
            }
            return new Sink<Env,T>(exporter.stream());
        }
        public execute<T,OutT>(action : Action<Env,T,OutT>, src : Source<Env,T>) : Source<Env,OutT> {
            src.stream.pipe(action.stream());
            return new Source<Env,OutT>(action.stream());
        }
        public actionAsSource<T,OutT>(action : Action<Env,T,OutT>) : Source<Env,OutT> {
            return new Source<Env,OutT>(action.stream());
        }
        public actionAsSink<T,OutT>(action : Action<Env,T,OutT>) : Sink<Env,T> {
            return new Sink<Env,T>(action.stream());
        }
        public placeOrderWithFacility<T,OutT>(src : Source<Env,Key<T>>, facility : OnOrderFacility<Env,T,OutT>, sink : Sink<Env,KeyedData<T,OutT>>) {
            if (this.otherComponents.indexOf(facility) < 0) {
                this.otherComponents.push(facility);
            }
            src.stream.pipe(facility.stream());
            facility.stream().pipe(sink.stream);
        }
        public placeOrderWithFacilityAndForget<T,OutT>(src : Source<Env,Key<T>>, facility : OnOrderFacility<Env,T,OutT>) {
            if (this.otherComponents.indexOf(facility) < 0) {
                this.otherComponents.push(facility);
            }
            src.stream.pipe(facility.stream());
        }
        public execute_2_1<T1,T2,OutT>(action : Action2<Env,T1,T2,OutT>, src : Source<Env,T1>) : Source<Env,OutT> {
            let p = Utils.liftPure<Env,T1,Either2<T1,T2>>((x : T1) => [0, x]);
            src.stream.pipe(p.stream());
            p.stream().pipe(action.stream());
            return new Source<Env,OutT>(action.stream());
        }
        public execute_2_2<T1,T2,OutT>(action : Action2<Env,T1,T2,OutT>, src : Source<Env,T2>) : Source<Env,OutT> {
            let p = Utils.liftPure<Env,T2,Either2<T1,T2>>((x : T2) => [1, x]);
            src.stream.pipe(p.stream());
            p.stream().pipe(action.stream());
            return new Source<Env,OutT>(action.stream());
        }
        public actionAsSource2<T1,T2,OutT>(action : Action2<Env,T1,T2,OutT>) : Source<Env,OutT> {
            return new Source<Env,OutT>(action.stream());
        }
        public actionAsSink2_1<T1,T2,OutT>(action : Action2<Env,T1,T2,OutT>) : Sink<Env,T1> {
            let p = Utils.liftPure<Env,T1,Either2<T1,T2>>((x : T1) => [0, x]);
            p.stream().pipe(action.stream());
            return new Sink<Env,T1>(p.stream());
        }
        public actionAsSink2_2<T1,T2,OutT>(action : Action2<Env,T1,T2,OutT>) : Sink<Env,T2> {
            let p = Utils.liftPure<Env,T2,Either2<T1,T2>>((x : T2) => [1, x]);
            p.stream().pipe(action.stream());
            return new Sink<Env,T2>(p.stream());
        }
        public connect<T>(src : Source<Env,T>, sink : Sink<Env,T>) : void {
            src.stream.pipe(sink.stream);
        }
        public finalize() : void {
            for (let e of this.exporters) {
                e.start(this.env);
            }
            for (let e of this.otherComponents) {
                e.start(this.env);
            }
            for (let e of this.importers) {
                e.start(this.env);
            }
        }
    }
    export interface FacilityStreamer<Env extends EnvBase, T1, T2> {
        send : ((x : (T1 | TimedDataWithEnvironment<Env,T1>)) => void);
        read : (() => AsyncGenerator<TimedDataWithEnvironment<Env,KeyedData<T1,T2>>>);
    }
    export class SynchronousRunner<Env extends EnvBase> {
        private env : Env;
        private started : Map<RealTimeApp.IExternalComponent<Env>,boolean>; 
        public constructor(e : Env) {
            this.env = e;
            this.started = new Map<RealTimeApp.IExternalComponent<Env>,boolean>();
        }
        public async * importItem<T>(importer : Importer<Env,T>) {
            if (this.started.has(importer)) {
                throw 'importer already started';
            }
            importer.start(this.env);
            this.started.set(importer, true);
            for await (const item of importer.stream()) {
                yield item;
                if (item.timedData.finalFlag) {
                    return;
                }
            }
        }
        public async * importItemUntil<T>(importer : Importer<Env,T>, condition : (data : TimedDataWithEnvironment<Env,T>) => boolean) {
            if (this.started.has(importer)) {
                throw 'importer already started';
            }
            importer.start(this.env);
            this.started.set(importer, true);
            for await (const item of importer.stream()) {
                yield item;
                if (condition(item)) {
                    return;
                }
                if (item.timedData.finalFlag) {
                    return;
                }
            }
        }
        public async * placeOrderWithFacility<T1,T2>(key : TimedDataWithEnvironment<Env,Key<T1>>, facility : OnOrderFacility<Env,T1,T2>) {
            if (!this.started.has(facility)) {
                facility.start(this.env);
                this.started.set(facility, true);
            }
            facility.stream().write(key);
            //facility.handle(key);
            for await (const item of (facility.stream() as any).iterator({destroyOnReturn: false, destroyOnError: false})) {
                yield item;
                if (item.timedData.finalFlag) {
                    break;
                }
            }
            return;
        }

        public facilityStreamer<T1,T2>(facility : OnOrderFacility<Env,T1,T2>) : FacilityStreamer<Env,T1,T2> {
            if (!this.started.has(facility)) {
                facility.start(this.env);
                this.started.set(facility, true);
            }
            let id = uuidv4();
            let env = this.env;
            return {
                send : (x : (T1 | TimedDataWithEnvironment<Env,T1>)) => {
                    if (<T1>(x) !== undefined) {
                        facility.stream().write({
                            environment: env
                            , timedData: {
                                timePoint: env.now()
                                , value: {id : id, key : (x as T1)}
                                , finalFlag : false
                            }
                        });
                    } else {
                        facility.stream().write({
                            environment: env
                            , timedData: {
                                timePoint: (x as TimedDataWithEnvironment<Env,T1>).timedData.timePoint
                                , value: {id : id, key : (x as TimedDataWithEnvironment<Env,T1>).timedData.value}
                                , finalFlag : (x as TimedDataWithEnvironment<Env,T1>).timedData.finalFlag
                            }
                        });
                    }
                }
                , read : async function *f() {
                    for await (const item of (facility.stream() as any).iterator({destroyOnReturn: false, destroyOnError: false})) {
                        yield item;
                        if (item.timedData.finalFlag) {
                            break;
                        }
                    }
                    return;
                }
            };
        }
        
        public exportItem<T>(exporter : Exporter<Env,T>, item : TimedDataWithEnvironment<Env,T>) : void {
            if (!this.started.has(exporter)) {
                exporter.start(this.env);
                this.started.set(exporter, true);
            }
            exporter.stream().write(item);
        }
    }
}