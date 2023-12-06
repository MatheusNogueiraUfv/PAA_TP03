#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu();
void Criptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave);
void Descriptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave);
void ExibirFrequencias(FILE *ArquivoSaida,FILE *ArquivoEntrada);
void ReiniciarLeitura(FILE *ArquivoEntrada, FILE *ArquivoSaida);
void EncontrarChaveComparacao(FILE *ArquivoEntrada, FILE *ArquivoSaida);
void EncontrarChave(double VetorFrequencias[26]);
int presenteVetor(int Vetor[26],int i);