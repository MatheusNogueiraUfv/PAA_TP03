#include "../Headers/criptografar.h"

//A cifra de deslocamento é o processo em que  cada letra no texto é deslocada por um 
//número fixo de posições para a direita no alfabeto,caso o número for negativo o deslocamento é 
//feito para a esquerda.

void Menu(){
    FILE *inputFile;
    FILE *outputFile;
    int chave,resposta;
    const char entrada[30],saida[30];
    printf("Digite o arquivo de entrada: \n");
    scanf("%s",&entrada);

    //Pegar a quebra de linha
    getchar();

    printf("Digite o arquivo de saida: \n");
    scanf("%s",&saida);

    //Pegar a quebra de linha
    getchar();

    printf("[1] Digitar uma propria chave\n");
    printf("[2] Usar chave aleatoria\n");
    scanf("%d",&resposta);

    inputFile = fopen(entrada, "r");
    outputFile = fopen(saida, "w");

    if(resposta==1){
        printf("Entre com uma chave: \n");
        scanf("%d", &chave);
        printf("O que deseja fazer?\n");
        printf("[1] Criptografar\n");
        printf("[2] Descriptografar\n");
        scanf("%d",&resposta);
        if(resposta==1){
            Criptografar(inputFile, outputFile, chave);

        }else if(resposta==2){
            Descriptografar(inputFile, outputFile, chave);
        }
    }else if(resposta==2){
        //Gerar de -26 até 26
        chave = rand() % 26;
        printf("Chave aleatoria gerada: %d\n", chave);
        printf("O que deseja fazer?\n");
        printf("[1] Criptografar\n");
        printf("[2] Descriptografar\n");
        scanf("%d",&resposta);
        if(resposta==1){
            Criptografar(inputFile, outputFile, chave);
        }else if(resposta==2){
            Descriptografar(inputFile, outputFile, chave);
        }
        fclose(outputFile);
        outputFile = fopen(saida, "r");
        ExibirFrequencias(outputFile);
        EncontrarChaveGerada(inputFile,outputFile);
    }else{
        printf("Opção inválida!\n");
        printf("Encerrando execução....");
        exit(1);
    }
    fclose(inputFile);
    fclose(outputFile);

}
void Criptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave) {
    char caractere;
    while ((caractere = fgetc(ArquivoEntrada)) != EOF) {
        char caractereCriptografado;
        if (caractere >= 'A' && caractere <= 'Z') {
            caractereCriptografado = (caractere + chave - 'A' + 26) % 26 + 'A';
        } else if (caractere >= 'a' && caractere <= 'z') {
            caractereCriptografado = (caractere + chave - 'a' + 26) % 26 + 'a';
        } else {
            caractereCriptografado = caractere;  // Manter caracteres que não são letras
        }
        fputc(caractereCriptografado, ArquivoSaida);
        putchar(caractereCriptografado);
    }
    ReiniciarLeitura(ArquivoEntrada, ArquivoSaida);
}

void Descriptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave) {
    char caractere;
    while ((caractere = fgetc(ArquivoEntrada)) != EOF) {
        char caractereDescriptografado;
        if (caractere >= 'A' && caractere <= 'Z') {
            caractereDescriptografado = (caractere - chave - 'A' + 26) % 26 + 'A';
        } else if (caractere >= 'a' && caractere <= 'z') {
            caractereDescriptografado = (caractere - chave - 'a' + 26) % 26 + 'a';
        } else {
            caractereDescriptografado = caractere;  // Manter caracteres que não são letras
        }
        fputc(caractereDescriptografado, ArquivoSaida);
        putchar(caractereDescriptografado);
    }
    ReiniciarLeitura(ArquivoEntrada, ArquivoSaida);
}


void ExibirFrequencias(FILE *ArquivoEntrada) {
    int frequencias[26];
    char caractere;
    int totalCaracteres = 0;
    for(int i = 0;i<26;i++){
        frequencias[i] = 0;
    }
    while ((caractere = fgetc(ArquivoEntrada)) != EOF) {
        if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')) {
            totalCaracteres+=1;
            if (caractere >= 'A' && caractere <= 'Z') {
                frequencias[caractere - 'A']+=1;
            } else if(caractere >= 'a' && caractere <= 'z'){
                frequencias[caractere - 'a']+=1;
            }
        }
    }

    printf("\nTabela de Frequencias:\n");
    printf("Caractere  |  Frequencia  |  Percentual\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < 26; i++) {
        char caractereAtual = 'A' + i;
        int frequenciaAtual = frequencias[i];
        double percentual = (frequenciaAtual / (double)totalCaracteres) * 100;

        printf("    %c      |      %d      |     %.2lf%%\n", caractereAtual, frequenciaAtual, percentual);
    }

    printf("\n");
}

void ReiniciarLeitura(FILE *ArquivoEntrada, FILE *ArquivoSaida){
    fseek(ArquivoSaida, 0, SEEK_SET);
    fseek(ArquivoEntrada, 0, SEEK_SET);
}
void EncontrarChaveGerada(FILE *ArquivoEntrada, FILE *ArquivoSaida) {
    ReiniciarLeitura(ArquivoEntrada,ArquivoSaida);
    char caractereOriginal, caractereCifrado;
    int chaveAdivinhada = 0,diferenca;

    while ((caractereOriginal = fgetc(ArquivoEntrada)) != EOF && (caractereCifrado = fgetc(ArquivoSaida)) != EOF) {
        if((int)caractereOriginal>(int)caractereCifrado){
            if(((int)caractereOriginal - (int)caractereCifrado)>diferenca){
                diferenca = caractereOriginal - caractereCifrado;
            }
        }else if((int)caractereOriginal<(int)caractereCifrado){
            if(((int)caractereCifrado - (int)caractereOriginal)>diferenca){
                diferenca = caractereCifrado - caractereOriginal;
            }
        }
        printf("Diferenca: %d \n",diferenca);
        printf("CA: %d C1: %d| C2: %d\n",chaveAdivinhada, (int)caractereOriginal, (int)caractereCifrado);
        chaveAdivinhada = diferenca;
    }
    printf("Chave Adivinhada: %d\n", chaveAdivinhada);
    ReiniciarLeitura(ArquivoEntrada,ArquivoSaida);
}