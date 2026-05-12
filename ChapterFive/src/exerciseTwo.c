#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
const char *DATA_PATH = "./data/existing_file.txt";

int main(){
	int fileDescriptor = open(DATA_PATH,O_APPEND|O_WRONLY);	
	if(fileDescriptor == -1){
		
		fprintf(stderr,"Failed to open: %s\n",strerror(errno));		
		exit(EXIT_FAILURE);
	}
	off_t startingPosition = lseek(fileDescriptor,0,SEEK_CUR);
	printf("Starting cursor location: %jd\n",startingPosition);
	off_t newOffset = lseek(fileDescriptor,0,SEEK_SET);
	if(newOffset == -1){
		fprintf(stderr,"Failed changing cursor: %s\n",
						strerror(errno));
		exit(EXIT_FAILURE);	
	}
	printf("Current cursor location is: %jd\n",newOffset);
	char *newtext = "new_file_data"; 
	ssize_t bytesWritten = write(fileDescriptor,newtext,strlen(newtext));
	
	if(bytesWritten == -1){
		
		fprintf(stderr,"Failed wrting to file: %s\n",
						strerror(errno));
		exit(EXIT_FAILURE);	
	}
	
	int success = close(fileDescriptor);
	if(success == -1){

		fprintf(stderr,"Failed closing file: %s\n",
						strerror(errno));
		exit(EXIT_FAILURE);
	}	
	exit(EXIT_SUCCESS);
}
