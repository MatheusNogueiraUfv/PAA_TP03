#include "menu.h"

void menu()
{
    int opcaoDesenvolvimento;
    char arqTexto[50], arqEntrada[70], padrao[50];


    printf("Insira qual método deseja seguir:\n");
    printf(" 1 - Arquivo\n");
    printf(" 2 - Interativo\n");
    printf(" 3 - Sair");
    scanf("%d", &opcaoDesenvolvimento);

    while(opcaoDesenvolvimento != 3){
        switch (opcaoDesenvolvimento)
        {
        case 1:
            
            break;
        
        case 2:
            printf("Insira o nome do arquivo que será lido (precisa estar na pasta Textos)\n");
            scanf("%s", arqTexto);

            snprintf(arqEntrada, sizeof(arqEntrada), "Textos/%s", arqTexto);

            printf("Insira o padrao que será pesquisado:\n");
            scanf("%s", padrao);

            menu2(arqEntrada, padrao);

            break;

        default:
            break;
        }
    }

}

void menu2(const char *arqEntrada, char *padrao)
{
    int opcaoAlgoritmo;

    FILE *arquivo = fopen(arqEntrada, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    printf("Insira qual algoritmo será utilizado:\n");
    printf(" 1 - Forca Bruta\n");
    printf(" 2 - KMP\n");
    scanf("%d", &opcaoAlgoritmo);

    if(opcaoAlgoritmo == 1){

        printf("\nForca Bruta escolhido:\n\n");

        // Ler o conteúdo do arquivo
        fseek(arquivo, 0, SEEK_END);
        long tamanho = ftell(arquivo);
        fseek(arquivo, 0, SEEK_SET);

        char texto[tamanho + 1];
        fread(texto, 1, tamanho, arquivo);
        texto[tamanho] = '\0'; // Adicionar o terminador nulo

        // Fechar o arquivo após a leitura
        fclose(arquivo);

        // Realizar a busca força bruta e medir o tempo
        clock_t inicio = clock();
        buscarForcaBruta(texto, padrao);
        clock_t fim = clock();
        double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    
    }else if(opcaoAlgoritmo == 2){

        printf("\n KMP escolhido:\n\n");

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
    
    }else{
        printf("Opcao invalida!\n");
    }

}