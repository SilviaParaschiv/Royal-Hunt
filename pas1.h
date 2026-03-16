#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PAS1_H
#define PAS1_H
#include "coada.h"
statutsocial modifstatutsocial(char *c);
char *modificanume(char *c);
void citeste(FILE *f, queue *coada);
void scrie(FILE *fw, queue *coada);
#endif