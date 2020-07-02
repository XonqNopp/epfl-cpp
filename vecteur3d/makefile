all: clr testvecteur3d

clr:
	clear

testvecteur3d: vecteur3d.o testvecteur3d.o
	g++ -o $@ $^

vecteur3d.o: vecteur3d.h vecteur3d.cc
	g++ -c -o $@ vecteur3d.cc

testvecteur3d.o: vecteur3d.h testvecteur3d.cc
	g++ -c -o $@ testvecteur3d.cc

clean:
	rm *.o testvecteur3d
