binDirectory = ./bin
includeDirectory = ./include
sourceDirectory = ./src
dataDirectory = ./data

exerciseTwoTarget = $(binDirectory)/exerciseTwo
exerciseTwoProgram = $(sourceDirectory)/exerciseTwo.c

exerciseFourTarget = $(binDirectory)/exerciseFour
exerciseFourProgram = $(sourceDirectory)/excerciseFour.c

clean:
	rm -f $(exerciseTwoTarget)
	rm -f $(exerciseFourTarget) 

ExerciseTwo: $(exerciseTwoTarget)
	$(exerciseTwoTarget)
	cat $(dataDirectory)/existing_file.txt 
	make clean

ExerciseFour: $(exerciseFourTarget)
	$(exerciseFourTarget)
	make clean

$(exerciseFourTarget): $(exerciseFourProgram)
	gcc $(exerciseFourProgram) -o $(exerciseFourTarget)

$(exerciseTwoTarget): $(exerciseTwoProgram)
	gcc $(exerciseTwoProgram) -o $(exerciseTwoTarget)	
