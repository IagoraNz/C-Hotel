#include "menus.h"
#include "../Quartos/quartos.h"
#include "../Quartos/cadastro_quarto.c"
#include "../Quartos/listar_quartos.c"
#include "../Quartos/consultar_quartos.c"
#include "../Quartos/edit_quarto.c"
#include "../Quartos/excluir_quarto.c"

void menuQuartos(){
    int opc;

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Cadastrar quartos\n");
        printf("2 - Listar todos os quartos\n");
        printf("3 - Consultar quartos disponiveis\n");
        printf("4 - Editar quartos\n");
        printf("5 - Excluir quartos\n");
        printf("6 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                cadastrarQuarto();
                system("PAUSE");
                system("cls");
                return menuQuartos();
                break;
            case 2:
                listarQuartos();
                system("PAUSE");
                system("cls");
                return menuQuartos();
                break;
            case 3:
                consultarQuartos();
                system("PAUSE");
                system("cls");
                return menuQuartos();
                break;
            case 4:
                editarQuarto();
                system("PAUSE");
                system("cls");
                return menuQuartos();
                break;
            case 5:
                excluirQuarto();
                system("PAUSE");
                system("cls");
                return menuQuartos();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opc != 6);
}