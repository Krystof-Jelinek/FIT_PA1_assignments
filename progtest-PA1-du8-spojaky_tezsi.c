#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TItem
{
  struct TItem             * m_Next;
  char                     * m_Name;
  char                       m_Secret[24];
} TITEM;

int cmpName ( const TITEM * a,
              const TITEM * b )
{
  return strcmp ( a -> m_Name, b -> m_Name );
}

int cmpNameInsensitive ( const TITEM * a,
                         const TITEM * b )
{
  return strcasecmp ( a -> m_Name, b -> m_Name );
}

int cmpNameLen ( const TITEM * a,
                 const TITEM * b )
{
  size_t la = strlen ( a -> m_Name ), lb = strlen ( b -> m_Name );
  return ( lb < la ) - ( la < lb );
}
#endif /* __PROGTEST__ */

TITEM            * newItem      ( const char      * name,
                                  TITEM           * next )
{
    TITEM *tmp = (TITEM*)malloc(sizeof(TITEM));
  tmp->m_Name = (char*)malloc(sizeof(char)*strlen(name)+10);
  strcpy(tmp->m_Name,name);
  tmp->m_Next = next;
  for(int i=0;i<24;i++){
    tmp->m_Secret[i] = '\0';
  }
  return tmp;
}

TITEM * stred(TITEM * l){
    TITEM * pomaly = l;
    TITEM * rychly = l->m_Next;
    while ((rychly !=NULL)&&(rychly->m_Next!=NULL)){
      pomaly = pomaly->m_Next;
      rychly = rychly->m_Next->m_Next;
    }
    return pomaly;
}

TITEM * mergeASC(TITEM * left,TITEM * right,int (*cmpFn) (const TITEM *,const TITEM *)){
    TITEM * tail;
    TITEM * otrok=(TITEM*)malloc(sizeof(TITEM));
    tail = otrok;
    while ((left!=NULL) && (right!=NULL)){
        int porovnani = (*cmpFn)(left,right);//pokud je left vetsi (podle ASCII) nez right compare vrati >0
        porovnani = porovnani*(-1);//kvuli prehlednosti prohozeni hodnot ted <0 znamena dej ho na konec protoze je vetsi - ascending
        if (porovnani>=0){
          tail->m_Next = left;
          left = left->m_Next;
        }
        else{
          tail->m_Next = right;
          right = right->m_Next;
        }
        tail = tail->m_Next;
    }
    if (left!=NULL){
      tail->m_Next = left;
    }
    if (right!=NULL){
      tail->m_Next = right;
    }
    TITEM * navrat = otrok->m_Next;
    free(otrok);
    return navrat;
}

TITEM * mergeDSC(TITEM * left,TITEM * right,int (*cmpFn) (const TITEM *,const TITEM *)){
    TITEM * tail;
    TITEM * otrok=(TITEM*)malloc(sizeof(TITEM));
    tail = otrok;
    while ((left!=NULL) && (right!=NULL)){
        int porovnani = (*cmpFn)(left,right);//pokud je left vetsi (podle ASCII) nez right compare vrati >0
        if (porovnani>=0){
          tail->m_Next = left;
          left = left->m_Next;
        }
        else{
          tail->m_Next = right;
          right = right->m_Next;
        }
        tail = tail->m_Next;
    }
    if (left!=NULL){
      tail->m_Next = left;
    }
    if (right!=NULL){
      tail->m_Next = right;
    }
    TITEM * navrat = otrok->m_Next;
    free(otrok);
    return navrat;
}


TITEM            * sortListCmp  ( TITEM           * l,
                                  int               ascending,
                                  int            (* cmpFn) ( const TITEM *, const TITEM *) )
{
    if (ascending != 0){
    if (l==NULL||l->m_Next==NULL){
      return l;
    }
    TITEM * left = l;
    TITEM * right = stred(l);
    TITEM * tmp = right->m_Next;
    right->m_Next = NULL;
    right = tmp;

    left = sortListCmp(left,1,(*cmpFn));
    right = sortListCmp(right,1,(*cmpFn));
    return mergeASC(left,right,(*cmpFn));
  }
  else{
    if (l==NULL||l->m_Next==NULL){
      return l;
    }
    TITEM * left = l;
    TITEM * right = stred(l);
    TITEM * tmp = right->m_Next;
    right->m_Next = NULL;
    right = tmp;

    left = sortListCmp(left,0,(*cmpFn));
    right = sortListCmp(right,0,(*cmpFn));
    return mergeDSC(left,right,(*cmpFn));
  }
}
void               freeList     ( TITEM           * src )
{
    TITEM * tmp = NULL;
  while (src != NULL){
    tmp = src->m_Next;
    free(src->m_Name);
    free(src);
    src = tmp;
  }
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TITEM * l;
  char tmp[50];

  assert ( sizeof ( TITEM ) == sizeof ( TITEM * ) + sizeof ( char * ) + 24 * sizeof ( char ) );
  l = NULL;
  l = newItem ( "BI-PA1", l );
  l = newItem ( "BIE-PA2", l );
  l = newItem ( "NI-PAR", l );
  l = newItem ( "lin", l );
  l = newItem ( "AG1", l );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 1, cmpName );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 1, cmpNameInsensitive );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 1, cmpNameLen );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = newItem ( "AAG.3", l );
  assert ( l
           && ! strcmp ( l -> m_Name, "AAG.3" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "AG1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 0, cmpNameLen );
  assert ( l
           && ! strcmp ( l -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "AAG.3" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "AG1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  freeList ( l );
  l = NULL;
  strncpy ( tmp, "BI-PA1", sizeof ( tmp ) - 1 );
  tmp[sizeof ( tmp ) - 1 ] = '\0';
  l = newItem ( tmp, l );
  strncpy ( tmp, "BIE-PA2", sizeof ( tmp ) - 1 );
  tmp[sizeof ( tmp ) - 1 ] = '\0';
  l = newItem ( tmp, l );
  strncpy ( tmp, "NI-PAR", sizeof ( tmp ) - 1 );
  tmp[sizeof ( tmp ) - 1 ] = '\0';
  l = newItem ( tmp, l );
  strncpy ( tmp, "lin", sizeof ( tmp ) - 1 );
  tmp[sizeof ( tmp ) - 1 ] = '\0';
  l = newItem ( tmp, l );
  strncpy ( tmp, "AG1", sizeof ( tmp ) - 1 );
  tmp[sizeof ( tmp ) - 1 ] = '\0';
  l = newItem ( tmp, l );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 1, cmpName );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 1, cmpNameInsensitive );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 1, cmpNameLen );
  assert ( l
           && ! strcmp ( l -> m_Name, "AG1" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  strncpy ( tmp, "AAG.3", sizeof ( tmp ) - 1 );
  tmp[sizeof ( tmp ) - 1 ] = '\0';
  l = newItem ( tmp, l );
  assert ( l
           && ! strcmp ( l -> m_Name, "AAG.3" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "AG1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  l = sortListCmp ( l, 0, cmpNameLen );
  assert ( l
           && ! strcmp ( l -> m_Name, "BIE-PA2" ) );
  assert ( l -> m_Next
           && ! strcmp ( l -> m_Next -> m_Name, "BI-PA1" ) );
  assert ( l -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Name, "NI-PAR" ) );
  assert ( l -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Name, "AAG.3" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "AG1" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "lin" ) );
  assert ( l -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  freeList ( l );
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
