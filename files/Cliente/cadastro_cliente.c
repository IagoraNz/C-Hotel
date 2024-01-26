#include "cliente.h"

void Cadastro_Cliente(Clientes *clientes) {
    FILE *cliente;

    cliente = fopen("..\\db\\cliente.txt", "a");

    if (cliente == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    printf("Informe o nome completo do cliente: ");
    scanf("%s", clientes->nome);

    printf("Informe a Idade: ");
    scanf("%d", &clientes->idade);

    printf("Digite o CPF (no formato XXX.XXX.XXX-XX): ");
    if (scanf("%3d.%3d.%3d-%2d", &clientes->bloco1, &clientes->bloco2, &clientes->bloco3, &clientes->bloco4) != 4) {
        printf("Formato de CPF inválido.\n");
        // Tratamento de erro, se necessário
        fclose(cliente);
        exit(EXIT_FAILURE);
    }

    printf("Informe o RG: ");
    scanf("%d", &clientes->rg);

    printf("Informe o Telefone: ");
    scanf("%s", clientes->telefone);

    printf("Informe o Email: ");
    scanf("%s", clientes->email);

    printf("Informe a Cidade: ");
    scanf("%s", clientes->cidade);

    printf("Informe o Estado: ");
    scanf("%s", clientes->estado);

    fprintf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n",
            clientes->nome, clientes->idade,
            clientes->bloco1, clientes->bloco2, clientes->bloco3, clientes->bloco4,
            clientes->rg, clientes->email, clientes->telefone, clientes->cidade, clientes->estado);

    fclose(cliente);
}
