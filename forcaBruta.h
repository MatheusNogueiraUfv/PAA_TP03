#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *caracteresTEXTO;
    long int tamTEXTO;
}TEXTO;

typedef struct{
    char *palavraPADRAO;
    int qtdOcorrenciaPADRAO;
    int *ocorrenciasPADRAO;
    int tamPADRAO;
}PADRAO;

int forcaBruta(TEXTO *text, PADRAO *padrao);
TEXTO *lerTexto(const char *nomeARQ);

void calcTAM_TEXTO(TEXTO *text, FILE *arq);