#include <stdio.h>

int main() {
    float vize, final, ortalama;

    printf("Vize notunu gir: ");
    scanf("%f", &vize);
    printf("Final notunu gir: ");
    scanf("%f", &final);

    ortalama = (vize * 0.4) + (final * 0.6);

    printf("\nOrtalamaniz: %.2f\n", ortalama);
    printf("Durum: ");

    if (ortalama >= 60) {
        printf("GECTI\n");
    } 
    else if (ortalama >= 50) {
        printf("SARTLI GECTI\n");
    } 
    else {
        printf("KALDI\n");
    }

    return 0;
}
