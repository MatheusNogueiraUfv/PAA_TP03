#include "kmp.h"

int main() {
    char nomeArquivo[100];
    char padrao[100];

    // Solicitar o nome do arquivo e padrão ao usuário
    printf("Digite o nome do arquivo de texto: ");
    scanf("%s", nomeArquivo);

    printf("Digite o padrao a ser buscado: ");
    scanf("%s", padrao);

    // Abrir o arquivo
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
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

    // Realizar a busca KMP e medir o tempo
    clock_t inicio = clock();
    buscarKMP(texto, padrao);
    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}