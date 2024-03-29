#include <chrono>
#include <stdio.h>
#include <stdlib.h>     /* malloc, calloc, realloc, free */
#include <string.h>

#define COUNT 1000*1000

void bench_malloc_func()
{
	for (size_t i = 0; i < COUNT; ++i)
	{
		int malloc_size = i * sizeof(int);
		int * pInt = (int*)malloc(malloc_size);
		free(pInt);
	}
}

void bench_malloc_and_access_func()
{
	for (size_t i = 0; i < COUNT; ++i)
	{
		int malloc_size = i * sizeof(int);
		int * pInt = (int*)malloc(malloc_size);

		memset(pInt, 0, malloc_size);
		free(pInt);
	}
}


int main()
{
  using namespace std::chrono;

  high_resolution_clock::time_point time_begin = high_resolution_clock::now();
  bench_malloc_func();
  high_resolution_clock::time_point time_end = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(time_end - time_begin);
  double time_span_avg = time_span.count() * 1000 / (COUNT);

  printf("bench malloc duration time: %lfs, avg: %lfms.\n", time_span.count(), time_span_avg);

  time_begin = high_resolution_clock::now();
  bench_malloc_and_access_func();
  time_end = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(time_end - time_begin);
  time_span_avg = time_span.count() * 1000 / (COUNT);

  printf("bench malloc and access duration time: %lfs, avg: %lfms.\n", time_span.count(), time_span_avg);

  return 0;
}

