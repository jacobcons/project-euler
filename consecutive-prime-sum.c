proj#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

// project-euler-problem-50
int main() {
	int i = 0,
		sum = 0,
		sumLim = 0,
		count = 0,
		max = 0,
		targetPrime = 0,
		start = 0,
		x = 0;

	// iterate over numbers below one-million
	for (i = 2; i < 1000000; i++) {

		if ( isPrime(i) ) {
			// iterate over different starting points for sum of consecutive primes
			for (start = 2, sumLim = (i/2) + 1; start < sumLim; start++) {

				count = 0;
				sum = 0;
				x = start;
				while (sum < i) {
						if ( isPrime(x) ) {
							sum += x;
							count++; // count holds number of primes summed
						}
						x++;
					}

				// if number of primes summed exceeds current maximum
				if (count > max && sum == i) {
					max = count;
					targetPrime = i;
					break;
				}

			}

		}

	}

	printf("%d", targetPrime);

	return 0;
}
