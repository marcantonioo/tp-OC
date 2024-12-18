#include "programas.h"

void cels_kelv (CPU *cpu, int t, int tK){
    Ram *ram = criaRamVazia(2);
    
    Instrucao* trecho1 = (Instrucao*) malloc(5 * sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, tK, -1);
    trecho1[1] = defineInstrucao(4, 2, t, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);

    Instrucao * trecho2 = (Instrucao*) malloc(2 * sizeof(Instrucao));
    trecho2[0] = defineInstrucao(0, 0, 1, 0);
    trecho2[1] = defineInstrucao(-1, -1, -1, -1);
    
    setPrograma(cpu, trecho2);
    iniciar(ram, cpu);
    
    printf("%d graus celsius em kelvin: %d\n", cpu->registrador2, cpu->registrador1);
    liberaRam(ram);

        //executar instrucao
		//-1 -> halt
		// 0 -> soma
		// 1 -> subtrai
		// 2 -> copia do registrador para RAM
		// 3 -> copia da RAM para o registrador
		// 4 -> salva conteudo externo no registrador
		// 5 -> obtem conteudo externo do registrador
}

void programaBhaskara(CPU *cpu, int a, int b, int c){
    Ram *ram = criaRamVazia(8);
    // ram[3] = -b; ram[4] = 2a; ram[5] = raiz(b^2-4ac); ram[6] = 4ac; ram[7] = b^2;
    Instrucao *trecho1 = malloc(7 * sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, a, -1);
    trecho1[1] = defineInstrucao(2, 1, 0, -1);
    trecho1[2] = defineInstrucao(4, 1, b, -1);
    trecho1[3] = defineInstrucao(2, 1, 1, -1);
    trecho1[4] = defineInstrucao(4, 1, c, -1);
    trecho1[5] = defineInstrucao(2, 1, 2, -1);
    trecho1[6] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);

    //definindo ram[3] = -b
    programaMult(cpu, -1, b);
    Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
    trecho2[0] = defineInstrucao(2, 1, 3, -1);
    trecho2[1] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho2);
    iniciar(ram, cpu);


    //definindo ram[4] = 2a
    programaMult(cpu, a, 2);
    Instrucao *trecho3 = malloc(2 * sizeof(Instrucao));
    trecho3[0] = defineInstrucao(2, 1, 4, -1);
    trecho3[1] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho3);
    iniciar(ram, cpu);

    //definindo ram[6] = 4ac
    programaMult(cpu, a, 4);
    programaMult(cpu, cpu->registrador1, c);
    Instrucao *trecho4 = malloc(2 * sizeof(Instrucao));
    trecho4[0] = defineInstrucao(2, 1, 6, -1);
    trecho4[1] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho4);
    iniciar(ram, cpu);

    //definindo ram[7] = b^2 e reg2 = 4ac
    programaExpo(cpu, b, 2);
    Instrucao *trecho5 = malloc(3 * sizeof(Instrucao));
    trecho5[0] = defineInstrucao(2, 1, 7, -1);
    trecho5[1] = defineInstrucao(3, 2, 6, -1);
    trecho5[2] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho5);
    iniciar(ram, cpu);
    
    //definindo ram[5] = raiz(b^2-4ac); e reg2 = -b
    programaSub(cpu, cpu->registrador1, cpu->registrador2);
    programaRaiz(cpu, cpu->registrador1);
    Instrucao *trecho6 = malloc(3 * sizeof(Instrucao));
    trecho6[0] = defineInstrucao(2, 1, 5, -1);
    trecho6[1] = defineInstrucao(3, 2, 3, -1);
    trecho6[2] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho6);
    iniciar(ram, cpu);

    programaSoma(cpu, cpu->registrador2, cpu->registrador1);
    //definindo reg2 = 2a
    Instrucao *trecho7 = malloc(2 * sizeof(Instrucao));
    trecho7[0] = defineInstrucao(3, 2, 4, -1);
    trecho7[1] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho7);
    iniciar(ram, cpu);

    programaDiv(cpu, cpu->registrador1, cpu->registrador2);
    int x1 = cpu->registrador1;  //+

    //definindo rag1 = -b e reg2 = raiz(b^2 - 4ac);
    Instrucao *trecho8 = malloc(3* sizeof(Instrucao));
    trecho8[0] = defineInstrucao(3, 1, 3, -1);
    trecho8[1] = defineInstrucao(3, 2, 5, -1);
    trecho8[2] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho8);
    iniciar(ram, cpu);

    programaSub(cpu, cpu->registrador1, cpu->registrador2);
    //definindo reg2 = 2a
    Instrucao *trecho9 = malloc(2 * sizeof(Instrucao));
    trecho9[0] = defineInstrucao(3, 2, 4, -1);
    trecho9[1] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho9);
    iniciar(ram, cpu);

    programaDiv(cpu, cpu->registrador1, cpu->registrador2);
    int x2 = cpu->registrador1; //-

    printf("Para a = %d, b = %d, c = %d. Obtemos x1 = %d e x2 = %d\n", a, b, c, x1, x2);
    liberaRam(ram);
} 

