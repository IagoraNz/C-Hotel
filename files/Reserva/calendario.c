#include "reserva.h"
#include <time.h>

#define espaco 26

void centro(char str[]) {
    int i, quantidade;
    i = strlen(str);

    quantidade = (espaco - i) / 2;

    for (i = 0; i < quantidade; i++) {
        printf(" ");
    }
    printf("%s", str);
}

void maincalendario() {
    char matriz[12][15] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int dia, mes, ano, semana, i;
    int ultimo_dia;

    printf("Digite o atual ano: ");
    scanf("%d", &ano);

    printf("Digite o numero do mes: ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        exit(1);
    }

    struct tm primeiro_dia = {0};
    primeiro_dia.tm_year = ano - 1900;
    primeiro_dia.tm_mon = mes - 1;
    primeiro_dia.tm_mday = 1;
    mktime(&primeiro_dia);

    printf("\n");
    centro(matriz[mes - 1]);
    printf("\n D   S   T   Q   Q   S   S\n");

    // Determina o último dia do mês
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            ultimo_dia = 29; // Ano bissexto
        } else {
            ultimo_dia = 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        ultimo_dia = 30;
    } else {
        ultimo_dia = 31;
    }

    semana = primeiro_dia.tm_wday;

    for (i = 0; i < semana; i++) {
        printf("    ");
    }

    for (dia = 1; dia <= ultimo_dia; dia++) {
        printf("%2d  ", dia);

        if (++semana == 7) {
            printf("\n");
            semana = 0;
        }
    }

    printf("\n\n");
}