#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
	
	bool append = false;  		
	char opt;
	printf("%d\n",argc); 
	while((opt = getopt(argc,argv,"a:")) != -1){
		switch(opt){
		
			case 'a': 
				append = true;
				if(argc == 2){
					return -1; 
				} 	
				break; 
			case '?':
				printf("%c",opt);
				printf("Invalid Option\n");
				return -1; 
		}
	}
	
	char *fileName = argv[argc-1];
	char *buffer = malloc(256);
	int bufferSize = sizeof(buffer); 
	
	if(append){
		int writeFile = open(fileName,O_WRONLY|O_APPEND);	
		if(writeFile == -1){
			fprintf(stderr,"open %s failed %s \n",fileName,strerror(errno)); 
			return -1; 
		}
		while(read(0,buffer,bufferSize) > 0){
			
			
			int offset = lseek(writeFile,10,SEEK_CUR);	
			if(offset == -1){
				fprintf(stderr,
					"lseek to %s failed %s \n",
					fileName,strerror(errno));
				return -1;
			}
			
			int numberBytesWritten = write(writeFile,buffer,bufferSize);
			if(numberBytesWritten ==  -1){
				fprintf(stderr,
					"write to %s failed %s \n",
					fileName,strerror(errno));
				return -1; 	
			}
		}
		
		int status = close(writeFile);
		if(status == -1){
			fprintf(stderr,"Error closeing %s: %s ",fileName,strerror(errno));
		}		
	}
	else{
		int writeFile = open(fileName,O_WRONLY);	
		if(writeFile == -1){
			fprintf(stderr,"open %s failed %s \n",fileName,strerror(errno)); 
			return -1; 
		}
		
		while(read(0,buffer,bufferSize) > 0){
			
			int numberBytesWritten = write(writeFile,buffer,bufferSize);
			if(numberBytesWritten ==  -1){
				fprintf(stderr,
					"write to %s failed %s \n",
					fileName,strerror(errno));
				return -1; 	
			}
		}
		int status = close(writeFile);
		if(status == -1){
			fprintf(stderr,"Error closeing %s: %s ",fileName,strerror(errno));
		}
	}
	
	return 0; 
}
