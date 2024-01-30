#include "checks.h"

void Valor_total(){
    FILE *pagamento;
    Pagamento pagamento1;

    float valor_total = 0;

    pagamento = fopen("..\\db\\pagamento.txt", "r");

    if (pagamento == NULL) {
        printf("Erro ao abrir o arquivo de pagamento.\n");
        return;
    }

    while (fscanf(pagamento, "%2d/%2d/%4d %s %f %3d.%3d.%3d-%2d %d %d", &pagamento1.datap.dia, &pagamento1.datap.mes, &pagamento1.datap.ano, pagamento1.cliente.nome, &pagamento1.valor_total, &pagamento1.cliente.bloco1, &pagamento1.cliente.bloco2, &pagamento1.cliente.bloco3, &pagamento1.cliente.bloco4, &pagamento1.forma_pag, &pagamento1.cartao) == 11)
    {
            valor_total += pagamento1.valor_total;
    }
    printf("Valor total arrecadado: %.2f\n", valor_total);
}