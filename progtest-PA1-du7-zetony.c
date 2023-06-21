#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

typedef struct hraciplocha{
    int zprava[32];
    int zleva[32];
    int zhora[32];
    int zdola[32];
    int pocetzprava;
    int pocetzleva;
    int pocetzhora;
    int pocetzdola;

}hraciplocha;

int max(int a,int b,int c,int d){
    int navrat = a;
    if (b>navrat){
        navrat = b;
    }
    if (c>navrat){
        navrat = c;
    }
    if (d>navrat){
        navrat = d;
    }
    return navrat;
}

int min(int a,int b,int c,int d){
    int navrat = a;
    if (b<navrat){
        navrat = b;
    }
    if (c<navrat){
        navrat = c;
    }
    if (d<navrat){
        navrat = d;
    }
    return navrat;
}

int odehraj_tah(const hraciplocha hracipole,int aktualni_hrac){
    if((hracipole.pocetzdola+hracipole.pocetzhora+hracipole.pocetzleva+hracipole.pocetzprava==1)&&(aktualni_hrac==2)){
        if (hracipole.pocetzdola==1){
        return 0;
    }
    if (hracipole.pocetzhora==1){
        return 0;
    }
    if (hracipole.pocetzleva==1){
        return 0;
    }
    if (hracipole.pocetzprava==1){
        return 0;
    }
    }
if(hracipole.pocetzdola+hracipole.pocetzhora+hracipole.pocetzleva+hracipole.pocetzprava==1){
    if (hracipole.pocetzdola==1){
        return hracipole.zdola[0];
    }
    if (hracipole.pocetzhora==1){
        return hracipole.zhora[0];
    }
    if (hracipole.pocetzleva==1){
        return hracipole.zleva[0];
    }
    if (hracipole.pocetzprava==1){
        return hracipole.zprava[0];
    }
}

if (aktualni_hrac == 1){
    int max_hodnota = INT_MIN;
    int hodnoceni1 = INT_MIN;
    int hodnoceni2 = INT_MIN;
    int hodnoceni3 = INT_MIN;
    int hodnoceni4 = INT_MIN;
    if(hracipole.pocetzprava != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni1 = hracipole.zprava[hracipole.pocetzprava-1];
        tmphracipole.pocetzprava--;
        hodnoceni1 = hodnoceni1 + odehraj_tah(tmphracipole,2);
    }
    if(hracipole.pocetzleva != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni2 = hracipole.zleva[hracipole.pocetzleva-1];
        tmphracipole.pocetzleva--;
        hodnoceni2 = hodnoceni2 + odehraj_tah(tmphracipole,2);
    }
    if(hracipole.pocetzdola != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni3 = hracipole.zdola[hracipole.pocetzdola-1];
        tmphracipole.pocetzdola--;
        hodnoceni3 = hodnoceni3 + odehraj_tah(tmphracipole,2);
    }
    if(hracipole.pocetzhora != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni4 = hracipole.zhora[hracipole.pocetzhora-1];
        tmphracipole.pocetzhora--;
        hodnoceni4 = hodnoceni4 + odehraj_tah(tmphracipole,2);
    }

    max_hodnota = max(hodnoceni1,hodnoceni2,hodnoceni3,hodnoceni4);
    return max_hodnota;
}
else{
    int min_hodnota = INT_MAX;
    int hodnoceni1 = INT_MAX;
    int hodnoceni2 = INT_MAX;
    int hodnoceni3 = INT_MAX;
    int hodnoceni4 = INT_MAX;
    if(hracipole.pocetzprava != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni1 = hracipole.zprava[hracipole.pocetzprava-1]*0;
        tmphracipole.pocetzprava--;
        hodnoceni1 = hodnoceni1 + odehraj_tah(tmphracipole,1);
    }
    if(hracipole.pocetzleva != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni2 = hracipole.zleva[hracipole.pocetzleva-1]*0;
        tmphracipole.pocetzleva--;
        hodnoceni2 = hodnoceni2 + odehraj_tah(tmphracipole,1);
    }
    if(hracipole.pocetzdola != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni3 = hracipole.zdola[hracipole.pocetzdola-1]*0;
        tmphracipole.pocetzdola--;
        hodnoceni3 = hodnoceni3 + odehraj_tah(tmphracipole,1);
    }
    if(hracipole.pocetzhora != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni4 = hracipole.zhora[hracipole.pocetzhora-1]*0;
        tmphracipole.pocetzhora--;
        hodnoceni4 = hodnoceni4 + odehraj_tah(tmphracipole,1);
    }

    min_hodnota = min(hodnoceni1,hodnoceni2,hodnoceni3,hodnoceni4); 
    return min_hodnota;
}

}


