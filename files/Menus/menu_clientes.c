#include "menus.h"
// #include "../struct.h"
// #include "../struct.c"
#include "../Cliente/cliente.h"
#include "../Cliente/cadastro_cliente.c"


void menuClientes(){
    Clientes cliente;
    int opc;

    do {
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU CLIENTES      \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Visualizar Clientes\n");
        printf("3 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1:
            Cadastro_Cliente(&cliente);  // Chama a função de cadastro
            break;
        case 2:
            // Adicione a lógica para visualizar clientes, se necessário
            break;
        case 3:
            return;  // Retorna ao menu principal
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opc != 3);
}