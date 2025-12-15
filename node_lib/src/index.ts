// index.ts
import * as Types from "./types";
import * as Stream from 'stream'
import { v4 as uuidv4 } from 'uuid';

export type * from "./types";
export { LogLevel } from "./types";

export function keyify<T>(t: T): Types.Key<T> {
    return {
        id: uuidv4()
        , key: t
    };
}
export function pureTimedDataWithEnvironment<Env extends Types.EnvBase, T>(env: Env, t: T, final: boolean = false): Types.TimedDataWithEnvironment<Env, T> {
    return {
        environment: env
        , timedData: {
            timePoint: env.now()
            , value: t
            , finalFlag: final
        }
    }
}
export function mapTimedDataWithEnvironment<Env extends Types.EnvBase, T1, T2>(f: (t: T1) => T2, x: Types.TimedDataWithEnvironment<Env, T1>): Types.TimedDataWithEnvironment<Env, T2> {
    return {
        environment: x.environment
        , timedData: {
            timePoint: x.timedData.timePoint
            , value: f(x.timedData.value)
            , finalFlag: x.timedData.finalFlag
        }
    };
}

export class Kleisli_Utils {
    public static liftPure<Env extends Types.EnvBase, T, OutT>(f: (a: T) => OutT): Types.Kleisli_F<Env, T, OutT> {
        return function (x: Types.TimedDataWithEnvironment<Env, T>): Types.TimedDataWithEnvironment<Env, OutT> | null {
            return mapTimedDataWithEnvironment<Env, T, OutT>(f, x);
        }
    }
    public static liftMaybe<Env extends Types.EnvBase, T, OutT>(f: (a: T) => OutT | null): Types.Kleisli_F<Env, T, OutT> {
        return function (x: Types.TimedDataWithEnvironment<Env, T>): Types.TimedDataWithEnvironment<Env, OutT> | null {
            let y = f(x.timedData.value);
            if (y === null) {
                return null;
            }
            return {
                environment: x.environment
                , timedData: {
                    timePoint: x.timedData.timePoint
                    , value: y
                    , finalFlag: x.timedData.finalFlag
                }
            };
        }
    }
    public static enhancedMaybe<Env extends Types.EnvBase, T, OutT>(f: (d: Date, a: T) => OutT | null): Types.Kleisli_F<Env, T, OutT> {
        return function (x: Types.TimedDataWithEnvironment<Env, T>): Types.TimedDataWithEnvironment<Env, OutT> | null {
            let y = f(x.timedData.timePoint, x.timedData.value);
            if (y === null) {
                return null;
            }
            return {
                environment: x.environment
                , timedData: {
                    timePoint: x.timedData.timePoint
                    , value: y
                    , finalFlag: x.timedData.finalFlag
                }
            };
        }
    }
    public static compose<Env extends Types.EnvBase, T1, T2, T3>(f1: Types.Kleisli_F<Env, T1, T2>, f2: Types.Kleisli_F<Env, T2, T3>): Types.Kleisli_F<Env, T1, T3> {
        return function (x: Types.TimedDataWithEnvironment<Env, T1>): Types.TimedDataWithEnvironment<Env, T3> | null {
            let y = f1(x);
            if (y === null) {
                return null;
            }
            return f2(y);
        }
    }
}
export const Kleisli = {
    Utils: Kleisli_Utils
} as const;


