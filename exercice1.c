#include <stdio.h>
#include <string.h>

void init_grille(int grille[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}
int remplirGrille(int grille[9][9],int n){
    int colonne, ligne, chiffre;
    char reponse[3]="oui";
    while (strcmp(reponse, "non") != 0)
    {
        printf("Mettre le numero de la colonne , de la ligne et le chiffre souhaite(sachant que la ligne et la premiere colonne sont egales a 0 et la derniere ligne et la derniere colonne sont egales a 3) : ");
        scanf("%d %d %d", &colonne, &ligne, &chiffre);

        
        if (colonne >= 0 && colonne <= n && ligne >= 0 && ligne <= n && chiffre >= 1 && chiffre <= 9) {
            grille[ligne][colonne] = chiffre;  
        } else {
            printf("Colonne, ligne ou chiffre invalides. Veuillez reessayer.\n");
        }

        
        printf("Voulez-vous changer autre chose ? (oui/non) : ");
        scanf(" %s", reponse);
    }
    return 0;    
}


int main() {
    int grille[9][9];
    int n=4;
    init_grille(grille, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }

    remplirGrille(grille,n);
    printf("Grille modifiee :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }


    return 0;
}

