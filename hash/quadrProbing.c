#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

int hash(int key){ return key % SIZE; }

void insertQuad(int ht[], int key){
    int i=hash(key), j=1;
    while(ht[i]!=-1){ 
        i = (hash(key) + j*j)%SIZE; 
        j++; 
        if(j>SIZE){ printf("Table full\n"); return; } 
    }
    ht[i]=key;
}
int searchQuad(int ht[], int key){
    int i=hash(key), j=0;
    while(j<SIZE){
        int idx = (i + j*j)%SIZE;
        if(ht[idx]==key) return idx;
        if(ht[idx]==-1) return -1;
        j++;
    }
    return -1;
}

int main(){
    int htQ[SIZE];
    for(int i=0;i<SIZE;i++){ htQ[i]=-1; }

    insertQuad(htQ, 23); insertQuad(htQ, 34); insertQuad(htQ,44);
    printf("search 34 quad at %d\n", searchQuad(htQ,34));
    return 0;
}
