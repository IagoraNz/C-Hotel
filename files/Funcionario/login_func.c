#include "funcionario.h"
#include "../Menus/menu_funcionario.c"

void login(Funcionario *funcionario){
    FILE *cadastro;
    char senha1[tam], usuario1[tam];

    cadastro = fopen("..\\db\\funcionario.txt", "r");

    if(cadastro == NULL){
        printf("Nenhum funcionario encontrado!\n");
        system("PAUSE");
        system("cls");
    }

    //O sistema deve ser capaz de ler vários cadastrados

    printf("Digite o nome do funcionario: ");
    scanf("%s", usuario1);

    printf("Digite a senha: ");
    scanf("%s", senha1);

    while(!feof(cadastro)){
        fscanf(cadastro, "%s\n%s\n", funcionario->usuario, funcionario->senha);

        if(strcmp(usuario1, funcionario->usuario) == 0 && strcmp(senha1, funcionario->senha) == 0){
            menu_funcionario();
            break;
        }
    }

    if(strcmp(usuario1, funcionario->usuario) != 0 || strcmp(senha1, funcionario->senha) != 0){
        printf("Usuario ou senha incorretos!\n");
        system("PAUSE");
        return login(funcionario);
    }

    fclose(cadastro);
}