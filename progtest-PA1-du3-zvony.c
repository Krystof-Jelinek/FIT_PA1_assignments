#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

void cas1stejnycas2(int h1,int i1,int h2,int i2,long long int *b1,long long int *b2){ 
    switch (i1){
        case 0: *b1=*b1+4;break;
        case 15: *b1=*b1+1;break;
        case 30: *b1=*b1+2;break;
        case 45: *b1=*b1+3;break;
    }
    if (i1==0){
            switch (h1){
                case 0: *b2=*b2+12;break;
                case 1: *b2=*b2+1;break;
                case 2: *b2=*b2+2;break;
                case 3: *b2=*b2+3;break;
                case 4: *b2=*b2+4;break;
                case 5: *b2=*b2+5;break;
                case 6: *b2=*b2+6;break;
                case 7: *b2=*b2+7;break;
                case 8: *b2=*b2+8;break;
                case 9: *b2=*b2+9;break;
                case 10: *b2=*b2+10;break;
                case 11: *b2=*b2+11;break;
                case 12: *b2=*b2+12;break;
                case 13: *b2=*b2+1;break;
                case 14: *b2=*b2+2;break;
                case 15: *b2=*b2+3;break;
                case 16: *b2=*b2+4;break;
                case 17: *b2=*b2+5;break;
                case 18: *b2=*b2+6;break;
                case 19: *b2=*b2+7;break;
                case 20: *b2=*b2+8;break;
                case 21: *b2=*b2+9;break;
                case 22: *b2=*b2+10;break;
                case 23: *b2=*b2+11;break;
            }  

        }
}

void cas1mensicas2(int h1,int i1,int h2,int i2,long long int *b1,long long int *b2){
    int tmp=0;
    if ((h1==23)&&(i1>45)){
      return;
    }
    int ogi1 = i1;

    while((i1!=0)&&(i1!=15)&&(i1!=30)&&(i1!=45)&&(i1!=60)){
        i1++;
        tmp++;
    }
    if ((h1==h2)&&(abs(ogi1-i2)<tmp)){return;}      
    while (1){
        switch (i1){
            case 0:  *b1=*b1+4;break;
            case 15: *b1=*b1+1;break;
            case 30: *b1=*b1+2;break;
            case 45: *b1=*b1+3;break;
            case 60: *b1=*b1+4;i1=i1-60;h1++;break;
        }
        if (i1==0){
            switch (h1){
                case 0: *b2=*b2+12;break;
                case 1: *b2=*b2+1;break;
                case 2: *b2=*b2+2;break;
                case 3: *b2=*b2+3;break;
                case 4: *b2=*b2+4;break;
                case 5: *b2=*b2+5;break;
                case 6: *b2=*b2+6;break;
                case 7: *b2=*b2+7;break;
                case 8: *b2=*b2+8;break;
                case 9: *b2=*b2+9;break;
                case 10: *b2=*b2+10;break;
                case 11: *b2=*b2+11;break;
                case 12: *b2=*b2+12;break;
                case 13: *b2=*b2+1;break;
                case 14: *b2=*b2+2;break;
                case 15: *b2=*b2+3;break;
                case 16: *b2=*b2+4;break;
                case 17: *b2=*b2+5;break;
                case 18: *b2=*b2+6;break;
                case 19: *b2=*b2+7;break;
                case 20: *b2=*b2+8;break;
                case 21: *b2=*b2+9;break;
                case 22: *b2=*b2+10;break;
                case 23: *b2=*b2+11;break;
            }  

        }
        if ((h1==h2)&&(abs(i1-i2)<15)&&(i1!=i2)){
            while(i1!=i2){
                i1++;
            }
        }
        if ((h1==h2)&&(i1==i2)){break;}
        i1=i1+15;  

    }
    }

