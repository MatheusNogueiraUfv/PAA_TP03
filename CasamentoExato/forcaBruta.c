#include "forcaBruta.h"

void forcaBruta(const char *texto, const char *padrao) {
    int tamanhoTexto = strlen(texto);
    int tamanhoPadrao = strlen(padrao);
    int contador = 0;

    for (int i = 0; i <= tamanhoTexto - tamanhoPadrao; ++i) {
        int j;
        for (j = 0; j < tamanhoPadrao; ++j) {
            if (texto[i + j] != padrao[j])
                break;
        }
        if (j == tamanhoPadrao) {
            printf("\n\t %sPadrao encontrado na posicao%s %d\n", CYAN, RESET, i);
            contador++;
        }
    }

    printf("\n\n\t %sPadrao encontrado %s%d %svezes%s", CYAN, GREEN, contador, CYAN, RESET);
}