#include "checks.h"
#include "realizar_pagamento.c"


void attstatus(int numquarto)
{
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if (quartos == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temporario;

    temporario = fopen("..\\db\\quartos_temp.txt", "w");

    if (temporario == NULL)
    {
        printf("Erro ao abrir o arquivo temporário");
        fclose(quartos);
        exit(EXIT_FAILURE);
    }

    int encontrado = 0;

    while (fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5)
    {
        if(numquarto == quartos1.numquarto)
        {
            encontrado = 1;
            quartos1.status = 2;

            fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        }
        else
        {
            fprintf(temporario, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        }
    }

    fclose(quartos);
    fclose(temporario);

    if (!encontrado)
    {
        printf("Quarto nao encontrado.\n");
        remove("..\\db\\quartos_temp.txt");
    }
    else
    {
        remove("..\\db\\quartos.txt");
        rename("..\\db\\quartos_temp.txt", "..\\db\\quartos.txt");
        printf("Status atualizado com sucesso!\n");
    }
}

void checkin()
{
    FILE *quartos;
    FILE *clientes;
    FILE *reserva;

    Quartos quartos1;
    Reserva reserva1;

    Data dataini;
    Data datafim;

    quartos = fopen("..\\db\\quartos.txt", "r");
    clientes = fopen("..\\db\\clientes.txt", "r");
    reserva = fopen("..\\db\\reserva.txt", "r");

    int numquarto, aux1, aux2, aux3, aux4, codigocheck;

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      CHECKS      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    do{
        printf("Digite o CPF(XXX.XXX.XXX-XX): ");
    }while(scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4);

    printf("Digite o numero do quarto: ");
    scanf("%d", &numquarto);

    printf("Digite a data de entrada(dd/mm/aaaa): ");
    if(scanf("%2d/%2d/%4d", &dataini.dia, &dataini.mes, &dataini.ano) != 3){
        printf("Formato invalido!\n");
    }

    printf("Informe a hora de entrada(XX:XX): ");
    if(scanf("%2d:%d", &dataini.hora, &dataini.min) != 2){
        printf("Formato invalido!\n");
    }

    printf("Digite a data de saida(dd/mm/aaaa): ");
    if(scanf("%2d/%2d/%4d", &datafim.dia, &datafim.mes, &datafim.ano) != 3){
        printf("Formato invalido!\n");
    }

    printf("Informe a hora de saida(XX:XX) prevista: ");
    if(scanf("%2d:%d", &datafim.hora, &datafim.min) != 2){
        printf("Formato invalido!\n");
    }

    FILE *temporario;

    temporario = fopen("..\\db\\reserva_temp.txt", "w");

    if(temporario == NULL){
        printf("Erro ao abrir o arquivo temporário");
        fclose(reserva);
        exit(EXIT_FAILURE);
    }
    int enc = 0;
    char contcheck;
    
    while(fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20)
    {
        if(reserva1.cliente.bloco1 == aux1 && reserva1.cliente.bloco2 == aux2 && reserva1.cliente.bloco3 == aux3 && reserva1.cliente.bloco4 == aux4 && reserva1.quarto.numquarto == numquarto && reserva1.datai.dia == dataini.dia && reserva1.datai.mes == dataini.mes && reserva1.datai.ano == dataini.ano && reserva1.dataf.dia == datafim.dia && reserva1.dataf.mes == datafim.mes && reserva1.dataf.ano == datafim.ano)
        {
            printf("Deseja fazer o pagamento agora? (s/n): ");
            scanf(" %c", &contcheck);
            if (contcheck == 's')
            {
                Realizar_pagamento(&dataini, &reserva1);
                reserva1.status_pag = 2;
            }
            enc = 1;
            reserva1.datai.hora = dataini.hora;
            reserva1.datai.min = dataini.min;

            reserva1.dataf.hora = datafim.hora;
            reserva1.dataf.min = datafim.min;
            fprintf(temporario, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %.2f\n", reserva1.cod_reserva, reserva1.cliente.nome, reserva1.quarto.numquarto, reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano, reserva1.datai.hora, reserva1.datai.min, reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4, reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano, reserva1.dataf.hora, reserva1.dataf.min, reserva1.dias_reservado, reserva1.status_pag, reserva1.valor_total);
        }
        else{
            fprintf(temporario, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %.2f\n", reserva1.cod_reserva, reserva1.cliente.nome, reserva1.quarto.numquarto, reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano, reserva1.datai.hora, reserva1.datai.min, reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4, reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano, reserva1.dataf.hora, reserva1.dataf.min, reserva1.dias_reservado, reserva1.status_pag, reserva1.valor_total);
        }
    }

    printf("Digite o codigo da reserva: ");
    scanf("%d", &codigocheck);

    //Bota o ponteiro no inicio do arquivo
    fseek(reserva, 0, SEEK_SET);

    while(fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20)
    {
        if(reserva1.cliente.bloco1 == aux1 && reserva1.cliente.bloco2 == aux2 && reserva1.cliente.bloco3 == aux3 && reserva1.cliente.bloco4 == aux4 && reserva1.quarto.numquarto == numquarto && reserva1.datai.dia == dataini.dia && reserva1.datai.mes == dataini.mes && reserva1.datai.ano == dataini.ano && reserva1.dataf.dia == datafim.dia && reserva1.dataf.mes == datafim.mes && reserva1.dataf.ano == datafim.ano)
        {
            printf("Deseja fazer o checkin? (s/n): ");
            scanf(" %c", &contcheck);

            // Caso sim, realizer o checkin e mudar o status do quarto para ocupado
            if(contcheck == 's' && reserva1.cod_reserva == codigocheck){
                while (fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5)
                {
                    if(quartos1.numquarto == numquarto){
                        fclose(quartos);
                        attstatus(numquarto);
                    }
                }
                printf("Checkin realizado com sucesso!\n");
            }
            else{
                return;
            }
        }
    }

    fclose(reserva);
    fclose(temporario);

    if(!enc){
        printf("Reserva nao encontrada!\n");
        remove("..\\db\\reserva_temp.txt");
    }
    else{
        remove("..\\db\\reserva.txt");
        rename("..\\db\\reserva_temp.txt", "..\\db\\reserva.txt");
    }

    fclose(clientes);
}