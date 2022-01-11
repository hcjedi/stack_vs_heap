.POSIX:
.SUFFIXES:
CC      = gcc
CFLAGS  = -std=c99 -Wall -Iinclude

all:
	@echo Please choose a target: benchmark_test clean

benchmark_test: obj/stack_vs_heap.o obj/bench_stack_vs_heap.o
	g++ -o $@ \
		obj/stack_vs_heap.o obj/bench_stack_vs_heap.o -lbenchmark -lpthread

clean:
	rm -f obj/* benchmark_test

obj/stack_vs_heap.o: src/stack_vs_heap.c include/stack_vs_heap.h
	$(CC) -c $(CFLAGS) -o $@ src/stack_vs_heap.c

obj/bench_stack_vs_heap.o: test/bench_stack_vs_heap.cpp include/stack_vs_heap.h
	g++ -Iinclude -Wall --std=c++11 -c -o $@ test/bench_stack_vs_heap.cpp