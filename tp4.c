#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_grille(int grille[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}

void afficher_grille(int grille[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grille[i][j] == 0) {
                printf("   ");
            } else {
                printf(" %d ", grille[i][j]);
            }
            if (j < n - 1) {
                printf("|");
            }
        }
        printf("\n");

        if (i < n - 1) {
            for (int k = 0; k < n; k++) {
                printf("----");
            }
            printf("\n");
        }
    }
}

int verificationGrille(int grille[9][9], int n) {
    int erreur = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (grille[i][j] != 0 && grille[i][j] == grille[i][k]) {
                    return 1; 
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (grille[i][j] != 0 && grille[i][j] == grille[k][j]) {
                    return 1;
                }
            }
        }
    }

    return erreur; 
}

void generer_grille_aleatoire(int grille[9][9], int n, int niveau) {
    int cases_a_remplir;

    if (niveau == 1) {
        cases_a_remplir = (n * n) / 2; 
    } else if (niveau == 2) {
        cases_a_remplir = (n * n) / 3;
    } else {
        cases_a_remplir = (n * n) / 4; 
    }

    srand(time(NULL)); 

    while (cases_a_remplir > 0) {
        int ligne = rand() % n;
        int colonne = rand() % n;
        int chiffre = (rand() % n) + 1;

        if (grille[ligne][colonne] == 0) {
            grille[ligne][colonne] = chiffre;

            if (verificationGrille(grille, n) == 0) {
                cases_a_remplir--;
            } else {
                grille[ligne][colonne] = 0; 
            }
        }
    }
}

int main() {
    int grille1[9][9];
    int grille2[9][9];
    int grille3[9][9];
    int n = 4;

    init_grille(grille1, n);
    init_grille(grille2, n);
    init_grille(grille3, n);

    printf("Grille avec moitie des cases remplies (niveau 1) :\n");
    generer_grille_aleatoire(grille1, n, 1);
    afficher_grille(grille1, n);

    printf("\nGrille avec un tiers des cases remplies (niveau 2) :\n");
    generer_grille_aleatoire(grille2, n, 2);
    afficher_grille(grille2, n);

    printf("\nGrille avec un quart des cases remplies (niveau 3) :\n");
    generer_grille_aleatoire(grille3, n, 3);
    afficher_grille(grille3, n);

    return 0;
}
