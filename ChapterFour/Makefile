tee: src/tee.c
	clang src/tee.c -o bin/tee
	./bin/tee -a data/appendfile.txt < data/appendinginput.txt 
	./bin/tee data/overwritefile.txt < data/input.txt 
	./bin/tee -a
	./bin/tee data/noExist.txt < data/input.txt
	echo "double hell" | bin/tee data/input.txt  
	make clean
clean:
	rm -f bin/tee
