
#include <stdio.h>

#include "memset-test.h"

static __inline__ void erms(void *buf, size_t size)
{
	asm volatile ("cld\n"
			"xor %%eax, %%eax\n"
			"rep stosb\n"
		       : /* no output */
		       : "D"(buf), "c"(size)
		       : "eax"
			);
}

int main() {
	unsigned long long total = 0;

	for (int i = 0; i < REPEAT ; ++i) {

		void *buf = prepared_buffer(BUF_SIZE);

		unsigned long long start = rdtsc();

		if (buf) {
			erms(buf, BUF_SIZE);
		} else {
			printf("Error\n");
			return 1;
		}

		unsigned long long end = rdtsc();

		total += end - start;
	}

	printf("%llu / %d\n ~= %llu cycles to zero\n", total, REPEAT, total/REPEAT);
}

