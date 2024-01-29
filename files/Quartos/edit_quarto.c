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
                printf("1 - Tipo: ");

                if(quartos1.tipo == 1){
                    printf("Luxo\n");
                }
                else if(quartos1.tipo == 2){
                    printf("Executivo\n");
                }
                else if(quartos1.tipo == 3){
                    printf("Simples\n");
                }

                printf("2 - Valor da diaria: ");

                if(quartos1.tipo == 1){
                    printf("R$ 100,00\n");
                }
                else if(quartos1.tipo == 2){
                    printf("R$ 250,00\n");
                }
                else if(quartos1.tipo == 3){
                    printf("R$ 35,00\n");
                }

                printf("3 - Capacidade: ");

                if(quartos1.capacidade == 1){
                    printf("Solteiro\n");
                }
                else if(quartos1.capacidade == 2){
                    printf("Casal\n");
                }

                printf("Digite qual caracteristica deseja atualizar: ");
                scanf("%d", &carac);

                int tipo, capacidade;

                switch (carac)
                {
                case 1:
                    printf("TIPOS\n");
                    printf("1 - Luxo\n");
                    printf("2 - Executivo\n");
                    printf("3 - Simples\n");
                    printf("Digite o tipo do quarto: ");
                    scanf("%d", &tipo);

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

                    if(tipo == quartos1.tipo){
                        printf("\nPara editar, digite uma opcao diferente da original\n");
                        system("PAUSE");
                        system("cls");
                        return editarQuarto();
                    }
                    else{
                        quartos1.tipo = tipo;
                    }
                    printf("Tipo do quarto atualizado!\n");
                    break;
                case 2:
                    printf("Para mudar o valor da diaria, mude o tipo do quarto!\n");
                    printf("1 - Luxo\n");
                    printf("2 - Executivo\n");
                    printf("3 - Simples\n");
                    printf("Digite o tipo do quarto: ");
                    scanf("%d", &tipo);

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

                    if(tipo == quartos1.tipo){
                        printf("O tipo do quarto é o mesmo!\nPara editar, digite uma opcao diferente da original\n");
                        system("PAUSE");
                        system("cls");
                        return editarQuarto();
                    }
                    else{
                        quartos1.tipo = tipo;
                    }
                    printf("Valor da diaria atualizado!\n");
                    break;
                case 3:
                    printf("Capacidade do Quarto\n");
                    printf("1 - Solteiro\n");
                    printf("2 - Casal\n");
                    printf("Digite a capacidade do quarto: ");
                    scanf("%d", &capacidade);

                    if(capacidade == quartos1.capacidade){
                        printf("A capacidade do quarto é a mesma!\nPara editar, digite uma opcao diferente da original\n");
                        system("PAUSE");
                        system("cls");
                        return editarQuarto();
                    }
                    else{
                        quartos1.capacidade = capacidade;
                    }
                    printf("Capacidade do quarto atualizada!\n");
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