#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <ncurses.h>

#include "grille.h"

void initialiser_couleurs();

void afficher_grille(Grille *g, int ci, int cj);

void afficher_score(int score, int tentatives);

void afficher_score_final(int score);

#endif