#include "reserva.h"

int stringparaintconsulres(const char str[]) {
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

void Consultar_reserva()
{
    char input[1];
    int numquarto, opc, aux1, aux2, aux3, aux4;
    FILE *reserva;
    Reserva reserva1;

    reserva = fopen("..\\db\\reserva.txt", "r");
    if (reserva == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    system("cls");
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
    printf("\xBA      CONSULTAR     \xBA\n");
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    printf("1 - CPF\n2 - Numero do quarto\n0 - Voltar\n");
    printf("Informe sua opcao: ");
    scanf("%s", input);

    opc = stringparaintconsulres(input);

    if(opc < 0 || opc > 2 || opc == -1){
        printf("Opcao invalida!\n");
        printf("Deseja tentar a consulta novamente? (s/n): ");
        scanf("%s", input);
        system("PAUSE");
        if (input[0] == 's' || input[0] == 'S'){
            Consultar_reserva();
        }
        else{
            return;
        }
    }

    switch (opc)
    {
    case 1:
        printf("Digite o CPF (no formato XXX.XXX.XXX-XX): ");
        if (scanf("%3d.%3d.%3d-%2d", &aux1, &aux2, &aux3, &aux4) != 4)
        {
            printf("Formato de CPF inválido.\n");
            exit(EXIT_FAILURE);
        }
        system("cls");
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA      RESERVAS      \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("NOME\t\tCPF\t\tNUMERO\tCHECK-IN\tCHECK-OUT\n");
        while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f %d\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                      &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                      &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                      &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total, &reserva1.status_check) == 21)
        {
            if (aux1 == reserva1.cliente.bloco1 && aux2 == reserva1.cliente.bloco2 && aux3 == reserva1.cliente.bloco3 && aux4 == reserva1.cliente.bloco4)
            {
                replaceUnderscoreWithSpace(reserva1.cliente.nome);
                printf("%s\t", reserva1.cliente.nome);
                printf("%3d.%3d.%3d-%2d\t", reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4);
                printf("%d\t", reserva1.quarto.numquarto);
                printf("%2d/%2d/%4d\t", reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano);
                printf("%2d/%2d/%4d\t", reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano);
                printf("\n");
            }
        }
        system("PAUSE");
        fclose(reserva);
        return Consultar_reserva();
        break;
    case 2:
        printf("Informe o numero do quarto: ");
        scanf("%d", &numquarto);
        system("cls");
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\xBA      RESERVAS      \xBA\n");
        printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        printf("NOME\t\tCPF\t\tNUMERO\tCHECK-IN\tCHECK-OUT\n");
        while (fscanf(reserva, "%d %s %d %02d/%02d/%4d %02d:%02d %3d.%3d.%3d-%2d %02d/%02d/%4d %02d:%02d %d %d %f %d\n", &reserva1.cod_reserva, reserva1.cliente.nome, &reserva1.quarto.numquarto,
                      &reserva1.datai.dia, &reserva1.datai.mes, &reserva1.datai.ano, &reserva1.datai.hora, &reserva1.datai.min, &reserva1.cliente.bloco1,
                      &reserva1.cliente.bloco2, &reserva1.cliente.bloco3, &reserva1.cliente.bloco4, &reserva1.dataf.dia,
                      &reserva1.dataf.mes, &reserva1.dataf.ano, &reserva1.dataf.hora, &reserva1.dataf.min, &reserva1.dias_reservado, &reserva1.status_pag, &reserva1.valor_total, &reserva1.status_check) == 21)
        {
            if (numquarto == reserva1.quarto.numquarto)
            {
                replaceUnderscoreWithSpace(reserva1.cliente.nome);
                printf("%s\t", reserva1.cliente.nome);
                printf("%3d.%3d.%3d-%2d\t", reserva1.cliente.bloco1, reserva1.cliente.bloco2, reserva1.cliente.bloco3, reserva1.cliente.bloco4);
                printf("%d\t", reserva1.quarto.numquarto);
                printf("%2d/%2d/%4d\t", reserva1.datai.dia, reserva1.datai.mes, reserva1.datai.ano);
                printf("%2d/%2d/%4d\t", reserva1.dataf.dia, reserva1.dataf.mes, reserva1.dataf.ano);
                printf("\n");
            }
        }
        fclose(reserva);
        system("PAUSE");
        return Consultar_reserva();
        break;

    case 3:
        return;
        break;

    default:
        break;
    }
    fclose(reserva);
}