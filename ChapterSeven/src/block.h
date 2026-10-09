#include <unistd.h>
#include <stddef.h>

typedef struct MemoryBlock{
	size_t size;
	MemoryBlock *next;
	unsigned char free;
}MemoryBlock


