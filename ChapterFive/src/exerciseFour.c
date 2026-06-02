#include <stdlib.h>
#include "../include/exerciseFour.h"

int main(int argc,char *argv[]){
	
	return	EXIT_SUCCESS; 

}


int duplicateFileDescriptor(int oldFileDescriptor){
		
	int otherFileDescriptor = fcntl(oldFileDescriptor,
				       	F_DUPFD,0);	
	if(otherFileDescriptor == -1){
		return -1; 
	}	
		
	return otherFileDescriptor;
}

int duplicateFileDescriptorTwo(int oldFileDescriptor,int newFileDescriptor){
	//check if oldfd is invalid
	// check if newfd is < 0 
	
	//check if newfd == oldfd
	
	//check if newfd open
		//close newfd 
		//fcntl
	// newfd too large
	
}
