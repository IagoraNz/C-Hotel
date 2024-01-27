#include "quartos.h"

int strparaint(const char str[]) {
    int result = 0, i;
    for (i = 0; str[i] != '\0'; i++) {
        if(isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } 
        else{
            return -1;
        }
    }
    return result;
}

void cadastrarQuarto(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "a");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        fclose(quartos);
        exit(EXIT_FAILURE);
    }
    int aux = 0;
    char input[1], input2[1], input3[1], input4[1];
    char cont[1];

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA     CADASTRO     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

    printf("TIPOS\n");
    printf("1 - Luxo\n");
    printf("2 - Executivo\n");
    printf("3 - Simples\n");
    printf("Digite o tipo do quarto: ");
    scanf("%s", input2);
    getchar();
    quartos1.tipo = strparaint(input2);
    aux = quartos1.tipo;
    printf("Tipo: %d\n", quartos1.tipo);

    if(quartos1.tipo < 1 || quartos1.tipo > 3 || quartos1.tipo == -1){
        printf("Falha ao cadastrar as informacoes\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", cont);
        if((strcmp(cont, "s") == 0) || (strcmp(cont, "S") == 0)){
            fclose(quartos);
            return cadastrarQuarto();
        }
        else{
            fclose(quartos);
            return menuQuartos();
        }
    }
    printf("Tipo: %d\n", quartos1.tipo);

    printf("\n");

    printf("Digite o numero do quarto: ");
    scanf("%s", input);

    quartos1.numquarto = strparaint(input);

    if(quartos1.numquarto < 1 || quartos1.tipo < 0){
        printf("Falha ao cadastrar as informacoes\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", cont);
        if((strcmp(cont, "s") == 0) || (strcmp(cont, "S") == 0)){
            fclose(quartos);
            return cadastrarQuarto();
        }
        else{
            fclose(quartos);
            return menuQuartos();
        }
    }

    printf("\n");

    printf("STATUS\n");
    printf("1 - Disponivel\n");
    printf("2 - Ocupado\n");
    printf("3 - Reservado\n");

    printf("Digite o status do quarto: ");
    scanf("%s", input3);

    quartos1.status = strparaint(input3);

    if(quartos1.status < 1 || quartos1.status > 3 || quartos1.status == -1){
        printf("Falha ao cadastrar as informacoes\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", cont);
        if((strcmp(cont, "s") == 0) || (strcmp(cont, "S") == 0)){
            fclose(quartos);
            return cadastrarQuarto();
        }
        else{
            fclose(quartos);
            return menuQuartos();
        }
    }

    
    quartos1.tipo = aux;
    printf("Tipo: %d\n", quartos1.tipo);
    printf("\n");

    if(quartos1.tipo == 1){
        quartos1.diaria = 100;
    } 
    else if(quartos1.tipo == 2){
        quartos1.diaria = 250;
    } 
    else if(quartos1.tipo == 3){
        quartos1.diaria = 35;
    }
    
    printf("Capacidade do Quarto\n");
    printf("1 - Solteiro\n");
    printf("2 - Casal\n");

    printf("Digite a capacidade do quarto: ");
    scanf("%s", input4);

    quartos1.capacidade = strparaint(input4);

    if(quartos1.capacidade < 1 || quartos1.capacidade > 2 || quartos1.capacidade == -1){
        printf("Falha ao cadastrar as informacoes\n");
        printf("Deseja tentar o cadastro novamente (s/n)?: ");
        scanf("%s", cont);
        if((strcmp(cont, "s") == 0) || (strcmp(cont, "S") == 0)){
            fclose(quartos);
            return cadastrarQuarto();
        }
        else{
            fclose(quartos);
            return menuQuartos();
        }
    }

    fprintf(quartos, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);

    fclose(quartos);
}