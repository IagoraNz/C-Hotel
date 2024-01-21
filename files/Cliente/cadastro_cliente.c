#include "cliente.h"

void Cadastro_Cliente(Clientes *clientes){
    FILE *cliente;

    cliente = fopen("..\\db\\cliente.txt", "a");

    if (cliente == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Informe seu Usuario: ");
    scanf("%s", clientes->usuarioc);

    do{
        printf("Digite a senha (entre 8 e 10 caracteres): ");
        scanf("%s", clientes->senhac);
        if (strlen(clientes->senhac) < 8)
        {
            printf("Senha Curta!\nMinimo de 8 caracteres!\n");
        } else if (strlen(clientes->senhac) > 10)
        {
            printf("Senha Longa!\nMaximo de 10 caracteres!\n");
        }
    }while(strlen(clientes->senhac) < 8 || strlen(clientes->senhac) > 10);

    printf("Informe seu RG: ");
    scanf("%d", &clientes->rg);

    fprintf(cliente, "%s\n%s\n%d\n", clientes->usuarioc, clientes->senhac, clientes->rg);
    
    fclose(cliente);

}