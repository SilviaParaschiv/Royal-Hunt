#include "pas5.h"
// functie pentru a calcula experienta dobandita conform cerintei
int experientadobandita(traseu t)
{
    int i, sum = 0;
    for (i = 0; i < t.nrpaduri; i++)
        sum = sum + t.paduri[i];
    return sum;
}

void actualizareexperienta(Heap *h, traseu trasee[], int nrtrasee, FILE *f)
{
    if (h == NULL)
        return;
    int i, j;
    for (i = 0; i < h->size; i++)
    {
        participant *c = &h->vec[i]; //iau un pointer c care face referire la participantul curent din heap
        for (j = 0; j < nrtrasee; j++)
            if (strcmp(c->traseu, trasee[j].nume) == 0) //daca traseul participantului coincide cu numele traseului din tablou actualizeaza experienta
            {
                int experientadob = experientadobandita(trasee[j]);
                c->experienta = c->experienta + experientadob;

                break; //daca a gasit traseul iese din for pentru a trece la alt participant
            }
    }
    for (i = (h->size - 1) / 2; i >= 0; i--) //(h->size-1)/2 e indicele ultimului nod care poate fi parinte intr un heap
        heapify_down(h, i); //refac proprietatea de heap

    for (i = 0; i < h->size; i++)
    {
        fprintf(f, "%s - %s (%.2f)\n", h->vec[i].traseu, h->vec[i].nume, h->vec[i].experienta);
    } 
}