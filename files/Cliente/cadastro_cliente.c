#include "cliente.h"
#include "../Menus/menus.h"
#include "Extras/funcao02.c"

void Cadastro_Cliente(Clientes *clientes) {
    FILE *cliente;
    char cont[1];

    cliente = fopen("..\\db\\cliente.txt", "a");

    if (cliente == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fclose(cliente);

    printf("Informe o nome completo do cliente: ");
    
    // Use o modificador %[^'\n'] para ler uma string até encontrar uma nova linha
    scanf(" %[^\n]", clientes->nome);

    // Substitua espaços por underscores
    replaceSpaceWithUnderscore(clientes->nome);

    printf("Informe a Idade: ");
    scanf("%d", &clientes->idade);
    if (clientes->idade < 18)
    {
        printf("O Cliente deve ter +18!\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", cont);
        if((strcmp(cont, "s") == 0) || (strcmp(cont, "S") == 0)){
            return Cadastro_Cliente(clientes);
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
        printf("Formato de CPF inválido.\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", cont);
        if((strcmp(cont, "s") == 0) || (strcmp(cont, "S") == 0)){
            return Cadastro_Cliente(clientes);
        }
        else{
            return menuClientes();
        }
    }


    printf("Informe o RG: ");
    scanf("%d", &RG);

    printf("Informe o Telefone: ");
    scanf(" %[^\n]", Telefone);

    printf("Informe o Email: ");
    scanf(" %[^\n]", Email);

    aux1 = clientes->bloco1;
    aux2 = clientes->bloco2;
    aux3 = clientes->bloco3;
    aux4 = clientes->bloco4;

    cliente = fopen("..\\db\\cliente.txt", "r");

    while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", clientes->nome, &clientes->idade, 
    &clientes->bloco1, &clientes->bloco2, &clientes->bloco3, &clientes->bloco4,
    &clientes->rg, clientes->email, clientes->telefone, clientes->cidade, clientes->estado) == 11){
        if (RG == clientes->rg)
        {
            printf("RG ja existe no banco de dados!\n");
            enc = 0;
        } else if (strcmp(Telefone, clientes->telefone) == 0)
        {
            printf("Telefone ja existe no banco de dados!\n");
            enc = 0;
        } else if (strcmp(Email, clientes->email) == 0)
        {
            printf("Email ja existe no banco de dados!\n");
            enc = 0;
        } else if (aux1 == clientes->bloco1 && aux2 == clientes->bloco2 && aux3 == clientes->bloco3 && aux4 == clientes->bloco4)
        {
            printf("CPF ja existe no banco de dados!\n");
            enc = 0;
        }
    }

    fclose(cliente);

    if (!enc)
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

    printf("Informe a Cidade: ");
    scanf("%s", clientes->cidade);

    printf("Informe o Estado: ");
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