export abstract class RealTimeApp_IExternalComponent<Env extends Types.EnvBase> {
    public abstract start(e: Env): void;
}
export abstract class RealTimeApp_Importer<Env extends Types.EnvBase, T> extends RealTimeApp_IExternalComponent<Env> {
    private theStream: Stream.Readable;
    protected env: Env | null;
    public constructor() {
        super();
        this.theStream = new Stream.Readable({
            read: function () { }
            , objectMode: true
        });
        this.env = null;
    }
    protected publish(data: T, isFinal: boolean = false) {
        if (this.env !== null) {
            this.theStream.push(pureTimedDataWithEnvironment(this.env!, data, isFinal));
        }
    }
    protected publishTimedDataWithEnvironment(data: Types.TimedDataWithEnvironment<Env, T> | null) {
        if (data != null) {
            this.theStream.push(data);
        }
    }
    public stream(): Stream.Readable {
        return this.theStream;
    }
};
export class RealTimeApp_TimeChecker<Env extends Types.EnvBase, T> {
    private now: Date | null;
    private version: any;
    public constructor() {
        this.now = null;
        this.version = null;
    }
    public check(data: Types.TimedDataWithEnvironment<Env, T>): boolean {
        if (this.now != null && data.timedData.timePoint < this.now) {
            return false;
        }
        if ((data.timedData.value as any).groupID !== undefined && (data.timedData.value as any).version !== undefined) {
            let groupID = (data.timedData.value as any).groupID;
            let version = (data.timedData.value as any).version;
            if (this.version == null) {
                this.version = { groupID: version };
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
export abstract class RealTimeApp_Exporter<Env extends Types.EnvBase, T> extends RealTimeApp_IExternalComponent<Env> {
    private theStream: Stream.Writable;
    private timeChecker: RealTimeApp_TimeChecker<Env, T>;
    public abstract handle(data: Types.TimedDataWithEnvironment<Env, T>): void;
    public constructor() {
        super();
        let thisObj = this;
        this.theStream = new Stream.Writable({
            write: function (chunk: Types.TimedDataWithEnvironment<Env, T>, _encoding: BufferEncoding, callback: () => void) {
                if (thisObj.timeChecker.check(chunk)) {
                    thisObj.handle(chunk);
                }
                callback();
            }
            , objectMode: true
        });
        this.timeChecker = new RealTimeApp_TimeChecker<Env, T>();
    }
    public stream(): Stream.Writable {
        return this.theStream;
    }
};
export abstract class RealTimeApp_Action<Env extends Types.EnvBase, T, OutT> {
    private theStream: Stream.Duplex;
    private timeChecker: RealTimeApp_TimeChecker<Env, T>;
    public abstract handle(data: Types.TimedDataWithEnvironment<Env, T>): void;
    protected publish(data: Types.TimedDataWithEnvironment<Env, OutT>) {
        this.theStream.push(data);
    }
    public constructor() {
        let thisObj = this;
        this.theStream = new Stream.Duplex({
            write: function (chunk: Types.TimedDataWithEnvironment<Env, T>, _encoding: BufferEncoding, callback: () => void) {
                if (thisObj.timeChecker.check(chunk)) {
                    thisObj.handle(chunk);
                }
                callback();
            }
            , read: function (_s: number) { }
            , objectMode: true
        });
        this.timeChecker = new RealTimeApp_TimeChecker<Env, T>();
    }
    public stream(): Stream.Duplex {
        return this.theStream;
    }
}
export abstract class RealTimeApp_Action2<Env extends Types.EnvBase, T1, T2, OutT> {
    private theStream: Stream.Duplex;
    private timeChecker1: RealTimeApp_TimeChecker<Env, T1>;
    private timeChecker2: RealTimeApp_TimeChecker<Env, T2>;
    public abstract handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void;
    protected publish(data: Types.TimedDataWithEnvironment<Env, OutT>) {
        this.theStream.push(data);
    }
    public constructor() {
        let thisObj = this;
        this.theStream = new Stream.Duplex({
            write: function (chunk: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>, _encoding: BufferEncoding, callback: () => void) {
                if (chunk.timedData.value[0] == 0) {
                    if (thisObj.timeChecker1.check(mapTimedDataWithEnvironment(
                        (x: Types.Either2<T1, T2>) => (x[1] as T1)
                        , chunk
                    ))) {
                        thisObj.handle(chunk);
                    }
                } else {
                    if (thisObj.timeChecker2.check(mapTimedDataWithEnvironment(
                        (x: Types.Either2<T1, T2>) => (x[1] as T2)
                        , chunk
                    ))) {
                        thisObj.handle(chunk);
                    }
                }
                callback();
            }
            , read: function (_s: number) { }
            , objectMode: true
        });
        this.timeChecker1 = new RealTimeApp_TimeChecker<Env, T1>();
        this.timeChecker2 = new RealTimeApp_TimeChecker<Env, T2>();
    }
    public stream(): Stream.Duplex {
        return this.theStream;
    }
}
export abstract class RealTimeApp_OnOrderFacility<Env extends Types.EnvBase, T, OutT> extends RealTimeApp_IExternalComponent<Env> {
    private theStream: Stream.Duplex;
    private timeChecker: RealTimeApp_TimeChecker<Env, Types.Key<T>>;
    private requestMap: Map<string, Types.Key<T>>;
    public abstract handle(data: Types.TimedDataWithEnvironment<Env, Types.Key<T>>): void;
    protected publish(data: Types.TimedDataWithEnvironment<Env, Types.Key<OutT>>): void {
        let originalKey = this.requestMap.get(data.timedData.value.id);
        if (originalKey === undefined) {
            return;
        }
        this.theStream.push({
            environment: data.environment
            , timedData: {
                timePoint: data.timedData.timePoint
                , value: {
                    key: originalKey
                    , data: data.timedData.value.key
                }
                , finalFlag: data.timedData.finalFlag
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
            write: function (chunk: Types.TimedDataWithEnvironment<Env, Types.Key<T>>, _encoding: BufferEncoding, callback: () => void) {
                if (thisObj.timeChecker.check(chunk)) {
                    thisObj.requestMap.set(chunk.timedData.value.id, chunk.timedData.value);
                    thisObj.handle(chunk);
                }
                callback();
            }
            , read: (_s: number) => { }
            , objectMode: true
        });
        this.timeChecker = new RealTimeApp_TimeChecker<Env, Types.Key<T>>();
        this.requestMap = new Map<string, Types.Key<T>>();
    }
    public stream(): Stream.Duplex {
        return this.theStream;
    }
}

export class RealTimeApp_Source<Env extends Types.EnvBase, T> {
    public stream: Stream.Readable;
    public constructor(s: Stream.Readable) {
        this.stream = s;
    }
};
export class RealTimeApp_Sink<Env extends Types.EnvBase, T> {
    public stream: Stream.Writable;
    public constructor(s: Stream.Writable) {
        this.stream = s;
    }
};
export function RealTimeApp_Utils_simpleImporter<Env extends Types.EnvBase, T>(gen: Types.Generator<Env, T>): RealTimeApp_Importer<Env, T> {
    class LocalI extends RealTimeApp_Importer<Env, T> {
        private genFunc: Types.Generator<Env, T>;
        public constructor() {
            super();
            this.genFunc = gen;
        }
        public start(e: Env): void {
            this.env = e;
            let thisObj = this;
            this.genFunc(e, (t: T, isFinal: boolean) => {
                thisObj.publish(t, isFinal);
            });
        }
    };
    return new LocalI();
}
export function RealTimeApp_Utils_uniformSimpleImporter<Env extends Types.EnvBase, T>(gen: Types.UniformSimpleGenerator<Env, T>): RealTimeApp_Importer<Env, T> {
    class LocalI extends RealTimeApp_Importer<Env, T> {
        private genFunc: Types.UniformSimpleGenerator<Env, T>;
        public constructor() {
            super();
            this.genFunc = gen;
        }
        public start(e: Env): void {
            this.env = e;
            let thisObj = this;
            (async () => {
                while (true) {
                    if (thisObj.env === null) {
                        continue;
                    }
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

export class RealTimeApp_Utils_TriggerImporter<Env extends Types.EnvBase, T> extends RealTimeApp_Importer<Env, T> {
    public constructor() {
        super();
    }
    public start(e: Env): void {
        this.env = e;
    }
    public trigger(t: T): void {
        this.publish(t, false);
    }
}
export class RealTimeApp_Utils_ConstTriggerImporter<Env extends Types.EnvBase, T> extends RealTimeApp_Importer<Env, T> {
    private value: T;
    public constructor(t: T) {
        super();
        this.value = t;
    }
    public start(e: Env): void {
        this.env = e;
    }
    public trigger(): void {
        this.publish(this.value, false);
    }
}
export function RealTimeApp_Utils_constFirstPushImporter<Env extends Types.EnvBase, T>(t: T): RealTimeApp_Importer<Env, T> {
    return RealTimeApp_Utils_simpleImporter<Env, T>((_e: Env, pub: Types.PubFunc<T>) => {
        pub(t, true);
    });
}
export function RealTimeApp_Utils_constFirstPushKeyImporter<Env extends Types.EnvBase, T>(t: T): RealTimeApp_Importer<Env, Types.Key<T>> {
    return RealTimeApp_Utils_simpleImporter<Env, Types.Key<T>>((_e: Env, pub: Types.PubFunc<Types.Key<T>>) => {
        pub(keyify(t), true);
    });
}
export function RealTimeApp_Utils_simpleExporter<Env extends Types.EnvBase, T>(f: (a: Types.TimedDataWithEnvironment<Env, T>) => void): RealTimeApp_Exporter<Env, T> {
    class LocalE extends RealTimeApp_Exporter<Env, T> {
        public start(_e: Env): void { }
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
            f(data);
        }
    };
    return new LocalE();
}
export function RealTimeApp_Utils_pureExporter<Env extends Types.EnvBase, T>(f: (a: T) => void): RealTimeApp_Exporter<Env, T> {
    class LocalE extends RealTimeApp_Exporter<Env, T> {
        public start(_e: Env): void { }
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
            f(data.timedData.value);
        }
    };
    return new LocalE();
}
export function RealTimeApp_Utils_liftPure<Env extends Types.EnvBase, T, OutT>(f: (a: T) => OutT): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
            this.publish(pureTimedDataWithEnvironment(
                data.environment, f(data.timedData.value), data.timedData.finalFlag
            ));
        }
    };
    return new LocalA();
}
export function RealTimeApp_Utils_liftMaybe<Env extends Types.EnvBase, T, OutT>(f: (a: T) => OutT | null): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
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
export function RealTimeApp_Utils_enhancedMaybe<Env extends Types.EnvBase, T, OutT>(f: (d: Date, a: T) => OutT): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
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
export function RealTimeApp_Utils_kleisli<Env extends Types.EnvBase, T, OutT>(f: Types.Kleisli_F<Env, T, OutT>): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
            let v = f(data);
            if (v === null || v.timedData.value === null) {
                return;
            }
            this.publish(v);
        }
    };
    return new LocalA();
}
export function RealTimeApp_Utils_liftMulti<Env extends Types.EnvBase, T, OutT>(f: (a: T) => OutT[]): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
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
export function RealTimeApp_Utils_enhancedMulti<Env extends Types.EnvBase, T, OutT>(f: (d: Date, a: T) => OutT[]): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
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
export function RealTimeApp_Utils_kleisliMulti<Env extends Types.EnvBase, T, OutT>(f: (a: Types.TimedDataWithEnvironment<Env, T>) => Types.TimedDataWithEnvironment<Env, OutT[]>): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
            let v = f(data);
            if (v === null || v.timedData.value === null) {
                return;
            }
            for (let i = 0; i < v.timedData.value.length; ++i) {
                this.publish({
                    environment: v.environment
                    , timedData: {
                        timePoint: v.timedData.timePoint
                        , value: v.timedData.value[i]
                        , finalFlag: v.timedData.finalFlag && (i == v.timedData.value.length - 1)
                    }
                });
            }
        }
    };
    return new LocalA();
}
export function RealTimeApp_Utils_liftPure2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: T1 | T2) => OutT): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
            this.publish(pureTimedDataWithEnvironment(
                data.environment, f(data.timedData.value[1]), data.timedData.finalFlag
            ));
        }
    };
    return new LocalA();
}
export function RealTimeApp_Utils_liftMaybe2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: T1 | T2) => OutT): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
            let v = f(data.timedData.value[1]);
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
export function RealTimeApp_Utils_enhancedMaybe2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: [Date, T1 | T2]) => OutT): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
            let v = f(
                [data.timedData.timePoint, data.timedData.value[1]]
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
export function RealTimeApp_Utils_kleisli2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>) => Types.TimedDataWithEnvironment<Env, OutT>): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
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
export function RealTimeApp_Utils_liftMulti2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: T1 | T2) => OutT[]): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
            let v = f(data.timedData.value[1]);
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
export function RealTimeApp_Utils_enhancedMulti2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: [Date, T1 | T2]) => OutT[]): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
            let v = f(
                [data.timedData.timePoint, data.timedData.value[1]]
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
export function RealTimeApp_Utils_kleisliMulti2<Env extends Types.EnvBase, T1, T2, OutT>(f: (x: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>) => Types.TimedDataWithEnvironment<Env, OutT[]>): RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
    class LocalA extends RealTimeApp_Action<Env, Types.Either2<T1, T2>, OutT> {
        public constructor() {
            super();
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Either2<T1, T2>>): void {
            let v = f(
                data
            );
            if (v === null || v.timedData.value === null) {
                return;
            }
            for (let i = 1; i < v.timedData.value.length; ++i) {
                this.publish({
                    environment: v.environment
                    , timedData: {
                        timePoint: v.timedData.timePoint
                        , value: v.timedData.value[i]
                        , finalFlag: v.timedData.finalFlag && (i == v.timedData.value.length - 1)
                    }
                });
            }
        }
    };
    return new LocalA();
}
export function RealTimeApp_Utils_continuationAction<Env extends Types.EnvBase, T, OutT>(f: Types.Kleisli_Cont<Env, T, OutT>): RealTimeApp_Action<Env, T, OutT> {
    class LocalA extends RealTimeApp_Action<Env, T, OutT> {
        public handle(data: Types.TimedDataWithEnvironment<Env, T>): void {
            f(data, this.publish);
        }
    };
    return new LocalA();
}
export function RealTimeApp_Utils_delayedImporter<Env extends Types.EnvBase, T1, T2>(i: RealTimeApp_Importer<Env, T2>): RealTimeApp_Action<Env, T1, T2> {
    class LocalA extends RealTimeApp_Action<Env, T1, T2> {
        private importer: RealTimeApp_Importer<Env, T2>;
        private started: boolean;
        public constructor() {
            super();
            this.importer = i;
            this.started = false;
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, T1>): void {
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
export function RealTimeApp_Utils_lazyImporter<Env extends Types.EnvBase, T1, T2>(f: (t1: T1) => RealTimeApp_Importer<Env, T2>): RealTimeApp_Action<Env, T1, T2> {
    class LocalA extends RealTimeApp_Action<Env, T1, T2> {
        private importerFactory: (t1: T1) => RealTimeApp_Importer<Env, T2>;
        private started: boolean;
        public constructor() {
            super();
            this.importerFactory = f;
            this.started = false;
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, T1>): void {
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
export function RealTimeApp_Utils_liftPureOnOrderFacility<Env extends Types.EnvBase, T, OutT>(f: (a: T) => OutT): RealTimeApp_OnOrderFacility<Env, T, OutT> {
    class LocalO extends RealTimeApp_OnOrderFacility<Env, T, OutT> {
        public start(e: Env): void {
        }
        public handle(data: Types.TimedDataWithEnvironment<Env, Types.Key<T>>): void {
            this.publish(pureTimedDataWithEnvironment(
                data.environment
                , {
                    id: data.timedData.value.id
                    , key: f(data.timedData.value.key)
                }
                , true
            ));
        }
    };
    return new LocalO();
}

export class RealTimeApp_Runner<Env extends Types.EnvBase> {
    private env: Env;
    private importers: RealTimeApp_IExternalComponent<Env>[];
    private exporters: RealTimeApp_IExternalComponent<Env>[];
    private otherComponents: RealTimeApp_IExternalComponent<Env>[];
    public constructor(e: Env) {
        this.env = e;
        this.importers = [];
        this.exporters = [];
        this.otherComponents = [];
    }
    public environment(): Env {
        return this.env;
    }
    public importItem<T>(importer: RealTimeApp_Importer<Env, T>): RealTimeApp_Source<Env, T> {
        if (this.importers.indexOf(importer) < 0) {
            this.importers.push(importer);
        }
        return new RealTimeApp_Source<Env, T>(importer.stream());
    }
    public exportItem<T>(exporter: RealTimeApp_Exporter<Env, T>, src: RealTimeApp_Source<Env, T>): void {
        if (this.exporters.indexOf(exporter) < 0) {
            this.exporters.push(exporter);
        }
        src.stream.pipe(exporter.stream());
    }
    public exporterAsSink<T>(exporter: RealTimeApp_Exporter<Env, T>): RealTimeApp_Sink<Env, T> {
        if (this.exporters.indexOf(exporter) < 0) {
            this.exporters.push(exporter);
        }
        return new RealTimeApp_Sink<Env, T>(exporter.stream());
    }
    public execute<T, OutT>(action: RealTimeApp_Action<Env, T, OutT>, src: RealTimeApp_Source<Env, T>): RealTimeApp_Source<Env, OutT> {
        src.stream.pipe(action.stream());
        return new RealTimeApp_Source<Env, OutT>(action.stream());
    }
    public actionAsSource<T, OutT>(action: RealTimeApp_Action<Env, T, OutT>): RealTimeApp_Source<Env, OutT> {
        return new RealTimeApp_Source<Env, OutT>(action.stream());
    }
    public actionAsSink<T, OutT>(action: RealTimeApp_Action<Env, T, OutT>): RealTimeApp_Sink<Env, T> {
        return new RealTimeApp_Sink<Env, T>(action.stream());
    }
    public placeOrderWithFacility<T, OutT>(src: RealTimeApp_Source<Env, Types.Key<T>>, facility: RealTimeApp_OnOrderFacility<Env, T, OutT>, sink: RealTimeApp_Sink<Env, Types.KeyedData<T, OutT>>) {
        if (this.otherComponents.indexOf(facility) < 0) {
            this.otherComponents.push(facility);
        }
        src.stream.pipe(facility.stream());
        facility.stream().pipe(sink.stream);
    }
    public placeOrderWithFacilityAndForget<T, OutT>(src: RealTimeApp_Source<Env, Types.Key<T>>, facility: RealTimeApp_OnOrderFacility<Env, T, OutT>) {
        if (this.otherComponents.indexOf(facility) < 0) {
            this.otherComponents.push(facility);
        }
        src.stream.pipe(facility.stream());
    }
    public execute_2_1<T1, T2, OutT>(action: RealTimeApp_Action2<Env, T1, T2, OutT>, src: RealTimeApp_Source<Env, T1>): RealTimeApp_Source<Env, OutT> {
        let p = RealTimeApp_Utils_liftPure<Env, T1, Types.Either2<T1, T2>>((x: T1) => [0, x]);
        src.stream.pipe(p.stream());
        p.stream().pipe(action.stream());
        return new RealTimeApp_Source<Env, OutT>(action.stream());
    }
    public execute_2_2<T1, T2, OutT>(action: RealTimeApp_Action2<Env, T1, T2, OutT>, src: RealTimeApp_Source<Env, T2>): RealTimeApp_Source<Env, OutT> {
        let p = RealTimeApp_Utils_liftPure<Env, T2, Types.Either2<T1, T2>>((x: T2) => [1, x]);
        src.stream.pipe(p.stream());
        p.stream().pipe(action.stream());
        return new RealTimeApp_Source<Env, OutT>(action.stream());
    }
    public actionAsSource2<T1, T2, OutT>(action: RealTimeApp_Action2<Env, T1, T2, OutT>): RealTimeApp_Source<Env, OutT> {
        return new RealTimeApp_Source<Env, OutT>(action.stream());
    }
    public actionAsSink2_1<T1, T2, OutT>(action: RealTimeApp_Action2<Env, T1, T2, OutT>): RealTimeApp_Sink<Env, T1> {
        let p = RealTimeApp_Utils_liftPure<Env, T1, Types.Either2<T1, T2>>((x: T1) => [0, x]);
        p.stream().pipe(action.stream());
        return new RealTimeApp_Sink<Env, T1>(p.stream());
    }
    public actionAsSink2_2<T1, T2, OutT>(action: RealTimeApp_Action2<Env, T1, T2, OutT>): RealTimeApp_Sink<Env, T2> {
        let p = RealTimeApp_Utils_liftPure<Env, T2, Types.Either2<T1, T2>>((x: T2) => [1, x]);
        p.stream().pipe(action.stream());
        return new RealTimeApp_Sink<Env, T2>(p.stream());
    }
    public connect<T>(src: RealTimeApp_Source<Env, T>, sink: RealTimeApp_Sink<Env, T>): void {
        src.stream.pipe(sink.stream);
    }
    public finalize(): void {
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
export class RealTimeApp_SynchronousRunner<Env extends Types.EnvBase> {
    private env: Env;
    private started: Map<RealTimeApp_IExternalComponent<Env>, boolean>;
    public constructor(e: Env) {
        this.env = e;
        this.started = new Map<RealTimeApp_IExternalComponent<Env>, boolean>();
    }
    public async * importItem<T>(importer: RealTimeApp_Importer<Env, T>) {
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
    public async * importItemUntil<T>(importer: RealTimeApp_Importer<Env, T>, condition: (data: Types.TimedDataWithEnvironment<Env, T>) => boolean) {
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
    public async * placeOrderWithFacility<T1, T2>(key: Types.TimedDataWithEnvironment<Env, Types.Key<T1>>, facility: RealTimeApp_OnOrderFacility<Env, T1, T2>) {
        if (!this.started.has(facility)) {
            facility.start(this.env);
            this.started.set(facility, true);
        }
        facility.stream().write(key);
        //facility.handle(key);
        for await (const item of (facility.stream() as any).iterator({ destroyOnReturn: false, destroyOnError: false })) {
            yield item;
            if (item.timedData.finalFlag) {
                break;
            }
        }
        return;
    }

    public facilityStreamer<T1, T2>(facility: RealTimeApp_OnOrderFacility<Env, T1, T2>): Types.FacilityStreamer<Env, T1, T2> {
        if (!this.started.has(facility)) {
            facility.start(this.env);
            this.started.set(facility, true);
        }
        let id = uuidv4();
        let env = this.env;
        return {
            send: (x: (T1 | Types.TimedDataWithEnvironment<Env, T1>)) => {
                if (<T1>(x) !== undefined) {
                    facility.stream().write({
                        environment: env
                        , timedData: {
                            timePoint: env.now()
                            , value: { id: id, key: (x as T1) }
                            , finalFlag: false
                        }
                    });
                } else {
                    facility.stream().write({
                        environment: env
                        , timedData: {
                            timePoint: (x as Types.TimedDataWithEnvironment<Env, T1>).timedData.timePoint
                            , value: { id: id, key: (x as Types.TimedDataWithEnvironment<Env, T1>).timedData.value }
                            , finalFlag: (x as Types.TimedDataWithEnvironment<Env, T1>).timedData.finalFlag
                        }
                    });
                }
            }
            , read: async function* f() {
                for await (const item of (facility.stream() as any).iterator({ destroyOnReturn: false, destroyOnError: false })) {
                    yield item;
                    if (item.timedData.finalFlag) {
                        break;
                    }
                }
                return;
            }
        };
    }

    public exportItem<T>(exporter: RealTimeApp_Exporter<Env, T>, item: Types.TimedDataWithEnvironment<Env, T>): void {
        if (!this.started.has(exporter)) {
            exporter.start(this.env);
            this.started.set(exporter, true);
        }
        exporter.stream().write(item);
    }
}
export const RealTimeApp = {
    IExternalComponent: RealTimeApp_IExternalComponent,
    TimeChecker: RealTimeApp_TimeChecker,
    Importer: RealTimeApp_Importer,
    Exporter: RealTimeApp_Exporter,
    Action: RealTimeApp_Action,
    Action2: RealTimeApp_Action2,
    OnOrderFacility: RealTimeApp_OnOrderFacility,
    Source: RealTimeApp_Source,
    Sink: RealTimeApp_Sink,
    Utils: {
        simpleImporter: RealTimeApp_Utils_simpleImporter,
        uniformSimpleImporter: RealTimeApp_Utils_uniformSimpleImporter,
        TriggerImporter: RealTimeApp_Utils_TriggerImporter,
        ConstTriggerImporter: RealTimeApp_Utils_ConstTriggerImporter,
        constFirstPushImporter: RealTimeApp_Utils_constFirstPushImporter,
        constFirstPushKeyImporter: RealTimeApp_Utils_constFirstPushKeyImporter,
        simpleExporter: RealTimeApp_Utils_simpleExporter,
        pureExporter: RealTimeApp_Utils_pureExporter,
        liftPure: RealTimeApp_Utils_liftPure,
        liftMaybe: RealTimeApp_Utils_liftMaybe,
        enhancedMaybe: RealTimeApp_Utils_enhancedMaybe,
        kleisli: RealTimeApp_Utils_kleisli,
        liftMulti: RealTimeApp_Utils_liftMulti,
        enhancedMulti: RealTimeApp_Utils_enhancedMulti,
        kleisliMulti: RealTimeApp_Utils_kleisliMulti,
        liftPure2: RealTimeApp_Utils_liftPure2,
        liftMaybe2: RealTimeApp_Utils_liftMaybe2,
        enhancedMaybe2: RealTimeApp_Utils_enhancedMaybe2,
        kleisli2: RealTimeApp_Utils_kleisli2,
        liftMulti2: RealTimeApp_Utils_liftMulti2,
        enhancedMulti2: RealTimeApp_Utils_enhancedMulti2,
        kleisliMulti2: RealTimeApp_Utils_kleisliMulti2,
        continuationAction: RealTimeApp_Utils_continuationAction,
        delayedImporter: RealTimeApp_Utils_delayedImporter,
        lazyImporter: RealTimeApp_Utils_lazyImporter,
        liftPureOnOrderFacility: RealTimeApp_Utils_liftPureOnOrderFacility,
    } as const,
    Runner: RealTimeApp_Runner,
    SynchronousRunner: RealTimeApp_SynchronousRunner,
} as const;
