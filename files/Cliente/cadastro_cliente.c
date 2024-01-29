#include "cliente.h"
#include "../Menus/menus.h"
#include "Extras/funcao02.c"

int stringparainteditcadc(const char str[]) {
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

void Cadastro_Cliente(Clientes *clientes) {
    FILE *cliente;
    char input[1];
    Clientes cliente1;

    cliente = fopen("..\\db\\cliente.txt", "a");

    if (cliente == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fclose(cliente);

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA     CLIENTES     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("Digite o nome completo do cliente: ");
    
    // Use o modificador %[^'\n'] para ler uma string até eninputrar uma nova linha
    scanf(" %[^\n]", clientes->nome);

    // Substitua espaços por underscores
    replaceSpaceWithUnderscore(clientes->nome);

    printf("Digite a idade: ");
    scanf("%s", input);

    clientes->idade = stringparainteditcadc(input);

    if (clientes->idade < 18 || clientes->idade == -1)
    {
        printf("O cliente deve ter +18 ou idade invalida!\n");
        printf("Deseja tentar editar novamente (s/n)?: ");
        scanf("%s", input);
        fclose(cliente);
        if((strcmp(input, "s") == 0) || (strcmp(input, "S") == 0)){
            return Cadastro_Cliente(&cliente1);
        }
        else{
            return menuClientes();
        }
    }
    int idade = clientes->idade;
    int RG, aux1, aux2, aux3, aux4, enc = 1;
    char Telefone[maxnome], Email[maxnome];

    printf("Digite o CPF (no formato XXX.XXX.XXX-XX): ");
    if (scanf("%3d.%3d.%3d-%2d", &clientes->bloco1, &clientes->bloco2, &clientes->bloco3, &clientes->bloco4) != 4) {
        printf("Formato de CPF invalido.\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", input);
        if((strcmp(input, "s") == 0) || (strcmp(input, "S") == 0)){
            return Cadastro_Cliente(&cliente1);
        }
        else{
            return menuClientes();
        }
    }

    printf("Digite o RG: ");
    scanf("%s", input);

    RG = stringparainteditcadc(input);

    if(RG == -1){
        printf("RG invalido!\n");
        printf("Deseja tentar o cadastro novamente(s/n)?: ");
        scanf("%s", input);
        if((strcmp(input, "s") == 0) || (strcmp(input, "S") == 0)){
            return cadastrarQuarto(&cliente1);
        }
        else{
            return menuClientes();
        }
    }

    printf("Digite o telefone, incluindo o DDD: ");
    scanf(" %[^\n]", Telefone);

    if(strlen(Telefone) != 11)
    {
        printf("Telefone invalido!\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", input);
        if((strcmp(input, "s") == 0) || (strcmp(input, "S") == 0)){
            return cadastrarQuarto(&cliente1);
        }
        else{
            return menuClientes();
        }
    }

    printf("Digite o email: ");
    scanf(" %[^\n]", Email);

    aux1 = clientes->bloco1;
    aux2 = clientes->bloco2;
    aux3 = clientes->bloco3;
    aux4 = clientes->bloco4;

    cliente = fopen("..\\db\\cliente.txt", "r");

    while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", clientes->nome, &clientes->idade, 
    &clientes->bloco1, &clientes->bloco2, &clientes->bloco3, &clientes->bloco4,
    &clientes->rg, clientes->email, clientes->telefone, clientes->cidade, clientes->estado) == 11){
        if(RG == clientes->rg)
        {
            printf("RG ja existe no banco de dados!\n");
            enc = 0;
        } 
        else if(strcmp(Telefone, clientes->telefone) == 0)
        {
            printf("Telefone ja existe no banco de dados!\n");
            enc = 0;
        } 
        else if(strcmp(Email, clientes->email) == 0)
        {
            printf("Email ja existe no banco de dados!\n");
            enc = 0;
        } 
        else if (aux1 == clientes->bloco1 && aux2 == clientes->bloco2 && aux3 == clientes->bloco3 && aux4 == clientes->bloco4)
        {
            printf("CPF ja existe no banco de dados!\n");
            enc = 0;
        }
    }

    fclose(cliente);

    if(!enc)
    {
        printf("Nao e possivel cadastrar esse cliente!\n");
        system("PAUSE");
        return;
    }

    clientes->idade = idade;
    clientes->rg = RG;
    strcpy(clientes->telefone, Telefone);
    strcpy(clientes->email, Email);
    clientes->bloco1 = aux1;
    clientes->bloco2 = aux2;
    clientes->bloco3 = aux3;
    clientes->bloco4 = aux4;

    printf("Digite a cidade: ");
    scanf("%s", clientes->cidade);

    printf("Digite o estado: ");
    scanf("%s", clientes->estado);

    cliente = fopen("..\\db\\cliente.txt", "a");

    if (cliente == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n",
            clientes->nome, clientes->idade,
            clientes->bloco1, clientes->bloco2, clientes->bloco3, clientes->bloco4,
            clientes->rg, clientes->email, clientes->telefone, clientes->cidade, clientes->estado);

    fclose(cliente);
}