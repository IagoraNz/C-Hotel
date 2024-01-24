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
    FILE *quartos;
    Quartos quarto;

    quartos = fopen("..\\db\\quartos.txt", "r");

    int cont = 0;

    while(fread(&quarto, sizeof(Quartos), 1, quartos)){
        cont++;
    }

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
                if(cont == 10){
                    printf("Nao e possivel cadastrar mais quartos!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    cadastroQuarto();
                }
                system("PAUSE");
                system("cls");
                break;
            case 2:
                if(cont == 0){
                    printf("Nenhum quarto cadastrado!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    listarQuartos();
                }
                system("PAUSE");
                system("cls");
                break;

            case 3:
                if(cont == 0){
                    printf("Nenhum quarto cadastrado!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    tabela();
                }
                system("PAUSE");
                system("cls");
                break;
            case 4:
                if(cont == 0){
                    printf("Nenhum quarto cadastrado!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    listarDisponiveis();
                }
                system("PAUSE");
                system("cls");
                break;
            case 5:
                if(cont == 0){
                    printf("Nenhum quarto cadastrado!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    editQuarto();
                }
                system("PAUSE");
                system("cls");
                break;
            case 6:
                if(cont == 0){
                    printf("Nenhum quarto cadastrado!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    excluirQuarto();
                }
                system("PAUSE");
                system("cls");
                break;
            case 7:
                if(cont == 0){
                    printf("Nenhum quarto cadastrado!\n");
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else{
                    consultarQuarto();
                }
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