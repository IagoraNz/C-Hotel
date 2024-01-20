#include "quartos.h"

void editarQuarto(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r+");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int edicao, opc;

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EDITAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("Digite o numero do quarto que deseja editar: ");
    scanf("%d", &edicao);

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        fgetc(quartos);

        if(edicao == quartos1.numquarto){
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
            printf("Capacidade: %d\n\n", quartos1.capacidade);

            printf("Digite qual campo deseja editar: \n");
            printf("1 - Tipo\n");
            printf("2 - Numero\n");
            printf("3 - Status\n");
            printf("4 - Capacidade\n");
            printf("5 - Sair\n");
            printf("Opcao: ");
            scanf("%d", &opc);  

            switch (opc)
            {
            case 1:
                printf("Digite o novo tipo: ");
                scanf("%d", &quartos1.tipo);
                break;
            case 2:
                printf("Digite o novo numero: ");
                scanf("%d", &quartos1.numquarto);
                break;
            case 3:
                printf("Digite o novo status: ");
                scanf("%d", &quartos1.status);
                break;
            case 4:
                printf("Digite a nova capacidade: ");
                scanf("%d", &quartos1.capacidade);
                break;
            case 5:
                return;
                break;
            default:
                printf("Opcao invalida!\n");
                break;
            }

            fseek(quartos, -sizeof(Quartos), SEEK_CUR);

            fprintf(quartos, "%d\n%d\n%d\n%.2f\n%d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
            break;
        }
    }
    fclose(quartos);
}