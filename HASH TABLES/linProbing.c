/* program6_hash.c */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

int hash(int key){ return key % SIZE; }

/* linear probing */
void insertLinear(int ht[], int key){
    int i=hash(key), start=i;
    while(ht[i]!=-1){ 
        i = (i+1)%SIZE; 
        if(i==start){ printf("Table full\n"); return; } 
    }
    ht[i]=key;
}
int searchLinear(int ht[], int key){
    int i=hash(key), start=i;
    while(ht[i]!=-1){ 
        if(ht[i]==key) return i; 
        i=(i+1)%SIZE; 
        if(i==start) break; 
    }
    return -1;
}

int main(){
    int htL[SIZE];
    for(int i=0;i<SIZE;i++){ htL[i]=-1; }
    insertLinear(htL, 23); insertLinear(htL, 34); insertLinear(htL,44);
    printf("search 34 linear at %d\n", searchLinear(htL,34));

    return 0;
}
