#include "reserva.h"

int diferencaDias(struct tm data1, struct tm data2) {
    // Converte as datas para o formato de tempo (time_t)
    time_t time1 = mktime(&data1);
    time_t time2 = mktime(&data2);

    // Verifica se as datas são válidas
    if (time1 == -1 || time2 == -1) {
        perror("Erro na conversão de tempo");
        return 0; // Retorna zero em caso de erro
    }

    // Calcula a diferença em segundos
    double diferencaSegundos = difftime(time2, time1);

    // Converte a diferença de segundos para dias
    int diferencaDias = (int)(diferencaSegundos / (60 * 60 * 24));

    return diferencaDias;
}