void programaRaiz(CPU *cpu, int numero) {
    Ram *ram = criaRamVazia(3);

    // Inicialização
    Instrucao *inicializa = malloc(7 * sizeof(Instrucao));
    inicializa[0] = defineInstrucao(4, 1, numero, -1); // Carrega o número no registrador1
    inicializa[1] = defineInstrucao(4, 2, 1, -1);     // Carrega 1 (primeiro número ímpar) no registrador2
    inicializa[2] = defineInstrucao(2, 1, 0, -1);
    inicializa[3] = defineInstrucao(2, 2, 1, -1);
    inicializa[4] = defineInstrucao(4, 1, 2, -1);
    inicializa[5] = defineInstrucao(2, 1, 2, -1);
    inicializa[6] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, inicializa);
    iniciar(ram, cpu);

    int cont = 0;
    // Loop para subtrair sucessivamente números ímpares
    while (cpu->registrador1 >= 0) { // Continua enquanto o número for >= 0

        Instrucao *atualiza = malloc(4 * sizeof(Instrucao));
        atualiza[0] = defineInstrucao(1, 0, 1, 0);
        atualiza[1] = defineInstrucao(0, 1, 2, 1);
        atualiza[2] = defineInstrucao(3, 1, 0, -1);
        atualiza[3] = defineInstrucao(-1, -1, -1, -1);

        setPrograma(cpu, atualiza);
        iniciar(ram, cpu);

        if (cpu->registrador1 >= 0) {
            cont++;
        }
    }

    Instrucao *trecho3 = malloc(2 * sizeof(Instrucao));
    trecho3[0] = defineInstrucao(4, 1, cont, -1);
    trecho3[1] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho3);
    iniciar(ram, cpu);

    printf("A raiz quadrada inteira de %d é: %d\n", numero, cpu->registrador1);
    liberaRam(ram);
}



void programaSub(CPU *cpu, int x, int y){

    Ram *ram = criaRamVazia(2);

    Instrucao *trecho1 = malloc(6*sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, x, -1);
    trecho1[1] = defineInstrucao(4, 2, y, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(1, 0, 1, 0);
    trecho1[5] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram ,cpu);

    printf("O resultado de %d - %d é: %d\n", x, y, cpu->registrador1);
    liberaRam(ram);
}

void programaSoma(CPU *cpu, int x, int y){

    Ram *ram = criaRamVazia(2);

    Instrucao *trecho1 = malloc(6*sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, x, -1);
    trecho1[1] = defineInstrucao(4, 2, y, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(0, 0, 1, 0);
    trecho1[5] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram ,cpu);

    printf("O resultado de %d + %d é: %d\n", x, y, cpu->registrador1);
    liberaRam(ram);
}



