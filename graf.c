#include "graf.h"
Graph *creategraf(FILE *f)
{ // creare graf folosind liste de adiacenta
    int i, j, exista, val1, val2;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
    {
        printf(" Nu exista memorie pt graf! ");
        return NULL;
    }
    g->V = 11;
    g->a = (Node **)malloc(g->V * sizeof(Node *));
    if (g->a == NULL)
    {
        printf(" Nu exista memorie pt matrice! ");
        free(g);
        return NULL;
    }
    for (int i = 0; i < g->V; i++)
        g->a[i] = NULL;
    g->E = 0;
    while (fscanf(f, "%d %d", &val1, &val2) == 2)
    {
        // creez un nod pentru a adauga varful val2 la lista de adiacenta a lui val1
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->vertex_no = val2;
        newnode->next = g->a[val1]; // Leagă nodul la capătul listei de adiacență a vârfului val1
        g->a[val1] = newnode;       // Se actualizează lista de adiacență pentru val1, punând noul nod la începutul listei
        g->E++;                     // cresc numarul de muchii
    }

    return g;
}

void sorteaza(int **matrice, int poz, int nrtraseu)
{

    int i, j, l;
    // parcurg matricea
    for (i = 0; i < nrtraseu - 1; i++)
    {
        for (j = i + 1; j < nrtraseu; j++)
        {
            int k = 0;
            while (k < 4 && matrice[i][k] == matrice[j][k]) // compar fiecare element al celor 2 linii
                k++;                                        // retin pozitia la care valorile nu mai sunt egale
            if (k < 4 && matrice[i][k] > matrice[j][k])     // daca nu sunt ordonate
                for (l = 0; l < 4; l++)
                {
                    int aux = matrice[i][l];
                    matrice[i][l] = matrice[j][l];
                    matrice[j][l] = aux;
                    // interschimb liniile element cu element
                }
        }
    }
}

// afisez matricea conform cerintei
void afisare(int **matrice, int nr, FILE *f, int nrtraseu)
{
    int k, i;

    for (i = 0; i < nr; i++)
    {
        fprintf(f, "T%d: ", i + 1);
        for (int j = 0; j < nrtraseu; j++)
        {

            fprintf(f, "%d ", matrice[i][j]);
        }
        fprintf(f, "\n");
    }
}

void DFS_scan(Graph *g, int **matrice, int *cale, int poz, int nod, int gradintrare[], int gradiesire[], int *vizitat, FILE *f, int *nrtraseu)
{
    vizitat[nod] = 1; // marchez nodul ca vizitat
    cale[poz] = nod;  // retin nodul in vectorul cale care va contine la final traseul
    poz++;
    int i;

    if (gradiesire[nod] == 0)
    {
        for (i = 0; i < poz; i++)
            matrice[*nrtraseu][i] = cale[i];
        (*nrtraseu)++;
        // daca nodul are gradul de iesire 0 adaug traseul stocat in vectorul cale in matrice si cresc nrtraseu(=al catalea traseu e)
    }

    Node *p = g->a[nod]; // parcurg lista aferenta nodului tocmai procesat
    while (p != NULL)
    {
        if (vizitat[p->vertex_no] == 0)                                                                   // daca gasesc un nod neprocesat
            DFS_scan(g, matrice, cale, poz, p->vertex_no, gradintrare, gradiesire, vizitat, f, nrtraseu); // il procesez
        p = p->next;                                                                                      // dupa care trec la urmatorul varf din lista
    }
    vizitat[nod] = 0; // il fac nevizitat pentru a fi luat in considerare la celelalte trasee
}

void nrtraseegenerate(Graph *g, int gradintrare[], int gradiesire[], FILE *f)
{
    int i;
    int nrtraseu = 0;                                // pentru a memora nr total de trasee gasite
    int *cale = (int *)malloc(11 * sizeof(int));     // aloc vectorul cale pentru a retine drumul curent in timpul dfs
    int *vizitat = (int *)calloc(g->V, sizeof(int)); // aloc vectorul vizitat pentru a tine evidenta nodurilor vizitate
    // aloc dinamic matricea pentru a salva traseele
    int **matrice = (int **)malloc(11 * sizeof(int *));
    for (i = 0; i < 11; i++)
        matrice[i] = (int *)malloc(11 * sizeof(int));

    for (i = 0; i < g->V; i++)
    {
        if (gradintrare[i] == 0) // daca gradul de intrare e 0 fac parcurgere dfs pentru a construi traseele
        {
            DFS_scan(g, matrice, cale, 0, i, gradintrare, gradiesire, vizitat, f, &nrtraseu);
        }
    }
    sorteaza(matrice, 4, nrtraseu); // sortez matricea si o afisez
    afisare(matrice, nrtraseu, f, 4);

    // eliberez memoria alocata dinamic
    for (i = 0; i < 11; i++)
        free(matrice[i]);
    free(matrice);
    free(cale);
    free(vizitat);
}
void freegraf(Graph *g)
{
    int i;
    for (i = 0; i < g->V; i++)
    {
        Node *p = g->a[i];
        while (p != NULL)
        {
            Node *next = p->next;
            free(p);
            p = next;
        }
    }
    free(g->a);
    free(g);
}