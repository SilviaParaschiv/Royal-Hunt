#include "pas3.h"

void citestecontestatii(FILE *f, nodbst **bstlorzi)
{
    char *date = (char *)malloc(265 * sizeof(char));
    if (date == NULL)
    {
        printf("\nAlocare nereusita de memorie");
        exit(1);
    }
    if (fgets(date, 256, f) == NULL) // ignora prima linie din fisier
    {
        free(date);
        return;
    }
    // modific datele astfel incat sa respecte cerinta
    while (fgets(date, 256, f))
    {

        date[strcspn(date, "\n")] = '\0'; // elimina caracterul \n de la sf liniei
        char *spatiu = strchr(date, ' '); // cauta primul spatiu pt a extrage statutul social
        if (spatiu == NULL)
            continue;          // daca nu exista spatiu in linie o sare pt ca nu e valida
        int x = spatiu - date; // in x se retine pozitia primului spatiu
        char *statut2 = (char *)malloc((x + 1) * sizeof(char));
        strncpy(statut2, date, x); // copiaza primele x caractere in statut 2 adica statutul social
        statut2[x] = '\0';
        char *p = spatiu + 1;         // pointer la primul caracter din nume
        char *punct = strchr(p, ';'); // cauta sfarsitul numelui
        if (punct == NULL)
        {
            free(statut2);
            continue;
        } // daca nu exista ; sare la umatoarea linie
        int lungime = punct - p;                                   // lungimea numelui
        char *nume = (char *)malloc((lungime + 1) * sizeof(char)); // aloca memorie pt nume
        strncpy(nume, p, lungime);                                 // il copiaza
        nume[lungime] = '\0';
        float experienta;
        int varsta;
        if (sscanf(punct + 1, "%f;%d", &experienta, &varsta) != 2) // extrage experienta si varsta
        {
            free(statut2);
            free(nume);
            continue;
        } // daca nu citeste corect experienta si varsta trece la urmatoarea linie
        statutsocial statutnou = modifstatutsocial(statut2); // transform statutul
        char *numenou = modificanume(nume);                  // modific numele
        // creez participantul
        participant nou;
        nou.nume = numenou;
        nou.experienta = experienta;
        nou.varsta = varsta;
        nou.statut = statutnou;
        // sterg participantul pentru care s-a facut contestatie din arbore
        *bstlorzi = deleteNode(*bstlorzi, nou);

        free(statut2);
        free(nume);
        free(numenou);
    }
}