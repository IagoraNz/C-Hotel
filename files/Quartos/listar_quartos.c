#include "quartos.h"

void listarQuartos(){
    FILE *quartos;
    Quartos quartos1;
    int quantidade = 0;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
        return;
    }

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      LISTAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        quantidade++;
    }

    printf("A quantidade total de quartos cadastrados: %d\n\n", quantidade);

    fseek(quartos, 0, SEEK_SET);

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        fgetc(quartos);

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
        printf("Numero: %d\n", quartos1.numquarto);
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
            printf("Status invalido!\n");
        }
        printf("\nDiaria do Quarto: %.2f\n", quartos1.diaria);

        printf("Capacidade do Quarto: ");
        if(quartos1.capacidade == 1){
            printf("Solteiro");
        } 
        else if(quartos1.capacidade == 2){
            printf("Casal");
        }
        printf("\n\n");
    }

    fclose(quartos);
}