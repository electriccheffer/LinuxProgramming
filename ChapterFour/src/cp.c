int main(int argc, char* argv[]){

	if(argc < 3){
		printf("Inadequate paramaters, must include source and destination\n");
		return -1; 
	}
	char* source = argv[1]; 
	char* destination = argv[2]; 	
	
	return 0; 
}
