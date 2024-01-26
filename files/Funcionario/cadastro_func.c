#include "funcionario.h"
#include "verificar_funcionario.c"

void cadastrar(Funcionario *funcionario)
{

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA        FUNCIONARIO       \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    FILE *cadastro;
    printf("Cadastre o nome do funcionario: ");
    scanf("%s", funcionario->usuario);

    if (verificar_funcionario(funcionario->usuario))
    {
        printf("O nome %s ja existe no banco de dados.\n", funcionario->usuario);
        return;
    }

    cadastro = fopen("..\\db\\funcionario.txt", "a");

    if (cadastro == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    do
    {
        printf("Digite a senha (entre 8 e 10 caracteres): ");
        scanf("%s", funcionario->senha);
        if (strlen(funcionario->senha) < 8)
        {
            printf("Senha Curta!\nMinimo de 8 caracteres!\n");
        }
        else if (strlen(funcionario->senha) > 10)
        {
            printf("Senha Longa!\nMaximo de 10 caracteres!\n");
        }
    } while (strlen(funcionario->senha) < 8 || strlen(funcionario->senha) > 10);

    fprintf(cadastro, "%s\n%s\n", funcionario->usuario, funcionario->senha);
    fclose(cadastro);
}