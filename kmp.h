#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void preProcessamento(char *padrao, int m, int *prefixo);
int kmpBusca(char *texto, char *padrao);

#endif