void programaExpo(CPU *cpu, int base, int expoente) {

    Ram *ram = criaRamVazia(2);

    Instrucao *trecho1 = malloc(5*sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, base, -1);
    trecho1[1] = defineInstrucao(4, 2, base, -1);
    trecho1[2] = defineInstrucao(2, 1, 0, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);


    for(int i = expoente-1; i>0; i--){
        programaMult(cpu, cpu->registrador1, cpu->registrador2);
        Instrucao *trecho2 = malloc(2*sizeof(Instrucao));
        trecho2[0] = defineInstrucao(3, 2, 1, -1);
        trecho2[1] = defineInstrucao(-1, -1, -1, -1);

        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);

    }


    printf("O valor da exponenciação é: %d\n", cpu->registrador1);

    liberaRam(ram);
}



void programaFibonacci(CPU *cpu, int n) {

    Ram *ram = criaRamVazia(2); 

    Instrucao *inicializa = malloc(5 * sizeof(Instrucao));
    inicializa[0] = defineInstrucao(4, 1, 0, -1);
    inicializa[1] = defineInstrucao(4, 2, 1, -1); 
    inicializa[2] = defineInstrucao(2, 1, 0, -1);
    inicializa[3] = defineInstrucao(2, 2, 1, -1);
    inicializa[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, inicializa);
    iniciar(ram, cpu);

    for (int i = 2; i <= n; i++) {
        Instrucao *passo = malloc(6 * sizeof(Instrucao));
        passo[0] = defineInstrucao(0, 0, 1, 0);
        passo[1] = defineInstrucao(3, 2, 0, -1);
        passo[2] = defineInstrucao(3, 1, 1, -1);
        passo[3] = defineInstrucao(2, 2, 1, -1);
        passo[4] = defineInstrucao(2, 1, 0, -1);
        passo[5] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, passo);
        iniciar(ram, cpu);
    }

    printf("O %d-ésimo número de Fibonacci é: %d\n", n, cpu->registrador2);

    liberaRam(ram);
}





void programaPA(CPU *cpu, int primeiroTermo, int razao, int numTermos) {
    Ram *ram = criaRamVazia(2);

    Instrucao *trecho1 = malloc(3 * sizeof(Instrucao));
    

    trecho1[0] = defineInstrucao(4, 1, primeiroTermo, -1);
    trecho1[1] = defineInstrucao(2, 1, 0, -1);
    trecho1[2] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);


    for (int i = 1; i < numTermos; i++) {
        Instrucao *trecho2 = malloc(6 * sizeof(Instrucao));
        trecho2[0] = defineInstrucao(3, 1, 0, -1);
        trecho2[1] = defineInstrucao(4, 2, razao, -1);
        trecho2[2] = defineInstrucao(2, 2, 1, -1);
        trecho2[3] = defineInstrucao(0, 0, 1, 1);
        trecho2[4] = defineInstrucao(2, 1, 0, -1);
        trecho2[5] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);
    }

    printf("O último termo da PA é: %d\n", cpu->registrador1);

    liberaRam(ram);
}




void programaFatorialDuplo(CPU *cpu, int n) {
    Ram *ram = criaRamVazia(3);


    Instrucao *trecho1 = malloc(6 * sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, 2, -1);
    trecho1[1] = defineInstrucao(2, 1, 2, -1); //ram[2] = reg1 = 2
    trecho1[2] = defineInstrucao(4, 1, n, -1);
    trecho1[3] = defineInstrucao(2, 1, 1, -1); //ram[1] = reg1 = n
    trecho1[4] = defineInstrucao(4, 2, 1, -1);
    trecho1[5] = defineInstrucao(-1, -1, -1, -1);
    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);

    
    while (n > 0) {
    
        programaMult(cpu, cpu->registrador1, cpu->registrador2);

        Instrucao *trecho2 = malloc(5 * sizeof(Instrucao));
        trecho2[0] = defineInstrucao(2, 1, 0, -1);
        trecho2[1] = defineInstrucao(1, 1, 2, 1);
        trecho2[2] = defineInstrucao(3, 1, 0, -1);
        trecho2[3] = defineInstrucao(3, 2, 1, -1);
        trecho2[4] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);


        n -= 2;
    }

    printf("O resultado do fatorial duplo eh: %d\n", cpu->registrador1);
    liberaRam(ram);
}




