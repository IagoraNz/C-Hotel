#include "reserva.h"

#define espaco 26

int gregjul(int dia, int mes, int ano){
    int juliana;

    juliana = (1461 * (ano + 4800 + (mes - 14) / 12)) / 4 + (367 * (mes - 2 - 12 * ((mes - 14) / 12))) / 12 - (3 * ((ano + 4900 + (mes - 14) / 12) / 100)) / 4 + dia - 32075;
    
    return juliana;
}

long int julgreg(int juliana){
    int b, n, k, j, dia, mes, ano;

    b = juliana + 68569;
    n = (4 * b) / 146097;
    b = b - ((146097 * n + 3) / 4);
    k = 4000 * (b + 1) / 1461001;
    b = b - (1461 * k) / 4 + 31;
    j = (80 * b) / 2447;
    dia = b - (2447 * j) / 80;
    b = (j / 11);
    mes = j + 2 - (12 * b);
    ano = 100 * (n - 49) + k + b;

    return ((ano * 10000) + (mes * 100) + dia);
}

int diajul(int dia, int mes, int ano){
    return ((gregjul(dia, mes, ano) + 1) % 7);
}

long int tempo(long int data, int aux){
    int juliana, dia, mes, ano;

    ano = data / 10000;
    mes = (data % 10000) / 100;
    dia = data % 100;

    juliana = gregjul(dia, mes, ano);
    juliana += aux;

    return julgreg(juliana);
}

void esp(){
    
    int i;
    for (i = 0; i < espaco; i++){
        printf("-");
    }
}

void centro(char str[]){
    int i, quantidade;
    i = strlen(str);

    quantidade = (espaco - i) / 2;

    for(i = 0; i < quantidade; i++){
        printf(" ");
    }
    printf("%s", str);
}

void maincalendario(){

    char matriz[12][15] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int dia, mes, ano, semana, i;
    long int data;

    printf("Digite o atual ano: ");
    scanf("%d", &ano);

    printf("Digite o numero do mes: ");
    scanf("%d", &mes);

    if(mes < 1 || mes > 12){
        printf("Mes invalido.\n");
        exit(1);
    }

    data = (ano * 10000) + (mes * 100) + 1;
    
    printf("\nCalendario de %d - %s\n", ano, matriz[mes - 1]);

    while((data / 100) % 100 == mes){
        mes = (data % 10000) / 100;
        dia = data % 100;

        if(dia == 1){
            printf("\n");
            esp();

            printf("\n");
            centro(matriz[mes - 1]);

            printf("\n");
            esp();

            printf("\n D   S   T   Q   Q   S   S\n");
            semana = diajul(dia, mes, ano);
            for (i = 0; i < semana; i++){
                printf("    ");
            }
        }

        printf("%02d  ", dia);

        if(((dia + semana) % 7 == 0) && (tempo(data, 1) - data == 1)){
            printf("\n");
        }
        data = tempo(data, 1);
    }

    printf("\n");
    esp();
    printf("\n");
}