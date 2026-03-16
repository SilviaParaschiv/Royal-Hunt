#include "pas2.h"

void organizarecandidati(queue *q, FILE *fr21, FILE *fr22, nodbst **bst_lorzi, nodbst **bst_cavaleri_aventurieri)
{
    *bst_lorzi = NULL;
    *bst_cavaleri_aventurieri = NULL;
    //initializam ambii arbori cu null

    while (!isEmpty(q))
    {
        //cat timp coada nu e nula scoatem cate un participant, daca e lord il inseram in bstlorzi, altfel in bstcavaleriaventurieri
        participant c = deQueue(q);

        if (c.statut == LORD)
            *bst_lorzi = insert(*bst_lorzi, c);
        else
            *bst_cavaleri_aventurieri = insert(*bst_cavaleri_aventurieri, c);
    }
//afisam arborii;
    fprintf(fr21, "Nume Experienta Varsta Statut_social");
    scriebst(*bst_lorzi, fr21);

    fprintf(fr22, "Nume Experienta Varsta Statut_social");
    scriebst(*bst_cavaleri_aventurieri, fr22);
}
