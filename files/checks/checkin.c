#include "checks.h"

void checkin(){
    FILE *quartos;
    Quartos quartos1;
    FILE *clientes;
    FILE *reserva;
    Reserva reserva1;

    quartos = fopen("..\\db\\quartos.txt", "r");
    clientes = fopen("..\\db\\clientes.txt", "r");
    reserva = fopen("..\\db\\reserva.txt", "r");

    int numquarto;
    int aux1, aux2, aux3, aux4;

    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      CHECKS      \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    do{
        printf("Digite o CPF(XXX.XXX.XXX-XX): ");
        scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4);
    }while(scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4);

    printf("Digite o numero do quarto: ");
    scanf("%d", &numquarto);

    int diai, mesi, anoi, diaf, mesf, anof;

    printf("Digite a data de entrada(dd/mm/aaaa): ");
    if(scanf("%2d/%2d/%4d", &diai, &mesi, &anoi) != 3){
        printf("Formato invalido!\n");
    }

    printf("Digite a data de saida(dd/mm/aaaa): ");
    if(scanf("%2d/%2d/%4d", &diaf, &mesf, &anof) != 3){
        printf("Formato invalido!\n");
    }

    char contcheck;

    while(fscanf(reserva, "%s %d %02d/%02d/%4d %3d.%3d.%3d-%2d %02d/%02d/%4d %d\n", reserva1.cliente.nome, &reserva1.quarto.numquarto, &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.cliente.bloco1, &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia, &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dias_reservado) == 13){
            if(reserva1.cliente.bloco1 == aux1 && reserva1.cliente.bloco2 == aux2 && reserva1.cliente.bloco3 == aux3 && reserva1.cliente.bloco4 == aux4 && reserva1.quarto.numquarto == numquarto && reserva1.datai.dia == diai && reserva1.datai.mes == mesi && reserva1.datai.ano == anoi && reserva1.dataf.dia == diaf && reserva1.dataf.mes == mesf && reserva1.dataf.ano == anof){
                printf("Deseja fazer o checkin? (s/n): ");
                scanf("%c", &contcheck);

                //Caso sim, realizer o checkin e mudar o status do quarto para ocupado
                if(contcheck == 's'){
                    while(fscanf(quartos, "%d%d%d%f%d", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) == 5){
                        if(quartos1.numquarto == numquarto){
                            quartos1.status = 2;
                        }
                    }
                    fclose(quartos);
                    printf("Checkin realizado com sucesso!\n");
                }
                else{
                    printf("Checkin nao realizado!\n");
                }
            }
            else{
                printf("Reserva nao encontrada!\n");
            }
    }

    fclose(reserva);
    fclose(clientes);
}