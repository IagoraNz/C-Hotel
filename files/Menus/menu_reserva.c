#include "menus.h"
#include "../Reserva/reserva_cliente.c"
#include "../Reserva/consultar_reserva.c"
#include "../Reserva/listar_reservas.c"
#include "../Reserva/excluir_reserva.c"
#include "../Reserva/contar_reservas.c"

void Menu_Reservas()
{
    int opc, cont;

    cont = Contar_reservas();

    system("cls");
    do
    {
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
            if (cont != 0)
            {
                Consultar_reserva();
            } else{
                printf("Nenhuma Reserva Disponivel!\n");
            }
            break;
        case 3:
            if (cont != 0)
            {
                Listar_reservas();
            } else{
                printf("Nenhuma Reserva Disponivel!\n");
            }
            break;
        case 4:
            if (cont != 0)
            {
                Excluir_reserva();
            } else{
                printf("Nenhuma Reserva Disponivel!\n");
            }
            break;
        case 0:
            return;
        default:
            break;
        }
    } while (opc != 0);
}