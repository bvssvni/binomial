
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "binomial.h"

typedef binomial_bignum bignum;

func(binomial, Start);
func(binomial, Next);

void printBigNum(bignum it)
{
	printf("0x%llxULL, ", it);
	/*
	int j;
	for (j = 63; j >= 0; j--) {
		printf("%llu", (it >> j) & 0x1);
	}
	printf("\n");
	 */
	fflush(stdout);
}

void test_1(void)
{
	assert(Start(0) == 0x0ULL);
	assert(Start(1) == 0x1ULL);
	assert(Start(2) == 0x3ULL);
	
	bignum it = binomial_Start(4);
	assert(it == 0xfULL);	// 0000 1111
	Next(&it, 8, 4);
	assert(it == 0x17ULL);  // 0001 0111
	Next(&it, 8, 4);
	assert(it == 0x1bULL);  // 0001 1011
	Next(&it, 8, 4);
	assert(it == 0x1dULL);	// 0001 1101
	Next(&it, 8, 4);
	assert(it == 0x1eULL);  // 0001 1110
	Next(&it, 8, 4);
	assert(it == 0x27ULL);  // 0010 0111
}

int main(int argc, char *argv[])
{
	assert(sizeof(bignum) == 8);
	
	test_1();
	
	int m = 4;
	int n = 64;
	bignum it = Start(m);
	int count = 0;
	do  {
		// printBigNum(it);
		count++;
	} while (Next(&it, n, m));
	printf("count %i\n", count);
	 
	return 0;
}
