#include <stdio.h>

int main() {
    int ogrenci_sayisi;

    printf("Kac ogrenci girilecek: ");
    scanf("%d", &ogrenci_sayisi);

    float vizeler[ogrenci_sayisi];
    float finaller[ogrenci_sayisi];
    float ortalamalar[ogrenci_sayisi];
    float sinif_toplami = 0;

    for (int i = 0; i < ogrenci_sayisi; i++) {
        printf("\n%d. ogrenci vize notu: ", i + 1);
        scanf("%f", &vizeler[i]);
        printf("%d. ogrenci final notu: ", i + 1);
        scanf("%f", &finaller[i]);

        ortalamalar[i] = (vizeler[i] * 0.4) + (finaller[i] * 0.6);
        sinif_toplami += ortalamalar[i];
    }

    printf("\n--- SONUCLAR ---\n");
    printf("No\tVize\tFinal\tOrtalama\tDurum\n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < ogrenci_sayisi; i++) {
        printf("%d\t%.1f\t%.1f\t%.1f\t\t%s\n", 
               i + 1, vizeler[i], finaller[i], ortalamalar[i], 
               (ortalamalar[i] >= 50 ? "GECTI" : "KALDI"));
    }

    printf("--------------------------------------------\n");
    printf("Sinif Ortalamasi: %.2f\n", sinif_toplami / ogrenci_sayisi);

    return 0;
}
