#include "quartos.h"

int strparaintconsul(const char str[]){
    int result = 0, i;
    for(i = 0; str[i] != '\0'; i++){
        if(isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } 
        else{
            return -1;
        }
    }
    return result;
}

void consultarQuarto(){
    FILE *quartos;
    Quartos quartos1;

    quartos = fopen("..\\db\\quartos.txt", "r");

    if(quartos == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int consulta, tipo, numquarto, status, capacidade;
    float diaria;
    char input[1];

    system("cls");
    do{
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA      OPCOES      \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("1 - Busca por tipo\n");
        printf("2 - Busca por numero\n");
        printf("3 - Busca por status\n");
        printf("4 - Busca por diaria\n");
        printf("5 - Busca por capacidade\n");
        printf("0 - Voltar\n");
        do{
            printf("Digite a opcao desejada: ");
            scanf("%s", input);

            consulta = strparaintconsul(input);
            if(consulta == -1 || consulta > 5 || consulta < 0){
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
                fclose(quartos);
                return consultarQuarto();
            }
        }while(consulta < 0 || consulta > 5);

        switch (consulta)
        {
        case 1:
            printf("TIPOS\n");
            printf("1 - Luxo\n");
            printf("2 - Executivo\n");
            printf("3 - Simples\n");

            printf("Digite o tipo do quarto: ");
            scanf("%s", input);

            tipo = strparaintconsul(input);

            if(tipo == -1 || tipo < 1 || tipo > 3){
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
                fclose(quartos);
                return consultarQuarto();
            }

            system("cls");
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\xBA      QUARTO      \xBA\n");
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");
            while(fscanf(quartos, "%d\n%d\n%d\n%f\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) != EOF){
                if(quartos1.tipo == tipo){

                    if(quartos1.tipo == 1){
                        printf("Luxo\t\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 2){
                        printf("Executivo\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 3){
                        printf("Simples\t\t%d\t\t", quartos1.numquarto);
                    }

                    if(quartos1.status == 1){
                        printf("Disponivel\t\t");
                    }
                    else if(quartos1.status == 2){
                        printf("Ocupado\t\t");
                    }
                    else if(quartos1.status == 3){
                        printf("Reservado\t\t");
                    }

                    printf("%.2f\t\t%d\n", quartos1.diaria, quartos1.capacidade);
                }
            }
            fseek(quartos, 0, SEEK_SET);
            fclose(quartos);
            system("PAUSE");
            system("cls");
            break;

        case 2:
            printf("Digite o numero do quarto: ");
            scanf("%s", input);

            numquarto = strparaintconsul(input);

            if(numquarto == -1 || numquarto < 1){
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
                fclose(quartos);
                return consultarQuarto();
            }

            system("cls");
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\xBA      QUARTO      \xBA\n");
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");
            while(fscanf(quartos, "%d\n%d\n%d\n%f\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) != EOF){
                if(quartos1.numquarto == numquarto){

                    if(quartos1.tipo == 1){
                        printf("Luxo\t\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 2){
                        printf("Executivo\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 3){
                        printf("Simples\t\t%d\t\t", quartos1.numquarto);
                    }

                    if(quartos1.status == 1){
                        printf("Disponivel\t\t");
                    }
                    else if(quartos1.status == 2){
                        printf("Ocupado\t\t");
                    }
                    else if(quartos1.status == 3){
                        printf("Reservado\t\t");
                    }

                    printf("%.2f\t\t%d\n", quartos1.diaria, quartos1.capacidade);
                }
            }
            fseek(quartos, 0, SEEK_SET);
            fclose(quartos);
            system("PAUSE");
            system("cls");
            break;

        case 3:
            printf("STATUS\n");
            printf("1 - Disponivel\n");
            printf("2 - Ocupado\n");
            printf("3 - Reservado\n");

            printf("Digite o status do quarto: ");
            scanf("%s", input);

            status = strparaintconsul(input);

            if(status == -1 || status < 1 || status > 3){
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
                fclose(quartos);
                return consultarQuarto();
            }

            system("cls");
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\xBA      QUARTO      \xBA\n");
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");
            while(fscanf(quartos, "%d\n%d\n%d\n%f\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) != EOF){
                if(quartos1.status == status){

                    if(quartos1.tipo == 1){
                        printf("Luxo\t\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 2){
                        printf("Executivo\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 3){
                        printf("Simples\t\t%d\t\t", quartos1.numquarto);
                    }

                    if(quartos1.status == 1){
                        printf("Disponivel\t\t");
                    }
                    else if(quartos1.status == 2){
                        printf("Ocupado\t\t");
                    }
                    else if(quartos1.status == 3){
                        printf("Reservado\t\t");
                    }

                    printf("%.2f\t\t%d\n", quartos1.diaria, quartos1.capacidade);
                }
            }
            fseek(quartos, 0, SEEK_SET);
            fclose(quartos);
            system("PAUSE");
            system("cls");
            break;

        case 4:
            printf("Digite a diaria do quarto: ");
            scanf("%s", input);

            diaria = strparaintconsul(input);

            if(diaria == -1 || diaria < 35 || diaria > 250){
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
                fclose(quartos);
                return consultarQuarto();
            }

            system("cls");
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\xBA      QUARTO      \xBA\n");
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");
            while(fscanf(quartos, "%d\n%d\n%d\n%f\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) != EOF){
                if(quartos1.diaria == diaria){

                    if(quartos1.tipo == 1){
                        printf("Luxo\t\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 2){
                        printf("Executivo\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 3){
                        printf("Simples\t\t%d\t\t", quartos1.numquarto);
                    }

                    if(quartos1.status == 1){
                        printf("Disponivel\t\t");
                    }
                    else if(quartos1.status == 2){
                        printf("Ocupado\t\t");
                    }
                    else if(quartos1.status == 3){
                        printf("Reservado\t\t");
                    }

                    printf("%.2f\t\t%d\n", quartos1.diaria, quartos1.capacidade);
                }
            }
            fseek(quartos, 0, SEEK_SET);
            fclose(quartos);
            system("PAUSE");
            system("cls");
            break;

        case 5:
            printf("Capacidade do Quarto\n");
            printf("1 - Solteiro\n");
            printf("2 - Casal\n");

            printf("Digite a capacidade do quarto: ");
            scanf("%s", input);

            capacidade = strparaintconsul(input);

            if(capacidade == -1 || capacidade < 1 || capacidade > 2){
                printf("Opcao invalida. Tente novamente.\n");
                system("PAUSE");
                system("cls");
                fclose(quartos);
                return consultarQuarto();
            }

            system("cls");
            printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\xBA      QUARTO      \xBA\n");
            printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
            printf("TIPO\t\tNUMERO\t\tSTATUS\t\t\tDIARIA\t\tCAPACIDADE\n");
            while(fscanf(quartos, "%d\n%d\n%d\n%f\n%d\n", &quartos1.tipo, &quartos1.numquarto, &quartos1.status, &quartos1.diaria, &quartos1.capacidade) != EOF){
                if(quartos1.capacidade == capacidade){

                    if(quartos1.tipo == 1){
                        printf("Luxo\t\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 2){
                        printf("Executivo\t%d\t\t", quartos1.numquarto);
                    }
                    else if(quartos1.tipo == 3){
                        printf("Simples\t\t%d\t\t", quartos1.numquarto);
                    }

                    if(quartos1.status == 1){
                        printf("Disponivel\t\t");
                    }
                    else if(quartos1.status == 2){
                        printf("Ocupado\t\t");
                    }
                    else if(quartos1.status == 3){
                        printf("Reservado\t\t");
                    }

                    printf("%.2f\t\t%d\n", quartos1.diaria, quartos1.capacidade);
                }
            }
            fseek(quartos, 0, SEEK_SET);
            fclose(quartos);
            system("PAUSE");
            system("cls");
            break;

        case 0:
            return;
            break;
        
        default:
            printf("Opcao invalida. Tente novamente.\n");
            system("PAUSE");
            system("cls");
            break;
        }
    }while(consulta != 0);

    fclose(quartos);
}