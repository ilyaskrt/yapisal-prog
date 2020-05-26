#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
//yüksekligi ve capi girilen koni taban alani ve hacim hesabi 
 
 int yukseklik,cap,yaricap;
  float pi=3.1419;
  float hacim,tabanAlani;
  printf("yuksekligi giriniz (cm) : "); scanf("%d",&yukseklik);
  printf("capi giriniz (cm) : "); scanf("%d",&cap);
  printf("Girdi degerleri yükseklik %d ve cap %d", yukseklik,cap);
  yaricap=cap/2;
  tabanAlani=pi*(yaricap*yaricap);
  hacim= (1.0/3)*yukseklik*tabanAlani ;
  
  printf("\n Dairesel koninin hami : %.2f cm kuptur" , hacim);  

	return 0;
}
