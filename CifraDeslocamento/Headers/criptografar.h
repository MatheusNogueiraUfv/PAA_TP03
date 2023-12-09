#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LetraFrequencia{
    char caractere;
    double frequencia;
}LetraFrequencia;

void Menu();
void Criptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave);
void Descriptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave);
void ExibirFrequencias(FILE *ArquivoSaida,int flag);
void ReiniciarLeitura(FILE *ArquivoEntrada, FILE *ArquivoSaida);
void EncontrarChaveAleatoria(double VetorFrequencias[26],int flag);
int compararFrequencias(const void *a, const void *b);