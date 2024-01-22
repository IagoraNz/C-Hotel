#include "menus.h"

void logo() {
    FILE *contador;
    int logoExibido = 0;

    contador = fopen("..\\db\\contador.txt", "a+");

    if(contador == NULL){
        printf("Erro ao abrir o arquivo do contador!\n");
        return;
    }

    fscanf(contador, "%d", &logoExibido);

    if(logoExibido > 0){
        fclose(contador);
        return;
    }

    printf("                           (   )\n");
    printf("                          (    )\n");
    printf("                           (    )\n");
    printf("                          (    )\n");
    printf("                            )  )\n");
    printf("                           (  (                  /\\ \n");
    printf("                            (_)                 /  \\  /\\ \n");
    printf("                    ________[_]________      /\\/    \\/  \\ \n");
    printf("           /\\      /\\        ______    \\    /   /\\/\\  /\\/\\ \n");
    printf("          /  \\    //_\\       \\    /\\    \\  /\\/\\/    \\/    \\\n");
    printf("   /\\    / /\\/\\  //___\\       \\__/  \\    \\/\n");
    printf("  /  \\  /\\/    \\//____\\       \\ |[]|     \\\n");
    printf(" /\\/\\/\\/       //_______\\       \\|__|      \\\n");
    printf("/      \\      /XXXXXXXXXX\\                  \\\n");
    printf("        \\    /_I_II  I__I_\\__________________\\\n");
    printf("               I_I|  I__I_____[]_|_[]_____I\n");
    printf("               I_II  I__I_____[]_|_[]_____I\n");
    printf("               I II__I  I     XXXXXXX     I\n");
    printf("            ~~~~~\"   \"~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Seja bem-vindo ao Folklore Palace!\n");

    logoExibido++;

    // Retorna ao início do arquivo para escrever o novo valor
    fseek(contador, 0, SEEK_SET);
    fprintf(contador, "%d", logoExibido);

    fclose(contador);

    system("PAUSE");
}

int menu() {
    int opc;
    char buffer[tam];

    logo();  // Chama a função logo

    system("cls");

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA       MENU       \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - Cadastrar Funcionario\n");
    printf("2 - Login Funcionario\n");
    printf("3 - Sair\n");

    do{
        printf("Digite a opcao desejada: ");

        fgets(buffer, sizeof(buffer), stdin);
        if(sscanf(buffer, "%d", &opc) != 1){
            return menu();
        }
    }while(opc < 1 || opc > 3);

    return opc;
}
