#include "menus.h"
#include "../Reserva/reserva_cliente.c"
#include "../Reserva/consultar_reserva.c"
#include "../Reserva/listar_reservas.c"
#include "../Reserva/excluir_reserva.c"
#include "../Reserva/contar_reservas.c"

int stringparaintr(const char str[]) {
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

void Menu_Reservas()
{
    char opc[1];
    int cont, input;

    system("cls");
    do
    {
        cont = Contar_reservas();
        system("cls");
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Realizar reserva\n");
        printf("2 - Consultar reserva\n");
        printf("3 - Listar reservas\n");
        printf("4 - Excluir reservas\n");
        printf("0 - Voltar\n");
        do{
            printf("Digite a opcao desejada: ");
            scanf("%s", opc);

            input = stringparaintr(opc);

            if(input == -1 || input > 4 || input < 0){
                printf("Opcao invalida!\n");
                system("PAUSE");
                return Menu_Reservas();
            }
        }while(input < 0 || input > 4);

        switch (input)
        {
        case 1:
            Reservar_Cliente();
            break;
        case 2:
            if(cont != 0){
                Consultar_reserva();
            } 
            else{
                printf("Nenhuma reserva disponivel\n");
            }
            break;
        case 3:
            Listar_reservas();
            break;
        case 4:
            if(cont != 0){
                Excluir_reserva();
            } 
            else{
                printf("Nenhuma reserva disponivel\n");
            }
            break;
        case 0:
            return;
        default:
            break;
        }
    } while (opc != 0);
}