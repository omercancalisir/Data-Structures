hepsi:	derle	calistir

derle:

	g++ -I ./include/ -o ./lib/FileRead.o    		-c ./src/FileRead.cpp	
	g++ -I ./include/ -o ./lib/Node.o    -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Iterator.o    		-c ./src/Iterator.cpp
	g++ -I ./include/ -o ./lib/DoubleLinkedList.o    	-c ./src/DoubleLinkedList.cpp
	g++ -I ./include/ -o ./lib/TestProgram.o    		-c ./src/TestProgram.cpp
	g++ ./lib/FileRead.o ./lib/Node.o ./lib/Iterator.o ./lib/DoubleLinkedList.o ./lib/TestProgram.o -o ./bin/program
	
calistir:
	./bin/program