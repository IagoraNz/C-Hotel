#include "funcionario.h"
#include <conio.h>
#include "../Menus/menu_funcionario.c"

#define tam 50

void esconder(char *senha1){
    int i = 0;
    char ch;

    while(1){
        ch = getch(); 
        if(ch == 13)
            break;
        else if(ch == 8 && i > 0){
            printf("\b \b");
            i--;
        } 
        else{
            senha1[i++] = ch;
            printf("*");
        }
    }

    senha1[i] = '\0';
}

void login(Funcionario *funcionario){
    FILE *cadastro;
    char senha1[tam], usuario1[tam];

    cadastro = fopen("..\\db\\funcionario.txt", "r");

    if(cadastro == NULL){
        printf("Nenhum funcionario encontrado!\n");
        system("PAUSE");
        system("cls");
    }

    do{
        printf("Digite o nome do funcionario: ");
        scanf("%s", usuario1);

        printf("Digite a senha: ");
        esconder(senha1);
    }while(strlen(usuario1) == 0 || strlen(senha1) == 0);

    while(!feof(cadastro)){
        fscanf(cadastro, "%s\n%s\n", funcionario->usuario, funcionario->senha);

        if(strcmp(usuario1, funcionario->usuario) == 0 && strcmp(senha1, funcionario->senha) == 0){
            menu_funcionario();
            break;
        }
    }

    if(strcmp(usuario1, funcionario->usuario) != 0 || strcmp(senha1, funcionario->senha) != 0){
        printf("\n\nUsuario ou senha incorretos!\n\n");
        system("PAUSE");
        system("cls");
        printf("\n\n");
        return login(funcionario);
    }

    fclose(cadastro);
}
