#ifndef instrucao_h
#define instrucao_h

typedef struct Instrucao {
    int add1;
    int add2;
    int add3;
    int opcode;
}Instrucao;

Instrucao defineInstrucao(int opcode, int add1, int add2, int add3);
#endif