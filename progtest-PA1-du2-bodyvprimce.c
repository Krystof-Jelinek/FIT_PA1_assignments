#include <stdio.h>
#include <math.h>
int main(void){
    double a1,a2,b1,b2,c1,c2;
    double Epsilon;
    bool lezinaprimce = false;
    printf("Bod A:\n");
    if (scanf(" %lf %lf",&a1,&a2)!=2){
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Bod B:\n");
    if (scanf(" %lf %lf",&b1,&b2)!=2){
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Bod C:\n");
    if (scanf(" %lf %lf",&c1,&c2)!=2){
        printf("Nespravny vstup.\n");
        return 0;
    }

    if(((a1==b1)&&(a2==b2))||((a1==c1)&&(a2==c2))||((b1==c1)&&(b2==c2))||((abs(a1-b1)==0)&&(abs(a2-b2)==0))){
        printf("Nektere body splyvaji.\n");
        return 0;
    }
    double vektorAB[2]={a1-b1,a2-b2};
    double vektorAC[2]={a1-c1,a2-c2};
    // tohle je asi zbytecny --double vektorBC[2]={b1-c1,b2-c2};
    if (a1-b1==0){
        Epsilon = abs((a2-b2)-(a2-c2))/10000;
        double alpha = vektorAC[1]/vektorAB[1];
        if (abs(alpha*vektorAB[0]-vektorAC[0])<Epsilon){
            printf("Body lezi na jedne primce.\n");
            lezinaprimce = true;
        }
        else {
        printf("Body nelezi na jedne primce.\n");
        return 0;
        }
    }
    else{
        Epsilon = abs((a1-b1)-(a1-c1))/10000;
        double alpha = vektorAC[0]/vektorAB[0];
        if (abs(alpha*vektorAB[1]-vektorAC[1])<Epsilon){
            printf("Body lezi na jedne primce.\n");
            lezinaprimce = true;
        }
        else {
            printf("Body nelezi na jedne primce.\n");
            return 0;
        }
    }
    if (lezinaprimce==true){
        double vzdalenostAB=sqrt(pow(b1-a1,2)+pow(b2-a2,2));
        double vzdalenostAC=sqrt(pow(c1-a1,2)+pow(c2-a2,2));
        double vzdalenostBC=sqrt(pow(c1-b1,2)+pow(c2-b2,2));
        double nejvetsi = 0;
        if (vzdalenostAB>nejvetsi){nejvetsi=vzdalenostAB;}
        if (vzdalenostAC>nejvetsi){nejvetsi=vzdalenostAC;}
        if (vzdalenostBC>nejvetsi){nejvetsi=vzdalenostBC;}
        if (vzdalenostAB == nejvetsi){
            printf("Prostredni je bod C.\n");
            return 0;
        }
        if (vzdalenostAC == nejvetsi){
            printf("Prostredni je bod B.\n");
            return 0;
        }
        if (vzdalenostBC == nejvetsi){
            printf("Prostredni je bod A.\n");
            return 0;
        }   
    }
    return 0;
}