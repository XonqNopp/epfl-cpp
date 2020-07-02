system = $(shell (uname | cut -b 1-6))

ifeq ($(system),Darwin)
 glutdflags =
 glutdlibs = -framework OpenGL -framework GLUT
else
 glutdflags = -L/usr/X11R6/lib/
 glutdlibs = -lglut -lGLU -lGL -lXmu -lXi
endif

LINK.GLUT = g++ $(glutdflags) $(glutdlibs)




all: clr testparseur

clr:
	clear

testparseur: parseur.o dessinable.o GUI.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o couleur4d.o erreurs.o testparseur.o
	$(LINK.GLUT) -o $@ $^

testparseur.o: parseur.h testparseur.cc
	g++ -c -o $@ testparseur.cc

parseur.o: parseur.h parseur.cc
	g++ -c -o $@ parseur.cc

erreurs.o: ../erreurs/erreurs.h ../erreurs/erreurs.cc
	g++ -c -o $@ ../erreurs/erreurs.cc

dessinable.o: ../dessinable/dessinable.cc ../dessinable/dessinable.h ../univers/univers.h
	g++ -c -o $@ ../dessinable/dessinable.cc

GUI.o: ../GUI/GUI.cc ../GUI/GUI.h ../dessinable/dessinable.h ../univers/univers.h
	g++ -c -o $@ ../GUI/GUI.cc

camera.o: ../camera/camera.cc ../camera/camera.h
	g++ -c -o $@ ../camera/camera.cc

vecteur3d.o: ../vecteur3d/vecteur3d.h ../vecteur3d/vecteur3d.cc
	g++ -c -o $@ ../vecteur3d/vecteur3d.cc

univers.o: ../univers/univers.h ../univers/univers.cc
	g++ -c -o $@ ../univers/univers.cc

corps.o: ../corps/corps.h ../corps/corps.cc
	g++ -c -o $@ ../corps/corps.cc

etoile.o: ../corps/corps.h ../corps/etoile.h ../corps/etoile.cc
	g++ -c -o $@ ../corps/etoile.cc

planete.o: ../corps/corps.h ../corps/planete.h ../corps/planete.cc
	g++ -c -o $@ ../corps/planete.cc

satellite.o: ../corps/corps.h ../corps/satellite.h ../corps/satellite.cc
	g++ -c -o $@ ../corps/satellite.cc

couleur4d.o: ../couleur4d/couleur4d.h ../couleur4d/couleur4d.cc
	g++ -c -o $@ ../couleur4d/couleur4d.cc

clean:
	rm *.o testparseur
