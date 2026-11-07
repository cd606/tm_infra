# Regression tests

Build and run through Meson:

```sh
meson setup builddir
meson compile -C builddir
meson test -C builddir --print-errorlogs
```

For an existing build directory, start with `meson compile` so Meson discovers
new test targets. Checks remain active in release builds.

- `realtime scheduler` checks FIFO and round-robin dispatch, shared-thread
  serialization, concurrent producers, independent IDs and application instances,
  variant and multi-output graphs, composition, move-only inputs, one-time and
  continuation actions, queue teardown, shutdown, and Linux CPU affinity.
- `realtime scheduler storage` counts allocations while enqueuing actual action
  inputs and compares them with a plain deque of the same input type. It rejects
  extra per-input allocations for envelopes, control blocks, or callbacks.
- `realtime publisher batching` checks stable mixed synchronous/dedicated-thread
  listener order, ascending scheduler IDs, shared batch locks, variant outputs,
  distinct application contexts, exception cleanup, and `std::any` adapters.
- `graphviz scheduler annotations` checks scheduler IDs and dark violet styling on plain
  and HTML labels, one-time dotted styling, existing dedicated-thread red styling,
  and compatibility with application models without schedulers.
- `realtime exporter scheduler` checks shared action/exporter threads, FIFO,
  synchronous execution, move-only composition, `SynchronousRunner`, publisher
  batching, mode validation, exporter teardown, and application isolation.
- `key semantics` checks copy/reference behavior of existing accessors, explicit
  consumption, reference counts, and compile-time rejection of `takeKey()` on
  lvalues and const objects.
- `chrono compatibility` compares against the frozen original implementation,
  with independent expected values and UTC round trips. It covers every date
  from 1900 through 2100, deterministic random timestamps, pre-epoch and
  submicrosecond values, fractional precision, numeric offsets, non-terminated
  string views, local timezone transitions, and custom numeric locales.
- `chrono zoned compatibility` requires C++20 timezone support (e.g. GCC 13+).
  It compares output, duration results and exception messages against frozen
  originals, covering DST gaps/overlaps, midnight transitions, half-hour DST,
  a skipped calendar date, and unknown zones. IANA timezone data must be installed.

`ChronoUtilsLegacy.cpp` and `ChronoZonedLegacy.hpp` are intentionally frozen
regression oracles, not production implementations to keep synchronized.
The short-input tests do not call the old parser where it accessed past the
end of its input. Local time tests change `TZ` only inside their own process.

To exercise the C++20 tests and sanitizers with a suitable compiler:

```sh
CXX=g++-15 meson setup build-test -Dbuildtype=debugoptimized -Db_sanitize=address,undefined
meson test -C build-test --print-errorlogs
```
