#include <stdio.h>
#include <stdlib.h>

//girilen iki sayinin harmonik ortalamasi

int main(int argc, char *argv[]) {
int sayi1,sayi2;
float harmort;
printf("sayi 1 i giriniz="); scanf("%d",&sayi1);
printf("sayi 2 i giriniz="); scanf("%d",&sayi2);
harmort= (2.0 *sayi1*sayi2)/(sayi1+sayi2);

printf("harmonik ortama = %.2f", harmort);

return 0;
}