long long int odecetnedeleb1(int h1,int i1,int h2,int i2){
    long long int b1=0;
    if ((h1==23)&&(i1>45)&&(h2==23)){
        return b1;
    }
    while((i1!=0)&&(i1!=15)&&(i1!=30)&&(i1!=45)&&(i1!=60)){
        i1++;
    }
       
    while (1){
        switch (i1){
            case 0:  b1=b1-4;break;
            case 15: b1=b1-1;break;
            case 30: b1=b1-2;break;
            case 45: b1=b1-3;break;
            case 60: b1=b1-4;i1=i1-60;h1++;break;
        }
        
        if ((h1==h2)&&(abs(i1-i2)<15)&&(i1!=i2)){
            while(i1!=i2){
                i1++;
            }
        }
        if ((h1==h2)&&(i1==i2)){break;}
        i1=i1+15;  

    }
    return b1;
    }

long long int odecetnedeleb2(int h1,int i1,int h2,int i2){
    long long int b2=0;
    if ((h1==23)&&(i1>0)&&(h2==23)){
        return b2;
    }
    while((i1!=0)&&(i1!=15)&&(i1!=30)&&(i1!=45)&&(i1!=60)){
        i1++;
    }
       
    while (1){
        switch (i1){
            case 0:  break;
            case 15: break;
            case 30: break;
            case 45: break;
            case 60: i1=i1-60;h1++;break;
        }
        if (i1==0){
            switch (h1){
                case 0: b2=b2-12;break;
                case 1: b2=b2-1;break;
                case 2: b2=b2-2;break;
                case 3: b2=b2-3;break;
                case 4: b2=b2-4;break;
                case 5: b2=b2-5;break;
                case 6: b2=b2-6;break;
                case 7: b2=b2-7;break;
                case 8: b2=b2-8;break;
                case 9: b2=b2-9;break;
                case 10: b2=b2-10;break;
                case 11: b2=b2-11;break;
                case 12: b2=b2-12;break;
                case 13: b2=b2-1;break;
                case 14: b2=b2-2;break;
                case 15: b2=b2-3;break;
                case 16: b2=b2-4;break;
                case 17: b2=b2-5;break;
                case 18: b2=b2-6;break;
                case 19: b2=b2-7;break;
                case 20: b2=b2-8;break;
                case 21: b2=b2-9;break;
                case 22: b2=b2-10;break;
                case 23: b2=b2-11;break;
            }  
        }
        
        if ((h1==h2)&&(abs(i1-i2)<15)&&(i1!=i2)){
            while(i1!=i2){
                i1++;
            }
        }
        if ((h1==h2)&&(i1==i2)){break;}
        i1=i1+15;  

    }
    return b2;
    }

void cas1vetsicas2(int h1,int i1,int h2,int i2,long long int *b1,long long int *b2){
     while((i1!=0)&&(i1!=15)&&(i1!=30)&&(i1!=45)&&(i1!=60)){
        i1++;
    }
       
    while (1){
        switch (i1){
            case 0: *b1=*b1+4;break;
            case 15: *b1=*b1+1;break;
            case 30: *b1=*b1+2;break;
            case 45: *b1=*b1+3;break;
            case 60: *b1=*b1+4;i1=i1-60;h1++;break;
        }
        if (i1==0){
            switch (h1){
                case 0: *b2=*b2+12;break;
                case 1: *b2=*b2+1;break;
                case 2: *b2=*b2+2;break;
                case 3: *b2=*b2+3;break;
                case 4: *b2=*b2+4;break;
                case 5: *b2=*b2+5;break;
                case 6: *b2=*b2+6;break;
                case 7: *b2=*b2+7;break;
                case 8: *b2=*b2+8;break;
                case 9: *b2=*b2+9;break;
                case 10: *b2=*b2+10;break;
                case 11: *b2=*b2+11;break;
                case 12: *b2=*b2+12;break;
                case 13: *b2=*b2+1;break;
                case 14: *b2=*b2+2;break;
                case 15: *b2=*b2+3;break;
                case 16: *b2=*b2+4;break;
                case 17: *b2=*b2+5;break;
                case 18: *b2=*b2+6;break;
                case 19: *b2=*b2+7;break;
                case 20: *b2=*b2+8;break;
                case 21: *b2=*b2+9;break;
                case 22: *b2=*b2+10;break;
                case 23: *b2=*b2+11;break;
                case 24: *b2=*b2+12;break;
            }  

        }
        if ((h1==24)&&(i1==0)){
            h1=0;
        }
        if ((h1==h2)&&(abs(i1-i2)<15)&&(i1!=i2)){
            while(i1!=i2){
                i1++;
            }
        }
        if ((h1==h2)&&(i1==i2)){break;}
        i1=i1+15;  

    }

}

