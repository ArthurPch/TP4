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
    int choix=0, niveau;

    while (choix != 6) {
        printf("\nMenu :\n");
        printf("1. Choisir la taille de la grille\n");
        printf("2. Initialiser la grille\n");
        printf("3. Generer la grille aleatoirement\n");
        printf("4. Resoudre la grille manuellement\n");
        printf("5. Afficher la grille\n");
        printf("6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:                
                printf("Entrez la taille de la grille (4 ou 9) : ");
                scanf("%d", &n);
                if (n != 4 && n != 9) {
                    printf("Taille invalide. Veuillez choisir 4 ou 9.\n");
                    n = 9; 
                }
                init_grille(grille, n);
                printf("Grille de taille %dx%d choisie.\n", n, n);
                break;

            case 2:               
                init_grille(grille, n);
                printf("Grille initialisee.\n");
                break;

            case 3:                
                printf("Choisissez le niveau de generation (1=moitie, 2=tiers, 3=quart) : ");
                scanf("%d", &niveau);
                if (niveau < 1 || niveau > 3) {
                    printf("Niveau invalide. Choix par defaut : niveau 1.\n");
                    niveau = 1;
                }
                generer_grille_aleatoire(grille, n, niveau);
                printf("Grille generee aleatoirement avec le niveau %d.\n", niveau);
                afficher_grille(grille, n);
                break;

            case 4:                
                remplirGrille(grille, n);
                afficher_grille(grille, n);
                break;

            case 5:
                afficher_grille(grille, n);
                break;

            case 6:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Option invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}