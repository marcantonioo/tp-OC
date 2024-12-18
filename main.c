#include "programas.h"


int main(){
    Ram *ram = iniciaRam();
    CPU *cpu = iniciaCPU();

    //programaMult(cpu, -20, -1);
    //programaSomaMatriz(cpu, 3);
    //programaFat(cpu, 4);
    //programaDiv(cpu, 16, 2);
    
    //programaSoma(cpu, 2, 6);
    //programaSub(cpu, 2, 2);

    //programaFatorialDuplo(cpu, 8); 
    //programaPA(cpu, 0, 2, 10);
    //programaFibonacci(cpu, 10);
    //programaExpo(cpu, 2, 3);
    //programaRaiz(cpu, 15);
    //programaBhaskara(cpu, 1, -5, 6);  //1, -6, 9;   1, -5, 6
    //cels_kelv (cpu, 2, 273);
    //programaDistancia(cpu, 1, 9, 1, 9);

    liberaCPU(cpu);
    liberaRam(ram);
    return 0;
}

