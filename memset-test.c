#include <stdio.h>
#include <sys/mman.h>

#include "memset-test.h"

void *prepared_buffer(size_t size) {
	void *buf = mmap(NULL, size, PROT_WRITE | PROT_READ, 
			MAP_ANONYMOUS | MAP_PRIVATE | MAP_POPULATE, -1, 0);

	if (buf == MAP_FAILED) {
		printf("Map failed \n");	
		return NULL;
	}

	return buf;
}
