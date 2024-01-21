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

typedef struct cpf {
    int bloco1;
    int bloco2;
    int bloco3;
    int bloco4;
} CPF;

typedef struct clientes{
    char nome[maxnome];
    int idade;
    CPF cpf1;
    int rg;
    char email[maxnome];
    int telefone;
    char cidade;
    char estado;
} Clientes;

