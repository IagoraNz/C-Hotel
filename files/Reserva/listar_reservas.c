#include "reserva.h"

void Listar_reservas(){
    FILE *reserva;
    Reserva reserva1;

    reserva = fopen("..\\db\\reserva.txt", "r");
    if(reserva == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      RESERVAS     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    while(fscanf(reserva, "%s %d %02d/%02d/%4d %3d.%3d.%3d-%2d %02d/%02d/%4d %d\n", reserva1.cliente.nome, &reserva1.quarto.numquarto, 
                        &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.cliente.bloco1, &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, 
                        &reserva1.dataf.dia, &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dias_reservado) == 13){
                                printf("Nome: %s\n", reserva1.cliente.nome);
                                printf("CPF: %3d.%3d.%3d-%2d\n", reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4);
                                printf("Numero do quarto: %d\n", reserva1.quarto.numquarto);
                                printf("Data para check-in: %2d/%2d/%4d\n", reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano);
                                printf("Data para check-out: %2d/%2d/%4d\n", reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano);
                                printf("\n\n");
                        }
}