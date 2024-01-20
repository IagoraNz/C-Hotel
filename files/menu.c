#include "struct.h"

int menu(){
    int opc;
    char buffer[tam];

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA       MENU       \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Logar\n");
    printf("3 - Sair\n");
    do{
        printf("Digite a opcao desejada: ");

        fgets(buffer, sizeof(buffer), stdin);

        if(sscanf(buffer, "%d", &opc) != 1){
            printf("Entrada invalida. Por favor, insira um numero inteiro.\n");
        }
    }while(opc < 1 || opc > 3);

    return opc;
}