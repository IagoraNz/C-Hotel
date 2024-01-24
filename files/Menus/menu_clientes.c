#include "menus.h"
// #include "../struct.h"
// #include "../struct.c"
#include "../Cliente/cliente.h"
#include "../Cliente/cadastro_cliente.c"
#include "../Cliente/visualizar_cliente.c"
#include "../Cliente/consultar_cliente.c"
#include "../Cliente/edit_cliente.c"

void menuClientes()
{
    Clientes cliente1;
    int opc;
    FILE *cliente;

    cliente = fopen("..\\db\\cliente.txt", "r");

    int cont = 0;

    while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade,
                  &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
                  &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) == 11)
    {
        cont++;
    }
    fclose(cliente);
    do
    {
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU CLIENTES      \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Visualizar clientes\n");
        printf("3 - Consultar cliente\n");
        printf("4 - Editar cliente\n");
        printf("0 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            Cadastro_Cliente(&cliente);
            break;
        case 2:
            if (cont == 0)
            {
                printf("Nenhum cliente cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                Listar_Clientes();
            }
            break;
        case 3:
            if (cont == 0)
            {
                printf("Nenhum cliente cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                Consultar_Cliente();
            }
            break;
        case 4:
            if (cont == 0)
            {
                printf("Nenhum cliente cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                Editar_Cliente();
            }
            break;
        case 0:
            return;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opc != 0);
}