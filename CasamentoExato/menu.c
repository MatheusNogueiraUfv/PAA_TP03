#include "menu.h"

void menu()
{
    int opcaoDesenvolvimento, opcaoAlgoritmo,escolhaNovamente;
    char arqTexto[50], arqEntrada[70], padrao[50];
    FILE *arq;

    menu1();

    scanf("%d", &opcaoDesenvolvimento);

    while(opcaoDesenvolvimento != 3){
        switch (opcaoDesenvolvimento)
        {
            case 1:

                arq = fopen("Textos/ArquivoApresentacao.txt", "r");
                fscanf(arq, "%s", arqTexto);

                snprintf(arqEntrada, sizeof(arqEntrada), "Textos/%s", arqTexto);
                printf("\n\t %sArquivo a ser lido:%s %s", ORANGE, RESET, arqEntrada);

                fscanf(arq, "%s", padrao);
                textoMinusculo(padrao);
                printf("\n\t %sPadrao a ser procurado:%s %s\n",ORANGE, RESET, padrao);

                fscanf(arq, "%d", &opcaoAlgoritmo);

                if(opcaoAlgoritmo == 1){

                    printf("\n\t%s Algoritmo de Forca Bruta escolhido:%s\n\n", CYAN, RESET);

                    realizarForcaBruta(arqEntrada, padrao);

                }
                else if(opcaoAlgoritmo == 2){
                   
                    printf("\n\t%s Algoritmo de Knuth-Morris-Pratt escolhido:%s\n\n", MAGENTA, RESET);

                    realizarKMP(arqEntrada, padrao);

                }

                printf("\n\t%sDeseja realizar o processo novamente?%s\n\t", RED, RESET);
                printf("\n\t%s[1] - SIM %s||%s [2] - NAO %s\n\t ", GREEN, RESET, RED, RESET);

                scanf("%d", &escolhaNovamente);

                if(escolhaNovamente == 1){
                    menu1();
                    scanf("%d", &opcaoDesenvolvimento);
                }else{
                    opcaoDesenvolvimento = 3;
                }
                
                break;
            
            case 2:
                printf("\n\t%sInsira o nome do arquivo que será lido (precisa estar na pasta Textos):%s\n\t", GREEN, RESET);
                scanf("%s", arqTexto);

                snprintf(arqEntrada, sizeof(arqEntrada), "Textos/%s", arqTexto);

                printf("\n\t%sInsira o padrao que será pesquisado:%s\n\t", GREEN, RESET);
                scanf("%s", padrao);
                
                textoMinusculo(padrao);

                menu2(arqEntrada, padrao);

                printf("\n\t%sDeseja realizar o processo novamente?%s\n\t", RED, RESET);
                printf("\n\t%s[1] - SIM %s||%s [2] - NAO %s\n\t ", GREEN, RESET, RED, RESET);

                scanf("%d", &escolhaNovamente);

                if(escolhaNovamente == 1){
                    menu1();
                    scanf("%d", &opcaoDesenvolvimento);
                }else{
                    opcaoDesenvolvimento = 3;
                }

                break;

            default:
                break;
        }
    }

    printf("\n\n\t%sEncerrando o programa...%s\n\n", B_RED, RESET);

}

void menu2(const char *arqEntrada, char *padrao)
{
    int opcaoAlgoritmo;
    
    printf("\n\t%s+========================================+%s", BLUE, RESET);
    printf("\n\t%s| Insira qual algoritmo será utilizado:  |%s", BLUE, RESET);
    printf("\n\t%s| 1 - Forca Bruta                        |%s", BLUE, RESET);
    printf("\n\t%s| 2 - Knuth-Morris-Pratt                 |%s", BLUE, RESET);
    printf("\n\t%s+========================================+%s", BLUE, RESET);
    printf("\n\n\t");

    scanf("%d", &opcaoAlgoritmo);

    if(opcaoAlgoritmo == 1){

        printf("\n\t%s Algoritmo de Forca Bruta escolhido:%s\n\n", CYAN, RESET);

        realizarForcaBruta(arqEntrada, padrao);
    
    }else if(opcaoAlgoritmo == 2){

        printf("\n\t%s Algoritmo de Knuth-Morris-Pratt escolhido:%s\n\n", MAGENTA, RESET);

        realizarKMP(arqEntrada, padrao);
    
    }else{
        printf("\n\t%sOpcao invalida!%s\n\t", B_WHITE, RESET);
    }

}

void menu1()
{
    printf("\n\t%s+========================================+%s", YELLOW, RESET);
    printf("\n\t%s| Insira qual método deseja seguir:      |%s", YELLOW, RESET);
    printf("\n\t%s| 1 - Arquivo                            |%s", YELLOW, RESET);
    printf("\n\t%s| 2 - Interativo                         |%s", YELLOW, RESET);
    printf("\n\t%s| 3 - Sair                               |%s", YELLOW, RESET);
    printf("\n\t%s+========================================+%s", YELLOW, RESET);
    printf("\n\n\t");
}