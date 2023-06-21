#include <stdio.h>
void ohraniceni(int pocetpoli,int velikostpole)
{
    printf("+");
    for (int i=0;pocetpoli*velikostpole>i;i++){
    printf("-");
    }
    printf("+\n");
}
void prvniradek(int pocetpoli,int velikostpole)
    {
    for (int m=0;velikostpole>m;m++){
        printf("|");
        for (int t=0;pocetpoli>t;){
            for (int i=0;velikostpole>i;i++){
                printf(" ");
                }
            t++;
            if (pocetpoli==t){break;}    
            for (int i=0;velikostpole>i;i++){
                printf("X");
                }
            t++;    
            }
        printf("|\n");    
    }
    }
void druhyradek(int pocetpoli,int velikostpole){
        for (int m=0;velikostpole>m;m++){
        printf("|");
        for (int t=0;pocetpoli>t;){
            for (int i=0;velikostpole>i;i++){
                printf("X");
                }
            t++;
            if (pocetpoli==t){break;}    
            for (int i=0;velikostpole>i;i++){
                printf(" ");
                }
            t++;    
            }
        printf("|\n");
        }
        }        
int main(void){
    int pocetpoli=0;
    int velikostpole=0;
    printf("Zadejte pocet poli:\n");
    if (scanf("%d",&pocetpoli)!=1){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if (pocetpoli<=0){
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Zadejte velikost pole:\n");
    if (scanf("%d",&velikostpole)!=1){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if (velikostpole<=0){
        printf("Nespravny vstup.\n");
        return 0;
    }
    ohraniceni(pocetpoli,velikostpole);
    for (int x=0;pocetpoli>x;){
    prvniradek(pocetpoli,velikostpole);
    x++;
    if (x==pocetpoli){break;}
    druhyradek(pocetpoli,velikostpole);
    x++;
    }
    ohraniceni(pocetpoli,velikostpole);
    return 0;
}