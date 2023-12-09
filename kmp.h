#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "cores.h"


void preencherLPS(char *padrao, int M, int *lps);
void buscarKMP(char *texto, char *padrao);

void realizarKMP(const char *arqEntrada, char *padrao);

void textoMinusculo(char *texto);