int **criaMatriz(int tam){
    int **matriz = malloc(tam * sizeof(int*));
    for(int i = 0; i<tam; i++){
        matriz[i] = malloc(tam * sizeof(int));
    }
    return matriz;
}



void liberaMatriz(int **a, int tam){
    for(int i = 0; i<tam; i++){
        free(a[i]);
    }
    free(a);
}



void programaDiv(CPU *cpu, int dividendo, int divisor){
    Ram *ram = criaRamVazia(4);

    Instrucao *trecho1 = malloc(5 * sizeof(Instrucao));
    trecho1[0] = defineInstrucao(4, 1, dividendo, -1);
    trecho1[1] = defineInstrucao(2, 1, 0, -1);
    trecho1[2] = defineInstrucao(4, 2, divisor, -1);
    trecho1[3] = defineInstrucao(2, 2, 1, -1);
    trecho1[4] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);


    Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
    trecho2[0] = defineInstrucao(4, 1, 1, -1);
    trecho2[1] = defineInstrucao(2, 1, 2, -1);
    trecho2[2] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho2);
    iniciar(ram, cpu);

    while(dividendo>=divisor){
        Instrucao *trecho3 = malloc(5 * sizeof(Instrucao));
        trecho3[0] = defineInstrucao(1, 0, 1, 0);
        trecho3[1] = defineInstrucao(0, 2, 3, 3);
        trecho3[2] = defineInstrucao(3, 1, 0, -1);
        trecho3[3] = defineInstrucao(5, 1, -1, -1);
        trecho3[4] = defineInstrucao(-1, -1, -1, -1);

        setPrograma(cpu, trecho3);
        iniciar(ram, cpu);

        dividendo = cpu->registrador1;
    }

    Instrucao *trecho4 = malloc(3 * sizeof(Instrucao));
    trecho4[0] = defineInstrucao(3, 1, 3, -1);
    trecho4[1] = defineInstrucao(5, 1, -1, -1);
    trecho4[2] = defineInstrucao(-1, -1, -1, -1);

    setPrograma(cpu, trecho4);
    iniciar(ram, cpu);

    printf("O resultado da divisão eh: %d\n", cpu->registrador1);

    liberaRam(ram);
}



void programaFat(CPU *cpu, int fat){
    int j = 1;
    Ram *ram = criaRamVazia(2);

    for(int i = 1; i<=fat; i++){
        programaMult(cpu, j, i);

        Instrucao *trecho1 = malloc(3 * sizeof(Instrucao));
        trecho1[0] = defineInstrucao(2, 1, 0, -1);
        trecho1[1] = defineInstrucao(-1, -1, -1, -1);
        setPrograma(cpu, trecho1);
        iniciar(ram, cpu);

        j = cpu->registrador1;
    }

    Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
    Instrucao inst4 = defineInstrucao(3, 1, 0, -1);
    trecho2[0] = inst4;

    Instrucao inst5 = defineInstrucao(5, 1, -1, -1);
    trecho2[1] = inst5;

    Instrucao inst6 = defineInstrucao(-1, -1, -1, -1);
    trecho2[2] = inst6;

    setPrograma(cpu, trecho2);
    iniciar(ram, cpu);

    printf("O resultado do fatorial eh: %d\n", cpu->registrador1);
    liberaRam(ram);
} 



