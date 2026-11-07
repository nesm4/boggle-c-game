#include "grille.h"

Grille *creer_grille(int taille) {
    assert(taille > 0);  

    Grille *g = malloc(sizeof(Grille)); 
    if (g == NULL) {
        perror("malloc Grille");
        exit(EXIT_FAILURE);
    }

    g->taille = taille;

    g->liste = malloc(taille * taille * sizeof(*g->liste));
    if (g->liste == NULL) {
        perror("malloc liste");
        free(g);
        exit(EXIT_FAILURE);
    }

    return g;
}

void liberer_grille(Grille * g) {
     if (!g) return;
     free(g -> liste);
     free(g);
}

void reinitialiser_selection(Grille *g) {
    for (int i = 0; i < g->taille * g->taille; i++)
        g->liste[i].ordre = 0;
}

int est_valide(Grille *g, int i, int j) {
    return i >= 0 && i < g->taille && j >= 0 && j < g->taille;
}

int sont_voisines(int i1, int j1, int i2, int j2) {
    return abs(i1 - i2) <= 1 && abs(j1 - j2) <= 1 && (i1 != i2 || j1 != j2);
}

void generer_grille(Grille *g) {
    assert(g != NULL);
    srand(time(NULL));

    char lettres[] = "ETAIOSNRHDLCMUBFGPWYJ KQVXZ";
    int cumulees[] = {11, 19, 26, 33, 40, 47, 54, 60, 65, 69, 73, 76, 79, 82, 84, 86, 88, 90, 92, 94, 95, 96, 97, 98, 99, 100};

    for (int i = 0; i < g->taille * g->taille; i++) {
        int r = rand() % 100;
        int k = 0;
        while (r >= cumulees[k]) k++;
        g->liste[i].lettre = lettres[k];
        g->liste[i].ordre = 0;
    }
}

void valider_case(Grille *g, int i, int j, int ordre) {
    assert(est_valide(g, i, j));
    g->liste[i * g->taille + j].ordre = ordre;
}

void mot_depuis_selection(Grille *g, char *buffer) {
    int n = g->taille * g->taille;
    Case *cases[n];
    int nb = 0;
    for (int i = 0; i < n; i++)
        if (g->liste[i].ordre != 0)
            cases[nb++] = &g->liste[i];
    for (int i = 0; i < nb - 1; i++)
        for (int j = 0; j < nb - 1 - i; j++)
            if (cases[j]->ordre > cases[j+1]->ordre) {
                Case *tmp = cases[j];
                cases[j] = cases[j+1];
                cases[j+1] = tmp;
            }
    for (int i = 0; i < nb; i++)
        buffer[i] = cases[i]->lettre;
    buffer[nb] = '\0';
}