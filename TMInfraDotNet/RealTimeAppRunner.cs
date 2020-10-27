using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Channels;
using Optional;
using Optional.Unsafe;

namespace Dev.CD606.TM.Infra.RealTimeApp
{
    public class Runner<Env> where Env : EnvBase
    {
        private Env env;
        private List<IExternalComponent<Env>> importers = new List<IExternalComponent<Env>>();
        private List<IExternalComponent<Env>> exporters = new List<IExternalComponent<Env>>();
        private List<IExternalComponent<Env>> otherComponents = new List<IExternalComponent<Env>>();
        private object lockObj = new object();

        public Runner(Env env)
        {
            this.env = env;
        }

        public readonly struct Source<T>
        {
            public readonly Producer<Env,T> producer;
            public Source(Producer<Env,T> producer)
            {
                this.producer = producer;
            }
        }
        public readonly struct Sink<T>
        {
            public readonly IHandler<Env,T> handler;
            public Sink(IHandler<Env,T> handler)
            {
                this.handler = handler;
            }
        }
        public Source<T> importItem<T>(AbstractImporter<Env,T> importer)
        {
            lock (lockObj)
            {
                if (!importers.Contains(importer))
                {
                    importers.Add(importer);
                }
            }
            return new Source<T>(importer);
        }
        public Sink<T> exporterAsSink<T>(AbstractExporter<Env,T> exporter)
        {
            lock (lockObj)
            {
                if (!exporters.Contains(exporter))
                {
                    exporters.Add(exporter);
                }
            }
            return new Sink<T>(exporter);
        }
        public void connect<T>(Source<T> source, Sink<T> sink)
        {
            source.producer.addHandler(sink.handler);
        }
        public void exportItem<T>(AbstractExporter<Env,T> exporter, Source<T> item)
        {
            connect(item, exporterAsSink(exporter));
        }
        public void finalize()
        {
            foreach (var e in exporters)
            {
                e.start(env);
            }
            foreach (var e in otherComponents)
            {
                e.start(env);
            }
            foreach (var e in importers)
            {
                e.start(env);
            }
        }
    }
}