#include <math.h>

int isPrime(int n) {
	int i = 0,
		root = sqrt(n) + 1;

	if (n <= 1) {
		return 0;
	}

	for (i = 2; i < root; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return n;
}
