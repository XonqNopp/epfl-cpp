all: clr testerreurs

clr:
	clear

testerreurs: erreurs.o testerreurs.o
	g++ -o $@ $^

erreurs.o: erreurs.h erreurs.cc
	g++ -c -o $@ erreurs.cc

testerreurs.o: erreurs.h testerreurs.cc
	g++ -c -o $@ testerreurs.cc

clean:
	rm *.o testerreurs

