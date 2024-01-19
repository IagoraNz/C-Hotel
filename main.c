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
    int tipo;
    int numquarto;
    int status;
} Quartos;

void cadastrarQuarto(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("quartos.txt", "a");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("TIPOS\n");
    printf("1 - Luxo\n");
    printf("2 - Executivo\n");
    printf("3 - Simples\n");
    printf("Digite o tipo do quarto: ");
    scanf("%d", &quartos1.tipo);

    printf("Digite o numero do quarto: ");
    scanf("%d", &quartos1.numquarto);

    printf("STATUS\n");
    printf("1 - Disponivel\n");
    printf("2 - Ocupado\n");
    printf("3 - Reservado\n");
    printf("Digite o status do quarto: ");
    scanf("%d", &quartos1.status);

    fprintf(quartos, "%d\n%d\n%d\n", quartos1.tipo, quartos1.numquarto, quartos1.status);

    fclose(quartos);
}

void listarQuartos(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      LISTAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    while(!feof(quartos)){
        fscanf(quartos, "%d\n%d\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status);

        printf("Tipo: ");
        if(quartos1.tipo == 1){
            printf("Luxo");
        }
        else if(quartos1.tipo == 2){
            printf("Executivo");
        }
        else if(quartos1.tipo == 3){
            printf("Simples");
        }
        else{
            printf("Tipo invalido!\n");
        }
        printf("\n");
        printf("Numero: %d", quartos1.numquarto);
        printf("\n");
        printf("Status: ");
        if(quartos1.status == 1){
            printf("Disponivel");
        }
        else if(quartos1.status == 2){
            printf("Ocupado");
        }
        else if(quartos1.status == 3){
            printf("Reservado");
        }
        else{
            printf("Status invalido!");
        }
        printf("\n\n");
    }

    fclose(quartos);
}

void consultarQuartos(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    while(!feof(quartos)){
        fscanf(quartos, "%d\n%d\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status);

        if(quartos1.status == 1){
            printf("Tipo: ");
            if(quartos1.tipo == 1){
                printf("Luxo\n");
            }
            else if(quartos1.tipo == 2){
                printf("Executivo\n");
            }
            else if(quartos1.tipo == 3){
                printf("Simples\n");
            }
            else{
                printf("Tipo invalido!\n");
            }
            printf("Numero: %d\n", quartos1.numquarto);
        }
    }
}

void menufuncionario(){
    int opc;

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA       MENU       \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - Cadastrar quartos\n");
    printf("2 - Listar todos os quartos\n");
    printf("3 - Consultar quartos disponiveis\n");
    printf("4 - Editar quartos\n");
    printf("5 - Excluir quartos\n");
    printf("6 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opc);

    switch(opc){
        case 1:
            cadastrarQuarto();
            system("PAUSE");
            system("cls");
            return menufuncionario();
            break;
        case 2:
            listarQuartos();
            system("PAUSE");
            system("cls");
            return menufuncionario();
            break;
        case 3:
            consultarQuartos();
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