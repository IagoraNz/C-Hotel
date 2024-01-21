#include "quartos.h"

void excluirQuarto(){
    FILE *quartos;
    FILE *quartosTemp;
    int numQuarto;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    quartosTemp = fopen("..\\db\\quartos_temp.txt", "w");

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EXCLUIR     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("Digite o numero do quarto que deseja excluir: ");
    scanf("%d", &numQuarto);

    int encontrado = 0;
    Quartos quartos1;

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5) {
        if(numQuarto == quartos1.numquarto){
            encontrado = 1;
            printf("Quarto encontrado!\n");
            printf("1 - Tipo: %d\n", quartos1.tipo);
            printf("2 - Numero: %d\n", quartos1.numquarto);
            printf("3 - Status: %d\n", quartos1.status);
            printf("4 - Diaria: %.2f\n", quartos1.diaria);
            printf("5 - Capacidade: %d\n", quartos1.capacidade);
            printf("Quarto excluido com sucesso!\n");
        } 
        else{
            fprintf(quartosTemp, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        }
    }

    if(encontrado == 0){
        printf("Quarto nao encontrado!\n");
    }

    fclose(quartos);
    fclose(quartosTemp);

    remove("..\\db\\quartos.txt");
    rename("..\\db\\quartos_temp.txt", "..\\db\\quartos.txt");
}