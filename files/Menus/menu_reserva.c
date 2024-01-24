#include "menus.h"
#include "../Reserva/reserva_cliente.c"
#include "../Reserva/consultar_reserva.c"
#include "../Reserva/listar_reservas.c"
#include "../Reserva/excluir_reserva.c"

void Menu_Reservas(){
    int opc;

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Realizar Reserva\n");
        printf("2 - Consultar Reserva\n");
        printf("3 - Listar Reservas\n");
        printf("4 - Excluir Reservas\n");
        printf("0 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            Reservar_Cliente();
            break;
        case 2:
            Consultar_reserva();
            break;
        case 3:
            Listar_reservas();
            break;
        case 4:
            Excluir_reserva();
            break;
        case 0:
            return;
        default:
            break;
        }
    }while(opc != 0);
}