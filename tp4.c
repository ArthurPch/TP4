#include <stdio.h>
#include <string.h>

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
            if (grille[i][j] < 0) {
                printf("Erreur : Chiffre negatif a la colonne %d, ligne %d. Veuillez entrer un nombre positif.\n", j, i);
                erreur = 1; 
            } else if (grille[i][j] > n) {
                printf("Erreur : Chiffre trop grand a la colonne %d, ligne %d. Veuillez entrer un nombre inferieur ou egal a %d.\n", j, i, n);
                erreur = 1; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (grille[i][j] != 0 && grille[i][j] == grille[i][k]) {
                    printf("Erreur : Le chiffre %d est repete dans la ligne %d, colonne %d et colonne %d.\n", grille[i][j], i, j, k);
                    erreur = 1; 
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (grille[i][j] != 0 && grille[i][j] == grille[k][j]) {
                    printf("Erreur : Le chiffre %d est repete dans la colonne %d, ligne %d et ligne %d.\n", grille[i][j], j, i, k);
                    erreur = 1;
                }
            }
        }
    }

    return erreur; 
}

int remplirGrille(int grille[9][9], int n) {
    int colonne, ligne, chiffre;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            while (grille[i][j] == 0) {
                printf("Mettre le numero de la colonne (0 a %d), de la ligne (0 a %d) et le chiffre souhaite (1 a %d) : ", n-1, n-1, n);
                scanf("%d %d %d", &colonne, &ligne, &chiffre);

                if (colonne >= 0 && colonne < n && ligne >= 0 && ligne < n && chiffre >= 1 && chiffre <= n) {
                    grille[ligne][colonne] = chiffre;

                    if (verificationGrille(grille, n) == 0) {
                        afficher_grille(grille, n);
                    } else {
                        printf("La grille contient des erreurs. Veuillez corriger.\n");
                        grille[ligne][colonne] = 0;
                    }
                } else {
                    printf("Erreur : Colonne, ligne ou chiffre invalides. Veuillez reessayer.\n");
                }
            }
        }
    }
    return 0;    
}

int main() {
    int grille[9][9];  
    int n = 4;
    init_grille(grille,n);

    printf("Grille initiale :\n");
    afficher_grille(grille, n);

    remplirGrille(grille, n);
    printf("Grille modifiee :\n");
    afficher_grille(grille, n);

    return 0;
}
