export interface Key<T> {
    id: string;
    key: T;
};
export interface KeyedData<A, B> {
    key: Key<A>;
    data: B;
};
export interface VersionedData<Version, T> {
    version: Version | null;
    data: T;
};
export interface GroupedVersionedData<GroupID, Version, T> {
    groupID: GroupID | null;
    version: Version | null;
    data: T;
};
export interface WithTime<T> {
    timePoint: Date;
    value: T;
    finalFlag: boolean;
};
export interface TimedDataWithEnvironment<Env, T> {
    environment: Env;
    timedData: WithTime<T>;
};
export enum LogLevel {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Critical
}
export interface EnvBase {
    now: () => Date;
    log: (l: LogLevel, s: string) => void;
    exit: () => void
}

export type Kleisli_F<Env extends EnvBase, T1, T2> = (x: TimedDataWithEnvironment<Env, T1>) => TimedDataWithEnvironment<Env, T2> | null;
export type Kleisli_Cont<Env extends EnvBase, T1, T2> = (x: TimedDataWithEnvironment<Env, T1>, f: (t2: TimedDataWithEnvironment<Env, T2>) => void) => void;
export type Either2<T1, T2> = [0, T1] | [1, T2];
//Action3 and above are currently not supported yet, so the Either3 and above types are
//simply convenience types
export type Either3<T1, T2, T3> = [0, T1] | [1, T2] | [2, T3];
export type Either4<T1, T2, T3, T4> = [0, T1] | [1, T2] | [2, T3] | [3, T4];
export type Either5<T1, T2, T3, T4, T5> = [0, T1] | [1, T2] | [2, T3] | [3, T4] | [4, T5];

export type PubFunc<T> = ((t: T, isFinal: boolean) => void);
export type Generator<Env extends EnvBase, T> = ((env: Env, pub: PubFunc<T>) => void);
export type UniformSimpleGenerator<Env extends EnvBase, T> =
    ((env: Env) => Promise<[boolean, TimedDataWithEnvironment<Env, T>]>);
export interface FacilityStreamer<Env extends EnvBase, T1, T2> {
    send: ((x: (T1 | TimedDataWithEnvironment<Env, T1>)) => void);
    read: (() => AsyncGenerator<TimedDataWithEnvironment<Env, KeyedData<T1, T2>>>);
}