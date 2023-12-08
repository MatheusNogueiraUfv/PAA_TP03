#include "forcaBruta.h"

void forcaBruta(const char *texto, const char *padrao) {
    int tamanhoTexto = strlen(texto);
    int tamanhoPadrao = strlen(padrao);

    for (int i = 0; i <= tamanhoTexto - tamanhoPadrao; ++i) {
        int j;
        for (j = 0; j < tamanhoPadrao; ++j) {
            if (texto[i + j] != padrao[j])
                break;
        }
        if (j == tamanhoPadrao) {
            printf("Padrao encontrado na posicao %d\n", i);
        }
    }
}