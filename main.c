#include "programas.h"


int main(){
    Ram *ram = iniciaRam();
    CPU *cpu = iniciaCPU();

    programaMult(ram, cpu, 20, 4);
    //programaSomaMatriz(ram, cpu, 3);
    //programaFat(ram, cpu, 10);
    //programaDiv(ram, cpu, 16, 2);
    
    //programaSoma(ram, cpu, 2, 6);
    //programaSub(ram, cpu, 2, 2);

    //programaFatorialDuplo(ram, cpu, 8);
    //programaPA(ram, cpu, 1, 2, 10);
    //programaFibonacci(ram, cpu, 10);
    //programaExpo(ram, cpu, 3, 3);

    liberaCPU(cpu);
    liberaRam(ram);
    return 0;
}

