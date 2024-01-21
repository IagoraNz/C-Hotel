#include "menus.h"
#include "../Funcionario/cadastro_func.c"
#include "../Cliente/cadastro_cliente.c"

void menu_cadastro(){
    Funcionario funcionario;
    Clientes clientes;
    int opc;
    char buffer[tam];

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA       MENU CADASTRO     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Cadastrar cliente\n");
    printf("3 - Voltar\n");

    do{
        printf("Digite a opcao desejada: ");

        fgets(buffer, sizeof(buffer), stdin);

        if(sscanf(buffer, "%d", &opc) != 1){
            printf("Entrada invalida. Por favor, insira um numero inteiro.\n");
        }
    }while(opc < 1 || opc > 3);

    switch (opc)
    {
    case 1:
        cadastrar(&funcionario);
        break;
    case 2:
        Cadastro_Cliente(&clientes);
        break;
    default:
        break;
    }





}