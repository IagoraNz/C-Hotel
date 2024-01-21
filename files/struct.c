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

