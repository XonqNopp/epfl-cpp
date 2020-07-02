all: clr testcouleur4d

clr:
	clear

testcouleur4d: testcouleur4d.o couleur4d.o
	g++ -o $@ $^

testcouleur4d.o: testcouleur4d.cc couleur4d.h
	g++ -c -o $@ testcouleur4d.cc

couleur4d.o: couleur4d.cc couleur4d.h
	g++ -c -o $@ couleur4d.cc

clean:
	rm *.o testcouleur4d
