#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct letadlo{
    double x;
    double y;
    char nazevletadla[200];
}letadlo;

typedef struct dvojice{
    char prvniletadlo[200];
    char druheletadlo[200];
}dvojice;

double vzdalenost_bodu(letadlo jedna,letadlo dva){
    return sqrt( (jedna.x - dva.x)*(jedna.x - dva.x) + (jedna.y - dva.y)*(jedna.y - dva.y)); 
}

double brute_force(letadlo vsechny_letadla[],int pocetletadel){
    double min_vzdalenost = 1.7*pow(10,300);
    for (int i = 0; i < pocetletadel; ++i){
        for (int j = i+1; j < pocetletadel; ++j){
            if (vzdalenost_bodu(vsechny_letadla[i], vsechny_letadla[j]) < min_vzdalenost){
                min_vzdalenost = vzdalenost_bodu(vsechny_letadla[i], vsechny_letadla[j]);
            } 
        } 
            
    }
    return min_vzdalenost; 
}


int main(void){
    letadlo* vsechny_letadla=(letadlo*)malloc(10*sizeof(letadlo));
    int pocetletadel = 0;
    int pocetdvojic =0;
    double min_vzdalenost;

    printf("Pozice letadel:\n");


    //scenovani vstupu ale ve funkci to nejde lol
    letadlo tmpletadlo;
    int n = 0;
    int kontrola=0;
    int flag=0;
    int kapacita = 10;
    while (1){
    kontrola =scanf("%lf,%lf: %s",&tmpletadlo.x,&tmpletadlo.y,tmpletadlo.nazevletadla);
    if (pocetletadel == kapacita-1){
        kapacita = 1.6* kapacita;
        vsechny_letadla = (letadlo*)realloc(vsechny_letadla,kapacita*sizeof(letadlo));
    }
    if (kontrola ==3){
        vsechny_letadla[n]=tmpletadlo;
        n++;
        pocetletadel=pocetletadel+1;
    }
    if (kontrola<3&&kontrola>=0){
        printf("Nespravny vstup.\n");
        free(vsechny_letadla);
        return 0;
        

    }
    if ((kontrola<0)&&(flag<2)){
        printf("Nespravny vstup.\n");
        free(vsechny_letadla);
        return 0;
    }
    if (kontrola<0){
        break;
    }
    flag++;
    }


    min_vzdalenost = brute_force(vsechny_letadla,pocetletadel);

    dvojice* dvojice_letadel = (dvojice*)malloc(10*sizeof(dvojice));


    dvojice tmpdvojice;
    int misto_pro_dvojice= 10;

    int b=0;
    for (int i = 0; i < pocetletadel; ++i){
        for (int j = i+1; j < pocetletadel; ++j){
            if(pocetdvojic==misto_pro_dvojice-1){
                misto_pro_dvojice= misto_pro_dvojice *1.6;
                dvojice_letadel = (dvojice*)realloc(dvojice_letadel,(misto_pro_dvojice+5)*sizeof(dvojice));
            }
            if (abs(vzdalenost_bodu(vsechny_letadla[i], vsechny_letadla[j])-min_vzdalenost)<=vzdalenost_bodu(vsechny_letadla[i], vsechny_letadla[j])/10000000){
                
                strcpy(tmpdvojice.prvniletadlo, vsechny_letadla[i].nazevletadla);
                strcpy(tmpdvojice.druheletadlo, vsechny_letadla[j].nazevletadla);


                dvojice_letadel[b]= tmpdvojice;
                b++;
                pocetdvojic=pocetdvojic+1;
            } 
        } 
            
    }



    printf("Vzdalenost nejblizsich letadel: %lf\n",min_vzdalenost);
    printf("Nalezenych dvojic: %d\n",pocetdvojic);
    
    for (int n =0;pocetdvojic>n;n++){
    printf("%s - %s\n",dvojice_letadel[n].prvniletadlo,dvojice_letadel[n].druheletadlo);
    }    
    free(dvojice_letadel);
    free(vsechny_letadla);
    return 0;
}   