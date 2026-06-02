#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

int duplicateFileDescriptor(int oldFileDescriptor); 

int duplicateFileDescriptorTwo(int oldFileDescriptor, int newFileDescriptor);