int kontrolarozmezi(int y1,int m1,int d1,int h1,int i1,int y2,int m2,int d2,int h2, int i2){
    if (y1>y2){return 1;}
    if ((y1==y2)&&(m1>m2)){return 1;}
    if ((y1==y2)&&(m1==m2)&&(d1>d2)){return 1;}
    if ((y1==y2)&&(m1==m2)&&(d1==d2)&&(h1>h2)){return 1;}
    if ((y1==y2)&&(m1==m2)&&(d1==d2)&&(h1==h2)&&(i1>i2)){return 1;}
    else {return 0;}
}

int den_v_roce(int year,int month,int day){
    int prestupny_rok=0;
    int denvroce=0;
    
    if (year%4==0){prestupny_rok=1;}
    if (year%100==0){prestupny_rok=0;}
    if (year%400==0){prestupny_rok=1;}
    if (year%4000==0){prestupny_rok=0;}

    if (prestupny_rok==0){
    switch (month){
        case 12: denvroce=334 + day; break;
        case 11: denvroce=304 +day; break;
        case 10: denvroce=273 +day; break;
        case 9: denvroce=243 +day; break;
        case 8: denvroce=212 +day; break;
        case 7: denvroce=181 +day; break;
        case 6: denvroce=151 +day; break;
        case 5: denvroce=120 +day; break;
        case 4: denvroce=90 +day; break;
        case 3: denvroce=59 +day; break;
        case 2: denvroce=31 +day; break;
        case 1: denvroce=0 +day; break;
        }
    }
    if (prestupny_rok==1){
    switch (month){
        case 12: denvroce=335 + day; break;
        case 11: denvroce=305 +day; break;
        case 10: denvroce=274 +day; break;
        case 9: denvroce=244 +day; break;
        case 8: denvroce=213 +day; break;
        case 7: denvroce=182 +day; break;
        case 6: denvroce=152 +day; break;
        case 5: denvroce=121 +day; break;
        case 4: denvroce=91 +day; break;
        case 3: denvroce=60 +day; break;
        case 2: denvroce=31 +day; break;
        case 1: denvroce=0 +day; break;
        }
    }
    return denvroce;    
    }

int pocet_prestupnych_dniodroku1600(int y1,int m1,int d1){
   //1600.1.1 - sobota
   //tady by to chtelo zrychlit
   int rok =1600;
   int prestupnedny =0;
   int prestupnyrok =0;
   if (y1%4==0){prestupnyrok=1;}
   if (y1%100==0){prestupnyrok=0;}
   if (y1%400==0){prestupnyrok=1;}
   if (y1%4000==0){prestupnyrok=0;}
   while (y1!=rok){
    if((rok%4==0)&&(rok%100!=0)){prestupnedny++;}
    if((rok%400==0)&&(rok%4000!=0)){prestupnedny++;}
    if ((rok%4000==0)&&(rok!=y1)){prestupnedny++;}
    rok++;
   }
   if ((prestupnyrok==1)&&(den_v_roce(y1,m1,d1)>59)){prestupnedny++;}
   return prestupnedny;
}

int pocetprestupnychdnimeziy1y2(int y1,int m1,int d1,int y2,int m2,int d2){
int prestupnydny = 0;
prestupnydny= pocet_prestupnych_dniodroku1600(y2,m2,d2)-pocet_prestupnych_dniodroku1600(y1,m1,d1);
return prestupnydny;
}

