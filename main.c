#include "./files/struct.h"
#include "./files/struct.c"

#include "./files/Menus/menus.h"
#include "./files/Menus/menu.c"

#include "./files/Quartos/quartos.h"
#include "./files/Quartos/def_predio.c"

#include "./files/Funcionario/cadastro_func.c"
#include "./files/Funcionario/login_func.c"

int main()
{
    int opcao, cont;
    Funcionario funcionario;

    Definindo_Predio();

    FILE *func;

    do
    {
        opcao = menu();
        func = fopen("..\\db\\funcionario.txt", "r");
        if (func == NULL)
        {
            cont = 0;
        } else
        {
            cont = 1;
        }
        fclose(func);
        switch (opcao)
        {
        case 1:
            cadastrar(&funcionario);
            system("PAUSE");
            system("cls");
            break;
        case 2:
            if (cont == 1)
            {
                login(&funcionario);
            }
            else
            {
                printf("Nenhum funcionario cadastrado!\n");
                printf("Deseja cadastrar um funcionario? (s/n): ");
                char input[1];
                scanf("%s", input);
                if (input[0] == 's' || input[0] == 'S')
                {
                    cadastrar(&funcionario);
                }
            }
            system("PAUSE");
            system("cls");
            break;
        default:
            exit(EXIT_FAILURE);
        }
    } while (opcao != 3);
}