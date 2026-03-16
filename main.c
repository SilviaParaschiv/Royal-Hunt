#include "pas1.h"
#include "pas2.h"
#include "pas3.h"
#include "pas4.h"
#include "pas5.h"
#include "pas6.h"
#include "graf.h"
int main()
{
	// pas1

	queue *q;
	q = create();
	if (q == NULL)
	{
		printf("eroare");
		return 1;
	}
	FILE *f = fopen("./Pas_1/candidati.csv", "r");
	if (f == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	citeste(f, q);
	fclose(f);
	FILE *fw = fopen("./Pas_1/test_1.csv", "w");
	if (fw == NULL)
	{
		printf("eroare\n");
		exit(1);
	}

	scrie(fw, q);
	fclose(fw);

	// Pas 2

	FILE *fr22 = fopen("Pas_2/test_2_cavaleri_aventurieri.csv", "w");
	if (fr22 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	FILE *fr21 = fopen("Pas_2/test_2_lorzi.csv", "w");
	if (fr21 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	nodbst *bstlorzi = NULL;
	nodbst *bstca = NULL;
	organizarecandidati(q, fr21, fr22, &bstlorzi, &bstca);
	fclose(fr21);
	fclose(fr22);

	// pas3

	FILE *f3 = fopen("./Pas_3/contestatii.csv", "r");
	if (f3 == NULL)
	{
		printf("eroare1\n");
		exit(1);
	}

	citestecontestatii(f3, &bstlorzi);

	FILE *f3w = fopen("./Pas_3/test_3_lorzi.csv", "w");
	if (f3w == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	fprintf(f3w, "Nume Experienta Varsta Statut_social");
	scriebst(bstlorzi, f3w);

	fclose(f3w);
	fclose(f3);

	// pas4

	FILE *f4 = fopen("./Pas_4/trasee.csv", "r");
	if (f4 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	Heap *heap = createheap(8);

	FILE *f4w = fopen("./Pas_4/test_4.csv", "w");
	if (f4w == NULL)
	{
		printf("eroare\n");
		exit(1);
	}

	fprintf(f4w, "Nume_Traseu - Nume_Participant (Experienta_participant)\n");
	asignaretrasee(&bstlorzi, &bstca, f4, f4w, heap);
	fclose(f4);
	fclose(f4w);

	// pas5

	FILE *f5 = fopen("./Pas_4/trasee.csv", "r");
	if (f5 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}

	traseu trasee[8];
	int nrtrasee = citestetraseu(f5, trasee);

	FILE *f5w = fopen("./Pas_5/test_5.csv", "w");
	if (f5w == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	fprintf(f5w, "Nume_Traseu - Nume_Participant (Experienta_participant)\n");

	actualizareexperienta(heap, trasee, nrtrasee, f5w);

	freebst(bstlorzi);
	freebst(bstca);
	fclose(f5);
	fclose(f5w);

	// pas 6

	FILE *f6 = fopen("./Pas_6/test_6.csv", "w");
	if (f6 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}
	fprintf(f6, "Nume Experienta_totala\n");
	printHeap(heap, f6);
	fclose(f6);

	// pas 7

	FILE *f7 = fopen("./Pas_7/drumuri.csv", "r");
	if (f7 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}

	Graph *g = creategraf(f7);

	int gradintrare[g->V];
	int gradiesire[g->V];

	for (int i = 0; i < g->V; i++)
	{
		gradintrare[i] = 0;
		gradiesire[i] = 0;
	}

	int val1, val2;

	FILE *f72 = fopen("./Pas_7/drumuri.csv", "r");
	if (f72 == NULL)
	{
		printf("eroare\n");
		exit(1);
	}

	while (fscanf(f72, "%d %d", &val1, &val2) == 2)
	{
		gradintrare[val2]++;
		gradiesire[val1]++;
	}

	FILE *f7w = fopen("./Pas_7/test_7.csv", "w");
	if (f7w == NULL)
	{
		printf("eroare\n");
		exit(1);
	}

	nrtraseegenerate(g, gradintrare, gradiesire, f7w);
	fclose(f7);
	fclose(f72);
	fclose(f7w);

	freegraf(g);
	deleteheap(&heap);
	freecoada(q);
	return 0;
}