char vyber_pole (hraciplocha hracipole,int aktualni_hrac){
    int hodnoceni1;    
    int hodnoceni2;
    int hodnoceni3;
    int hodnoceni4;
    if(hracipole.pocetzprava != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni1 = hracipole.zprava[hracipole.pocetzprava-1];
        tmphracipole.pocetzprava--;
        hodnoceni1 = hodnoceni1 + odehraj_tah(tmphracipole,2);
    }
    if(hracipole.pocetzleva != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni2 = hracipole.zleva[hracipole.pocetzleva-1];
        tmphracipole.pocetzleva--;
        hodnoceni2 = hodnoceni2 + odehraj_tah(tmphracipole,2);
    }
    if(hracipole.pocetzdola != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni3 = hracipole.zdola[hracipole.pocetzdola-1];
        tmphracipole.pocetzdola--;
        hodnoceni3 = hodnoceni3 + odehraj_tah(tmphracipole,2);
    }
    if(hracipole.pocetzhora != 0){
        hraciplocha tmphracipole = hracipole;
        hodnoceni4 = hracipole.zhora[hracipole.pocetzhora-1];
        tmphracipole.pocetzhora--;
        hodnoceni4 = hodnoceni4 + odehraj_tah(tmphracipole,2);
    }
    int minimum = min(hodnoceni1,hodnoceni2,hodnoceni3,hodnoceni4);
    if (minimum == hodnoceni1){return 'E';}
    if (minimum == hodnoceni2){return 'W';}
    if (minimum == hodnoceni3){return 'S';}
    if (minimum == hodnoceni4){return 'N';}

    return 'X';
}


