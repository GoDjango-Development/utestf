#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <malloc.h>
#include <utestf.h>

#define SOMECHUNK 256

void reserv_memory(void **pmem)
{
	*pmem = malloc(SOMECHUNK);
}

int int_sum(int a, int b)
{
	return a + b;
}

double f_sum(double a, double b)
{
	return a + b;
}

int test_mem(void)
{
	void *mem = NULL;
	reserv_memory(&mem);
	if (!mem)
		return 1;
	else 
		return 0;
}

int test_math(void)
{
	if (int_sum(5, 5) != 10)
		return 1;
	if (f_sum(4.5, 4.5) != 9)
		return 1;
	return 0;
}

void run_tests(void)
{
	utestf_run(test_mem, 0, 1);
	utestf_run(test_math, 0, 2);
}

int main(void)
{
	utestf_chk();
	run_tests();
	return 0;
}
