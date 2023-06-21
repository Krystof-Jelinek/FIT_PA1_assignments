#include <stdio.h>
#include <math.h>
int main(void){
    double cislo1,cislo2;
    char operand;
    char rovnitko;
    printf("Zadejte vzorec:\n");
    if (scanf("%lf %c %lf %c",&cislo1,&operand,&cislo2,&rovnitko)!=4){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if (rovnitko!='='){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if ((operand!=('+'))&&(operand!=('*'))&&(operand!=('/'))&&(operand!=('-'))){
        printf("Nespravny vstup.\n");
        return 0;
    } 
    if ((operand=='/')&&(cislo2==0)){
        printf("Nespravny vstup.\n");
        return 0;
    }
    double scitani = cislo1+cislo2;
    double odcitani = cislo1-cislo2;
    double nasobeni = cislo1*cislo2;
    double deleni = cislo1/cislo2;
    if (operand =='+'){
        printf("%g\n",scitani);//zaokrouhluje .0 je picovina//
        return 0;
    }
    if (operand =='-'){
        printf("%g\n",odcitani);
        return 0;
    }
    if (operand =='/'){
        printf("%.10g\n",trunc(deleni));
        return 0;
    }
    if (operand =='*'){
        printf("%g\n",nasobeni);
        return 0;
    }
    return 0;
}