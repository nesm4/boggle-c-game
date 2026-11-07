
# Jeu du Boggle - TP7



Implémentation en C du jeu Boggle. Le jeu valide les mots trouvés sur une grille aléatoire grâce à un dictionnaire.



## Fonctionnalités

- Génération aléatoire de la grille de lettres.

- Recherche et validation des mots via un algorithme de Backtracking.

- Chargement d'un dictionnaire texte (`Mots.txt`).

- Interface utilisateur textuelle en CLI.



## Architecture du projet

- `lexique.c` : Gestion du dictionnaire et recherches lexicales.

- `grille.c` : Génération et manipulation du plateau de jeu.

- `jeu.c` : Logique de validation et parcours des cases.

- `affichage.c` : Rendu du score et de la grille dans le terminal.



## Compilation et Exécution



### Compilation

```bash

gcc -Wall -Wextra -std=c99 *.c -o boggle

```



### Exécution

```bash

./boggle.exe

```

