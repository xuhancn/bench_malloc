#include <chrono>
#include <stdio.h>

#define COUNT 1000*1000

void bench_func()
{
	for (size_t i = 0; i < COUNT; ++i)
	{
		int * pInt = (int*)malloc(i * sizeof(int));
		free(pInt);
	}
}

int main()
{
  using namespace std::chrono;

  high_resolution_clock::time_point time_begin = high_resolution_clock::now();

  bench_func();

  high_resolution_clock::time_point time_end = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(time_end - time_begin);

  printf_s("duration time: %lf.\n", time_span.count());

  return 0;
}