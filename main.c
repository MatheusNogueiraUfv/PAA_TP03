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

    ResultadoKMP resultado = kmpBusca(texto, padrao);

    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    if (resultado.quantidade > 0) {
        printf("Padrao encontrado em %d posicoes:\n", resultado.quantidade);
        for (int i = 0; i < resultado.quantidade; i++) {
            printf("Posicao %d: %d\n", i + 1, resultado.posicoes[i]);
        }
    } else {
        printf("Padrao nao encontrado no texto.\n");
    }

    // Libere a memória alocada
    free(resultado.posicoes);

    fclose(arquivo);

    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}

