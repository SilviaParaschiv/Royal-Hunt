#include "arbore.h"
#ifndef HEAP_H
#define HEAP_H
typedef struct {
    participant *vec; //vectorul in care stochez elementele colectiei
    int size, capacity; // size – cate elemente exista la un moment dat
    //capacity – nr. max de elemente ce pot sa fie stocate
    //int type; //min sau max – poate sa lipseasca
   } Heap;

   Heap *createheap(int capacitate);
   void heapify_up(Heap *h, int i);
   void insertheap(Heap *h, participant x);
   int leftChild(Heap *h, int i);
   int rightChild(Heap *h, int i);
   void heapify_down(Heap *h, int i);
   void printHeap(Heap *h,FILE* f);
   void deleteheap(Heap **h);
   
#endif