int main(void){

    hraciplocha hracipole;

    /*hracipole.zprava[0] = 1;
    hracipole.zprava[1] = 1;
    hracipole.zprava[2] = 1;
    hracipole.zleva[0] = 5;
    hracipole.zhora[0] = 2;
    hracipole.zhora[1] = 1;
    hracipole.zdola[0] = 7;
    hracipole.zdola[1] = 1;
    hracipole.pocetzprava = 3;
    hracipole.pocetzleva = 1;
    hracipole.pocetzhora = 2;
    hracipole.pocetzdola = 2;  HRA 1 */


    hracipole.zprava[0] = 1;
    hracipole.zprava[1] = 1;
    hracipole.zprava[2] = 1;
    hracipole.zprava[3] = 9;
    hracipole.zleva[0] = 5;
    hracipole.zleva[1] = 3;
    hracipole.zhora[0] = 2;
    hracipole.zhora[1] = 1;
    hracipole.zdola[0] = 7;
    hracipole.zdola[1] = 1;
    hracipole.pocetzprava = 4;
    hracipole.pocetzleva = 2;
    hracipole.pocetzhora = 2;
    hracipole.pocetzdola = 2;    /*HRA 2*/ 
    


    /*hracipole.zprava[0] = 1;
    hracipole.zprava[1] = 1;
    hracipole.zprava[2] = 9;
    hracipole.zleva[0] = -2;
    hracipole.zleva[1] = 5;
    hracipole.zleva[2] = 3;
    hracipole.zhora[0] = -4;
    hracipole.zhora[1] = 2;
    hracipole.zhora[2] = 1;
    hracipole.zdola[0] = 7;
    hracipole.zdola[1] = 1;
    hracipole.pocetzprava = 3;
    hracipole.pocetzleva = 3;
    hracipole.pocetzhora = 3;
    hracipole.pocetzdola = 2; HRA 3*/


    /*hracipole.zprava[0] = 1;
    hracipole.zprava[1] = 1;
    hracipole.zprava[2] = 9;
    hracipole.zleva[0] = -2;
    hracipole.zleva[1] = 5;
    hracipole.zleva[2] = 3;
    hracipole.zhora[0] = 5;
    hracipole.zhora[1] = 1;
    hracipole.zhora[2] = -4;
    hracipole.zhora[3] = 2;
    hracipole.zhora[4] = 1;
    hracipole.zdola[0] = 7;
    hracipole.zdola[1] = 1;
    hracipole.pocetzprava = 3;
    hracipole.pocetzleva = 3;
    hracipole.pocetzhora = 5;
    hracipole.pocetzdola = 2; HRA 4 */

    /*hracipole.zprava[0] = 1;
    hracipole.zprava[1] = 1;
    hracipole.zprava[2] = 9;
    hracipole.zleva[0] = -2;
    hracipole.zleva[1] = 5;
    hracipole.zleva[2] = 3;
    hracipole.zhora[0] = -4;
    hracipole.zhora[1] = 2;
    hracipole.zhora[2] = 1;
    hracipole.zdola[0] = 1;
    hracipole.zdola[1] = 7;
    hracipole.pocetzprava = 3;
    hracipole.pocetzleva = 3;
    hracipole.pocetzhora = 3;
    hracipole.pocetzdola = 2; HRA 5 */

    /*hracipole.zprava[0] = 29;
    hracipole.zleva[0] = -61;
    hracipole.zleva[1] = 128;
    hracipole.zhora[0] = 181;
    hracipole.zhora[1] = 43;
    hracipole.zdola[0] = 75;
    hracipole.zdola[1] = -99;
    hracipole.zdola[2] = 118;
    hracipole.zdola[3] = -35;
    hracipole.pocetzprava = 1;
    hracipole.pocetzleva = 2;
    hracipole.pocetzhora = 2;
    hracipole.pocetzdola = 4; HRA 6 */


    /*hracipole.zprava[0] = 179;
    hracipole.zprava[1] = 88;
    hracipole.zleva[0] = 61;
    hracipole.zleva[1] = -77;
    hracipole.zhora[0] = -99;
    hracipole.zhora[1] = 14;
    hracipole.zdola[0] = 127;
    hracipole.zdola[1] = -93;
    hracipole.zdola[2] = -83;
    hracipole.zdola[3] = 114;
    hracipole.pocetzprava = 2;
    hracipole.pocetzleva = 2;
    hracipole.pocetzhora = 2;
    hracipole.pocetzdola = 4; HRA 7 */

    /*hracipole.zprava[0] = 77;
    hracipole.zprava[1] = 46;
    hracipole.zprava[2] = 146;
    hracipole.zprava[3] = 118;
    hracipole.zleva[0] = 78;
    hracipole.zhora[0] = 109;
    hracipole.zhora[1] = -52;
    hracipole.zhora[2] = -66;
    hracipole.zdola[0] = -13;
    hracipole.zdola[1] = 159;
    hracipole.zdola[2] = 67;
    hracipole.pocetzprava = 4;
    hracipole.pocetzleva = 1;
    hracipole.pocetzhora = 3;
    hracipole.pocetzdola = 3; HRA 8 */

    



    int vysledek = odehraj_tah(hracipole,1);
    int vysledek2 = odehraj_tah(hracipole,2);

    
    printf("prvni hrac :%d\n",vysledek);
    printf("druhy hrac :%d\n",vysledek2);
    /*printf("prvni odehrany tah: %c\n",vyber_pole(hracipole,1));
    hracipole.pocetzhora = hracipole.pocetzhora -1;//N
    printf("prvni odehrany tah: %c\n",vyber_pole(hracipole,2));
    hracipole.pocetzdola = hracipole.pocetzdola -1;//S
    printf("prvni odehrany tah: %c\n",vyber_pole(hracipole,1));
    hracipole.pocetzleva = hracipole.pocetzleva -1;//W
    printf("prvni odehrany tah: %c\n",vyber_pole(hracipole,2));
    hracipole.pocetzhora = hracipole.pocetzhora -1;//N
    printf("prvni odehrany tah: %c\n",vyber_pole(hracipole,1));
    hracipole.pocetzhora = hracipole.pocetzhora -1;
    printf("prvni odehrany tah: %c\n",vyber_pole(hracipole,2));*/
    
    return 0;
    
}