CC = gcc
CFLAGS = -std=c17 -pedantic -Wall
LDLIBS = -lncurses -lm

boggle: main.o affichage.o grille.o jeu.o lexique.o
	$(CC) -o boggle main.o affichage.o grille.o jeu.o lexique.o $(LDLIBS)

main.o: main.c jeu.h affichage.h
	$(CC) $(CFLAGS) -c main.c -o main.o

affichage.o: affichage.c affichage.h grille.h
	$(CC) $(CFLAGS) -c affichage.c -o affichage.o

grille.o: grille.c grille.h
	$(CC) $(CFLAGS) -c grille.c -o grille.o

jeu.o: jeu.c jeu.h grille.h lexique.h affichage.h
	$(CC) $(CFLAGS) -c jeu.c -o jeu.o

lexique.o: lexique.c lexique.h
	$(CC) $(CFLAGS) -c lexique.c -o lexique.o

clean:
	rm -f *.o boggle

.PHONY: clean