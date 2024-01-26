#include "menus.h"
#include "../Quartos/quartos.h"
#include "../Quartos/cadastro_quarto.c"
#include "../Quartos/listar_quartos.c"
#include "../Quartos/listar_disponiveis.c"
#include "../Quartos/edit_quarto.c"
#include "../Quartos/excluir_quarto.c"
#include "../Quartos/tabela.c"
#include "../Quartos/consultar_quarto.c"

void lbuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void menuQuartos()
{
    int opc;
    char buffer[tam];
    FILE *quartos;
    FILE *predio;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    int cont = 0, qtd_quartos;

    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        cont++;
    }
    fclose(quartos);

    predio = fopen("..\\db\\predio.txt", "r");

    fscanf(predio,"%d", &qtd_quartos);
    fclose(predio);

    system("cls");
    do
    {
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
        fflush(stdin);
        do
        {
            printf("Digite a opcao desejada: ");
            fflush(stdin);
            if(fgets(buffer, sizeof(buffer), stdin) == NULL){
                printf("Erro ao ler a entrada!\n");
                exit(EXIT_FAILURE);
            }

            if(sscanf(buffer, "%d", &opc) == 1 && (opc >= 1 && opc <= 7)){
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
            if (cont == qtd_quartos)
            {
                printf("Nao e possivel cadastrar mais quartos!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                cadastrarQuarto();
            }
            system("PAUSE");
            system("cls");
            break;
        case 2:
            if (cont == 0)
            {
                printf("Nenhum quarto cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                listarQuartos();
            }
            system("PAUSE");
            system("cls");
            break;

        case 3:
            if (cont == 0)
            {
                printf("Nenhum quarto cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                tabela();
            }
            system("PAUSE");
            system("cls");
            break;
        case 4:
            if (cont == 0)
            {
                printf("Nenhum quarto cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                listarDisponiveis();
            }
            system("PAUSE");
            system("cls");
            break;
        case 5:
            if (cont == 0)
            {
                printf("Nenhum quarto cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                editarQuarto();
            }
            system("PAUSE");
            system("cls");
            break;
        case 6:
            if (cont == 0)
            {
                printf("Nenhum quarto cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                excluirQuarto();
            }
            system("PAUSE");
            system("cls");
            break;
        case 7:
            if (cont == 0)
            {
                printf("Nenhum quarto cadastrado!\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
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
    } while (opc != 0);
}