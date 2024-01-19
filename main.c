#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

typedef struct funcionario {
    char senha[tam];
    char usuario[tam];
} Funcionario;

void cadastrar(Funcionario funcionario){
    FILE *cadastro;

    cadastro = fopen("cadastro.txt", "a");

    if(cadastro == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Cadastre o nome do funcionario: ");
    scanf("%s", funcionario.usuario);

    printf("Digite a senha: ");
    scanf("%s", funcionario.senha);

    fprintf(cadastro, "%s %s\n", funcionario.usuario, funcionario.senha);

    fclose(cadastro);
}

void login(Funcionario funcionario){
    FILE *cadastro;
    char senha1[tam], usuario1[tam];

    cadastro = fopen("cadastro.txt", "r");

    if(cadastro == NULL){
        printf("Erro ao executar o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Digite o usuário: ");
    scanf("%s", usuario1);

    printf("Digite a senha: ");
    scanf("%s", senha1);

    if(usuario1 == )
}

int main(){

    int opcao;
    Funcionario funcionario;

    FILE *cadastro;

    printf("----- MENU -----\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Logar\n");
    printf("3 - Cadastrar cliente\n");
    printf("3 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            cadastrar(funcionario);
            break;
        case 2:
            login(funcionario);
            break;
        case 3:
            break;
        case 4:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida!");
            break;
    }

    return 0;
}
