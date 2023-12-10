#include "kmp.h"

// Função para preencher o array lps (Longest Prefix Suffix)
void preencherLPS(char *padrao, int M, int *lps) {
    int len = 0; // Comprimento do prefixo atualmente igual ao sufixo

    lps[0] = 0; // Caso base

    int i = 1;
    while (i < M) {
        if (padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Função principal para realizar a busca KMP
void buscarKMP(char *texto, char *padrao) {
    int M = strlen(padrao);
    int N = strlen(texto);
    int contador = 0;

    // Criar e preencher o array LPS
    int lps[M];
    preencherLPS(padrao, M, lps);

    int i = 0; // Índice para o texto
    int j = 0; // Índice para o padrão

    while (i < N) {
        if (padrao[j] == texto[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("\n\t %sPadrao encontrado na posicao%s %d\n", MAGENTA, RESET, i - j);
            contador++;
            j = lps[j - 1];
        } else if (i < N && padrao[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    printf("\n\n\t %sPadrao encontrado %s%d %svezes%s", MAGENTA, GREEN, contador, MAGENTA, RESET);
}
