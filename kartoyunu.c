#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#
void deste_yap(int x[4], int y[13],int deste[][2]){
	int i,j;
	int a=0;
	for ( i=0;i<4;i++){
		for( j=0;j<13;j++){
		deste[a][0]=x[i];
		deste[a][1]=y[j];
		a=a+1;
		}
	}	
}
void kar(int deste[][2]){
	int i,j;
	int gecici[1][2];
	for (i=0;i<52;i++){
		j=rand() % 52;
		gecici[0][0]=deste[i][0];
		gecici[0][1]=deste[i][1];
		deste[i][0]=deste[j][0];
		deste[i][1]=deste[j][1];
		deste[j][0]=gecici[0][0];
		deste[j][1]=gecici[0][1];
	}
		
}
int main(int argc, char *argv[]) {
	int deste[52][2];
	int tur[4]={1,2,3,4};   /*1->sinek 2->maça 3->karo 4->kupa*/
	int no[13]={2,3,4,5,6,7,8,9,10,11,12,13,14};  /*11->vale 12->kız 13->papas 14->as*/
	int i,j,k,a,b,c=0;
	char d[1];
	char e[1]={"e"};
	int oyuncu1[8];
	int oyuncu2[8];
	int bir_oyun_skor=0,iki_oyun_skor=0;
	int el_sayisi=0;
	srand(time(NULL));
	deste_yap(tur,no,deste);
	kar(deste);

	while(d[0]!=e[0]){
	for(i=0;i<10;i++){	
		printf("\n \n------------%d . El ------------\n \n", i+1);
		for (j=0;j<8;j=j+2){
			a=rand()%52;
			b=rand()%52;
			oyuncu1[j]=deste[a][0];
			oyuncu1[j+1]=deste[a][1];
			oyuncu2[j]=deste[b][0];
			oyuncu2[j+1]=deste[b][1];
			switch (oyuncu1[j]){
				case 1 : printf("1. Oyunun Actigi Kart: Sinek %d \n",oyuncu1[j+1]); break;
				case 2 : printf("1. Oyunun Actigi Kart: Maca %d \n",oyuncu1[j+1]); break;
				case 3 : printf("1. Oyunun Actigi Kart: Karo %d \n",oyuncu1[j+1]); break;
				case 4 : printf("1. Oyunun Actigi Kart: Kupa %d \n",oyuncu1[j+1]); break;
				default: break;
			}
			switch (oyuncu2[j]){
				case 1 : printf("2. Oyunun Actigi Kart: Sinek %d \n",oyuncu2[j+1]); break;
				case 2 : printf("2. Oyunun Actigi Kart: Maca %d \n",oyuncu2[j+1]); break;
				case 3 : printf("2. Oyunun Actigi Kart: Karo %d \n",oyuncu2[j+1]); break;
				case 4 : printf("2. Oyunun Actigi Kart: Kupa %d \n",oyuncu2[j+1]); break;
				default: break;
			}
			
			if (oyuncu1[j]!=oyuncu2[j]){
				if(oyuncu1[j]>oyuncu2[j])
					bir_oyun_skor++;
				else if (oyuncu1[j]<oyuncu2[j])
					iki_oyun_skor++;
				else 
					continue;
			}else{
				if(oyuncu1[j+1]>oyuncu2[j+1])
					bir_oyun_skor++;
				else if (oyuncu1[j+1]<oyuncu2[j+1])
					iki_oyun_skor;
				else
					continue;
			}
				
		}
		printf("1. Oyuncunun Elindeki kartlar :");
		for(k=0;k<8;k=k+2){
			switch (oyuncu1[k]){
				case 1 : printf("Sinek %d ",oyuncu1[k+1]); break;
				case 2 : printf("Maca %d ",oyuncu1[k+1]); break;
				case 3 : printf("Karo %d ",oyuncu1[k+1]); break;
				case 4 : printf("Kupa %d ",oyuncu1[k+1]); break;
			}
		}
		printf("\n2. Oyuncunun Elindeki kartlar :");
		for(k=0;k<8;k=k+2){
			switch (oyuncu2[k]){
				case 1 : printf("Sinek %d ",oyuncu2[k+1]); break;
				case 2 : printf("Maca %d ",oyuncu2[k+1]); break;
				case 3 : printf("Karo %d ",oyuncu2[k+1]); break;
				case 4 : printf("Kupa %d ",oyuncu2[k+1]); break;
			}
		}
	
	kar(deste);
	}
	
	
	if(bir_oyun_skor>iki_oyun_skor){
	printf("\n \nKAZANAN  = *OYUNCU1* Toplam puan: %d \n",bir_oyun_skor);
	printf("KAYBEDEN = *OYUNCU2* Toplam puan: %d \n",iki_oyun_skor);
	
	}
	else if(bir_oyun_skor<iki_oyun_skor){
	printf("\n \nKAZANAN  = *OYUNCU2* Toplam puan: %d \n",iki_oyun_skor);
	printf("KAYBEDEN = *OYUNCU1* Toplam puan: %d \n",bir_oyun_skor);
	}
	else{
	printf("\nOyuncularin Puanlari esittir: %d \n",bir_oyun_skor);	
	}
	bir_oyun_skor=0;
	iki_oyun_skor=0;
	
	printf("Cikmak icin e ye basiniz. ");
	gets(d);
	}
	return 0;
}
