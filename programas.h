#ifndef programas_h
#define programas_h

#include "CPU.h"

void cels_kelv (CPU *cpu, int t, int tK);

void programaMult(CPU *cpu, int multiplicando, int multiplicador);

void programaSomaMatriz(CPU *cpu, int cardinalidade);
int **criaMatriz(int tam);
void liberaMatriz(int **a, int tam);

void programaFat(CPU *cpu, int fat);

void programaDiv(CPU *cpu, int dividendo, int divisor);

void programaFatorialDuplo(CPU *cpu, int n);

void programaPA(CPU *cpu, int primeiroTermo, int razao, int numTermos);

void programaFibonacci(CPU *cpu, int n);

void programaExpo(CPU *cpu, int base, int expoente);

void programaSoma(CPU *cpu, int x, int y);

void programaSub(CPU *cpu, int x, int y);

void programaRaiz(CPU *cpu, int numero);

void programaBhaskara(CPU *cpu, int a, int b, int c);

#endif