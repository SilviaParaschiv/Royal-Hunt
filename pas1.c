#include "pas1.h"

statutsocial modifstatutsocial(char *c)
{
    int i;
    char s[50];
    strcpy(s, c);//copiaza statutul intr-un sir auxiliar
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    } //transforma toatele literele in litere mari
    if (strcmp(s, "LORD") == 0)
        return LORD;
    if (strcmp(s, "AVENTURIER") == 0)
        return AVENTURIER;
    if (strcmp(s, "CAVALER") == 0)
        return CAVALER;
    //compara cu valorile posibile pe care le poate avea statutul si returneaza enumul corespunzator
}

char *modificanume(char *c)
{
    char *final = (char *)malloc((strlen(c) + 1) * sizeof(char));//aloc memorie pentru sirul final care va contine numele modificat
    final[0] = '\0';//initializez sirul cu un sir gol
    char *aux = (char *)malloc(strlen(c) + 1);//iau un sir auxiliar in care fac o copie pentru sirul c pentru a nu modifica direct sirul original
    if (aux == NULL)
    {
        printf("eroare\n");
        return NULL;
    }
    strcpy(aux, c);
    char *p = strtok(aux, " ");//stochez in p primul cuvant din nume
    int i;
    while (p)
    {
        if (p[0] >= 'a' && p[0] <= 'z')
            p[0] = p[0] - 32;  //fac prima litera mare
        for (i = 1; i < strlen(p); i++)
            if (p[i] >= 'A' && p[i] <= 'Z')
                p[i] = p[i] + 32; //fac celelalte litere mici, mai putin prima
        strcat(final, p);//copiez numele modificat in sirul final 
        p = strtok(NULL, " "); //scot celalalt nume daca exista 
        if (p)
            strcat(final, "-");//adaug - intre nume
    }
    free(aux);
    return final;
}

void citeste(FILE *f, queue *coada)
{

    char *date = (char *)malloc(265 * sizeof(char));//aloc memorie pentru un sir care va contine fiecare linie din fisier
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
        if (sscanf(punct + 1, "%f;%d", &experienta, &varsta) != 2)//extrage experienta si varsta
        {
            free(statut2);
            free(nume);
            continue;
        } // daca nu citeste corect experienta si varsta trece la urmatoarea linie
        statutsocial statutnou = modifstatutsocial(statut2);
        char *numenou = modificanume(nume);
       //crearea participantului conform regulilor din cerinta si adaugarea lui in coada
        participant nou;
        nou.nume = numenou;
        nou.experienta = experienta;
        nou.varsta = varsta;
        nou.statut = statutnou;

        enqueue(coada, nou);
        free(statut2);
        free(nume);
    }

    free(date);
}

void scrie(FILE *fw, queue *q)
{
    node *aux;
    fprintf(fw, "Nume Experienta Varsta Statut_social \n");
    aux = q->front;
    //se parcurge coada si se scriu datele fiecarui participant
    while (aux != NULL)
    {
        fprintf(fw, "%s %.2f %d ", aux->candidat.nume, aux->candidat.experienta, aux->candidat.varsta);
        if (aux->candidat.statut == LORD)
            fprintf(fw, "LORD\n");
        if (aux->candidat.statut == AVENTURIER)
            fprintf(fw, "AVENTURIER\n");
        if (aux->candidat.statut == CAVALER)
            fprintf(fw, "CAVALER\n");
 
        aux = aux->next;
    }

}
