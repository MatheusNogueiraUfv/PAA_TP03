#include <stdio.h>
#include "kmp.h"

int main() {
    FILE *arquivo;
    char nomeArquivo[100], padrao[100], texto[1000];

    printf("Digite o nome do arquivo (com extensao .txt): ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o padrao que deseja buscar: ");
    scanf("%s", padrao);

    fgets(texto, sizeof(texto), arquivo);
    
    // Medição do tempo de execução
    clock_t inicio = clock();

    int resultado = kmpBusca(texto, padrao);

    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;


    if (resultado != -1) {
        printf("Padrao encontrado na posicao %d.\n", resultado);
    } else {
        printf("Padrao nao encontrado no texto.\n");
    }

    fclose(arquivo);

    return 0;
}
