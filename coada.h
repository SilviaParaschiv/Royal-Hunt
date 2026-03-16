#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef COADA_H
#define COADA_H
typedef enum  {LORD, CAVALER, AVENTURIER}statutsocial;
typedef struct {
    char *nume;
    int varsta;
    float experienta;
    statutsocial statut;
    char *traseu;
}participant;
typedef struct elem
{
    participant candidat;
    struct elem *next;
}node;
typedef struct{
  node *front, *rear;  
}queue;
queue* create();
void enqueue(queue *q, participant c);
participant deQueue(queue*q) ; 
int isEmpty(queue*q);
void freecoada(queue* q);
#endif