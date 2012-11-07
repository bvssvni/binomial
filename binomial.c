
#include "binomial.h"

typedef binomial_bignum bignum;

bignum binomial_Start(int a)
{
	return a == 0 ? 0ULL : ~0ULL >> (64-a);
}

int binomial_Next(bignum *it, int n, int m)
{
	int i;
	int count = 0;
	int val;
	int end = n - 1;
	for (i = 0; i < end; i++) {
		val = (*it >> i) & 0x3;
		if (val == 2) count = i+1;
		if (val != 1) continue;
		
		// Remove old bits.
		*it &= ~binomial_Start(i+1);
		
		// Put in new bits.
		*it |= binomial_Start(i-count);
		
		*it |= 1ULL << (i+1);
		
		return 1;
	}
	
	return 0;
}
