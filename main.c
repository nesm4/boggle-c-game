#include "affichage.h"
#include "jeu.h"

int main() {
    initscr();
    initialiser_couleurs();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();

    Jeu j;
    initialiser_jeu(&j);
    jouer(&j);
    liberer_jeu(&j);

    endwin();
    return 0;
}