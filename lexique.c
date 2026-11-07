#include "lexique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Lexique *creer_lexique(char *chemin) {
    assert(chemin != NULL);
    
    FILE *f = fopen(chemin, "r");
    if (f == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // compter le nombre de mots
    int taille = 0;
    char buf[100];
    while (fgets(buf, 100, f) != NULL)
        taille++;

    rewind(f);

    Lexique *l = malloc(sizeof(Lexique));
    if (l == NULL) {
        perror("malloc Lexique");
        exit(EXIT_FAILURE);
    }

    l->taille = taille;
    l->mots = malloc(taille * sizeof(char *));  // ✅ sizeof(char*) pas sizeof(char)
    if (l->mots == NULL) {
        perror("malloc mots");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(buf, 100, f) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';  // enlever le \n
        l->mots[i] = malloc(strlen(buf) + 1);
        if (l->mots[i] == NULL) {
            perror("malloc mot");
            exit(EXIT_FAILURE);
        }
        strcpy(l->mots[i], buf);
        i++;
    }

    fclose(f);
    return l;
}

void liberer_lexique(Lexique *l) {
    assert(l != NULL);
    for (int i = 0; i < l->taille; i++)
        free(l->mots[i]);
    free(l->mots);
    free(l);
}

int rechercher(Lexique *l, char *mot) {
    assert(l != NULL && mot != NULL);

    int gauche = 0;
    int droite = l->taille - 1;

    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;
        int c = strcmp(l->mots[milieu], mot);

        if (c == 0) return 1;
        else if (c < 0) gauche = milieu + 1;
        else droite = milieu - 1;
    }

    return 0;
}