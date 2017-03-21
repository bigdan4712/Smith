program: program.o SmithCounter.o Stats.o
	g++ program.o SmithCounter.o Stats.o -o program

test1: test.o SmithCounter.o Stats.o
	g++ test.o SmithCounter.o Stats.o -o test1

test.o: testSmithCounter.cpp
	g++ -c testSmithCounter.cpp -o test.o

program.o: program.cpp
	g++ -c program.cpp

SmithCounter.o: SmithCounter.cpp SmithCounter.h
	g++ -c SmithCounter.cpp

Stats.o: Stats.cpp Stats.h
	g++ -c Stats.cpp

clean:
	rm *.o program test1
