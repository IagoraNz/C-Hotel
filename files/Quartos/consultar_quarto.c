#include "quartos.h"

void consultarQuarto(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int consulta;

    printf("Digite o numero do quarto que deseja consultar: ");
    scanf("%d", &consulta);

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      QUARTO      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");

    while(fscanf(quartos, "%d %d %d %f %d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) != EOF){
        if(consulta == quartos1.numquarto){
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