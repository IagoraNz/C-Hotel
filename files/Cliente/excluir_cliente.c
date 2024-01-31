#include "cliente.h"

void Excluir_Cliente()
{
    FILE *cliente;
    Clientes cliente1;

    cliente = fopen("..\\db\\cliente.txt", "r");

    if (cliente == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temporario;

    temporario = fopen("..\\db\\cliente_temp.txt", "w");

    if (temporario == NULL)
    {
        printf("Erro ao abrir o arquivo temporário");
        fclose(cliente);
        exit(EXIT_FAILURE);
    }

    int aux1, aux2, aux3, aux4;
    int encontrado = 0;

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EXCLUIR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("Digite o CPF (no formato XXX.XXX.XXX-XX): ");
    if (scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4)
    {
        printf("Formato de CPF inválido.\n");
        // Tratamento de erro, se necessário
        fclose(cliente);
        fclose(temporario);
        return;
    }

    fseek(cliente, 0, SEEK_SET);

    while(fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade,
                  &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
                  &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) != EOF)
    {
        if (aux1 == cliente1.bloco1 && aux2 == cliente1.bloco2 && aux3 == cliente1.bloco3 && aux4 == cliente1.bloco4)
        {
            encontrado = 1;
            printf("Cliente Encontrado!\n");
        }
        else
        {
            fprintf(temporario, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n",
                    cliente1.nome, cliente1.idade,
                    cliente1.bloco1, cliente1.bloco2, cliente1.bloco3, cliente1.bloco4,
                    cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado);
        }
    }
    fclose(cliente);
    fclose(temporario);
    if (!encontrado)
    {
        printf("Cliente não encontrado.\n");
        remove("..\\db\\cliente_temp.txt");
    }
    else
    {
        remove("..\\db\\cliente.txt");
        rename("..\\db\\cliente_temp.txt", "..\\db\\cliente.txt");
        printf("Informacoes sobre Cliente apagada com sucesso!\n");
    }

    system("PAUSE");
}