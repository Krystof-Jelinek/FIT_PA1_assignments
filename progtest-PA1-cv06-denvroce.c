#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dateToIndex(int day, int month, int year, int *idx) {
    bool prestupny_rok=false;
    int denvroce; 
    if (day<=0){
        return 0;
    }
    if (year<2000){
        return 0;
    }
    if ((1>month)||(12<month)){
        return 0;
    }
    if (year%4==0){prestupny_rok=true;}
    if (year%100==0){prestupny_rok=false;}
    if (year%400==0){prestupny_rok=true;}
    if (year%4000==0){prestupny_rok=false;}
    
    if (prestupny_rok==false){
    switch (month) {
        case 1: if (day>31){return 0;} break;
        case 2: if (day>28){return 0;} break;
        case 3: if (day>31){return 0;} break;
        case 4: if (day>30){return 0;} break;
        case 5: if (day>31){return 0;} break;
        case 6: if (day>30){return 0;} break;
        case 7: if (day>31){return 0;} break;
        case 8: if (day>31){return 0;} break;
        case 9: if (day>30){return 0;} break;
        case 10: if (day>31){return 0;} break;
        case 11: if (day>30){return 0;} break;
        case 12: if (day>31){return 0;} break;
    }
    }
    if (prestupny_rok==true){
    switch (month) {
        case 1: if (day>31){return 0;} break;
        case 2: if (day>29){return 0;} break;
        case 3: if (day>31){return 0;} break;
        case 4: if (day>30){return 0;} break;
        case 5: if (day>31){return 0;} break;
        case 6: if (day>30){return 0;} break;
        case 7: if (day>31){return 0;} break;
        case 8: if (day>31){return 0;} break;
        case 9: if (day>30){return 0;} break;
        case 10: if (day>31){return 0;} break;
        case 11: if (day>30){return 0;} break;
        case 12: if (day>31){return 0;} break;
    }
    }

    if (prestupny_rok==false){
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
    if (prestupny_rok==true){
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
    *idx = denvroce;
    return 1;
    }


#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;
    assert(dateToIndex( 1,  1, 2000, &idx) == 1 && idx == 1);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */

