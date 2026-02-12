#include <stdio.h>
int main (){
    int n;
    int adim = 0;
    printf("Bir sayi giriniz: ");
    scanf("%d", &n);
    while(n > 1) {
        printf("%d ", n);
        if(n%2==0){
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        adim++;
    }
    printf("1 \n");
    printf("Toplam adim: %d", adim);
    return 0;
}