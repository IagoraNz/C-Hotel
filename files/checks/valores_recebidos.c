#include "checks.h"

int DataEstaNoPeriodo(Data data, Data inicio, Data fim) {
    if (ComparaDatas(data, inicio) >= 0 && ComparaDatas(data, fim) <= 0) {
        return 1; // A data está dentro do período
    } else {
        return 0; // A data está fora do período
    }
}

// Função para comparar duas datas
int ComparaDatas(Data data1, Data data2) {
    if (data1.ano != data2.ano) {
        return data1.ano - data2.ano;
    } else if (data1.mes != data2.mes) {
        return data1.mes - data2.mes;
    } else {
        return data1.dia - data2.dia;
    }
}

void Valores_Recebidos(){
    FILE *pagamento;
    Pagamento pagamento1;
    Data datai, dataf;

    float Valor_Periodo = 0;

    pagamento = fopen("..\\db\\pagamento.txt", "r");

    printf("Informe a Data de inicio(XX/XX/XXXX): ");
    scanf("%2d/%2d/%4d", &datai.dia, &datai.mes, &datai.ano);

    printf("Informe a Data de Fim(XX/XX/XXXX): ");
    scanf("%2d/%2d/%4d", &dataf.dia, &dataf.mes, &dataf.ano);

    while (fscanf(pagamento, "%2d/%2d/%4d %s %f %3d.%3d.%3d-%2d %d %d", &pagamento1.datap.dia, &pagamento1.datap.mes, &pagamento1.datap.ano, pagamento1.cliente.nome, &pagamento1.valor_total, &pagamento1.cliente.bloco1, &pagamento1.cliente.bloco2, &pagamento1.cliente.bloco3, &pagamento1.cliente.bloco4, &pagamento1.forma_pag, &pagamento1.cartao) == 11)
    {
        if (DataEstaNoPeriodo(pagamento1.datap, datai, dataf)) {
            Valor_Periodo += pagamento1.valor_total;
            printf("Data de pagamento dentro do periodo: %02d/%02d/%04d\n", pagamento1.datap.dia, pagamento1.datap.mes, pagamento1.datap.ano);
        }
    }
    printf("O Valor que foi arrecadado dentro do periodo foi de: %.2f\n", Valor_Periodo);
}