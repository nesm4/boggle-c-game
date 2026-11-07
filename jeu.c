#include "jeu.h"
/* typedef struct Jeu {
    Grille *grille;
    Lexique *lexique;
    int score;
    int tentatives;
} Jeu; */


void initialiser_jeu(Jeu *j) {
    assert(j != NULL);
    
    j->grille = creer_grille(4);
    generer_grille(j->grille);
    
    j->lexique = creer_lexique("Mots.txt");
    
    j->score = 0;
    j->tentatives = 0;
}


void liberer_jeu(Jeu *j) {
    assert(j != NULL);

    liberer_grille(j -> grille);
    liberer_lexique(j -> lexique);
}

int calculer_score(char *mot) {
    assert(mot != NULL);
    int len = strlen(mot);
    if (len < 3)
        return 0;
    return pow(2, len-3);
}

void jouer(Jeu *j) {
    assert(j != NULL);
    
    int curseur_i = 0, curseur_j = 0;
    int compteur = 1;
    
    while (j->tentatives < 4) {
        afficher_grille(j->grille, curseur_i, curseur_j);
        afficher_score(j->score, j->tentatives);
        
        int touche = getch();
        
        switch (touche) {
            case KEY_UP:
                if (est_valide(j->grille, curseur_i - 1, curseur_j))
                    curseur_i--;
                break;
            case KEY_DOWN:
                if (est_valide(j->grille, curseur_i + 1, curseur_j))
                    curseur_i++;
                break;
            case KEY_LEFT:
                if (est_valide(j->grille, curseur_i, curseur_j - 1))
                    curseur_j--;
                break;
            case KEY_RIGHT:
                if (est_valide(j->grille, curseur_i, curseur_j + 1))
                    curseur_j++;
                break;
            
            case ' ':
                if (j->grille->liste[curseur_i * j->grille->taille + curseur_j].ordre == 0)
                    valider_case(j->grille, curseur_i, curseur_j, compteur++);
                break;
            
            case 'a':
                reinitialiser_selection(j->grille);
                compteur = 1;
                break;
            
            case '\n': {
                char m[j->grille->taille * j->grille->taille + 1];
                mot_depuis_selection(j->grille, m);
                
                // convertir en minuscules D'ABORD
                for (int k = 0; m[k]; k++)
                    m[k] = tolower(m[k]);
                
                // debug
                mvprintw(18, 0, "mot: '%s' | trouve: %d | score: %d    ", 
                        m, rechercher(j->lexique, m), j->score);
                refresh();
                getch();
                
                if (rechercher(j->lexique, m)) {
                    j->score += calculer_score(m);
                } else {
                    j->tentatives++;
                }
                reinitialiser_selection(j->grille);
                compteur = 1;
                break;
            }
                    }
    }
    
    afficher_score_final(j->score);
}