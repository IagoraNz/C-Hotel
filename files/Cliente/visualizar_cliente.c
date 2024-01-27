#include "cliente.h"

void Listar_Clientes(){
    FILE *cliente;
    Clientes cliente1;

    cliente = fopen("..\\db\\cliente.txt", "r");
    if(cliente == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
        return;
    }

    while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade, 
    &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
    &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) == 11){

        printf("Nome: %s\n", cliente1.nome);
        printf("Idade: %d\n", cliente1.idade);
        printf("CPF: %03d.%03d.%03d-%02d\n", cliente1.bloco1,cliente1.bloco2,cliente1.bloco3,cliente1.bloco4);
        printf("RG: %d\n", cliente1.rg);
        printf("E-Mail: %s\n", cliente1.email);
        printf("Telefone: %s\n", cliente1.telefone);
        printf("Cidade: %s\n", cliente1.cidade);
        printf("Estado: %s\n", cliente1.estado);
        printf("\n\n");
    }
    fclose(cliente);
    system("PAUSE");
}