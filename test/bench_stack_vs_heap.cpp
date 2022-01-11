#include <benchmark/benchmark.h>

extern "C" {
#include "stack_vs_heap.h"
}

static void BM_StackVsHeap(benchmark::State &state) {
  for (auto _ : state) {
    stack_vs_heap(state.range(0));
  }
}

BENCHMARK(BM_StackVsHeap)->Arg(0)->Arg(1);
BENCHMARK_MAIN();