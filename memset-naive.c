
#include <stdio.h>
#include <string.h>

#include "memset-test.h"

int main() {
	unsigned long long total = 0;

	for (int i = 0; i < REPEAT ; ++i) {

		void *buf = prepared_buffer(BUF_SIZE);

		unsigned long long start = rdtsc();

		if (buf) {
			memset(buf, 0, BUF_SIZE);
		} else {
			printf("Error\n");
			return 1;
		}

		unsigned long long end = rdtsc();

		total += end - start;
	}

	printf("%llu / %d\n ~= %llu cycles to zero\n", total, REPEAT, total/REPEAT);
}
