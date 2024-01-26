#include "reserva.h"

void Excluir_reserva() {
    FILE *reserva;
    FILE *reservaTemp;
    int aux1, aux2, aux3;

    reserva = fopen("..\\db\\reserva.txt", "r");

    if(reserva == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    reservaTemp = fopen("..\\db\\reserva_temp.txt", "a");

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      EXCLUIR     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    int encontrado = 0;
    Reserva reserva1;

    printf("Digite a data de saida: ");
    scanf("%2d/%2d/%4d", &aux1, &aux2, &aux3);

    while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20) {
        if(aux1 == reserva1.dataf.dia && aux2 == reserva1.dataf.mes && aux3 == reserva1.dataf.ano){
            encontrado = 1;
            printf("Reserva excluída com sucesso!\n");
        } 
        else{
            fprintf(reservaTemp, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %.2f\n", reserva1.cod_reserva, reserva1.cliente.nome, reserva1.quarto.numquarto,
                                        reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano, reserva1.datai.hora, reserva1.datai.min,
                                        reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4,
                                        reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano, reserva1.dataf.hora, reserva1.dataf.min,
                                        reserva1.dias_reservado, reserva1.status_pag, reserva1.valor_total);
        }
    }

    fclose(reserva);
    fclose(reservaTemp);

    if(!encontrado){
      remove("..\\db\\reserva.txt");  
    }
    else{
        remove("..\\db\\reserva.txt");
        rename("..\\db\\reserva_temp.txt", "..\\db\\reserva.txt");
    }
}
