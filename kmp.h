#ifndef KMP_H
#define KMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int *posicoes;
    int quantidade;
} ResultadoKMP;

void preProcessamento(char *padrao, int m, int *prefixo);
ResultadoKMP kmpBusca(char *texto, char *padrao);

#endif


