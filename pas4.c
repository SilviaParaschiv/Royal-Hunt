#include "pas4.h"
int citestetraseu(FILE *f, traseu trasee[])
{
    char *date2 = (char *)malloc(265 * sizeof(char));//aloca dinamic un buffer pentru a citi fiecare linie din fisier
    if (date2 == NULL)
    {
        printf("\nAlocare nereusita de memorie");
        exit(1);
    }
    int k = 0;
    while (fgets(date2, 256, f) && k < 8)
    {
        char *p = strtok(date2, ":");//extrage numele traseului
        if (p != NULL)
            strcpy(trasee[k].nume, p); //daca numele a fost gasit corect il salveaza
        trasee[k].nrpaduri = 0;
        p = strtok(NULL, " ");//extrage padurile
        while (p != NULL && trasee[k].nrpaduri < 10)
        {

            trasee[k].paduri[trasee[k].nrpaduri] = atoi(p);//functia atoi converteste fiecare traseu care e dat printr un caracter in numarul corespunzator
            trasee[k].nrpaduri++;//incrementeaza numarul de paduri
            p = strtok(NULL, " ");
        }
        k++;
    }

    free(date2);
    return k; //returneaza numarul de paduri
}
nodbst *scoatemaxim(nodbst **root, nodbst **maxim)
{
    nodbst *curent = *root; //iau un pointer curent care va incepe de la radacina arborelui
    nodbst *parinte = NULL; //si un pointer parinte initial null
    if (*root == NULL)
        return NULL;
    //caut nodul cel mai din dreapta, nodul cu valoare maxima
    while (curent->right != NULL)
    { 
        parinte = curent; 
        curent = curent->right;
        //actualizam pointerul parinte pentru a stii nodul curent
    }
    *maxim = curent; //retin nodul cu valoare maxima
      if (parinte == NULL) //daca parintele e null inseamna ca nodul maxim e radacina
        (*root) = curent->left; //setam noua radacina la fiul stang al radacinii
    else
        parinte->right = curent->left; //daca parintele nu e radacina, leg fiul stang al nodului maxim la fiul drept al parintelui
    return curent;//returnez nodul cu valoare maxima
}
void asignaretrasee(nodbst **bstlorzi, nodbst **bstca, FILE *f, FILE *fw, Heap *heap)
{

    traseu trasee[8];
    int nrtrasee = citestetraseu(f, trasee);

    nodbst *concurent = NULL;  //pointerul concurent e folosit pentru a tine evidenta participantului curent in arborele binar de cautare
    participant c;
    int nr = 0; //folosit pentru a retine indexul curent al traseelor din tablou
    int i;
    for (i = 0; i < 8; i++)
    {
        //le scot alternativ
        if (i % 2 == 0)
            concurent = scoatemaxim(bstlorzi, &concurent); //daca i e par elimin si returnez nodul cu valoare maxima din bstlorzi
        else
            concurent = scoatemaxim(bstca, &concurent);

        if (concurent != NULL && nr < nrtrasee)
        {
            c.nume = (char *)malloc(strlen(concurent->candidat.nume) + 1); //aloc memorie pentru numele participantului
            if (c.nume == NULL)
            {
                printf("alocarea a esuat\n");
                exit(1);
            }
            strcpy(c.nume, concurent->candidat.nume);
            modificanume(c.nume); //modific numele conform cerintei
            c.traseu = (char *)malloc(strlen(trasee[nr].nume) + 1); //aloc memorie pentru numele traseului 

            if (c.traseu == NULL)
            {
                printf("alocarea a esuat\n");
                exit(1);
            }
            strcpy(c.traseu, trasee[nr].nume);

            c.experienta = concurent->candidat.experienta;
            //introduc participantul in heap
            insertheap(heap, c);

            free(concurent);
            nr++;  //trec la urmatorul traseu
        }
    }

    //scriu informatiile despre participanti in fisier
    for (i = 0; i < heap->size; i++)
    {
        fprintf(fw, "%s - %s (%.2f)\n", heap->vec[i].traseu, heap->vec[i].nume, heap->vec[i].experienta);
    }


}
