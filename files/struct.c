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
    int status_check;
}Reserva;

typedef struct pagamento
{
    Clientes cliente;
    Data datap;
    float valor_total;
    int forma_pag;
    int cartao;
}Pagamento;

//int cartao e para caso selecionar se e Debito ou Credito: 0 - Nada 1 - Debito e 2 - Credito

// Forma de Pagamento: 1 - Pix 2 - Especie 3 - Cartão

//pagamento: 1 - Pedente 2 - Pago

