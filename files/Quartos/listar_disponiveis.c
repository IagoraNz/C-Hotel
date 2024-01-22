#include "quartos.h"

void listarDisponiveis(){
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

    int disp = 0;

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        if(quartos1.status == 1){
            disp++;
        }        
    }

    printf("A quantidade total de quartos disponiveis: %d\n\n", disp);

    fseek(quartos, 0, SEEK_SET);

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      TABELA      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");
    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        if(quartos1.status == 1){
            if(quartos1.tipo == 1){
                printf("Luxo\t\t");
            }
            else if(quartos1.tipo == 2){
                printf("Exec.\t\t");
            }
            else if(quartos1.tipo == 3){
                printf("Simples\t\t");
            }

            printf("%d\t\t", quartos1.numquarto);

            if(quartos1.status == 1){
                printf("Disponivel\t\t");
            }
            else if(quartos1.status == 2){
                printf("Ocupado\t\t");
            }
            else if(quartos1.status == 3){
                printf("Reservado\t\t");
            }

            printf("%.2f\t\t", quartos1.diaria);

            if(quartos1.capacidade == 1){
                printf("Solteiro\n");
            }
            else if(quartos1.capacidade == 2){
                printf("Casal\n");
            }
        }
    }

    fclose(quartos);
}