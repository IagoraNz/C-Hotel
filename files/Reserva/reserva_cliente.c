#include "reserva.h"
#include "calendario.c"
#include "atualizar_status.c"

void Reservar_Cliente(){
    Reserva reserva1;
    FILE *reserva;
    FILE *quarto1;
    FILE *cliente1;
    int aux1, aux2, aux3, aux4, num = 0, numquarto;

    cliente1 = fopen("..\\db\\cliente.txt", "r");

    if(cliente1 == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    printf("Informe o CPF(XXX.XXX.XXX-XX): ");
    if(scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4){
        printf("Formato de CPF invalido!\n");
        return;
    }

    while(fscanf(cliente1, "%s %d %03d.%03d.%03d-%02d %d %s %s %s %s\n", reserva1.cliente.nome, &reserva1.cliente.idade, &reserva1.cliente.bloco1, &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.cliente.rg, reserva1.cliente.email, reserva1.cliente.telefone, reserva1.cliente.cidade, reserva1.cliente.estado) == 11)
    {
        if (aux1 == reserva1.cliente.bloco1 && aux2 == reserva1.cliente.bloco2 && aux3 == reserva1.cliente.bloco3 && aux4 == reserva1.cliente.bloco4)
        {
            printf("Cliente encontrado com sucesso!\n");
            printf("Deseja verificar os quartos disponiveis(1 - Sim 2 - Nao): ");
            scanf("%d", &num);

            if(num == 1){
                listarDisponiveis();
            }
            
            printf("Informe o numero do quarto: ");
            scanf("%d", &numquarto);

            quarto1 = fopen("..\\db\\quartos.txt", "r+");
            while (fscanf(quarto1, "%d%d%d%f%d", &reserva1.quarto.tipo, &reserva1.quarto.numquarto, &reserva1.quarto.status, &reserva1.quarto.diaria, &reserva1.quarto.capacidade) == 5)
            {
                if (reserva1.quarto.status == 1 && numquarto == reserva1.quarto.numquarto)
                {
                    printf("Tipo: ");
                    if (reserva1.quarto.tipo == 1)
                    {
                        printf("Luxo\n");
                    }
                    else if (reserva1.quarto.tipo == 2)
                    {
                        printf("Executivo\n");
                    }
                    else if (reserva1.quarto.tipo == 3)
                    {
                        printf("Simples\n");
                    }
                    else
                    {
                        printf("Tipo invalido!\n");
                    }
                    printf("Numero: %d\n", reserva1.quarto.numquarto);
                    printf("Valor da diaria: %.2f\n", reserva1.quarto.diaria);
                    printf("Capacidade: ");
                    if (reserva1.quarto.capacidade == 1)
                    {
                        printf("Solteiro\n");
                    }
                    else if (reserva1.quarto.capacidade == 2)
                    {
                        printf("Casal\n");
                    }
                    else
                    {
                        printf("Capacidade invalida!\n");
                    }
                    printf("\n");

                    printf("Deseja reservar esse quarto?(1 - sim ou 2 - nao): ");
                    scanf("%d", &num);

                    if (num == 1)
                    {
                        // maincalendario();
                        printf("Informe a data da entrada(XX/XX/XXX): ");
                        if(scanf("%2d/%2d/%4d", &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano) != 3){
                            printf("Formato invalido!\n");
                        }
                        
                        printf("Informe a data de saida(XX/XX/XXX): ");
                        if(scanf("%2d/%2d/%4d", &reserva1.dataf.dia, &reserva1.dataf.mes, &reserva1.dataf.ano) != 3){
                            printf("Formato invalido!\n");
                        }

                        if (reserva1.datai.ano > reserva1.dataf.ano)
                        {
                            printf("Nao e possivel alugar um quarto!\n");
                            break;
                        }
                        fclose(quarto1);
                        Atualizar_Status(numquarto);

                        
                    }
                }
            }
        }
    }

    fclose(cliente1);

    reserva = fopen("..\\db\\reserva.txt", "a");

    if(reserva == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
    fclose(reserva);
}