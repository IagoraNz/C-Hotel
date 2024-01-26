#include "menus.h"
#include "menu_quartos.c"
#include "menu_clientes.c"
#include "menu_reserva.c"
#include "menu_checks.c"

#define tam 50

int stringparaintf(const char str[]) {
    int result = 0, i;
    for (i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } 
        else{
            return -1;
        }
    }
    return result;
}

void menu_funcionario(){
    char opc[1];
    int input;

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
        fflush(stdin);
        do{
            printf("Digite a opcao desejada: ");
            scanf("%s", opc);

            input = stringparaintf(opc);

            if(input == -1){
                printf("Opcao invalida!\n");
                system("PAUSE");
                return menu_funcionario();
            }
        }while(input < 0 || input > 7);

        switch (input)
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