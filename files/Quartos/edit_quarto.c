#include "quartos.h"

void editarQuarto() {
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r+");

    if (quartos == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EDITAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    int edicao, carac;

    printf("Digite o numero do quarto que deseja editar: ");
    scanf("%d", &edicao);

    while (fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5) {
        if (edicao == quartos1.numquarto) {
            printf("Digite qual caracteristica deseja atualizar: ");
            scanf("%d", &carac);

            long posicaoAtual = ftell(quartos);
            fseek(quartos, posicaoAtual - sizeof(Quartos), SEEK_SET);

            if (carac == 1) {
                printf("TIPOS\n");
                printf("1 - Luxo\n");
                printf("2 - Executivo\n");
                printf("3 - Simples\n");
                printf("Digite o tipo do quarto: ");
                scanf("%d", &quartos1.tipo);
            } else if (carac == 2) {
                printf("Digite o numero do quarto: ");
                scanf("%d", &quartos1.numquarto);
            } else if (carac == 3) {
                printf("STATUS\n");
                printf("1 - Disponivel\n");
                printf("2 - Ocupado\n");
                printf("3 - Reservado\n");
                printf("Digite o status do quarto: ");
                scanf("%d", &quartos1.status);
            } else if (carac == 4) {
                if (quartos1.tipo == 1) {
                    quartos1.diaria = 100;
                } else if (quartos1.tipo == 2) {
                    quartos1.diaria = 250;
                } else if (quartos1.tipo == 3) {
                    quartos1.diaria = 35;
                }
            } else if (carac == 5) {
                printf("Capacidade do Quarto\n");
                printf("1 - Solteiro\n");
                printf("2 - Casal\n");
                printf("Digite a capacidade do quarto: ");
                scanf("%d", &quartos1.capacidade);
            } else {
                printf("Caracteristica invalida!\n");
            }

            fseek(quartos, posicaoAtual, SEEK_SET);
            fprintf(quartos, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
            break;
        }
    }

    fclose(quartos);
}
