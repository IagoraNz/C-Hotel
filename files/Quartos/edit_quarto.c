#include "quartos.h"

void editarQuarto()
{
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if (quartos == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temporario;

    temporario = fopen("..\\db\\quartos_temp.txt", "w");

    if (temporario == NULL)
    {
        printf("Erro ao abrir o arquivo temporário");
        fclose(quartos);
        exit(EXIT_FAILURE);
    }

    int edicao, carac;
    int encontrado = 0;

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EDITAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("Digite o numero do quarto que deseja editar: ");
    scanf("%d", &edicao);

    while (fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5)
    {
        if (edicao == quartos1.numquarto)
        {
            encontrado = 1;
            if (quartos1.status == 3 || quartos1.status == 2)
            {
                printf("Quarto Ocupado/Reservado!\n");
                fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
            }
            else
            {
                printf("Quarto encontrado!\n");
                printf("1 - Tipo: %d\n", quartos1.tipo);
                printf("2 - Numero: %d\n", quartos1.numquarto);
                printf("3 - Capacidade: %d\n", quartos1.capacidade);
                printf("Digite qual caracteristica deseja atualizar: ");
                scanf("%d", &carac);

                switch (carac)
                {
                case 1:
                    printf("TIPOS\n");
                    printf("1 - Luxo\n");
                    printf("2 - Executivo\n");
                    printf("3 - Simples\n");
                    printf("Digite o tipo do quarto: ");
                    scanf("%d", &quartos1.tipo);

                    if (quartos1.tipo == 1)
                    {
                        quartos1.diaria = 100;
                    }
                    else if (quartos1.tipo == 2)
                    {
                        quartos1.diaria = 250;
                    }
                    else if (quartos1.tipo == 3)
                    {
                        quartos1.diaria = 35;
                    }
                    break;
                case 2:
                    printf("Digite o numero do quarto: ");
                    scanf("%d", &quartos1.numquarto);
                    break;
                case 3:
                    printf("Capacidade do Quarto\n");
                    printf("1 - Solteiro\n");
                    printf("2 - Casal\n");
                    printf("Digite a capacidade do quarto: ");
                    scanf("%d", &quartos1.capacidade);
                    break;
                default:
                    printf("Caracteristica invalida!\n");
                    break;
                }

                fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
            }
        }
        else
        {
            fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        }
    }

    fclose(quartos);
    fclose(temporario);

    if (!encontrado)
    {
        printf("Quarto não encontrado.\n");
        remove("..\\db\\quartos_temp.txt");
    }
    else
    {
        remove("..\\db\\quartos.txt");
        rename("..\\db\\quartos_temp.txt", "..\\db\\quartos.txt");
    }
}