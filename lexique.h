#ifndef LEXIQUE_H
#define LEXIQUE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct Lexique {
    char **mots;
    int taille;
} Lexique;

Lexique *creer_lexique(char *chemin);

void liberer_lexique(Lexique *l);

int rechercher(Lexique *l, char *mot);

#endif