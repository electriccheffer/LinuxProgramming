#include <unistd.h>
#include <stddef.h>
#include "../src/block.h"

static MemoryBlock *heap_start = NULL; 

void *malloc(size_t size){
	
	size_t header_size = sizeof(MemoryBlock);
	size_t increment = header_size + size; 
	if(heap_start == NULL){
		
		void *block_address = sbrk(increment);
		if(block_address == (void*)-1){
			return NULL; 
		}	 
		heap_start = (MemoryBlock *) block_address; 
		heap_start->size = size; 
		heap_start->next = NULL; 
		heap_start->free = 0; 
		
		void *start_address = (char *)block_address + header_size;
		 	
		return start_address; 
	}
	else{
		MemoryBlock *current_node = heap_start; 
		
		while(current_node->next != NULL){
			
			if(current_node->free && current_node->size >= size){
				current_node->free = 0; 
				void *start_address = (char *)current_node + header_size; 
				return start_address;
			}
			current_node = current_node->next;
		}
		if(current_node->free && current_node->size >= size){
				current_node->free = 0; 
				void *start_address = (char *)current_node + header_size; 
				return start_address;
		}
		void *block_address = sbrk(increment); 
		if(block_address == (void*)-1){
			return NULL;
		}
		MemoryBlock *new_block = (MemoryBlock *)block_address; 
		current_node->next = new_block; 
		new_block->size = size;
		new_block->next = NULL; 
		new_block->free = 0; 
		void *start_address = (char*)block_address + header_size; 	
		return start_address;  
	}
}

void free(void *ptr){
	
	if(heap_start == NULL || ptr == NULL){
		return;
	}

	size_t header_size = sizeof(MemoryBlock); 
	void  *block_address = (char *)ptr - header_size; 
		
	MemoryBlock *current_node = heap_start; 
	while(current_node->next != NULL){
		
		if(current_node == block_address){
			current_node->free = 1; 	
			return; 
		}
		current_node = current_node->next; 		
	}
	if(current_node == block_address){
		current_node->free = 1; 
		return; 
	}
	return; 	
}