int kontrola_vstupu(int y, int m, int d, int h, int i)
{
    int prestupny_rok=0;
    if (i<0||i>59){
        return 1;
    }
    if (h<0||h>23){
        return 1;
    }
    if (d<=0){
        return 1;
    }
    if (y<1600){
        return 1;
    }
    if ((1>m||12<m)){
        return 1;
    }
    if (y%4==0){prestupny_rok=1;}
    if (y%100==0){prestupny_rok=0;}
    if (y%400==0){prestupny_rok=1;}
    if (y%4000==0){prestupny_rok=0;}
    
    if (prestupny_rok==0){
    switch (m) {
        case 1: if (d>31){return 1;} break;
        case 2: if (d>28){return 1;} break;
        case 3: if (d>31){return 1;} break;
        case 4: if (d>30){return 1;} break;
        case 5: if (d>31){return 1;} break;
        case 6: if (d>30){return 1;} break;
        case 7: if (d>31){return 1;} break;
        case 8: if (d>31){return 1;} break;
        case 9: if (d>30){return 1;} break;
        case 10: if (d>31){return 1;} break;
        case 11: if (d>30){return 1;} break;
        case 12: if (d>31){return 1;} break;
    }
    }
    
    if (prestupny_rok==1){
    switch (m) {
        case 1: if (d>31){return 1;} break;
        case 2: if (d>29){return 1;} break;
        case 3: if (d>31){return 1;} break;
        case 4: if (d>30){return 1;} break;
        case 5: if (d>31){return 1;} break;
        case 6: if (d>30){return 1;} break;
        case 7: if (d>31){return 1;} break;
        case 8: if (d>31){return 1;} break;
        case 9: if (d>30){return 1;} break;
        case 10: if (d>31){return 1;} break;
        case 11: if (d>30){return 1;} break;
        case 12: if (d>31){return 1;} break;
    }
    }
    return 0;
}

int datum_den(int y1,int m1,int d1){
int prestupnedny = pocetprestupnychdnimeziy1y2(1600,1,2,y1,m1,d1); 
int rozdillet = y1-1600;
long long int rozdildnu=0;
int prestupnyrok =0;
   if (y1%4==0){prestupnyrok=1;}
   if (y1%100==0){prestupnyrok=0;}
   if (y1%400==0){prestupnyrok=1;}
   if (y1%4000==0){prestupnyrok=0;}
if (y1==1600){
    rozdildnu = den_v_roce(y1,m1,d1)-2;
    }
if (1600<y1){

    rozdildnu = 363+den_v_roce(y1,m1,d1)+365*(rozdillet-1)+prestupnedny;
    }
if ((1600<y1)&&(prestupnyrok==1)&&(den_v_roce(y1,m1,d1)>59)){

    rozdildnu = 363+den_v_roce(y1,m1,d1)+365*(rozdillet-1)+prestupnedny-1;
    }     
if (rozdildnu%7==0){return 0;}    
if (rozdildnu%7==1){return 1;}    
if (rozdildnu%7==2){return 2;}    
if (rozdildnu%7==3){return 3;}    
if (rozdildnu%7==4){return 4;}    
if (rozdildnu%7==5){return 5;}    
if (rozdildnu%7==6){return 6;}    
else {return 50;}

}

