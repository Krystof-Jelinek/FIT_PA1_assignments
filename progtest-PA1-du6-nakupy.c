#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct zbozi{
    char *nazev_zbozi;
    int cislo_regalu;
}zbozi;

typedef struct polozky{
    char *nazev_zbozi;
    int uz_v_kosiku = 0;
}polozky;

int nacteni_zbozi(zbozi **obchod,int& pocet_obchod,int* pocet_regal){
    char *tmp = NULL;
    int n =0;
    int misto_v_regalech = 20;
    size_t velikost_getline = 0;
    int returned;
    int regal = 0;
    char hashtag[2] = "#";
    char new_line[2] = {'\n','\0'};
    char prvni_line[4] = {'#','0','\n','\0'};
    char zacatek[4];
    fgets(zacatek,4,stdin);
    int zacatek2 = strcmp(zacatek,prvni_line);
    if ((zacatek2 != 0 )){
        free(tmp);
        return 1;
    }
    while ((returned = getline(&tmp,&velikost_getline,stdin))!=EOF){
        if (strcmp(tmp,new_line) == 0){
            free(tmp);
            return 0;
        }
        if (strncmp(tmp,hashtag,1) == 0){
            regal++;
            *pocet_regal = *pocet_regal + 1;
            char *tmp2 = tmp;
            tmp[0] = '0'; 
            int prevod1= atoi(tmp2);
            
            if (prevod1 != regal){
                free(tmp);
                return 1;
            } 
            continue;
        }
        char *ptr = strchr(tmp,'\n');
        if (ptr)
        {
            *ptr  = '\0';
        }
        if (n > misto_v_regalech -3){
            misto_v_regalech = misto_v_regalech*1.6;
            *obchod = (zbozi*)realloc(*obchod,misto_v_regalech*sizeof(zbozi));
        }
        (*obchod)[n].nazev_zbozi = (char*) malloc(returned+10);
        strcpy((*obchod)[n].nazev_zbozi,tmp);
        (*obchod)[n].cislo_regalu = regal;
        pocet_obchod++; 
        free(tmp);
        tmp = NULL;
        returned = 0;
        velikost_getline = 0;

        n++;
    }
    free(tmp);
    return 0;
}

int nacteni_seznamu(polozky **seznam,int* pocet_seznam,int* flag){
    char *tmp = NULL;
    int misto_v_seznamu = 20;
    int n =0;
    size_t velikost_getline;
    int returned;
    char new_line[2] = {'\n','\0'};
   
    while ((returned = getline(&tmp,&velikost_getline,stdin))!=EOF){
        *flag = 1;
        if (strcmp(tmp,new_line) == 0){
            free(tmp);
            return 1;
        }
        char *ptr = strchr(tmp,'\n');
        if (ptr)
        {
            *ptr  = '\0';
        }
        if (n > misto_v_seznamu -3){
            misto_v_seznamu = misto_v_seznamu*1.6;
            *seznam = (polozky*)realloc(*seznam,misto_v_seznamu*sizeof(polozky));
        }
        (*seznam)[n].nazev_zbozi = (char*) malloc(returned+10);
        strcpy((*seznam)[n].nazev_zbozi,tmp);
        (*seznam)[n].uz_v_kosiku = 0;
        free(tmp);
        tmp = NULL;
        returned = 0;
        velikost_getline = 0;
        n++;
        *pocet_seznam = *pocet_seznam +1; 
    }
    if (*flag == 0){free(tmp);return 69;}
    free(tmp);
    return 0;
}

