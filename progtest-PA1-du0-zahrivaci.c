#include <stdio.h>
int main(void)
{
  int cislo;
  printf("ml' nob:\n");
  if (scanf("%d",&cislo)!=1){
    printf("luj\n");
    
  }
  else if ((cislo!=1)&&(cislo!=2)&&(cislo!=3)&&(cislo!=4)&&(cislo!=5)&&(cislo!=6)&&(cislo!=7)&&(cislo!=8)&&(cislo!=9))
  {
    printf("luj\n");
  }
  else
  {switch (cislo){
      case 1:
      printf("Qapla\'\n");
      printf("noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
      break;
      case 2:
      printf("Qapla\'\n");
      printf("bortaS bIr jablu'DI' reH QaQqu' nay'.\n");
      break;
      case 3:
      printf("Qapla\'\n");
      printf("Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
      break;
      case 4:
      printf("Qapla\'\n");  
      printf("bISeH'eghlaH'be'chugh latlh Dara'laH'be'.\n");
      break;
      case 5:
      printf("Qapla\'\n");  
      printf("qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
      break;
      case 6:
      printf("Qapla\'\n");  
      printf("Suvlu'taHvIS yapbe' HoS neH.\n");
      break;
      case 7:
      printf("Qapla\'\n");  
      printf("Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
      break;
      case 8:
      printf("Qapla\'\n");  
      printf("Heghlu'meH QaQ jajvam.\n");
      break;
      case 9:
      printf("Qapla\'\n");  
      printf("leghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
      break;
    }
    }
    
  return 0;
}