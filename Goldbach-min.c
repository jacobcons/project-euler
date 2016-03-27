#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

int main() {
	int odd = 7,
		i = 0;
	short unsigned int expressable = 1;

	while ( expressable ) {
		expressable = 0;
        odd += 2;

        if ( !isPrime(odd) ) {
			int minSum = odd - 2;
			for (i = 2; i <= minSum; i++) {
					if ( isPrime(i) ) {
						int difference = (odd - i) / 2;
						if ( sqrt(difference) == (int)sqrt(difference) ) {
							expressable = 1;
						}
					}
				}
        } else {
			expressable = 1;
		}
	}

	printf("n: %d", odd);
	return 0;
}
