#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);
int expressable(int n);



int main() {
	int odd = 7, // project euler gives the first example of 9
        expressed = 1;

	while (expressed) {
        odd += 2;

		// if the odd is composite
        if (!isPrime(odd)) {
            expressed = expressable(odd); //if not expressable returns 0
        }
	} // terminates if not expressable


	printf("n: %d", odd);

	return 0;
}

int isPrime(int n) {
	int i = 0,
		root = sqrt(n);

	// loop upto sqrt as factors come in pairs
	for (i = 2; i <= root; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return n;
}

int expressable(int n) {
	int i = 0,
		minSum = n - 2, // n = p + 2*square => i loops up to n-2 as the smallest square number is 1
		difference = 0;

		for (i = 2; i <= minSum; i++) {
                if (isPrime(i)) {

					// difference represents the 2*square part of the expresion => divide by 2
                    difference = n - isPrime(i);
                    difference /= 2;

                    // if the difference is a square
                    if (sqrt(difference) == floor(sqrt(difference))) {
                        return 1; // n is expressable in Goldbach form
                    }
                }
			}

		return 0; // n isn't expressable in Goldbach form
	}
