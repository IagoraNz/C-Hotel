#include "reserva.h"

int stringparaintres(const char str[]) {
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

void Excluir_reserva(){
    FILE *reserva;
    FILE *reservaTemp;
    int codigoexc;

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

    char input[1];

    printf("Digite o codigo da reserva: ");
    scanf("%s", input);

    int num_quarto;

    codigoexc = stringparaintres(input);

    while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f %d\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total, &reserva1.status_check) == 21) {
        if(codigoexc == reserva1.cod_reserva){

            num_quarto = reserva1.quarto.numquarto;
            encontrado = 1;
            printf("Reserva excluída com sucesso!\n");
            system("PAUSE");
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

    int verificacao = 0;

    reserva = fopen("..\\db\\reserva.txt", "r");

    if(reserva == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f %d\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total, &reserva1.status_check) != EOF) {
                  if (num_quarto == reserva1.quarto.numquarto)
                  {
                    verificacao = 1;
                  }                  
    }

    fclose(reserva);

    FILE *quarto;
    FILE *quartoTemp;

    quarto = fopen("..\\db\\quartos.txt", "r");

    if(quarto == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    quartoTemp = fopen("..\\db\\quarto_temp.txt", "w");

    Quartos quartos1;

    while(fscanf(quarto, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
        if (num_quarto == quartos1.numquarto)
        {
            if (verificacao == 1)
            {
                fprintf(quartoTemp, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, 3, quartos1.diaria, quartos1.capacidade);
            }
            else{
                fprintf(quartoTemp, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, 1, quartos1.diaria, quartos1.capacidade);
            }
            
        }
        else{
            fprintf(quartoTemp, "%d %d %d %.2f %d\n", quartos1.tipo, quartos1.numquarto, quartos1.status, quartos1.diaria, quartos1.capacidade);
        }
    }

    fclose(quarto);
    fclose(quartoTemp);
    fclose(reserva);

    if(verificacao == 1){
        remove("..\\db\\quartos.txt");
        rename("..\\db\\quarto_temp.txt", "..\\db\\quartos.txt");
    }
    else{
        remove("..\\db\\quartos.txt");
        rename("..\\db\\quarto_temp.txt", "..\\db\\quartos.txt");
    }
}
