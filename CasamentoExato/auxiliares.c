#include "auxiliares.h"


void realizarForcaBruta(const char *arqEntrada, char *padrao) {
    
    FILE *arquivo = fopen(arqEntrada, "r");

    if (arquivo == NULL) {
        perror("\n\tErro ao abrir o arquivo");
        return;
    }

    // Ler o conteúdo do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char texto[tamanho + 1];
    fread(texto, 1, tamanho, arquivo);
    texto[tamanho] = '\0'; // Adicionar o terminador nulo

    // Fechar o arquivo após a leitura
    fclose(arquivo);

    textoMinusculo(texto);

    // Realizar a busca força bruta e medir o tempo
    clock_t inicio = clock();
    forcaBruta(texto, padrao);
    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n\t %sTempo de execucao: %f segundos%s\n", CYAN, tempo_execucao, RESET);
}

void realizarKMP(const char *arqEntrada, char *padrao) {
    
    FILE *arquivo = fopen(arqEntrada, "r");

    if (arquivo == NULL) {
        perror("\n\tErro ao abrir o arquivo");
        return;
    }

    // Ler o conteúdo do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char texto[tamanho + 1];
    fread(texto, 1, tamanho, arquivo);
    texto[tamanho] = '\0'; // Adicionar o terminador nulo

    // Fechar o arquivo após a leitura
    fclose(arquivo);

    textoMinusculo(texto);

    // Realizar a busca KMP e medir o tempo
    clock_t inicio = clock();
    buscarKMP(texto, padrao);
    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n\t %sTempo de execucao: %f segundos%s\n", MAGENTA, tempo_execucao, RESET);
}

void textoMinusculo(char *texto)
{
    int i = 0;
    while (texto[i]) {
        texto[i] = tolower(texto[i]);
        i++;
    }
}