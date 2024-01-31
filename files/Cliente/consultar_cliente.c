#include "cliente.h"
#include "Extras/funcao01.c"

int stringparaintc1(const char str[]) {
    int result = 0, i;
    for (i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } 
        else{
            return -1;
        }
    }
    return result;
}

void Consultar_Cliente(){
    FILE *cliente;
    Clientes cliente1;
    int opc, aux1, aux2, aux3, aux4;
    char auxs[maxnome];
    

    cliente = fopen("..\\db\\cliente.txt", "r");
    if(cliente == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
        return;
    }

    char input[1];

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      CONSULTAR     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("1 - Nome\n2 - CPF\n3 - RG\n");
    printf("Informe sua opcao: ");
    scanf("%s", input);

    opc = stringparaintc1(input);

    if(opc < 1 || opc > 3 || opc == -1){
        printf("Opcao invalida!\n");
        printf("Deseja tentar a consulta novamente? (s/n): ");
        scanf("%s", input);
        system("PAUSE");
        if(input[0] == 's' || input[0] == 'S'){
            Consultar_Cliente();
        }
        else{
            return;
        }
    }

    switch (opc)
    {
    case 1:
        printf("Informe o nome: ");
        scanf(" %[^\n]", auxs);
        replaceSpaceWithUnderscore(auxs);
        while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade, 
        &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
        &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) == 11){
            if (strcmp(auxs, cliente1.nome) == 0)
            {   
                replaceUnderscoreWithSpace(cliente1.nome);
                printf("\nCliente encontrado!\n\n");
                printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
                printf("\xBA      CLIENTE     \xBA\n");
                printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
                printf("Nome: %s\n", cliente1.nome);
                printf("Idade: %d\n", cliente1.idade);
                printf("CPF: %03d.%03d.%03d-%02d\n", cliente1.bloco1,cliente1.bloco2,cliente1.bloco3,cliente1.bloco4);
                printf("RG: %d\n", cliente1.rg);
                printf("E-Mail: %s\n", cliente1.email);
                printf("Telefone: %s\n", cliente1.telefone);
                printf("Cidade: %s\n", cliente1.cidade);
                printf("Estado: %s\n", cliente1.estado);
                printf("\n");
            }
        }
        fclose(cliente);
        printf("Deseja fazer outra consulta? (s/n): ");
        scanf("%s", input);
        if(input[0] == 's' || input[0] == 'S'){
            Consultar_Cliente();
        }
        else{
            return;
        }
        break;
    case 2:
        printf("Digite o CPF (no formato XXX.XXX.XXX-XX): ");
        if (scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4) {
            printf("Formato de CPF inválido.\n");

            fclose(cliente);
            exit(EXIT_FAILURE);
        }
        while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade, 
            &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
            &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) == 11){
            if (aux1 == cliente1.bloco1 && aux2 == cliente1.bloco2 && aux3 == cliente1.bloco3 && aux4 == cliente1.bloco4)
                {
                    printf("\nCliente encontrado!\n\n");
                    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
                    printf("\xBA      CLIENTE     \xBA\n");
                    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
                    replaceUnderscoreWithSpace(cliente1.nome);
                    printf("Nome: %s\n", cliente1.nome);
                    printf("Idade: %d\n", cliente1.idade);
                    printf("CPF: %03d.%03d.%03d-%02d\n", cliente1.bloco1,cliente1.bloco2,cliente1.bloco3,cliente1.bloco4);
                    printf("RG: %d\n", cliente1.rg);
                    printf("E-Mail: %s\n", cliente1.email);
                    printf("Telefone: %s\n", cliente1.telefone);
                    printf("Cidade: %s\n", cliente1.cidade);
                    printf("Estado: %s\n", cliente1.estado);
                    printf("\n");
                }
            }
        fclose(cliente);
        printf("Deseja fazer outra consulta? (s/n): ");
        scanf("%s", input);
        if(input[0] == 's' || input[0] == 'S'){
            Consultar_Cliente();
        }
        else{
            return;
        }
        break;
    case 3:
        printf("Informe o RG: ");
        scanf("%d", &aux1);
        while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade, 
            &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
            &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) == 11){
            if (aux1 == cliente1.rg)
                {
                    printf("\nCliente encontrado!\n\n");
                    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
                    printf("\xBA      CLIENTE     \xBA\n");
                    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
                    replaceUnderscoreWithSpace(cliente1.nome);
                    printf("Nome: %s\n", cliente1.nome);
                    printf("Idade: %d\n", cliente1.idade);
                    printf("CPF: %03d.%03d.%03d-%02d\n", cliente1.bloco1,cliente1.bloco2,cliente1.bloco3,cliente1.bloco4);
                    printf("RG: %d\n", cliente1.rg);
                    printf("E-Mail: %s\n", cliente1.email);
                    printf("Telefone: %s\n", cliente1.telefone);
                    printf("Cidade: %s\n", cliente1.cidade);
                    printf("Estado: %s\n", cliente1.estado);
                    printf("\n");
                }
            }
        fclose(cliente);
        printf("Deseja fazer outra consulta? (s/n): ");
        scanf("%s", input);
        if(input[0] == 's' || input[0] == 'S'){
            Consultar_Cliente();
        }
        else{
            return;
        }
        break;
    default:
        break;
    }
}