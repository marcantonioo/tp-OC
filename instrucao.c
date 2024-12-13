#include "instrucao.h"


Instrucao defineInstrucao(int opcode,int add1, int add2, int add3){
    Instrucao a;
    a.add1 = add1;
    a.add2 = add2;
    a.add3 = add3;
    a.opcode = opcode;
    return a;
}