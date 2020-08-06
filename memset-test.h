#ifndef _MEMSET_TEST_H_
#define _MEMSET_TEST_H_

#include <unistd.h>

#define BUF_SIZE (1<<21)
#define REPEAT (1000)

// mmap and prefault aligned `size` byte region, and return a pointer to it.
// null if error.
void *prepared_buffer(size_t size);

static __inline__ unsigned long long rdtsc(void)
{
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

#endif 