int bells ( int y1, int m1, int d1, int h1, int i1,
            int y2, int m2, int d2, int h2, int i2,
            long long int * b1, long long int * b2 )
{
if (kontrola_vstupu(y1,m1,d1,h1,i1)==1){return 0;}
if (kontrola_vstupu(y2,m2,d2,h2,i2)==1){return 0;}
if (kontrolarozmezi(y1,m1,d1,h1,i1,y2,m2,d2,h2,i2)==1){return 0;}
*b1=0;
*b2=0;
int prestupnedny = pocetprestupnychdnimeziy1y2(y1,m1,d1,y2,m2,d2); 
int rozdillet = y2-y1;
long long int rozdildnu=0;
int prvnidatumnedele=0;
int druhedatumnedele=0;
int prvnidatum = datum_den(y1,m1,d1);
int druhedatum = datum_den(y2,m2,d2);
int tmp =0;
long long int pocetnedeli=0;

if (y1==y2){
    rozdildnu = den_v_roce(y2,m2,d2)-den_v_roce(y1,m1,d1);
    }
if (y1<y2){

    rozdildnu = 365-den_v_roce(y1,m1,d1)+den_v_roce(y2,m2,d2)+365*(rozdillet-1)+prestupnedny;
    if ((((y1%4==0)&&(y1%100!=0))||((y1%400==0)&&(y1%4000!=0))||(y1%4000==0))&&(den_v_roce(y1,m1,d1)>=60)){
        rozdildnu = 366-den_v_roce(y1,m1,d1)+den_v_roce(y2,m2,d2)+365*(rozdillet-1)+prestupnedny;
            
    }
    if ((((y2%4==0)&&(y2%100!=0))||((y2%400==0)&&(y2%4000!=0))||(y2%4000==0))&&(den_v_roce(y2,m2,d2)>=60)){
        rozdildnu=rozdildnu-1;
    }
    }
if (prvnidatum==0){
    prvnidatumnedele = 1;
}
if (druhedatum==0){
    druhedatumnedele = 1;
}
for (;prvnidatum%7!=0;){
    prvnidatum++;
    tmp++;
    if (prvnidatum%7==0){
        pocetnedeli++;
    }
}
pocetnedeli=pocetnedeli+(rozdildnu-tmp)/7;
if (druhedatumnedele==1){pocetnedeli=pocetnedeli-1;}
if (tmp>=rozdildnu){pocetnedeli=0;}


if ((h1*60+i1)<(h2*60+i2)){
    cas1mensicas2(h1,i1,h2,i2,b1,b2);
    *b1=*b1+rozdildnu*240-pocetnedeli*240;
    *b2=*b2+rozdildnu*156-pocetnedeli*156;
    if (prvnidatumnedele==1){
        *b1=*b1+odecetnedeleb1(h1,i1,23,59);
        *b2=*b2+odecetnedeleb2(h1,i1,23,59);
    }
    if (druhedatumnedele==1){
        *b1=*b1+odecetnedeleb1(0,0,h2,i2);
        *b2=*b2+odecetnedeleb2(0,0,h2,i2);         
    }
   if (prvnidatumnedele==1&&druhedatumnedele==1&&rozdildnu==0){
        *b1=0;
        *b2=0;
    }
    return 1;
    }
if ((h1*60+i1)>(h2*60+i2)){
    cas1vetsicas2(h1,i1,h2,i2,b1,b2);
    rozdildnu=rozdildnu-1;
    *b1=*b1+rozdildnu*240-pocetnedeli*240;
    *b2=*b2+rozdildnu*156-pocetnedeli*156;
    if (prvnidatumnedele==1){
        *b1=*b1+odecetnedeleb1(h1,i1,23,50);
        *b2=*b2+odecetnedeleb2(h1,i1,23,50);
    }
    if (druhedatumnedele==1){
        *b1=*b1+odecetnedeleb1(0,0,h2,i2);
        *b2=*b2+odecetnedeleb2(0,0,h2,i2);         
    }
    if ((prvnidatumnedele==1)&&(druhedatumnedele==1)&&(rozdildnu==0)){
        *b1=0;
        *b2=0;
    }
    return 1;
    if (prvnidatumnedele==1&&druhedatumnedele==1&&rozdildnu==0){
        *b1=0;
        *b2=0;
    }
    }
if ((h1*60+i1)==(h2*60+i2)){
    cas1stejnycas2(h1,i1,h2,i2,b1,b2);
    *b1=*b1+rozdildnu*240-pocetnedeli*240;;
    *b2=*b2+rozdildnu*156-pocetnedeli*156;;
    if (prvnidatumnedele==1){
        *b1=*b1+odecetnedeleb1(h1,i1,23,50);
        *b2=*b2+odecetnedeleb2(h1,i1,23,50);
    }
    if (druhedatumnedele==1){
        *b1=*b1+odecetnedeleb1(0,0,h2,i2);
        *b2=*b2+odecetnedeleb2(0,0,h2,i2);         
    }
    if (prvnidatumnedele==1&&druhedatumnedele==1&&rozdildnu==0){
        *b1=0;
        *b2=0;
    }
    return 1;
}
    return 1;

}





