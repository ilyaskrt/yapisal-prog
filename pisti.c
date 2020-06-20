#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void puan(int oyuncu_el[56], int pc_el[56], int o_pisti[20], int pc_pisti[20]){
	int a,b,c,d,i=0;
	int o_skor=0;
	int p_skor=0;
	printf("puan hesaplaniyor");
	while(oyuncu_el[a]!=0){
		a=a+1;
	}
	while(i<a){
			switch (oyuncu_el[i]){
				case 1 : printf("\nOyuncunun Elindeki Kartlar Sinek %d",oyuncu_el[i+1]); break;
				case 2 : printf("\nOyuncunun Elindeki Kartlar Maca %d",oyuncu_el[i+1]); break;
				case 3 : printf("\nOyuncunun Elindeki Kartlar Karo %d",oyuncu_el[i+1]); break;
				case 4 : printf("\nOyuncunun Elindeki Kartlar Kupa %d",oyuncu_el[i+1]); break;
				default: break;
			}
		i=i+2;
	}
	while(pc_el[b]!=0){
		b=b+1;
	}i=0;
	while(i<b){
			switch (pc_el[i]){
				case 1 : printf("\nPc Elindeki Kartlar Sinek %d",pc_el[i+1]); break;
				case 2 : printf("\nPc Elindeki Kartlar Maca %d",pc_el[i+1]); break;
				case 3 : printf("\nPc Elindeki Kartlar Karo %d",pc_el[i+1]); break;
				case 4 : printf("\nPc Elindeki Kartlar Kupa %d",pc_el[i+1]); break;
				default: break;
			}
		i=i+2;
	}
	i=0;
	while(i<a){
		
		if(oyuncu_el[i]==2 && oyuncu_el[i+1]==2)    	//elindeki kartın Maca 2 olması durumunda 2 puan
			o_skor +=2;
		else if(oyuncu_el[i]==3 && oyuncu_el[i+1]==10)   //elindeki kartın Karo 10 olması durumunda 3 puan
			o_skor +=3;
		else if(oyuncu_el[i+1]==14) 					 //elindeki kartın As olması durumunda 1 puan
			o_skor +=1;
		else if(oyuncu_el[i+1]==11) 					//elindeki kartın Vale olması durumunda 1 puan
			o_skor +=1;
	i=i+2;
	}
	while(pc_el[b]!=0){
		b=b+1;
	}
	i=0;
	while(i<b){
		if(pc_el[i]==2 && pc_el[i+1]==2) 			//elindeki kartın Maca 2 olması durumunda 2 puan
			p_skor +=2;
		else if(pc_el[i]==3 && pc_el[i+1]==10)		    //elindeki kartın Karo 10 olması durumunda 3 puan
			p_skor +=3;
		else if(pc_el[i+1]==14) 						//elindeki kartın As olması durumunda 1 puan
			p_skor +=1;
		else if(pc_el[i+1]==11)							//elindeki kartın Vale olması durumunda 1 puan
			p_skor +=1;
	i=i+2;
	}
	
	if(o_pisti[0]!=0){
		while(o_pisti[c]!=0){
			c=c+1;
		}
		i=0;
		while(i<c){
			if(o_pisti[i+1]==11){ 						//pisti vale ile yapıldıysa 20 puan
				o_skor=o_skor+20;}
			else{
				o_skor=o_skor+10;}						//pisti normal yapıldı ise 10 puan
		i=i+2;
		}		
	}	
	if(pc_pisti[0]!=0){
		while(pc_pisti[d]!=0){
			d=d+1;
		}
		i=0;
		while(i<d){
			if(pc_pisti[i+1]==11){ 						//pisti vale ile yapıldıysa 20 puan
				p_skor=p_skor+20;}
			else{
				p_skor=p_skor+10;}						//pisti normal yapıldı ise 10 puan
		i=i+2;
		}	
	}
	if(a>b)
		o_skor +=3;
	if(a<b)
		p_skor +=3;
			
	if(o_skor>p_skor){
		printf("\n %d Puan ile OYUNCU kazandi.\n",o_skor);
		printf("\n %d Puan ile PC kaybetti.\n",p_skor);
	}
	else if(p_skor>o_skor){
		printf("\n %d Puan ile PC kazandi.\n",p_skor);
		printf("\n %d Puan ile OYUNCU kaybetti.\n",o_skor);
	}
	else{
		printf("\n %d BERABERE\n",o_skor);}
		
}
int main(int argc, char *argv[]) {
	int deste[52][2];
	int tur[4]={1,2,3,4};   /*1->sinek 2->maça 3->karo 4->kupa*/
	int no[13]={2,3,4,5,6,7,8,9,10,11,12,13,14};  /*11->vale 12->kız 13->papas 14->as*/
	int i,j,k,b,c,d,f=0;
	int l=0;
	int a=1;
	int e=4;
	int oyuncu[8];
	int pc[8];
	int orta[104]={0};
	int oyuncu_el[56]={0};
	int pc_el[56]={0};
	int o_pisti[20];
	int pc_pisti[20];
	int o_skor=0,p_skor=0;
	int son_kart[2];
	srand(time(NULL));
	deste_yap(tur,no,deste);
	kar(deste);
	printf("\n   *************************************************************************\n");
	printf("   **Oyuna hos geldiniz. Kartlar karistirildi dagitiliyor. Iyi oyunlar :) **\n");
	printf("   *************************************************************************\n");
	for (i=0;i<4;i=i+1){
		orta[f]=deste[i][0];
		orta[f+1]=deste[i][1];
		f=f+2;
		if(i==3){
			son_kart[0]=deste[i][0];
			son_kart[1]=deste[i][1];
			switch (son_kart[0]){
				case 1 : printf("\nYere acilan kartlar : \nKart 1 \nKart 2 \nKart 3 \nSinek %d \n",son_kart[1]); break;
				case 2 : printf("\nYere acilan kartlar : \nKart 1 \nKart 2 \nKart 3 \nMaca %d \n",son_kart[1]); break;
				case 3 : printf("\nYere acilan kartlar : \nKart 1 \nKart 2 \nKart 3 \nKaro %d \n",son_kart[1]); break;
				case 4 : printf("\nYere acilan kartlar : \nKart 1 \nKart 2 \nKart 3 \nKupa %d \n",son_kart[1]); break;
				default: break;
			}
		}
	}
	printf("\n********Bir el icerisinde ayni rakamlari girmeyiniz.********\n");
	for (i=4;i<52;i=i+8){
		//4 kart oyuncuya 4 kart pc ye dağıtıldığı için 8 arttırıldı.
		
		for (j=0;j<8;j=j+2){
			oyuncu[j]=deste[e][0];
			oyuncu[j+1]=deste[e][1];	//oyuncunun kartları atandı
			pc[j]=deste[e+1][0];
			pc[j+1]=deste[e+1][1];		//pc nin kartları atandı
			e=e+2;
    	
	    }
	    
	    for (k=0;k<4;k=k+1){
	    	a=1;
	    	for (l=0;l<8;l=l+2){ // oyuncunun elindeki kartlar yazdirilir ve hangisini atmak istediği sorulur.
				printf("\n%d ",a);
				a=a+1;
				switch (oyuncu[l]){
				case 1 : printf("Sinek %d",oyuncu[l+1]); break;
				case 2 : printf("Maca %d",oyuncu[l+1]); break;
				case 3 : printf("Karo %d",oyuncu[l+1]); break;
				case 4 : printf("Kupa %d",oyuncu[l+1]); break;
				default: break;
	    	}
			}
	    	
	    printf("\nAtmak istediginiz kart kacinci sirada?(1-4)\n");    scanf("%d",&b);
	    switch(b){
	    	case 1:if(oyuncu[1]==son_kart[1]){  
	    				if(orta[2]==0){			//eger yerde kart yoksa ve aynıysa pişti olur
	    					switch (oyuncu[0]){
								case 1 : printf("\nOyuncu Sinek %d ile pisti yapti\n",oyuncu[1]); break;
								case 2 : printf("\nOyuncu Maca %d ile pisti yapti\n",oyuncu[1]); break;
								case 3 : printf("\nOyuncu Karo %d ile pisti yapti\n",oyuncu[1]); break;
								case 4 : printf("\nOyuncu Kupa %d ile pisti yapti\n",oyuncu[1]); break;
								default: break;
	    					}
	    					c=0;
	    					while(o_pisti[c]!=0){
	    						c=c+1;
							}
							o_pisti[c]=oyuncu[0];
							o_pisti[c+1]=oyuncu[1];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c]=orta[d];
								oyuncu_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[0];
							oyuncu_el[c+1]=oyuncu[1];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
							
						}
					}
					if(oyuncu[1]==11){
							printf("\nOyuncu *Vale* atarak kartlari aldi.\n");
							c=0;
							while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c]=orta[d];
								oyuncu_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[0];
							oyuncu_el[c+1]=oyuncu[1];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
								
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=oyuncu[0];
							orta[d+1]=oyuncu[1];
							son_kart[0]=oyuncu[0];
							son_kart[1]=oyuncu[1];
							switch (oyuncu[0]){
								case 1 : printf("Oyuncu :Sinek %d atti\n",oyuncu[1]); break;
								case 2 : printf("Oyuncu :Maca %d atti\n",oyuncu[1]); break;
								case 3 : printf("Oyuncu :Karo %d atti\n",oyuncu[1]); break;
								case 4 : printf("Oyuncu :Kupa %d atti\n",oyuncu[1]); break;
							default: break;
	    					}
		
					}
					if(pc[1]==son_kart[1]){
	    				if(orta[2]==0){
	    					switch (pc[0]){
								case 1 : printf("\nPC Sinek %d ile pisti yapti\n",pc[1]); break;
								case 2 : printf("\nPC Maca %d ile pisti yapti\n",pc[1]); break;
								case 3 : printf("\nPC Karo %d ile pisti yapti\n",pc[1]); break;
								case 4 : printf("\nPC Kupa %d ile pisti yapti\n",pc[1]); break;
								default: break;
	    					}
	    					c=0;
	    					while(pc_pisti[c]!=0){
	    						c=c+1;
							}
							pc_pisti[c]=oyuncu[0];
							pc_pisti[c+1]=oyuncu[1];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[0];
							pc_el[c+1]=pc[1];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(pc[1]==11){
							printf("\nPC *Vale* atarak kartlari aldi.\n");
							c=0;
							while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[0];
							pc_el[c+1]=pc[1];
							son_kart[0]=0;
							son_kart[1]=0;	
							orta[d]=0;
							orta[d+1]=0;
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=pc[0];
							orta[d+1]=pc[1];
							son_kart[0]=pc[0];
							son_kart[1]=pc[1];
							switch (pc[0]){
								case 1 : printf("Pc :Sinek %d atti\n",pc[1]); break;
								case 2 : printf("Pc :Maca %d atti\n",pc[1]); break;
								case 3 : printf("Pc :Karo %d atti\n",pc[1]); break;
								case 4 : printf("Pc :Kupa %d atti\n",pc[1]); break;
							default: break;
	    					}
		
					}oyuncu[0]=0; oyuncu[1]=0;
					break;   
	    	case 2:if(oyuncu[3]==son_kart[1]){
						if(orta[2]==0){
	    					switch (oyuncu[2]){
								case 1 : printf("\nOyuncu Sinek %d ile pisti yapti\n",oyuncu[3]); break;
								case 2 : printf("\nOyuncu Maca %d ile pisti yapti\n",oyuncu[3]); break;
								case 3 : printf("\nOyuncu Karo %d ile pisti yapti\n",oyuncu[3]); break;
								case 4 : printf("\nOyuncu Kupa %d ile pisti yapti\n",oyuncu[3]); break;
								default: break;
	    					}
	    					c=0;
	    					while(o_pisti[c]!=0){
	    						c=c+1;
							}
							o_pisti[c]=oyuncu[2];
							o_pisti[c+1]=oyuncu[3];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c]=orta[d];
								oyuncu_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[2];
							oyuncu_el[c+1]=oyuncu[3];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(oyuncu[3]==11){
							printf("\nOyuncu *Vale* atarak kartlari aldi.\n");
							c=0;
							while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c]=orta[d];
								oyuncu_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[2];
							oyuncu_el[c+1]=oyuncu[3];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;	
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=oyuncu[2];
							orta[d+1]=oyuncu[3];
							son_kart[0]=oyuncu[2];
							son_kart[1]=oyuncu[3];
							switch (oyuncu[2]){
								case 1 : printf("Oyuncu :Sinek %d atti\n",oyuncu[3]); break;
								case 2 : printf("Oyuncu :Maca %d atti\n",oyuncu[3]); break;
								case 3 : printf("Oyuncu :Karo %d atti\n",oyuncu[3]); break;
								case 4 : printf("Oyuncu :Kupa %d atti\n",oyuncu[3]); break;
							default: break;
	    					}
					}if(pc[3]==son_kart[1]){
	    				if(orta[2]==0){
	    					switch (pc[0]){
								case 1 : printf("\nPC Sinek %d ile pisti yapti\n",pc[3]); break;
								case 2 : printf("\nPC Maca %d ile pisti yapti\n",pc[3]); break;
								case 3 : printf("\nPC Karo %d ile pisti yapti\n",pc[3]); break;
								case 4 : printf("\nPC Kupa %d ile pisti yapti\n",pc[3]); break;
								default: break;
	    					}
	    					c=0;
	    					while(pc_pisti[c]!=0){
	    						c=c+1;
							}
							pc_pisti[c]=oyuncu[0];
							pc_pisti[c+1]=oyuncu[1];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[2];
							pc_el[c+1]=pc[3];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(pc[3]==11){
							printf("\nPC *Vale* atarak kartlari aldi.\n");
							c=0;
							while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[2];
							pc_el[c+1]=pc[3];
							son_kart[0]=0;
							son_kart[1]=0;	
							orta[d]=0;
							orta[d+1]=0;
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=pc[2];
							orta[d+1]=pc[3];
							son_kart[0]=pc[2];
							son_kart[1]=pc[3];
							switch (pc[2]){
								case 1 : printf("Pc :Sinek %d atti\n",pc[3]); break;
								case 2 : printf("Pc :Maca %d atti\n",pc[3]); break;
								case 3 : printf("Pc :Karo %d atti\n",pc[3]); break;
								case 4 : printf("Pc :Kupa %d atti\n",pc[3]); break;
							default: break;
	    					}
		
					}oyuncu[2]=0; oyuncu[3]=0;
					break;   
	    	case 3:if(oyuncu[5]==son_kart[1]){
	    			if(orta[2]==0){
	    					switch (oyuncu[4]){
								case 1 : printf("\nOyuncu Sinek %d ile pisti yapti\n",oyuncu[5]); break;
								case 2 : printf("\nOyuncu Maca %d ile pisti yapti\n",oyuncu[5]); break;
								case 3 : printf("\nOyuncu Karo %d ile pisti yapti\n",oyuncu[5]); break;
								case 4 : printf("\nOyuncu Kupa %d ile pisti yapti\n",oyuncu[5]); break;
								default: break;
	    					}
	    					c=0;
	    					while(o_pisti[c]!=0){
	    						c=c+1;
							}
							o_pisti[c]=oyuncu[4];
							o_pisti[c+1]=oyuncu[5];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c+1]=orta[d];
								oyuncu_el[c+2]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[4];
							oyuncu_el[c+1]=oyuncu[5];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(oyuncu[5]==11){
							printf("\nOyuncu *Vale* atarak kartlari aldi.\n");
							c=0;
							while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c+1]=orta[d];
								oyuncu_el[c+2]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[4];
							oyuncu_el[c+1]=oyuncu[5];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;	
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=oyuncu[4];
							orta[d+1]=oyuncu[5];
							son_kart[0]=oyuncu[4];
							son_kart[1]=oyuncu[5];
							switch (oyuncu[4]){
								case 1 : printf("Oyuncu :Sinek %d atti\n",oyuncu[5]); break;
								case 2 : printf("Oyuncu :Maca %d atti\n",oyuncu[5]); break;
								case 3 : printf("Oyuncu :Karo %d atti\n",oyuncu[5]); break;
								case 4 : printf("Oyuncu :Kupa %d atti\n",oyuncu[5]); break;
							default: break;
	    					}
					}if(pc[5]==son_kart[1]){
	    				if(orta[2]==0){
	    					switch (pc[4]){
								case 1 : printf("\nPC Sinek %d ile pisti yapti\n",pc[5]); break;
								case 2 : printf("\nPC Maca %d ile pisti yapti\n",pc[5]); break;
								case 3 : printf("\nPC Karo %d ile pisti yapti\n",pc[5]); break;
								case 4 : printf("\nPC Kupa %d ile pisti yapti\n",pc[5]); break;
								default: break;
	    					}
	    					c=0;
	    					while(pc_pisti[c]!=0){
	    						c=c+1;
							}
							pc_pisti[c]=oyuncu[0];
							pc_pisti[c+1]=oyuncu[1];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[4];
							pc_el[c+1]=pc[5];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(pc[5]==11){
							printf("\nPC *Vale* atarak kartlari aldi.\n");
							c=0;
							while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[4];
							pc_el[c+1]=pc[5];
							son_kart[0]=0;
							son_kart[1]=0;	
							orta[d]=0;
							orta[d+1]=0;
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=pc[4];
							orta[d+1]=pc[5];
							son_kart[0]=pc[4];
							son_kart[1]=pc[5];
							switch (pc[4]){
								case 1 : printf("Pc :Sinek %d atti\n",pc[5]); break;
								case 2 : printf("Pc :Maca %d atti\n",pc[5]); break;
								case 3 : printf("Pc :Karo %d atti\n",pc[5]); break;
								case 4 : printf("Pc :Kupa %d atti\n",pc[5]); break;
							default: break;
	    					}
		
					}oyuncu[4]=0; oyuncu[5]=0;
					break;   
	    	case 4:if(oyuncu[7]==son_kart[1]){
	    			if(orta[2]==0){
	    					switch (oyuncu[6]){
								case 1 : printf("\nOyuncu Sinek %d ile pisti yapti\n",oyuncu[7]); break;
								case 2 : printf("\nOyuncu Maca %d ile pisti yapti\n",oyuncu[7]); break;
								case 3 : printf("\nOyuncu Karo %d ile pisti yapti\n",oyuncu[7]); break;
								case 4 : printf("\nOyuncu Kupa %d ile pisti yapti\n",oyuncu[7]); break;
								default: break;
	    					}
	    					c=0;
	    					while(o_pisti[c]!=0){
	    						c=c+1;
							}
							o_pisti[c]=oyuncu[6];
							o_pisti[c+1]=oyuncu[7];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
							
	    			    }else{
	    			    	c=0;
	    			    	while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c]=orta[d];
								oyuncu_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[6];
							oyuncu_el[c+1]=oyuncu[7];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(oyuncu[7]==11){
							printf("\nOyuncu *Vale* atarak kartlari aldi.\n");
							c=0;
							while(oyuncu_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								oyuncu_el[c]=orta[d];
								oyuncu_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							oyuncu_el[c]=oyuncu[6];
							oyuncu_el[c+1]=oyuncu[7];
							son_kart[0]=0;
							son_kart[1]=0;	
							orta[d]=0;
							orta[d+1]=0;
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=oyuncu[6];
							orta[d+1]=oyuncu[7];
							son_kart[0]=oyuncu[6];
							son_kart[1]=oyuncu[7];
							switch (oyuncu[6]){
								case 1 : printf("Oyuncu :Sinek %d atti\n",oyuncu[7]); break;
								case 2 : printf("Oyuncu :Maca %d atti\n",oyuncu[7]); break;
								case 3 : printf("Oyuncu :Karo %d atti\n",oyuncu[7]); break;
								case 4 : printf("Oyuncu :Kupa %d atti\n",oyuncu[7]); break;
							default: break;
	    					}
					}if(pc[7]==son_kart[1]){
	    				if(orta[2]==0){
	    					switch (pc[6]){
								case 1 : printf("\nPC Sinek %d ile pisti yapti\n",pc[7]); break;
								case 2 : printf("\nPC Maca %d ile pisti yapti\n",pc[7]); break;
								case 3 : printf("\nPC Karo %d ile pisti yapti\n",pc[7]); break;
								case 4 : printf("\nPC Kupa %d ile pisti yapti\n",pc[7]); break;
								default: break;
	    					}
	    					c=0;
	    					while(pc_pisti[c]!=0){
	    						c=c+1;
							}
							pc_pisti[c]=oyuncu[0];
							pc_pisti[c+1]=oyuncu[1];
							orta[0]=0;
							orta[1]=0;
							son_kart[0]=0;
							son_kart[1]=0;
	    			    }else{
	    			    	c=0;
	    			    	while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[6];
							pc_el[c+1]=pc[7];
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
						}
					}
					if(pc[7]==11){
							printf("\nPC *Vale* atarak kartlari aldi.\n");
							c=0;
							while(pc_el[c]!=0){
	    			    		c=c+1;
							}
							d=0;
							while(orta[d]!=0){
								pc_el[c]=orta[d];
								pc_el[c+1]=orta[d+1];
								orta[d]=0;
								orta[d+1]=0;
								c=c+2;
								d=d+2;
							}
							pc_el[c]=pc[6];
							pc_el[c+1]=pc[7];	
							son_kart[0]=0;
							son_kart[1]=0;
							orta[d]=0;
							orta[d+1]=0;
					}
					else{	
							d=0;
							while(orta[d]!=0){
								d=d+1;
							}
							orta[d]=pc[6];
							orta[d+1]=pc[7];
							son_kart[0]=pc[6];
							son_kart[1]=pc[7];
							switch (pc[6]){
								case 1 : printf("Pc :Sinek %d atti\n",pc[7]); break;
								case 2 : printf("Pc :Maca %d atti\n",pc[7]); break;
								case 3 : printf("Pc :Karo %d atti\n",pc[7]); break;
								case 4 : printf("Pc :Kupa %d atti\n",pc[7]); break;
							default: break;
	    					}
		
					}oyuncu[6]=0; oyuncu[7]=0;
					break;   
	    	
	    	default: printf("yanlis deger girdiniz..");   break;	  
			}
	
	
		a=1;
		c=0;
	    while(orta[c]!=0){
	    	switch (orta[c]){
				case 1 : printf("	Ortada : Sinek %d\n",orta[c+1]); break;
				case 2 : printf("	Ortada : Maca %d\n",orta[c+1]); break;
				case 3 : printf("	Ortada : Karo %d\n",orta[c+1]); break;
				case 4 : printf("	Ortada : Kupa %d\n",orta[c+1]); break;
				default: break;
	    		}
	    
	    	c=c+2;
		}
	 }
//	break;
   }
   	puan(oyuncu_el,pc_el,o_pisti,pc_pisti);
	return 0;

}