int optimalizace_seznamu(zbozi obchod[],polozky seznam[],int pocet_obchod,int pocet_seznam,int pocet_regal){
    int n = 0;
    int i = 0;
    int pocitadlo = 0;
    int regal = 0;
    int nalezeno = 0;
    polozky *nenalezeno = (polozky*) malloc(20*sizeof(polozky));
    int kapacita_nenalezeno = 20;
    int pocetnenalezeno = 0;
    printf("Optimalizovany seznam:\n");
    
    while(regal<=pocet_regal){
        n = 0;
        while(n<pocet_seznam){
            i =0;
            nalezeno = 0;
            while (i<pocet_obchod){
                
            if (strcasecmp(seznam[n].nazev_zbozi,obchod[i].nazev_zbozi)==0){
                if (strcasecmp(seznam[n].nazev_zbozi,obchod[i].nazev_zbozi)==0){
                    nalezeno = 1;
                }
                if ((obchod[i].cislo_regalu == regal)&&(seznam[n].uz_v_kosiku == 0)){
                printf(" %d. %s -> #%d %s\n",pocitadlo, seznam[n].nazev_zbozi, obchod[i].cislo_regalu, obchod[i].nazev_zbozi);
                seznam[n].uz_v_kosiku = 1;
                pocitadlo++;
                break;
                }

            }

            i++;
            }

            
            if (nalezeno == 0){
            i = 0;
                                 
            while (i<pocet_obchod){
                
                char* p;
                p = strcasestr(obchod[i].nazev_zbozi,seznam[n].nazev_zbozi);
                if (p!=NULL){nalezeno = 1;}
                if ((p!=NULL)&&(obchod[i].cislo_regalu == regal)&&(seznam[n].uz_v_kosiku == 0)){
                printf(" %d. %s -> #%d %s\n",pocitadlo, seznam[n].nazev_zbozi, obchod[i].cislo_regalu, obchod[i].nazev_zbozi);
                seznam[n].uz_v_kosiku = 1;
                pocitadlo++;
                nalezeno = 1;
                break;
                }
                i++;
            }      
            
            }
            if ((nalezeno == 0)&&(pocet_regal==regal)){
                if (pocetnenalezeno > kapacita_nenalezeno -3){
                    kapacita_nenalezeno = kapacita_nenalezeno*1.6;
                    nenalezeno = (polozky*)realloc(nenalezeno,kapacita_nenalezeno*sizeof(polozky));
                }
            nenalezeno[pocetnenalezeno].nazev_zbozi = (char*) malloc(strlen(seznam[n].nazev_zbozi)+10);    
            strcpy(nenalezeno[pocetnenalezeno].nazev_zbozi,seznam[n].nazev_zbozi);
            pocetnenalezeno++;
            
            }
            n++;
            }

        regal++;
        }
    for (int q = 0;q<pocetnenalezeno;q++){
        printf(" %d. %s -> N/A\n",pocitadlo,nenalezeno[q].nazev_zbozi);
        pocitadlo++;
    }    
    for (int t =0;t<pocetnenalezeno;t++){

    free(nenalezeno[t].nazev_zbozi);
    }
    free(nenalezeno);

    return 0;
        }
    


int main(void){
    zbozi* obchod = (zbozi*)malloc(20*sizeof(zbozi));
    int pocet_obchod = 0;
    int pocet_seznam = 0;
    int pocet_regal = 0;
    int opakovani = 0;
    polozky* seznam = NULL;

    if (nacteni_zbozi(&obchod,pocet_obchod,&pocet_regal)==1){
        printf("Nespravny vstup.\n");

        for (int t =0;t<pocet_obchod;t++){

        free(obchod[t].nazev_zbozi);
        }
        
        free(obchod);
        return 0;
    }
    
    int flag = 0;

    while (1){
    pocet_seznam = 0;
    polozky* seznam = (polozky*)malloc(20*sizeof(polozky));
    opakovani = nacteni_seznamu(&seznam,&pocet_seznam,&flag);
    if (opakovani ==69){
        printf("Nespravny vstup.\n");
        for (int t =0;t<pocet_obchod;t++){

        free(obchod[t].nazev_zbozi);
        }
        for (int q =0;q<pocet_seznam;q++){

        free(seznam[q].nazev_zbozi);
        }
        free(obchod);
        free(seznam);
        return 0;
    }
    if (opakovani==0){
    optimalizace_seznamu(obchod,seznam,pocet_obchod,pocet_seznam,pocet_regal);
    for (int t =0;t<pocet_obchod;t++){

    free(obchod[t].nazev_zbozi);
    }
    for (int q =0;q<pocet_seznam;q++){

    free(seznam[q].nazev_zbozi);
    }

    free(obchod);
    free(seznam);
    return 0;
    }
    if (opakovani==1){
    optimalizace_seznamu(obchod,seznam,pocet_obchod,pocet_seznam,pocet_regal);
    for (int q =0;q<pocet_seznam;q++){

    free(seznam[q].nazev_zbozi);
    }
    free(seznam);
    
    }

    }
    for (int t =0;t<pocet_obchod;t++){

    free(obchod[t].nazev_zbozi);
    }
    for (int q =0;q<pocet_seznam;q++){

    free(seznam[q].nazev_zbozi);
    }
    
    free(obchod);
    free(seznam);
    return 0;
}