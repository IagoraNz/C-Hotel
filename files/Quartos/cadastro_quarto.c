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
    printf("Digite o tipo do quarto: ");
    scanf("%d", &quartos1.tipo);

    printf("Digite o numero do quarto: ");
    scanf("%d", &quartos1.numquarto);

    printf("STATUS\n");
    printf("1 - Disponivel\n");
    printf("2 - Ocupado\n");
    printf("3 - Reservado\n");
    printf("Digite o status do quarto: ");
    scanf("%d", &quartos1.status);

    fprintf(quartos, "%d\n%d\n%d\n", quartos1.tipo, quartos1.numquarto, quartos1.status);

    fclose(quartos);
}