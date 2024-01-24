#include "reserva.h"

int Contar_reservas()
{
    Reserva reserva1;
    int cont = 0;

    FILE *reserva = fopen("..\\db\\reserva.txt", "a+");

    if (reserva == NULL)
    {
        printf("Erro ao abrir o arquivo de reservas.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20)
    {
        cont++;
    }
    fclose(reserva);

    return cont;
}