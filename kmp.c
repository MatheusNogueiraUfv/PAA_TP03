#include "kmp.h"

void preProcessamento(char *padrao, int m, int *prefixo) {
    int len = 0;
    prefixo[0] = 0; // O primeiro caractere não tem prefixo

    for (int i = 1; i < m;) {
        if (padrao[i] == padrao[len]) {
            len++;
            prefixo[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = prefixo[len - 1];
            } else {
                prefixo[i] = 0;
                i++;
            }
        }
    }
}

ResultadoKMP kmpBusca(char *texto, char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

    ResultadoKMP resultado;
    resultado.posicoes = NULL;
    resultado.quantidade = 0;

    // Caso padrão ou texto sejam vazios, não há correspondência
    if (n == 0 || m == 0) {
        return resultado;
    }

    // Criando o array para armazenar os valores de prefixo
    int prefixo[m];
    preProcessamento(padrao, m, prefixo);

    int i = 0; // Índice para o texto
    int j = 0; // Índice para o padrão

    while (i < n) {
        if (padrao[j] == texto[i]) {
            j++;
            i++;
        }

        if (j == m) {
            // Padrão encontrado, armazena a posição inicial
            resultado.quantidade++;
            resultado.posicoes = (int *)realloc(resultado.posicoes, resultado.quantidade * sizeof(int));
            resultado.posicoes[resultado.quantidade - 1] = i - j;

            // Continue a busca para encontrar todas as ocorrências
            j = prefixo[j - 1];
        } else if (i < n && padrao[j] != texto[i]) {
            if (j != 0) {
                j = prefixo[j - 1];
            } else {
                i++;
            }
        }
    }

    return resultado;
}
