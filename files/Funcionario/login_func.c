#include "funcionario.h"
#include "menu_func.c"

void login(Funcionario *funcionario){
    FILE *cadastro;
    char senha1[tam], usuario1[tam];

    cadastro = fopen("..\\db\\funcionario.txt", "r");

    if(cadastro == NULL){
        printf("Nenhum Funcionario Encontrado!\n");
        system("PAUSE");
        system("cls");
        return main();
    }

    fscanf(cadastro, "%s\n%s\n", funcionario->usuario, funcionario->senha);

    do{
        printf("Digite o usuario: ");
        scanf("%s", usuario1);

        printf("Digite a senha: ");
        scanf("%s", senha1);

        if(strcmp(usuario1, funcionario->usuario) == 0 && strcmp(senha1, funcionario->senha) == 0){
            system("cls");
            menufuncionario();
        }
        else{
            if(strcmp(usuario1, funcionario->usuario) != 0){
                printf("Usuario invalido!\n");
            }
            else if(strcmp(senha1, funcionario->senha) != 0){
                printf("Senha invalida!\n");
            }
        }
    }while(strcmp(usuario1, funcionario->usuario) != 0 || strcmp(senha1, funcionario->senha) != 0);

    fclose(cadastro);
}