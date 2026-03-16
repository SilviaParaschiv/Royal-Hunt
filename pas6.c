#include "pas6.h"

void printHeap(Heap *h, FILE *f)
{
    int i, j, k;
    participant aux[3]={0};

    for (i = 0; i < h->size; i++) //parcurg fiecare participant din heap
    {
        participant p = h->vec[i]; //retin participantul curent in p
        for (j = 0; j < 3; j++)
        {
            if (p.experienta > aux[j].experienta) //daca experienta participantului curent e mai mare decat cea a participantilor deja salvati
            {
                //mut participantii de la stanga la dreapta
                for (k = 2; k > j; k--)
                    aux[k] = aux[k - 1];
                aux[j] = p; //adaug participantul

                break; //cand participantul a fost adaugat ies din forul j
            }
        }
    }
    for (i = 0; i < 3; i++)
    {

        fprintf(f, "%s %.2f \n", aux[i].nume, aux[i].experienta);
    }
}