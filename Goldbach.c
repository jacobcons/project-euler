#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);
int expressable(int n);



int main() {
	int odd = 7,
        expressed = 1;

	while (expressed) {
        odd += 2;
        if (!isPrime(odd)) {
            expressed = expressable(odd);
        }


	}


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
		minSum = n - 2,
		difference = 0;

		for (i = 2; i <= minSum; i++) {
                if (isPrime(i)) {
                    difference = n - isPrime(i);
                    difference /= 2;

                    // if the difference is a square
                    if (sqrt(difference) == floor(sqrt(difference))) {
                        return 1;
                    }
                }
			}

		return 0;
	}