void programaSomaMatriz(CPU *cpu, int cardinalidade){
    int **matriz1 = criaMatriz(cardinalidade);
    int **matriz2 = criaMatriz(cardinalidade);
    srand(time(NULL));
    
    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            matriz1[i][j] = rand() % 100;
            matriz2[i][j] = rand() % 100;
        }
    }

    Ram *ram = criaRamVazia(27);
    int endRam = 0;

    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            Instrucao *trecho1 = malloc(3 * sizeof(Instrucao));
            Instrucao inst0 = defineInstrucao(4, 1, matriz1[i][j], -1);
            trecho1[0] = inst0;

            Instrucao inst1 = defineInstrucao(2, 1, endRam, -1);
            trecho1[1] = inst1;

            Instrucao inst3 = defineInstrucao(-1, -1, -1, -1);
            trecho1[2] = inst3;

            setPrograma(cpu, trecho1);
            iniciar(ram, cpu);

            endRam++;
        }
    }


    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            Instrucao *trecho2 = malloc(3 * sizeof(Instrucao));
            Instrucao inst0 = defineInstrucao(4, 1, matriz2[i][j], -1);
            trecho2[0] = inst0;

            Instrucao inst1 = defineInstrucao(2, 1, endRam, -1);
            trecho2[1] = inst1;

            Instrucao inst3 = defineInstrucao(-1, -1, -1, -1);
            trecho2[2] = inst3;

            setPrograma(cpu, trecho2);
            iniciar(ram, cpu);

            endRam++;
        }
    }

    endRam = 0;
    int delta = 9;

    for(int i = 0; i<cardinalidade; i++){
        for(int j = 0; j<cardinalidade; j++){
            Instrucao *trecho3 = malloc(2*sizeof(Instrucao));
            Instrucao inst1 = defineInstrucao(0, endRam, endRam+delta, endRam+(2*delta));
            trecho3[0] = inst1;

            Instrucao inst2 = defineInstrucao(-1, -1, -1, -1);
            trecho3[1] = inst2;

            setPrograma(cpu, trecho3);
            iniciar(ram, cpu);

            endRam++;
        }
    }

    liberaMatriz(matriz1, cardinalidade);
    liberaMatriz(matriz2, cardinalidade);
    liberaRam(ram);

}



void programaMult(CPU *cpu, int multiplicando, int multiplicador){
    
    Ram *ram = criaRamVazia(2);
    
    Instrucao *trecho1 = malloc(3*sizeof(Instrucao));
    Instrucao inst0 = defineInstrucao(4, 1, multiplicando, -1);
    trecho1[0] = inst0;

    Instrucao inst1 = defineInstrucao(2, 1, 1, -1);
    trecho1[1] = inst1;

    Instrucao inst2 = defineInstrucao(-1, -1, -1, -1);
    trecho1[2] = inst2;

    setPrograma(cpu, trecho1);
    iniciar(ram, cpu);

    for(int i = 0; i<multiplicador; i++){
        Instrucao *trecho2 = malloc(2*sizeof(Instrucao));
        Instrucao inst3 = defineInstrucao(0, 0, 1, 0);
        trecho2[0] = inst3;

        Instrucao inst4 = defineInstrucao(-1, -1, -1, -1);
        trecho2[1] = inst4;

        setPrograma(cpu, trecho2);
        iniciar(ram, cpu);

    }

    Instrucao *trecho3 = malloc(3 * sizeof(Instrucao));
    Instrucao inst5 = defineInstrucao(3, 1, 0, -1);
    trecho3[0] = inst5;

    Instrucao inst6 = defineInstrucao(5, 1, -1, -1);
    trecho3[1] = inst6;

    Instrucao inst7 = defineInstrucao(-1, -1, -1, -1);
    trecho3[2] = inst7;

    setPrograma(cpu, trecho3);
    iniciar(ram, cpu);

    printf("O resultado da multiplicação eh: %d\n",cpu->registrador1);
    liberaRam(ram);
}