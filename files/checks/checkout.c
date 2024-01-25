#include "checks.h"

// void atualizareserva(){
//     FILE *reserva;
//     FILE *reservaTemp;
//     int aux1, aux2, aux3, aux4;

//     reserva = fopen("..\\db\\reserva.txt", "r");

//     if(reserva == NULL){
//         printf("Erro ao abrir o arquivo");
//         exit(EXIT_FAILURE);
//     }

//     reservaTemp = fopen("..\\db\\reserva_temp.txt", "a");

//     int encontrado = 0;
//     Reserva reserva1;

//     do{
//         printf("Digite o CPF(XXX.XXX.XXX-XX) para check-ou: ");
//     }while(scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4);

//     while(fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
//                   &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
//                   &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
//                   &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20) {
//         if(reserva1.cliente.bloco1 == aux1 && reserva1.cliente.bloco2 == aux2 && reserva1.cliente.bloco3 == aux3 && reserva1.cliente.bloco4 == aux4){
//             encontrado = 1;
//             printf("Reserva excluída com sucesso!\n");
//         } 
//         else{
//             fprintf(reservaTemp, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %.2f\n", reserva1.cod_reserva, reserva1.cliente.nome, reserva1.quarto.numquarto,
//                                         reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano, reserva1.datai.hora, reserva1.datai.min,
//                                         reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4,
//                                         reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano, reserva1.dataf.hora, reserva1.dataf.min,
//                                         reserva1.dias_reservado, reserva1.status_pag, reserva1.valor_total);
//         }
//     }

//     if(encontrado == 0){
//         printf("Quarto nao encontrado!\n");
//     }

//     fclose(reserva);
//     fclose(reservaTemp);

//     remove("..\\db\\reserva.txt");
//     rename("..\\db\\reserva_temp.txt", "..\\db\\reserva.txt");
// }

void checkout(){

    FILE *quartos;
    FILE *clientes;
    FILE *reserva;

    Data dataini;
    Data datafim;

    Quartos quartos1;
    Reserva reserva1;

    quartos = fopen("..\\db\\quartos.txt", "r");
    clientes = fopen("..\\db\\clientes.txt", "r");
    reserva = fopen("..\\db\\reserva.txt", "r");

    int numquarto, aux1, aux2, aux3, aux4;

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      CHECKS      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    do{
        printf("Digite o CPF(XXX.XXX.XXX-XX): ");
    }while(scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4);

    printf("Digite o numero do quarto: ");
    scanf("%d", &numquarto);

    printf("Digite a data de entrada(dd/mm/aaaa): ");
    if(scanf("%2d/%2d/%4d", &dataini.dia, &dataini.mes, &dataini.ano) != 3){
        printf("Formato invalido!\n");
    }

    printf("Informe a hora de entrada(XX:XX): ");
    if(scanf("%2d:%d", &dataini.hora, &dataini.min) != 2){
        printf("Formato invalido!\n");
    }

    printf("Digite a data de saida(dd/mm/aaaa): ");
    if(scanf("%2d/%2d/%4d", &datafim.dia, &datafim.mes, &datafim.ano) != 3){
        printf("Formato invalido!\n");
    }

    printf("Informe a hora de saida(XX:XX): ");
    if(scanf("%2d:%d", &datafim.hora, &datafim.min) != 2){
        printf("Formato invalido!\n");
    }


    FILE *temporario;

    temporario = fopen("..\\db\\reserva_temp.txt", "w");

    if (temporario == NULL) {
        printf("Erro ao abrir o arquivo temporário");
        fclose(reserva);
        exit(EXIT_FAILURE);
    }

    int enc = 0;
    char contcheck;
    while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                  &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                  &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                  &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20) {

        if (reserva1.cliente.bloco1 == aux1 && reserva1.cliente.bloco2 == aux2 && reserva1.cliente.bloco3 == aux3 && reserva1.cliente.bloco4 == aux4 && reserva1.quarto.numquarto == numquarto && reserva1.datai.dia == dataini.dia && reserva1.datai.mes == dataini.mes && reserva1.datai.ano == dataini.ano && reserva1.dataf.dia == datafim.dia && reserva1.dataf.mes == datafim.mes && reserva1.dataf.ano == datafim.ano) {

            printf("Para concluir o check-out: \n");
            Realizar_pagamento(&dataini, &reserva1);
            reserva1.status_pag = 2;
        
            enc = 1;
            reserva1.datai.hora = dataini.hora;
            reserva1.datai.min = dataini.min;

            reserva1.dataf.hora = datafim.hora;
            reserva1.dataf.min = datafim.min;

            fseek(reserva, 0, SEEK_SET);  // Move to the beginning of the file

            int codres;

            printf("Digite o codigo da reserva: ");
            scanf("%d", &codres);

            while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                          &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                          &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                          &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total) == 20) {

                if(reserva1.cod_reserva == codres){
                    printf("Deseja fazer o check-out? (s/n): ");
                    scanf(" %c", &contcheck);

                    // Caso sim, realizar o check-out e mudar o status do quarto para ocupado
                    if (contcheck == 's') {
                        while (fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5) {
                            if (quartos1.numquarto == numquarto) {
                                fclose(quartos);
                                attstatus(numquarto);
                            }
                        }
                        printf("Check-out realizado com sucesso!\n");
                    } 
                } 
            }
        } 
        else{
            // Write the reservation back to the temporary file
            fprintf(temporario, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %.2f\n", reserva1.cod_reserva, reserva1.cliente.nome, reserva1.quarto.numquarto, reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano, reserva1.datai.hora, reserva1.datai.min, reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4, reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano, reserva1.dataf.hora, reserva1.dataf.min, reserva1.dias_reservado, reserva1.status_pag, reserva1.valor_total);
        }
    }

    fclose(reserva);
    fclose(temporario);

    if (!enc) {
        printf("Reserva nao encontrada!\n");
        remove("..\\db\\reserva_temp.txt");
    } else {
        remove("..\\db\\reserva.txt");
        rename("..\\db\\reserva_temp.txt", "..\\db\\reserva.txt");
    }

    fclose(clientes);
}