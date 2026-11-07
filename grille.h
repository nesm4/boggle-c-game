#ifndef GRILLE_H
#define GRILLE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct Case {
    char lettre;
    int ordre;
} Case;

typedef struct Grille {
    Case * liste;
    int taille;
} Grille;

Grille * creer_grille(int taille);

void generer_grille(Grille * g);

void liberer_grille(Grille * g);

int est_valide(Grille * g, int i, int j);

int sont_voisines(int i1, int j1, int i2, int j2);

void valider_case(Grille * g, int i, int j, int ordre);

void reinitialiser_selection(Grille * g);

void mot_depuis_selection(Grille * g, char * buffer);

#endif