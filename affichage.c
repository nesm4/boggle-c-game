#include "affichage.h"

void initialiser_couleurs() {
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); 
    init_pair(2, COLOR_WHITE, COLOR_BLUE);    
    init_pair(3, COLOR_BLACK, COLOR_YELLOW); 
}

void afficher_grille(Grille *g, int ci, int cj) {
    assert(g != NULL);

    for (int i = 0; i < g->taille; i++) {
        for (int j = 0; j < g->taille; j++) {
            Case c = g->liste[i * g->taille + j];

            if (i == ci && j == cj)
                attron(COLOR_PAIR(3) | A_BOLD);
            else if (c.ordre != 0)
                attron(COLOR_PAIR(2) | A_BOLD);
            else
                attron(COLOR_PAIR(1));

            mvprintw(i * 3,     j * 5, "     ");
            mvprintw(i * 3 + 1, j * 5, "  %c  ", c.lettre);
            mvprintw(i * 3 + 2, j * 5, "     ");

            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
        }
    }

    mvprintw(g->taille * 3 + 1, 0, "Score : %d", 0);
    mvprintw(g->taille * 3 + 2, 0, "Tentatives restantes : %d", 4);

    refresh();
}

void afficher_score(int score, int tentatives) {
    attron(A_BOLD);
    mvprintw(14, 0, "Score            : %d  ", score);
    mvprintw(15, 0, "Tentatives restantes : %d  ", 4 - tentatives);
    attroff(A_BOLD);
    refresh();
}

void afficher_score_final(int score) {
    clear();
    attron(A_BOLD | COLOR_PAIR(2));
    mvprintw(0, 0, "  Partie terminee !  ");
    attroff(A_BOLD | COLOR_PAIR(2));
    mvprintw(2, 0, "Score final : %d", score);
    mvprintw(4, 0, "Appuyez sur une touche pour quitter...");
    refresh();
    getch();
}