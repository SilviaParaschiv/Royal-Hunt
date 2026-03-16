
#ifndef ARBORE_H
#define ARBORE_H
#include "coada.h"
#include "pas1.h"
typedef struct nodbst
{
    participant candidat;
    struct nodbst  *right, *left;
}nodbst;
nodbst* newNode(participant c) ;
nodbst* insert(nodbst* nod, participant key);
void scriebst(nodbst *root, FILE *f2) ;
nodbst * minValueNode(nodbst* node);
nodbst* deleteNode(nodbst* root, participant key);
void freebst(nodbst* root);
#endif