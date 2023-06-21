#include <stdio.h>
#include <cstdlib>
#include <math.h>
void stejna_stena(double a,double x1,double x2,double y1,double y2,double z1,double z2){
    double delkapotrubi= (abs(x1-x2)+abs(y1-y2)+abs(z1-z2));
    double delkahadice = sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2)+pow(abs(z1-z2),2));
    printf("Delka potrubi: %.0lf\n",trunc(delkapotrubi));
    printf("Delka hadice: %.6lf\n",delkahadice);
}
void steny_vedle_sebe(double a,double x1,double x2,double y1,double y2,double z1,double z2){
    double delkapotrubi= (abs(x1-x2)+abs(y1-y2)+abs(z1-z2));
    double delkahadice = sqrt(pow(abs(x1-x2)+abs(y1-y2),2)+pow(abs(z1-z2),2));
    if((abs(x1-x2==0))||(abs(y1-y2==0))||(abs(z1-z2==0))){
        delkahadice=delkapotrubi; 
        printf("Delka potrubi: %.0lf\n",trunc(delkapotrubi));
        printf("Delka hadice: %.6lf\n",delkahadice);
        return;
    }
    if((z1==0||z2==a||z1==a||z2==0)&&(y1==0||y1==a||y2==0||y2==a)){ 
        delkahadice= sqrt(pow(abs(y1-y2)+abs(z1-z2),2)+pow(abs(x1-x2),2));
    }
    if((z1==0||z2==a||z1==a||z2==0)&&(x1==0||x1==a||x2==0||x2==a)){
        delkahadice= sqrt(pow(abs(x1-x2)+abs(z1-z2),2)+pow(abs(y1-y2),2));
    }
    printf("Delka potrubi: %.0lf\n",trunc(delkapotrubi));
    printf("Delka hadice: %.6lf\n",delkahadice);

}
void steny_proti_sobe(double a,double souradnice11,double souradnice12,double souradnice21,double souradnice22){
    double trubky_1 = souradnice11+souradnice12+a+abs(souradnice21-souradnice22);
    double trubky_2 = 3*a-souradnice11-souradnice12+abs(souradnice21-souradnice22);
    double trubky_3 = 3*a -souradnice21-souradnice22+abs(souradnice11-souradnice12);
    double trubky_4 = souradnice21+souradnice22+a+abs(souradnice11-souradnice12);
    double hadice_1 = sqrt(pow(souradnice11+souradnice12+a,2)+pow(abs(souradnice21-souradnice22),2));
    double hadice_2 = sqrt(pow(3*a-souradnice11-souradnice12,2)+pow(abs(souradnice21-souradnice22),2));
    double hadice_3 = sqrt(pow(souradnice21+souradnice22+a,2)+pow(abs(souradnice11-souradnice12),2));
    double hadice_4 = sqrt(pow(3*a-souradnice21-souradnice22,2)+pow(abs(souradnice11-souradnice12),2));
    double delkapotrubi = 0;
    if (trubky_1>delkapotrubi){delkapotrubi=trubky_1;}
    if (trubky_2<delkapotrubi){delkapotrubi=trubky_2;}
    if (trubky_3<delkapotrubi){delkapotrubi=trubky_3;}
    if (trubky_4<delkapotrubi){delkapotrubi=trubky_4;}
    double delkahadice = 0;
    if (hadice_1>delkahadice){delkahadice=hadice_1;}
    if (hadice_2<delkahadice){delkahadice=hadice_2;}
    if (hadice_3<delkahadice){delkahadice=hadice_3;}
    if (hadice_4<delkahadice){delkahadice=hadice_4;}
    printf("Delka potrubi: %.0lf\n",trunc(delkapotrubi));
    printf("Delka hadice: %.6lf\n",delkahadice);
}
int main(void){
    double a;
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    printf("Rozmer mistnosti:\n");
    if ((scanf("%lf",&a)!=1)||(a<=0)){
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Bod #1:\n");
    if ((scanf("%lf %lf %lf",&x1,&y1,&z1)!=3)||((x1<0)||(y1<0)||(z1<0))){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if ((((x1!=0) && (x1!=a))&&((y1!=0)&&(y1!=a))&&((z1!=0)&&(z1!=a)))||(x1>a)||(y1>a)||(z1>a)){
        printf("Nespravny vstup.\n");
        return 0;
        }
    if (((x1!=0)&&(x1<20))||((y1!=0)&&(y1<20))||((z1!=0)&&(z1<20))||((x1!=a)&&(x1>a-20))||((y1!=a)&&(y1>a-20))||((z1!=a)&&(z1>a-20))){
        printf("Nespravny vstup.\n");
        return 0;
    }      
    printf("Bod #2:\n");
    if ((scanf("%lf %lf %lf",&x2,&y2,&z2)!=3)||((x1<0)||(y1<0)||(z1<0))){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if ((((x2!=0) && (x2!=a))&&((y2!=0)&&(y2!=a))&&((z2!=0)&&(z2!=a)))||(x2>a)||(y2>a)||(z2>a)){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if (((x2!=0)&&(x2<20))||((y2!=0)&&(y2<20))||((z2!=0)&&(z2<20))||((x2!=a)&&(x2>a-20))||((y2!=a)&&(y2>a-20))||((z2!=a)&&(z2>a-20))){
        printf("Nespravny vstup.\n");
        return 0;
    }
    if((((x1==0)&&(x2==0))||((x1==a)&&(x2==a))||((y1==0)&&(y2==0))||((y1==a)&&(y2==a))||((z1==0)&&(z2==0))||((z1==a)&&(z2==a)))){
        stejna_stena(a,x1,x2,y1,y2,z1,z2);
        return 0;
    }
    if ((((x1==0)&&(x2==a))||((x1==a)&&(x2==0)))){
        steny_proti_sobe(a,y1,y2,z1,z2);
        return 0;
    }
    if ((((y1==0)&&(y2==a))||((y1==a)&&(y2==0)))){
        steny_proti_sobe(a,x1,x2,z1,z2);
        return 0;
    }
    if ((((z1==0)&&(z2==a))||((z1==a)&&(z2==0)))){
        steny_proti_sobe(a,x1,x2,y1,y2);
        return 0;
    }
    else{
        steny_vedle_sebe(a,x1,x2,y1,y2,z1,z2);
        return 0;
    }
    
    return 0;
}