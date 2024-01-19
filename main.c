#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50
#define maxsenha 10

typedef struct funcionario {
    char senha[tam];
    char usuario[maxsenha];
} Funcionario;

typedef struct quartos {
    char tipo[tam];
    int numquarto[3];
    char status[tam];
} Quartos;

void menufuncionario(){
    int opc;

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA       MENU       \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - Cadastrar quartos\n");
    printf("2 - Consultar quartos\n");
    printf("3 - Editar quartos\n");
    printf("4 - Excluir quartos\n");
    printf("5 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opc);

    switch(opc){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void cadastrar(Funcionario *funcionario){
    FILE *cadastro;

    cadastro = fopen("cadastro.txt", "a");

    if(cadastro == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Cadastre o nome do funcionario: ");
    scanf("%s", funcionario->usuario);

    do{
        printf("Digite a senha (entre 8 e 10 caracteres): ");
        scanf("%s", funcionario->senha);
    }while(strlen(funcionario->senha) < 8 || strlen(funcionario->senha) > 10);

    fprintf(cadastro, "%s\n%s\n", funcionario->usuario, funcionario->senha);

    fclose(cadastro);
}

void login(Funcionario *funcionario){
    FILE *cadastro;
    char senha1[tam], usuario1[tam];

    cadastro = fopen("cadastro.txt", "r");

    if(cadastro == NULL){
        printf("Erro ao executar o arquivo");
        exit(EXIT_FAILURE);
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

int menu(){
    int opc;

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA       MENU       \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Logar\n");
    printf("3 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opc);

    return opc;
}

int main(){

    int opcao;
    Funcionario funcionario;

    opcao = menu();

    switch(opcao){
        case 1:
            cadastrar(&funcionario);
            system("PAUSE");
            system("cls");
            return main(); //Aqui é para retornar ao menu, que está no início do main
            break;
        case 2:
            login(&funcionario);
            system("PAUSE");
            system("cls");
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}