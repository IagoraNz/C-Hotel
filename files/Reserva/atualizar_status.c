#include "reserva.h"

int Atualizar_Status(int numquarto){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temporario;

    temporario = fopen("..\\db\\quartos_temp.txt", "w");

    if(temporario == NULL){
        printf("Erro ao abrir o arquivo temporário");
        fclose(quartos);
        exit(EXIT_FAILURE);
    }

    int encontrado = 0;

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        if(numquarto == quartos1.numquarto){
            encontrado = 1;
            quartos1.status = 3;

            fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        } 
        else{
            fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        }
    }

    fclose(quartos);
    fclose(temporario);

    if(!encontrado){
        printf("Quarto não encontrado.\n");
        remove("..\\db\\quartos_temp.txt");
    } 
    else{
        remove("..\\db\\quartos.txt");
        rename("..\\db\\quartos_temp.txt", "..\\db\\quartos.txt");
        printf("Status atualizado com sucesso!\n");
    }
    
    return 0; 
}