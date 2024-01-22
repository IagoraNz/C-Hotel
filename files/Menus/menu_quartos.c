#include "menus.h"
#include "../Quartos/quartos.h"
#include "../Quartos/cadastro_quarto.c"
#include "../Quartos/listar_quartos.c"
#include "../Quartos/listar_disponiveis.c"
#include "../Quartos/edit_quarto.c"
#include "../Quartos/excluir_quarto.c"
#include "../Quartos/tabela.c"
#include "../Quartos/consultar_quarto.c"

void menuQuartos(){
    int opc;

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA       MENU       \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Cadastrar quartos\n");
        printf("2 - Listar todos os quartos\n");
        printf("3 - Tabela dos quartos\n");
        printf("4 - Consultar quartos disponiveis\n");
        printf("5 - Editar quartos\n");
        printf("6 - Excluir quartos\n");
        printf("7 - Consultar quarto\n");
        printf("0 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                cadastrarQuarto();
                system("PAUSE");
                system("cls");
                break;
            case 2:
                listarQuartos();
                system("PAUSE");
                system("cls");
                break;

            case 3:
                tabela();
                system("PAUSE");
                system("cls");
                break;
            case 4:
                listarDisponiveis();
                system("PAUSE");
                system("cls");
                break;
            case 5:
                editarQuarto();
                system("PAUSE");
                system("cls");
                break;
            case 6:
                excluirQuarto();
                system("PAUSE");
                system("cls");
                break;
            case 7:
                consultarQuarto();
                system("PAUSE");
                system("cls");
                break;
            case 0:
                printf("Saindo...\n");
                system("PAUSE");
                system("cls");
                return;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opc != 0);
}