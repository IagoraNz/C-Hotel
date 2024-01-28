#include "cliente.h"

void Editar_Cliente(){
    FILE *cliente;
    Clientes cliente1;

    cliente = fopen("..\\db\\cliente.txt", "r");

    if (cliente == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temporario;

    temporario = fopen("..\\db\\cliente_temp.txt", "w");

    if (temporario == NULL) {
        printf("Erro ao abrir o arquivo temporário");
        fclose(cliente);
        exit(EXIT_FAILURE);
    }

    int aux1, aux2, aux3, aux4, carac;
    int encontrado = 0;

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EDITAR      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("Informe o CPF (no formato XXX.XXX.XXX-XX): ");
        if (scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4) {
            printf("Formato de CPF inválido.\n");
            // Tratamento de erro, se necessário
            fclose(cliente);
            fclose(temporario);
            return;
        }

    while (fscanf(cliente, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", cliente1.nome, &cliente1.idade, 
            &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4,
            &cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado) == 11){
                if (aux1 == cliente1.bloco1 && aux2 == cliente1.bloco2 && aux3 == cliente1.bloco3 && aux4 == cliente1.bloco4){
                    encontrado = 1;
                    printf("Cliente encontrado!\n");
                    replaceUnderscoreWithSpace(cliente1.nome);
                    printf("1 - Nome: %s\n", cliente1.nome);
                    printf("2 - Idade: %d\n", cliente1.idade);
                    printf("3 - CPF: %3d.%3d.%3d-%2d\n", cliente1.bloco1, cliente1.bloco2, cliente1.bloco3, cliente1.bloco4);
                    printf("4 - RG: %d\n", cliente1.rg);
                    printf("5 - E-mail: %s\n", cliente1.email);
                    printf("6 - Telefone: %s\n", cliente1.telefone);
                    printf("7 - Endereco: %s - %s\n", cliente1.cidade, cliente1.estado);
                    printf("Digite qual caracteristica deseja atualizar: ");
                    scanf("%d", &carac);

                    switch (carac)
                    {
                    case 1:
                        printf("Informe o novo nome do Cliente: ");
                        scanf(" %[^\n]", cliente1.nome);
                        replaceSpaceWithUnderscore(cliente1.nome);
                        break;
                    case 2:
                        printf("Informe a Nova Idade: ");
                        scanf("%d", &cliente1.idade);
                        break;
                    case 3:
                        printf("Digite o novo CPF (no formato XXX.XXX.XXX-XX): ");
                        if (scanf("%3d.%3d.%3d-%2d", &cliente1.bloco1, &cliente1.bloco2, &cliente1.bloco3, &cliente1.bloco4) != 4) {
                            printf("Formato de CPF inválido.\n");
                            // Tratamento de erro, se necessário
                            fclose(cliente);
                            return;
                        }
                        break;
                    case 4:
                        printf("Informe o novo RG: ");
                        scanf("%d", &cliente1.rg);
                        break;
                    case 6:
                        printf("Informe o Telefone: ");
                        scanf("%s", cliente1.telefone);
                        break;
                    case 5:
                        printf("Informe o Email: ");
                        scanf("%s", cliente1.email);
                        break;
                    
                    case 7:
                        printf("Informe a Cidade: ");
                        scanf("%s", cliente1.cidade);
                        printf("Informe o Estado: ");
                        scanf("%s", cliente1.estado);
                        break;               
                    default:
                        break;
                    }
                    fprintf(temporario, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n",
                            cliente1.nome, cliente1.idade,
                            cliente1.bloco1, cliente1.bloco2, cliente1.bloco3, cliente1.bloco4,
                            cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado);
                } else{
                    fprintf(temporario, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n",
                            cliente1.nome, cliente1.idade,
                            cliente1.bloco1, cliente1.bloco2, cliente1.bloco3, cliente1.bloco4,
                            cliente1.rg, cliente1.email, cliente1.telefone, cliente1.cidade, cliente1.estado);
                }

            }
            fclose(cliente);
            fclose(temporario);
            if(!encontrado){
                printf("Cliente não encontrado.\n");
                remove("..\\db\\cliente_temp.txt"); 
            } 
            else{
                remove("..\\db\\cliente.txt");
                rename("..\\db\\cliente_temp.txt", "..\\db\\cliente.txt");
                printf("Informacoes sobre Cliente editado com sucesso!\n");
            }
}

