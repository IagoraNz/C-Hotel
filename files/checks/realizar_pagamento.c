#include "checks.h"

void Realizar_pagamento(Data *datapag, Reserva *reserva1)
{
    FILE *pagamento;
    Pagamento pagamento1;
    int opc;

    pagamento1.datap.ano = datapag->ano;

    pagamento1.datap.mes = datapag->mes;

    pagamento1.datap.dia = datapag->dia;

    pagamento1.datap.hora = datapag->hora;

    pagamento1.datap.min = datapag->min;

    strcpy(pagamento1.cliente.nome, reserva1->cliente.nome);

    pagamento1.valor_total = reserva1->valor_total;

    pagamento1.cliente.bloco1 = reserva1->cliente.bloco1;
    pagamento1.cliente.bloco2 = reserva1->cliente.bloco2;
    pagamento1.cliente.bloco3 = reserva1->cliente.bloco3;
    pagamento1.cliente.bloco4 = reserva1->cliente.bloco4;

    printf("Forma de Pagamento:\n");
    printf("1 - Pix\n2 - Especie\n3 - Cartao\n");
    printf("Digite a opcao: ");
    scanf("%d", &opc);
    if (opc == 1)
    {
        pagamento1.forma_pag = 1;
        pagamento1.cartao = 0;
    }
    else if (opc == 2)
    {
        pagamento1.forma_pag = 2;
        pagamento1.cartao = 0;
    }
    else if (opc == 3)
    {
        pagamento1.forma_pag = 3;
        printf("1 - Debito\n2 - Credito\n");
        printf("Digite a opcao: ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            pagamento1.cartao = 1;
        }
        else if (opc == 2)
        {
            pagamento1.cartao = 2;
        }
        else
        {
            printf("Opcao Invalida!\n");
        }
    }
    else
    {
        printf("Opcao Invalida!\n");
    }

    printf("Comprovante de Pagamento\n");
    printf("Data de Pagamento: %02d/%02d/%4d\n", pagamento1.datap.dia, pagamento1.datap.mes, pagamento1.datap.ano);
    printf("Nome: %s\n", pagamento1.cliente.nome);
    printf("CPF: %3d.%3d.%3d-%2d\n", pagamento1.cliente.bloco1, pagamento1.cliente.bloco2, pagamento1.cliente.bloco3, pagamento1.cliente.bloco4);
    printf("Valor Pago: %.2f\n", pagamento1.valor_total);
    printf("Forma de Pagamento: ");
    if (pagamento1.forma_pag == 1)
    {
        printf("PIX\n");
    }
    else if (pagamento1.forma_pag == 2)
    {
        printf("Especie\n");
    }
    else
    {
        printf("Cartao - ");
        if (pagamento1.cartao == 1)
        {
            printf("Debito\n");
        }
        else
        {
            printf("Credito\n");
        }
    }

    pagamento = fopen("..\\db\\pagamento.txt", "a");
    if (pagamento == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    fprintf(pagamento, "%02d/%02d/%4d %s %f %3d.%3d.%3d-%2d %d %d\n", pagamento1.datap.dia, pagamento1.datap.mes, pagamento1.datap.ano, pagamento1.cliente.nome,
            pagamento1.valor_total, pagamento1.cliente.bloco1, pagamento1.cliente.bloco2, pagamento1.cliente.bloco3,
            pagamento1.cliente.bloco4, pagamento1.forma_pag, pagamento1.cartao);

    fclose(pagamento);
}