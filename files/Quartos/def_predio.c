#include "quartos.h"

void Definindo_Predio(){
    FILE *predio;
    int qtd_quartos;

    predio = fopen("..\\db\\predio.txt", "a+");  // "a+" abre o arquivo para leitura e escrita (append)
    if(predio == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fseek(predio, 0, SEEK_SET);  // Mover o cursor para o início do arquivo

    if(fgetc(predio) == EOF){
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA      INICIO      \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("Antes de iniciar o sistema, precisamos definir a quantidade de quartos no predio.\n");
        printf("Digite a quantidade de quartos no predio: ");
        scanf("%d", &qtd_quartos);
        fprintf(predio, "%d ", qtd_quartos);
        system("PAUSE");
        system("cls");
    } 
    else{
        return; // Se o arquivo já estiver preenchido, não faz nada
    }

    fclose(predio);
}