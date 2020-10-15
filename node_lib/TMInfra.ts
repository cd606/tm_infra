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
export function pureTimedDataWithEnvironment<Env,T>(env : Env, t : T, final : boolean = true) : TimedDataWithEnvironment<Env,T> {
    return {
        environment : env
        , timedData : {
            timePoint : new Date()
            , value : t                
            , finalFlag : final
        }
    }
}
export function mapTimedDataWithEnvironment<Env,T1,T2>(f : (t : T1)=>T2, x : TimedDataWithEnvironment<Env,T1>) : TimedDataWithEnvironment<Env,T2> {
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
    export type F<Env,T1,T2> = (x : TimedDataWithEnvironment<Env,T1>) => TimedDataWithEnvironment<Env,T2>;
    export class Utils {
        public static liftPure<Env,T,OutT>(f : (a : T) => OutT) : F<Env,T,OutT> {
            return function (x : TimedDataWithEnvironment<Env,T>) : TimedDataWithEnvironment<Env,OutT> {
                return mapTimedDataWithEnvironment<Env,T,OutT>(f, x);
            }
        }
        public static liftMaybe<Env,T,OutT>(f : (a : T) => OutT) : F<Env,T,OutT> {
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
        public static enhancedMaybe<Env,T,OutT>(f : (d : Date, a : T) => OutT) : F<Env,T,OutT> {
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
        public static compose<Env,T1,T2,T3>(f1 : F<Env,T1,T2>, f2 : F<Env,T2,T3>) : F<Env,T1,T3> {
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
    export abstract class IExternalComponent<Env> {
        public abstract start(e : Env) : void;
    }
    export abstract class Importer<Env,T> extends IExternalComponent<Env> {
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
        public stream() : Stream.Readable {
            return this.theStream;
        }
    };
    export class TimeChecker<Env,T> {
        private now : Date;
        private version : any;
        public constructor() {
            this.now = new Date();
            this.version = null;
        }
        public check(data : TimedDataWithEnvironment<Env,T>) : boolean {
            if (data.timedData.timePoint < this.now) {
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
    export abstract class Exporter<Env,T> extends IExternalComponent<Env> {
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
    export abstract class Action<Env,T,OutT> {
        private theStream : Stream.Transform;
        private timeChecker : TimeChecker<Env, T>;
        public abstract handle(data: TimedDataWithEnvironment<Env, T>) : void;
        protected publish(data : TimedDataWithEnvironment<Env,OutT>) {
            this.theStream.push(data);
        }
        public constructor() {
            let thisObj = this;
            this.theStream = new Stream.Transform({
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
        public stream() : Stream.Transform {
            return this.theStream;
        }
    }
    export type Either2<T1,T2> = [number, T1|T2];
    export abstract class Action2<Env,T1,T2,OutT> {
        private theStream : Stream.Transform;
        private timeChecker1 : TimeChecker<Env, T1>;
        private timeChecker2 : TimeChecker<Env, T2>;
        public abstract handle(data: TimedDataWithEnvironment<Env,Either2<T1,T2>>) : void;
        protected publish(data : TimedDataWithEnvironment<Env, OutT>) {
            this.theStream.push(data);
        }
        public constructor() {
            let thisObj = this;
            this.theStream = new Stream.Transform({
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
                , objectMode : true
            });
            this.timeChecker1 = new TimeChecker<Env,T1>();
            this.timeChecker2 = new TimeChecker<Env,T2>();
        }
        public stream() : Stream.Transform {
            return this.theStream;
        }
    }
    export abstract class OnOrderFacility<Env,T,OutT> extends IExternalComponent<Env> {
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
                , objectMode : true
            });
            this.timeChecker = new TimeChecker<Env,Key<T>>();
        }
        public stream() : Stream.Duplex {
            return this.theStream;
        }
    }
    export class Source<Env,T> {
        public stream : Stream.Readable;
        public constructor(s : Stream.Readable) {
            this.stream = s;
        }
    };
    export class Sink<Env,T> {
        public stream : Stream.Writable;
        public constructor(s : Stream.Writable) {
            this.stream = s;
        }
    };
    export type PubFunc<T> = ((t : T, isFinal : boolean) => void);
    export type Generator<T> = ((pub : PubFunc<T>) => void);
    export class Utils {
        public static simpleImporter<Env,T>(gen : Generator<T>) : Importer<Env,T> {
            class LocalI extends Importer<Env,T> {
                private genFunc : Generator<T>;
                public constructor() {
                    super();
                    this.genFunc = gen;
                }
                public start(e : Env) : void {
                    this.env = e;
                    let thisObj = this;
                    this.genFunc((t : T, isFinal : boolean) => {
                        thisObj.publish(t, isFinal);
                    });
                }
            };
            return new LocalI();
        }
        public static simpleExporter<Env,T>(f : (a : TimedDataWithEnvironment<Env,T>) => void) : Exporter<Env,T> {
            class LocalE extends Exporter<Env,T> {
                public start(_e : Env) : void {}
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    f(data);
                }
            };
            return new LocalE();
        }
        public static pureExporter<Env,T>(f : (a : T) => void) : Exporter<Env,T> {
            class LocalE extends Exporter<Env,T> {
                public start(_e : Env) : void {}
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    f(data.timedData.value);
                }
            };
            return new LocalE();
        }
        public static liftPure<Env,T,OutT>(f : (a : T) => OutT) : Action<Env,T,OutT> {
            class LocalA extends Action<Env,T,OutT> {
                public handle(data : TimedDataWithEnvironment<Env, T>) : void {
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, f(data.timedData.value), data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        public static liftMaybe<Env,T,OutT>(f : (a : T) => OutT) : Action<Env,T,OutT> {
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
        public static enhancedMaybe<Env,T,OutT>(f : (d : Date, a : T) => OutT) : Action<Env,T,OutT> {
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
        public static kleisli<Env,T,OutT>(f : Kleisli.F<Env,T,OutT>) : Action<Env,T,OutT> {
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
        public static liftMulti<Env,T,OutT>(f : (a : T) => OutT[]) : Action<Env,T,OutT> {
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
        public static enhancedMulti<Env,T,OutT>(f : (d : Date, a : T) => OutT[]) : Action<Env,T,OutT> {
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
        public static kleisliMulti<Env,T,OutT>(f : (a : TimedDataWithEnvironment<Env,T>) => TimedDataWithEnvironment<Env,OutT[]>) : Action<Env,T,OutT> {
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
        public static liftPure2<Env,T1,T2,OutT>(f : (index: number, a : T1, b : T2) => OutT, reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : T1;
                private snapshot2 : T2;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = data.timedData.value[1] as T1;
                    } else {
                        this.snapshot2 = data.timedData.value[1] as T2;
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, f(data.timedData.value[0], this.snapshot1, this.snapshot2), data.timedData.finalFlag
                    ));
                }
            };
            return new LocalA();
        }
        public static liftMaybe2<Env,T1,T2,OutT>(f : (index: number, a : T1, b : T2) => OutT, reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : T1;
                private snapshot2 : T2;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = data.timedData.value[1] as T1;
                    } else {
                        this.snapshot2 = data.timedData.value[1] as T2;
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    let v = f(data.timedData.value[0], this.snapshot1, this.snapshot2);
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
        public static enhancedMaybe2<Env,T1,T2,OutT>(f : (index: number, d1 : Date, a : T1, d2 : Date, b : T2) => OutT, reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : TimedDataWithEnvironment<Env,T1>;
                private snapshot2 : TimedDataWithEnvironment<Env,T2>;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T1)
                            , data
                        );
                    } else {
                        this.snapshot2 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T2)
                            , data
                        );
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    let v = f(
                        data.timedData.value[0]
                        , this.snapshot1.timedData.timePoint
                        , this.snapshot1.timedData.value
                        , this.snapshot2.timedData.timePoint
                        , this.snapshot2.timedData.value
                    );
                    if (v === null) {
                        return;
                    }
                    this.publish(pureTimedDataWithEnvironment(
                        data.environment, v, (this.snapshot1.timedData.finalFlag && this.snapshot2.timedData.finalFlag)
                    ));
                }
            };
            return new LocalA();
        }
        public static kleisli2<Env,T1,T2,OutT>(f : (index: number, d1 : TimedDataWithEnvironment<Env,T1>, d2 : TimedDataWithEnvironment<Env,T2>) => TimedDataWithEnvironment<Env,OutT>, reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : TimedDataWithEnvironment<Env,T1>;
                private snapshot2 : TimedDataWithEnvironment<Env,T2>;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T1)
                            , data
                        );
                    } else {
                        this.snapshot2 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T2)
                            , data
                        );
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    let v = f(
                        data.timedData.value[0]
                        , this.snapshot1
                        , this.snapshot2
                    );
                    if (v === null || v.timedData.value === null) {
                        return;
                    }
                    this.publish(v);
                }
            };
            return new LocalA();
        }
        public static liftMulti2<Env,T1,T2,OutT>(f : (index: number, a : T1, b : T2) => OutT[], reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : T1;
                private snapshot2 : T2;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = data.timedData.value[1] as T1;
                    } else {
                        this.snapshot2 = data.timedData.value[1] as T2;
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    let v = f(data.timedData.value[0], this.snapshot1, this.snapshot2);
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
        public static enhancedMulti2<Env,T1,T2,OutT>(f : (index: number, d1 : Date, a : T1, d2 : Date, b : T2) => OutT[], reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : TimedDataWithEnvironment<Env,T1>;
                private snapshot2 : TimedDataWithEnvironment<Env,T2>;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T1)
                            , data
                        );
                    } else {
                        this.snapshot2 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T2)
                            , data
                        );
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    let v = f(
                        data.timedData.value[0]
                        , this.snapshot1.timedData.timePoint
                        , this.snapshot1.timedData.value
                        , this.snapshot2.timedData.timePoint
                        , this.snapshot2.timedData.value
                    );
                    if (v === null) {
                        return;
                    }
                    for (let t of v) {
                        this.publish(pureTimedDataWithEnvironment(
                            data.environment, t, (this.snapshot1.timedData.finalFlag && this.snapshot2.timedData.finalFlag)
                        ));
                    }
                }
            };
            return new LocalA();
        }
        public static kleisliMulti2<Env,T1,T2,OutT>(f : (index: number, d1 : TimedDataWithEnvironment<Env,T1>, d2 : TimedDataWithEnvironment<Env,T2>) => TimedDataWithEnvironment<Env,OutT[]>, reqMask : typeof BitSet) : Action2<Env,T1,T2,OutT> {
            class LocalA extends Action2<Env,T1,T2,OutT> {
                private snapshot1 : TimedDataWithEnvironment<Env,T1>;
                private snapshot2 : TimedDataWithEnvironment<Env,T2>;
                private requireMask : typeof BitSet;
                public constructor() {
                    super();
                    this.snapshot1 = null;
                    this.snapshot2 = null;
                    this.requireMask = reqMask;
                }
                public handle(data : TimedDataWithEnvironment<Env, Either2<T1,T2>>) : void {
                    if (data.timedData.value[0] == 0) {
                        this.snapshot1 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T1)
                            , data
                        );
                    } else {
                        this.snapshot2 = mapTimedDataWithEnvironment(
                            (x : Either2<T1,T2>) => (x[1] as T2)
                            , data
                        );
                    }
                    if (this.requireMask.get(0) && this.snapshot1 === null) {
                        return;
                    }
                    if (this.requireMask.get(1) && this.snapshot2 === null) {
                        return;
                    }
                    let v = f(
                        data.timedData.value[0]
                        , this.snapshot1
                        , this.snapshot2
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
    }

    export class Runner<Env> {
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
        public importItem<T>(importer : Importer<Env,T>) : Source<Env,T> {
            if (this.importers.indexOf(importer) < 0) {
                this.importers.push(importer);
            }
            return new Source<Env,T>(importer.stream());
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
}