#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../struct.h"

void Reservar_Cliente();

void calendario();

int Atualizar_Status(int numquarto);

int diferencaDias(struct tm data1, struct tm data2);

void Listar_reservas();

void Excluir_reserva();