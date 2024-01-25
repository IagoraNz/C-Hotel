#include "menus.h"
#include "menu_quartos.c"
#include "menu_clientes.c"
#include "menu_reserva.c"
#include "menu_checks.c"

#define tam 50

void lbuffer1(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void menu_funcionario(){
    char buffer[tam];
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
        fflush(stdin);
        do{
            printf("Digite a opcao desejada: ");

            if(fgets(buffer, sizeof(buffer), stdin) == NULL){
                printf("Erro ao ler a entrada!\n");
                exit(EXIT_FAILURE);
            }

            if(sscanf(buffer, "%d", &opc) == 1 && (opc >= 1 && opc <= 4)){
                break;
            }

            printf("Opcao invalida! Digite um numero entre 1 e 3.\n");
            printf("Pressione enter para tentar novamente... ");
            lbuffer();
            printf("\n");
        }while(opc < 0 || opc > 7);

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