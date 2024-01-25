#include "struct.h"

typedef struct funcionario {
    char senha[tam];
    char usuario[maxsenha];
} Funcionario;

typedef struct quartos {
    int tipo;
    int numquarto;
    int status;
    float diaria;
    int capacidade;
} Quartos;

typedef struct clientes{
    char nome[maxnome];
    int idade;
    int bloco1;
    int bloco2;
    int bloco3;
    int bloco4;
    int rg;
    char email[maxnome];
    char telefone[20];
    char cidade[maxnome];
    char estado[maxnome];
} Clientes;

typedef struct data{
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
} Data;

typedef struct reserva
{
    int cod_reserva;
    Data datai;
    Clientes cliente;
    Quartos quarto;
    Data dataf;
    int dias_reservado;
    int status_pag;
    float valor_total;
}Reserva;

typedef struct pagamento
{
    Clientes cliente;
    Data datap;
    float valor_total;
}Pagamento;


//pagamento: 1 - Pedente 2 - Pago