#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
 long long int b1, b2;
  assert ( bells ( 1932, 4, 8, 21, 50, 1980, 2, 26, 1, 22, &b1, &b2 ) == 1
           && b1 == 3597635
           && b2 == 2338474 );
   assert (bells (2000,12,21,0,0,
                 2000,12,31,0,0,&b1,&b2)==1&&b1==2160&&b2==1404);        
     
  assert (datum_den(2022,1,3)==1);
  assert (bells (2000,12,21,0,0,
                 2000,12,31,0,0,&b1,&b2)==1&&b1==2160&&b2==1404);
  assert (pocetprestupnychdnimeziy1y2(1600,2,20,1600,3,1)==1);
  assert (pocetprestupnychdnimeziy1y2(2000,3,1,2096,12,31)==24);
  assert (pocet_prestupnych_dniodroku1600(1624,2,28)==6);
  assert (den_v_roce(2020 ,2,2)==33);
  assert ( bells ( 2022, 10,  1, 13, 15,
                   2022, 10,  1, 18, 45, &b1, &b2 ) == 1
           && b1 == 56
           && b2 == 20 );
  assert ( bells ( 2047, 10, 6, 3, 15, 2120, 10, 17, 3, 5, &b1, &b2 ) == 1
           && b1 == 5487154
           && b2 == 3566646 );        
  assert ( bells ( 2022, 10,  3, 13, 15,
                   2022, 10,  4, 11, 20, &b1, &b2 ) == 1
           && b1 == 221
           && b2 == 143 );
  assert (datum_den(2022,10,1)==6); 
  assert (datum_den(2022,10,2)==0);
  assert (odecetnedeleb1(0,0,11,20)==-115); 
  assert (odecetnedeleb2(0,0,11,20)==-78);
  assert (bells (2022,10,1,13,15,
                 2022,10,1,23,59,&b1,&b2)==1&&b1==106&&b2==65);
  assert ( bells ( 2022, 10,  1, 13, 15,
                   2022, 10,  2, 11, 20, &b1, &b2 ) == 1
           && b1 == 106
           && b2 == 65 );
  assert ( bells ( 2022, 10,  2, 13, 15,
                   2022, 10,  3, 11, 20, &b1, &b2 ) == 1
           && b1 == 115
           && b2 == 78 );
  assert ( bells ( 2022, 10,  1, 13, 15,
                   2022, 10,  3, 11, 20, &b1, &b2 ) == 1
           && b1 == 221
           && b2 == 143 );
  assert ( bells ( 2022,  1,  1, 13, 15,
                   2022, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 56861
           && b2 == 36959 );
  assert ( bells ( 2019,  1,  1, 13, 15,
                   2019, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 57101
           && b2 == 37115 );
  assert (den_v_roce(2024,1,1)==1);           
  assert (den_v_roce(2024,10,5)==279);   
  assert (datum_den(2024,1,1)==1);  
  assert (datum_den(2024,2,28)==3); 
  assert (datum_den(2024,2,29)==4);
  assert (datum_den(2024,3,1)==5);  
  assert (datum_den(2024,10,5)==6);  
  assert (pocetprestupnychdnimeziy1y2(2024,1,1,2024,10,5)==1);
  assert ( bells ( 2024,  1,  1, 13, 15,
                   2024, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 57341
           && b2 == 37271 );
  assert ( bells ( 1900,  1,  1, 13, 15,
                   1900, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 57101
           && b2 == 37115 );
  assert ( bells ( 2022, 10,  1,  0,  0,
                   2022, 10,  1, 12,  0, &b1, &b2 ) == 1
           && b1 == 124
           && b2 == 90 );
  assert ( bells ( 2022, 10,  1,  0, 15,
                   2022, 10,  1,  0, 25, &b1, &b2 ) == 1
           && b1 == 1
           && b2 == 0 );
  assert ( bells ( 2022, 10,  1, 12,  0,
                   2022, 10,  1, 12,  0, &b1, &b2 ) == 1
           && b1 == 4
           && b2 == 12 );
  //tady je ted problem tyvole.
  assert ( bells ( 2022, 11,  1, 12,  0,
                   2022, 10,  1, 12,  0, &b1, &b2 ) == 0
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2022, 10, 32, 12,  0,
                   2022, 11, 10, 12,  0, &b1, &b2 ) == 0
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2100,  2, 29, 12,  0,
                   2100,  2, 29, 12,  0, &b1, &b2 ) == 0
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2000,  2, 29, 12,  0,
                   2000,  2, 29, 12,  0, &b1, &b2 ) == 1
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2004,  2, 29, 12,  0,
                   2004,  2, 29, 12,  0, &b1, &b2 ) == 1
           && b1 == 0
           && b2 == 0 );
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
