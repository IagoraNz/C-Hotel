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
    fclose(quartos);
    printf("A quantidade total de quartos cadastrados: %d\n\n", quantidade);

    printf("Deseja ver a tabela de quartos? (s/n): ");
    char input[1];
    scanf("%s", input);

    if(input[0] == 's' || input[0] == 'S'){
        tabela();
    }
    else{
        return menuQuartos();
    }    
}