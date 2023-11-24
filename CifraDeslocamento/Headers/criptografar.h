#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu();
void Criptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave);
void Descriptografar(FILE *ArquivoEntrada, FILE *ArquivoSaida, int chave);
void ExibirFrequencias(FILE *ArquivoEntrada);
void ReiniciarLeitura(FILE *ArquivoEntrada, FILE *ArquivoSaida);
void EncontrarChaveGerada(FILE *ArquivoEntrada, FILE *ArquivoSaida);