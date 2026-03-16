#ifndef PAS4_H
#define PAS4_H
#include"arbore.h"
#include "heap.h"
typedef struct{
    char nume[3];
    int paduri[10];
    int nrpaduri;
}traseu;
int citestetraseu(FILE *f, traseu trasee[]);
nodbst* scoatemaxim(nodbst **root, nodbst **maxim);
void asignaretrasee(nodbst **bstlorzi, nodbst **bstca, FILE *f, FILE *fw, Heap *heap);
#endif