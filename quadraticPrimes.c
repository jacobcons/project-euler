#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

int main() {
	int a = 0,
		b = 0,
		n = 0,
		maxN = 0,
		maxA = 0,
		maxB = 0;

	for (a = -1000; a < 1001; a++) {
		for (b = -1000; b < 1001; b++) {
			n = 0;
			while ( isPrime(pow(n,2) + a*n + b) ) {
				n++;
			}

			if (n > maxN) {
				maxN = n;
				maxA = a;
				maxB = b;
			}
		}
	}

	printf("product: %d", maxA*maxB);
	return 0;
}
