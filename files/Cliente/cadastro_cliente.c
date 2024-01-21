#include "cliente.h"

void Cadastro_Cliente(Clientes *clientes){
    FILE *cliente;

    cliente = fopen("..\\db\\cliente.txt", "a");

    if (cliente == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Informe o Nome Completo do Cliente: ");
    scanf("%s", clientes->nome);

    printf("Informe a Idade: ");
    scanf("%d", clientes->idade);

    printf("Digite o CPF (no formato XXX.XXX.XXX-XX): ");
    if (scanf("%3d.%3d.%3d-%2d", &clientes->cpf1->bloco1, &clientes->cpf1->bloco2, &clientes->cpf1->bloco3, &clientes->cpf1->bloco4) == 4) {
        continue;
    } else {
        // Se a leitura falhar, exibe uma mensagem de erro
        printf("Formato de CPF inválido.\n");
    }

    printf("Informe o RG: ");
    scanf("%d", &clientes->rg);

    printf("Informe o Email: ");
    scanf("%99s", &clientes->email);

    printf("Informe o Telefone: ");
    scanf("%d", &clientes->telefone);

    printf("Informe a Cidade: ");
    scanf("%s", &clientes->cidade);

    printf("Informe o Estado: ");
    scanf("%d",&clientes->estado);
    
    fclose(cliente);

}