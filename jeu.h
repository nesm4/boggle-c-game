#ifndef JEU_H
#define JEU_H

#include "grille.h"
#include "lexique.h"
#include "affichage.h"

#include <ncurses.h>
#include <math.h>
#include <ctype.h>


typedef struct Jeu {
    Grille *grille;
    Lexique *lexique;
    int score;
    int tentatives;
} Jeu;

void initialiser_jeu(Jeu *j);

void liberer_jeu(Jeu *j);

int calculer_score(char *mot);

void jouer(Jeu *j);

#endif