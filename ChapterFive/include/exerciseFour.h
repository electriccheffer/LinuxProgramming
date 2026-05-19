#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

int duplicateFileDescriptor(int oldFileDescriptor); 

int duplicateFileDescriptor(int oldFileDescriptor){
		
	int otherFileDescriptor = fcntl(oldFileDescriptor,
				       	F_DUPFD,0);	
	if(otherFileDescriptor == -1){
		return -1; 
	}	
		
	return otherFileDescriptor;
}
