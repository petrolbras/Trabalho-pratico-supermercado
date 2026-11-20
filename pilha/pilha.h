#ifndef PILHA_H
#define PILHA_H
#include "stdbool.h"

#define MAX_NOME 30
#define MAX_DADOS 30

typedef struct {
    int quantidade;
    int id;
    char nome[MAX_NOME];
} produto;

typedef struct {
    produto dados[MAX_DADOS];
    int top;
} devolucoes;

bool pilha_init(devolucoes *a);

bool pilha_push(devolucoes *a, produto *produto);

bool pilha_pop(devolucoes *a, produto *produto);

bool pilha_topo(devolucoes *a, produto *produto);

bool pilha_vazio(devolucoes *a);

bool pilha_cheia(devolucoes *a);

int pilha_tamanho(devolucoes *a);

void imprimir_pilha(devolucoes *a);

#endif