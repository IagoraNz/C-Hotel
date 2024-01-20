#include "quartos.h"

void consultarQuartos(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      LISTAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
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
            printf("Valor da diaria: %.2f\n", quartos1.diaria);
            printf("Capacidade: ");
            if(quartos1.capacidade == 1){
                printf("Solteiro\n");
            }
            else if(quartos1.capacidade == 2){
                printf("Casal\n");
            }
            else{
                printf("Capacidade invalida!\n");
            }
            printf("\n");
        }
    }

    fclose(quartos);
}