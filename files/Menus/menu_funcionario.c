#include "menus.h"
#include "menu_quartos.c"
#include "menu_clientes.c"
#include "menu_reserva.c"
#include "menu_checks.c"

void menu_funcionario(){
    int opc;

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Area quartos\n");
        printf("2 - Area clientes\n");
        printf("3 - Area reservas\n");
        printf("4 - Area check-in/out\n");
        printf("0 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            menuQuartos();
            system("PAUSE");
            system("cls");
            break;
        case 2:
            menuClientes();
            system("PAUSE");
            system("cls");
            break;
        case 3:
            Menu_Reservas();
            system("PAUSE");
            system("cls");
            break;
        case 4:
            menu_checks();
            system("PAUSE");
            system("cls");
            break;
        case 0:
            return;
        default:
            break;
        }
    }while(opc != 0);
}