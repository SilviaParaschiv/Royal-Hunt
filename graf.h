#include<stdio.h>
#include <stdlib.h>
#ifndef GRAF_H
#define GRAF_H
typedef struct ListNode{
    int vertex_no; //informatia utila = numarul varfului de stocat
    struct ListNode* next;
   } Node;
   typedef struct{
   int V, E;
   Node** a; //vector cu V elemente - capetele de liste
   } Graph;
   Graph *creategraf(FILE *f);
   void sorteaza(int **matrice,int poz,int nrtraseu);
   void afisare(int **matrice, int nr, FILE *f, int nrtraseu);
   void DFS_scan(Graph *g, int **matrice,int *cale, int poz, int nod, int gradintrare[], int gradiesire[], int *vizitat, FILE *f, int *nrtraseu);
   void nrtraseegenerate(Graph *g, int gradintrare[], int gradiesire[], FILE *f);
   void printGraph(Graph *g);
   void freegraf(Graph *g);
#endif