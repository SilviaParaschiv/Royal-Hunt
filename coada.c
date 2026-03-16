#include "coada.h"

queue *create()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}
void enqueue(queue *q, participant c)
{
    // functie pentru adaugarea participantilor in coada
    node *newnode = (node *)malloc(sizeof(node));
    newnode->candidat.nume = (char *)malloc((strlen(c.nume) + 1) * sizeof(char));
    if (newnode->candidat.nume != NULL)
        strcpy(newnode->candidat.nume, c.nume);
    newnode->candidat.experienta = c.experienta;
    newnode->candidat.varsta = c.varsta;
    newnode->candidat.statut = c.statut;
    newnode->next = NULL;
    if (q->rear == NULL)
        q->rear = newnode;
    else
    {
        (q->rear)->next = newnode;
        (q->rear) = newnode;
    }
    if (q->front == NULL)
        q->front = q->rear;
    // free(c.nume);
    // free(newnode);
}
int isEmpty(queue *q)
{
    return (q->front == NULL);
}
participant deQueue(queue *q)
{
    // functie pentru scoaterea din coada;
    node *aux = q->front;
    participant c = aux->candidat;
    q->front = (q->front)->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(aux);
    return c;
}

void freecoada(queue *q)
{
    node *curent = q->front;
    while (curent != NULL)
    {
        node *aux = curent;
        curent = curent->next;
        free(aux->candidat.nume);
        free(aux);
    }
}