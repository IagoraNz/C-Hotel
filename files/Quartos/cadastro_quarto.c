#include "quartos.h"

void cadastrarQuarto(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "a");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("TIPOS\n");
    printf("1 - Luxo\n");
    printf("2 - Executivo\n");
    printf("3 - Simples\n");
    do{
        printf("Digite o tipo do quarto: ");
        scanf("%d", &quartos1.tipo);
    }while(quartos1.tipo < 1 || quartos1.tipo > 3);

    do{
        printf("Digite o numero do quarto: ");
        scanf("%d", &quartos1.numquarto);
    }while(quartos1.numquarto == 0);

    printf("STATUS\n");
    printf("1 - Disponivel\n");
    printf("2 - Ocupado\n");
    printf("3 - Reservado\n");
    do{
        printf("Digite o status do quarto: ");
        scanf("%d", &quartos1.status);
    }while(quartos1.status < 1 || quartos1.status > 3);

    if(quartos1.tipo == 1){
        quartos1.diaria = 100;
    } 
    else if(quartos1.tipo == 2){
        quartos1.diaria = 250;
    } 
    else if(quartos1.tipo == 3){
        quartos1.diaria = 35;
    }
    
    printf("Capacidade do Quarto\n");
    printf("1 - Solteiro\n");
    printf("2 - Casal\n");
    do{
        printf("Digite a capacidade do quarto: ");
        scanf("%d", &quartos1.capacidade);
    }while(quartos1.capacidade < 1 || quartos1.capacidade > 2);

    fprintf(quartos, "%d\n%d\n%d\n%.2f\n%d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);

    fclose(quartos);
}