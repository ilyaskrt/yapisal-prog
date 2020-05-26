#include <stdio.h>
#include <stdlib.h>
// vize %40 final %50 ve devamsızlık puanı %10 a göre geçme notu hesaplama

int main(int argc, char *argv[]) {
int vize, final, devam;
float ortalama;

	printf("arasinav puanini giriniz:");	scanf("%d",&vize);
	printf("final puanini giriniz   :");	scanf("%d",&final);
	printf("devam puanini giriniz   :");	scanf("%d",&devam);	
	printf("------------------------\n");
	ortalama= vize*0.4+ final*0.5+ devam*0.1;
	printf("Ortalama puaniniz %.2f :" , ortalama);
	if(ortalama>60)
		printf("\n tebrikler gectiniz");
	else
		printf("\n üzgünüz.");
	return 0;
}
