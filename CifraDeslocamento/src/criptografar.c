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
        //Chave até 26
        chave = rand() % 26;
        printf("O que deseja fazer?\n");
        printf("[1] Criptografar\n");
        printf("[2] Descriptografar\n");
        scanf("%d",&resposta);
        if(resposta==1){
            Criptografar(inputFile, outputFile, chave);
        }else if(resposta==2){
            Descriptografar(inputFile, outputFile, chave);
        }
        ReiniciarLeitura(inputFile,outputFile);
        fclose(outputFile);
        outputFile = fopen(saida, "r");
        ExibirFrequencias(outputFile,inputFile);

        printf("Chave aleatoria gerada: %d\n", chave);
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
            caractereCriptografado = caractere;
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
            caractereDescriptografado = caractere;
        }
        fputc(caractereDescriptografado, ArquivoSaida);
        putchar(caractereDescriptografado);
    }
    ReiniciarLeitura(ArquivoEntrada, ArquivoSaida);
}


void ExibirFrequencias(FILE *ArquivoSaida,FILE *ArquivoEntrada) {
    int *frequencias = (int*)malloc(26 * sizeof(int)),totalCaracteres = 0,flag = 0,frequenciasEntrada[26];
    char caractere,caractereVetor,caractereArquivo;
    double VetorFrequencias[26];

    for(int i = 0;i<26;i++){

        frequencias[i] = 0;
        VetorFrequencias[i] = 0.0;
    
    }

    while ((caractere = fgetc(ArquivoSaida)) != EOF) {
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
        VetorFrequencias[i] =(double)(percentual / 100.0); 
    }
    
    EncontrarChave(VetorFrequencias); 
}

void ReiniciarLeitura(FILE *ArquivoEntrada, FILE *ArquivoSaida){
    fseek(ArquivoSaida, 0, SEEK_SET);
    fseek(ArquivoEntrada, 0, SEEK_SET);
}

int presenteVetor(int Vetor[26], int valor) {
    for (int i = 0; i < 26; i++) {
        if (Vetor[i] == valor) {
            return 0;
        }
    }
    return 1;
}

void EncontrarChave(double VetorFrequencias[26]) {
    double VetorPesos[] = {
        0.1463, 0.0104, 0.0388, 0.0499, 0.1257, 0.0102, 0.0130, 0.0128, 0.0618, 0.0040,
        0.0002, 0.0278, 0.0474, 0.0505, 0.1073, 0.0252, 0.0120, 0.0653, 0.0781, 0.0434,
        0.0463, 0.0167, 0.0001, 0.0021, 0.0001, 0.0047
    };

    int PMax1[26], PMAX2[26], control = 0, AUXP, AUXP2 = 0, MaiorChave = 0;

    for (int i = 0; i < 26; i++) {
        //printf("[%lf] [%lf]\n", VetorPesos[i], VetorFrequencias[i]);
        PMax1[i] = 0;
        PMAX2[i] = 0;
    }

    while (control != 26) {
        double flag = -1.0, flag2 = -1.0;

        for (int i = 0; i < 26; i++) {
            if (VetorFrequencias[i] > flag && presenteVetor(PMax1, i) == 1) {
                flag = VetorFrequencias[i];
                AUXP = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (VetorPesos[i] > flag2 && presenteVetor(PMAX2, i) == 1) {
                flag2 = VetorPesos[i];
                AUXP2 = i;
            }
        }

        int diferenca = ('a' + AUXP) - ('a' + AUXP2);

        if (diferenca < 0 && (-1 * diferenca) > MaiorChave) {
            MaiorChave = (-1 * diferenca);
        } else if (diferenca > MaiorChave) {
            MaiorChave = diferenca;
        }

        PMax1[AUXP] = 1;
        PMAX2[AUXP2] = 1;

        control += 1;
    }

    printf("Chave Chute: %d\n", MaiorChave == 0 ? 1 : MaiorChave);
}