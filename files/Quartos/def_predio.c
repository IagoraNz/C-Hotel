#include "quartos.h"

void Definindo_Predio(){
    FILE *predio;
    int qtd_quartos;

    predio = fopen("..\\db\\predio.txt", "a+");  // "a+" abre o arquivo para leitura e escrita (append)
    if (predio == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fseek(predio, 0, SEEK_SET);  // Mover o cursor para o início do arquivo

    // Verificar se o arquivo está vazio
    if (fgetc(predio) == EOF) {
        printf("Informe a Quantidade de Quartos no Predio: ");
        scanf("%d", &qtd_quartos);
        fprintf(predio, "%d ", qtd_quartos);
    } else {
        return;
    }

    fclose(predio);
}