#include "quartos.h"

void listarQuartos(){
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
    while(!feof(quartos)){
        fscanf(quartos, "%d\n%d\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status);

        printf("Tipo: ");
        if(quartos1.tipo == 1){
            printf("Luxo");
        }
        else if(quartos1.tipo == 2){
            printf("Executivo");
        }
        else if(quartos1.tipo == 3){
            printf("Simples");
        }
        else{
            printf("Tipo invalido!\n");
        }
        printf("\n");
        printf("Numero: %d", quartos1.numquarto);
        printf("\n");
        printf("Status: ");
        if(quartos1.status == 1){
            printf("Disponivel");
        }
        else if(quartos1.status == 2){
            printf("Ocupado");
        }
        else if(quartos1.status == 3){
            printf("Reservado");
        }
        else{
            printf("Status invalido!");
        }
        printf("\n\n");
    }

    fclose(quartos);
}