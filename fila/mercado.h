#ifndef CAIXA_H
#define CAIXA_H

#include "fila.h"
#include <stdbool.h>

#define MAX_CAIXAS 10

typedef struct {
    bool aberto;
    Cliente atual;
    Fila fila;
    int id;
} Caixa;

typedef struct {
    Caixa caixas[MAX_CAIXAS];
} mercado;

bool mercado_init(mercado *m);

bool fechar_caixa(Caixa *c);

bool abrir_caixa(Caixa *c);

bool atender_caixa(Caixa *c);

bool caixa_fechado(Caixa *c);

bool caixa_tem_clientes(Caixa *c);

bool redistribuicao_gulosa_caixas(mercado *m);

#endif