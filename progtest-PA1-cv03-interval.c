#include <stdio.h>
int main(){
    int h,h2;
    int m,m2;
    int s,s2;
    int ms,ms2;
    printf("Zadejte cas t1:\n");
    if ((scanf(" %d : %d : %d , %d",&h,&m,&s,&ms)!=4)||(h>23)||(m>59)||(s>59)||(ms>999)||(h<0)||(m<0)||(s<0)||(ms<0)){
        printf("Nespravny vstup.\n");
    }
    else{
        printf("Zadejte cas t2:\n");    
        if ((scanf(" %d : %d : %d , %d",&h2,&m2,&s2,&ms2)!=4)||(h2>23)||(m2>59)||(s2>59)||(ms2>999)||(h<0)||(m<0)||(s<0)||(ms<0))
        {
            printf("Nespravny vstup.\n");
        }
        else{
        int oldms=ms;
        int oldms2=ms2;
        int pocet_cislic_ms=0;
        int pocet_cislic_ms2=0;
        while (oldms%10!=0){
            oldms=oldms/10;
            pocet_cislic_ms=pocet_cislic_ms+1;
        }
        while (oldms2%10!=0){
            oldms2=oldms2/10;
            pocet_cislic_ms2=pocet_cislic_ms2+1;
        }
        if (pocet_cislic_ms==1) {ms=ms*100;}
        if (pocet_cislic_ms==2) {ms=ms*10;} 
        if (pocet_cislic_ms2==1) {ms2=ms2*100;} 
        if (pocet_cislic_ms2==2) {ms2=ms2*10;}      
        int cas1 = h*60*60*1000+m*60*1000+s*1000+ms;
        int cas2 = h2*60*60*1000+m2*60*1000+s2*1000+ms2;
        int vysledna_doba = cas2-cas1;
        int h3=vysledna_doba/3600000;
        int m3=(vysledna_doba%3600000)/60000;
        int s3=((vysledna_doba%3600000)%60000)/1000;
        int ms3=(((vysledna_doba%3600000)%60000)%1000);
            if(cas1>cas2){
                printf("Nespravny vstup.\n");
            }
            else{
        printf("Doba: %2d:%02d:%02d,%03d\n",h3,m3,s3,ms3);
            }
        }
        }    
    
    return 0;
    }





    