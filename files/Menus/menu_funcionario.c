#include "menus.h"
#include "menu_quartos.c"
#include "menu_clientes.c"

void menu_funcionario(){
    int opc;

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Area quartos\n");
        printf("2 - Area clientes\n");
        printf("0 - Voltar\n");
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
        case 0:
            return;
        default:
            break;
        }
    }while(opc != 0);
}