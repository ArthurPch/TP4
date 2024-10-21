#include <stdio.h>

void init_grille(int grille[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}


int main() {
    int grille[9][9];
    int n=6;
    init_grille(grille, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }

    return 0;
}
