#include "forcaBruta.h"
#include "kmp.h"
#include "cores.h"
#include <ctype.h>
#include <time.h>


void realizarForcaBruta(const char *arqEntrada, char *padrao);
void realizarKMP(const char *arqEntrada, char *padrao);

void textoMinusculo(char *texto);