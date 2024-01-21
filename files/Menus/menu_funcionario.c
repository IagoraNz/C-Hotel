#include "menus.h"
#include "menu_quartos.c"
#include "menu_clientes.c"

void menu_funcionario(){
    int opc;

    do {
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Area Quartos\n");
        printf("2 - Area Clientes\n");
        printf("3 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            menuQuartos();
            break;
        case 2:
            menuClientes();
            break;
        case 3:
            return main();
        default:
            break;
        }
    } while (opc != 3);
}