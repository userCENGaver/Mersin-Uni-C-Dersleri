#include <stdio.h>

int main() {
    char tahta[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int satir, sutun, hamle_sayisi = 0;
    char sira = 'X';

    while (hamle_sayisi < 9) {

        printf("\n  0  1  2\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i);
            for (int j = 0; j < 3; j++) {
                printf("%c", tahta[i][j]);
                if (j < 2) printf("|");
            }
            if (i < 2) printf("\n  ----------\n");
        }

        printf("\n\nSira %c'de. Satir ve Sutun gir (ornek: 1 2): ", sira);
        scanf("%d %d", &satir, &sutun);

        if (satir < 0 || satir > 2 || sutun < 0 || sutun > 2 || tahta[satir][sutun] != ' ') {
            printf("Gecersiz hamle! Tekrar dene.\n");
            continue;
        }

        tahta[satir][sutun] = sira;
        hamle_sayisi++;

        for (int i = 0; i < 3; i++) {
            if ((tahta[i][0] == sira && tahta[i][1] == sira && tahta[i][2] == sira) ||
                (tahta[0][i] == sira && tahta[1][i] == sira && tahta[2][i] == sira)) {
                printf("\nTEBRIKLER! Oyuncu %c kazandi!\n", sira);
                return 0;
            }
        }

        if ((tahta[0][0] == sira && tahta[1][1] == sira && tahta[2][2] == sira) ||
            (tahta[0][2] == sira && tahta[1][1] == sira && tahta[2][0] == sira)) {
            printf("\nTEBRIKLER! Oyuncu %c kazandi!\n", sira);
            return 0;
        }

        sira = (sira == 'X') ? 'O' : 'X';
    }

    printf("\nBerabere bitti!\n");
    return 0;
}