#include "quartos.h"

void consultarQuartos(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    while(!feof(quartos)){
        fscanf(quartos, "%d\n%d\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status);

        if(quartos1.status == 1){
            printf("Tipo: ");
            if(quartos1.tipo == 1){
                printf("Luxo\n");
            }
            else if(quartos1.tipo == 2){
                printf("Executivo\n");
            }
            else if(quartos1.tipo == 3){
                printf("Simples\n");
            }
            else{
                printf("Tipo invalido!\n");
            }
            printf("Numero: %d\n", quartos1.numquarto);
        }
    }
}