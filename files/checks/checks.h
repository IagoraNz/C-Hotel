#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../struct.h"

void checkin();

void Realizar_pagamento(Data *datapag, Reserva *reserva1);

void atualizareserva();

void Valores_Recebidos();

int ComparaDatas(Data data1, Data data2);

int DataEstaNoPeriodo(Data data, Data inicio, Data fim);