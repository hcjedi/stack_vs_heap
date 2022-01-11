#include <stdlib.h>
#include "stack_vs_heap.h"

#define UNUSED(x) (void)(x)

static void
stack_alloc()
{
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  UNUSED(array);
}

static void
heap_alloc()
{
  int *array = malloc(sizeof(int) * 10);
  for (int i = 0; i <= 9; i++) {
    array[i] = i;
  }
}

void
stack_vs_heap(int x)
{
  if (x == 0) {
    stack_alloc();
  }

  if (x == 1) {
    heap_alloc();
  }
}