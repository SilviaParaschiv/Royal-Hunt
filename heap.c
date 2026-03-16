#include "heap.h"
Heap *createheap(int capacitate)
{ // se da capacitatea 
    Heap *h = (Heap *)malloc(sizeof(Heap));
    if (h == NULL)
    {
        printf("Nu s-a putut aloca spatiu");
        return NULL;
    }
    h->size = 0; // initial SD e goala; as putea sa pornesc de la -1
    h->capacity = capacitate;
    h->vec = (participant *)malloc(sizeof(participant) * h->capacity);
    if (h->vec == NULL)
    {
        printf("Nu s-a putut aloca spatiu");
        return NULL;
    }
    return h;
}
void heapify_up(Heap *h, int i)
{
    participant aux;
    while (i > 0)
    {
        int parinte = (i - 1) / 2; // calculez indicele parintelui pentru nodul i
        if (h->vec[parinte].experienta < h->vec[i].experienta)
        { // daca experienta parintelui e mai mica decat cea a participantului curent le intrerschimb pentru a respecta proprietatea de heap
            aux = h->vec[parinte];
            h->vec[parinte] = h->vec[i];
            h->vec[i] = aux;
            i = parinte; // actualizez indicele nodului
        }
        else
            break; // daca heap-ul e corect ordonat ies din bucla
    }
}
// Functie pentru aflarea pozitiei copilului stang al unui nod de pe pozitia i

int leftChild(Heap *h, int i)
{
    int poz = 2 * i + 1;
    if (poz > h->size - 1 || i < 0)
        return -1; // nu are copil stg
    return poz;
}

// Functie pentru aflarea pozitiei copilului drept al unui nod de pe pozitia i

int rightChild(Heap *h, int i)
{
    int poz = 2 * i + 2;
    if (poz > h->size - 1 || i < 0)
        return -1; // nu are copil dr
    return poz;
}

void heapify_down(Heap *h, int i)
{
    int l, r, max = i; // retin pozitia i in max
    participant aux;
    l = leftChild(h, i);  // pozitia copilului stang al lui i
    r = rightChild(h, i); // pozitia copilului drept al lui i
    if (l == -1 && r == -1)
        return; // daca e frunza -> am terminat

    if (l != -1 && h->vec[l].experienta > h->vec[max].experienta)
        max = l; // in max stochez l sau r
    if (r != -1 && h->vec[r].experienta > h->vec[max].experienta)
        max = r;
    // in max stochez pozitia copilului cu valoare mai mare (daca e cazul)
    // interschimb elementele
    if (max != i)
    { // proprietatea de heap nu e respectata
        aux = h->vec[i];
        h->vec[i] = h->vec[max];
        h->vec[max] = aux;
        // repet procesul pentru nodurile de sub cel cu indice i
        heapify_down(h, max);
    }
    return; // altfel am terminat, prop. e respectata
}

// functie pentru adaugarea unui nou participant
void insertheap(Heap *h, participant x)
{

    if (h->size == h->capacity)
    {
        printf("Heap-ul e plin\n");
        return;
    }

    h->vec[h->size] = x; // adaugam participantul x la pozitia h->size

    heapify_up(h, h->size); // refac proprietatea de heap
    h->size++;              // cresc dimensiunea
}

void deleteheap(Heap **h)
{
    if (*h == NULL)
        return;
    free((*h)->vec); // eliberez mai intai spatiul ocupat de vector (contine date de tip int)
    free(*h);
    *h = NULL;
}