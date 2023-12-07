#include "forcaBruta.h"

int forcaBruta(TEXTO *text, PADRAO *padrao)
{
    int ocorrenciasEncontradas = 0;
    char *ocorrencia = strstr(text->caracteresTEXTO, padrao->palavraPADRAO);

    while (ocorrencia) {
        padrao->ocorrenciasPADRAO[ocorrenciasEncontradas++] = ocorrencia - text->caracteresTEXTO;
        ocorrencia = strstr(ocorrencia + 1, padrao->palavraPADRAO);
    }

    padrao->qtdOcorrenciaPADRAO = ocorrenciasEncontradas;

    return 1;
}

TEXTO *lerTexto(const char *nomeARQ)
{
    TEXTO *texto = (TEXTO *) malloc(sizeof(TEXTO));
    if (!texto) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo = fopen(nomeARQ, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    fseek(arquivo, 0, SEEK_END);
    texto->tamTEXTO = ftell(arquivo);
    rewind(arquivo);

    texto->caracteresTEXTO = (char *) malloc(texto->tamTEXTO + 1);
    if (!texto->caracteresTEXTO) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    fread(texto->caracteresTEXTO, sizeof(char), texto->tamTEXTO, arquivo);
    texto->caracteresTEXTO[texto->tamTEXTO] = '\0';

    fclose(arquivo);

    return texto;

}

void calcTAM_TEXTO(TEXTO *text, FILE *arq)
{
    int tam = 0, i = 0;

    while(fgetc(arq) != EOF){
        tam++;
    }
    text->tamTEXTO = tam;
    text->caracteresTEXTO = malloc(text->tamTEXTO * sizeof(char));
}