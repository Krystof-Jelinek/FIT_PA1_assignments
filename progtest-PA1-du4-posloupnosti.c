#include <stdio.h>
#include <stdlib.h>
int zadaniposloupnosti(int cisla[],int* pocetcisel){
    int a=0;
    int n=0;
    int kontrola =0;
    *pocetcisel=0;
    while(n<=2000){
        kontrola=(scanf(" %d",&a));
        if (kontrola==0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if ((kontrola==EOF)&&(n==0)){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if ((n==2000)&&(kontrola!=EOF)){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if (kontrola==EOF){
            return 0;
        }
        cisla[n]=a;
        n++;
        *pocetcisel=*pocetcisel+1;
    }
    return 0;
}

int comparator(const void *x,const void *y){
    int a =*(int *)x;
    int b =*(int *)y;
    return a-b;

}

int sumovani(int zadanecisla[],int sumy[],int pocetcisel, int* pocetsum){
    int a =0;
    int b =2;
    for (;a<pocetcisel-1;a++,b++){
        int i=b;
        for (;i<=pocetcisel;i++){
            long int suma =0;
            int n =a;
            for(;n<i;n++){
                suma=suma+zadanecisla[n];
                
            }
            sumy[*pocetsum]= suma;
            *pocetsum= *pocetsum +1;
            
        }
    }
    return 0;
}

int main(void){
    int zadanecisla[2000];
    int pocetcisel = 0;
    int pocetsum = 0;
    printf("Posloupnost:\n");
    if (zadaniposloupnosti(zadanecisla,&pocetcisel)==1){
        return 0;
    }

    int sumy[2000000];
    sumovani(zadanecisla,sumy,pocetcisel,&pocetsum);
   
    qsort(sumy,pocetsum,sizeof(int),comparator);

    int n =0;
    int pocetdvojic =0;
    while (n<pocetsum){
        int tmp = 1;
        while (sumy[n]==sumy[n+1]){
            tmp++;
            n++;
        }
        pocetdvojic = pocetdvojic + (tmp*(tmp-1))/2;
        n++;
    }
    printf("Pocet dvojic: %d\n",pocetdvojic);

    return 0;
}