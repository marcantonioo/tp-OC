#include "CPU.h"


CPU* iniciaCPU(){
    CPU *a = malloc(sizeof(CPU));
    return a;
}

void liberaCPU(CPU *a){
    free(a);
}

void setPrograma(CPU *cpu, Instrucao *programaAux) {
    cpu->programa = programaAux;
}

void iniciar(Ram *ram, CPU *cpu){
    cpu->opcode = 0;
    cpu->PC = 0;

    while(cpu->opcode != -1){
        Instrucao inst = cpu->programa[cpu->PC];

        cpu->opcode = inst.opcode;

        //executar instrucao
		//-1 -> halt
		// 0 -> soma
		// 1 -> subtrai
		// 2 -> copia do registrador para RAM
		// 3 -> copia da RAM para o registrador
		// 4 -> salva conteudo externo no registrador
		// 5 -> obtem conteudo externo do registrador

        switch(cpu->opcode){

            case -1:
                printf("O programa terminou!!");
                imprimir(ram);
                break;

            case 0:
                cpu->registrador1 = getDado(ram, inst.add1);
                cpu->registrador2 = getDado(ram, inst.add2);
                cpu->registrador1 += cpu->registrador2;

                setDado(ram, inst.add3, cpu->registrador1);
                printf("Inst sum -> RAM posição %d com conteudo %d\n",inst.add3, cpu->registrador1);
                break;
            
            case 1:
                cpu->registrador1 = getDado(ram, inst.add1);
                cpu->registrador2 = getDado(ram, inst.add2);
                cpu->registrador1 -= cpu->registrador2;

                setDado(ram, inst.add3, cpu->registrador1);
                printf("Inst sub -> RAM posição %d com conteudo %d\n",inst.add3, cpu->registrador1);
                break;

            case 2:

                if(inst.add1 == 1){
                    setDado(ram, inst.add2, cpu->registrador1);
                    printf("Inst copy_reg_ram _> RAM posição %d com conteudo %d\n",inst.add2, cpu->registrador1);
                }
                
                if(inst.add1 == 2){
                    setDado(ram, inst.add2, cpu->registrador2);
                    printf("Inst copy_reg_ram _> RAM posição %d com conteudo %d\n",inst.add2, cpu->registrador2);
                }
                break;
            
            case 3:

                if(inst.add1 == 1){
                    cpu->registrador1 = getDado(ram, inst.add2);
                    printf("Inst copy_ram_reg -> Registrador1 com conteudo %d\n",cpu->registrador1);
                }

                if(inst.add1 == 2){
                    cpu->registrador2 = getDado(ram, inst.add2);
                    printf("Inst copy_ram_reg -> Registrador2 com conteudo %d\n",cpu->registrador2);
                }
                break;
            
            case 4:

                if(inst.add1 == 1){
                    cpu->registrador1 = inst.add2;
                    printf("Inst copy_ext_reg -> Registrador1 com conteudo %d\n",cpu->registrador1);
                }

                if(inst.add1 == 2){
                    cpu->registrador2 = inst.add2;
                    printf("Inst copy_ext_reg -> Registrador2 com conteudo %d\n",cpu->registrador2);
                }
                break;
            
            case 5:

                if(inst.add1 == 1){
                    inst.add1 = cpu->registrador1;
                    printf("Inst obtain_reg -> Registrador1 com conteudo %d\n",cpu->registrador1);
                }
                if(inst.add1 == 2){
                    inst.add1 = cpu->registrador2;
                    printf("Inst obtain_reg -> Registrador2 com conteudo %d\n",cpu->registrador2);
                }
                break;
        }
        (cpu->PC)++;
    }
    free(cpu->programa);
}