binDirectory = ./bin
includeDirectory = ./include
sourceDirectory = ./src
dataDirectory = ./data

exerciseTwoTarget = $(binDirectory)/exerciseTwo
exerciseTwoProgram = $(sourceDirectory)/exerciseTwo.c

clean:
	rm -f $(exerciseTwoTarget)
	
ExerciseTwo: $(exerciseTwoTarget)
	$(exerciseTwoTarget)
	cat $(dataDirectory)/existing_file.txt 
	make clean

$(exerciseTwoTarget): $(exerciseTwoProgram)
	gcc $(exerciseTwoProgram) -o $(exerciseTwoTarget)	
