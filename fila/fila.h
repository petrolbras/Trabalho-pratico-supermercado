#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define MAX_NOME 20
#define MAX_CLIENTES 5

typedef struct {
    char nome[MAX_NOME];
    //produtos (não será implementado agora)
} Cliente;

typedef struct {
    Cliente clientes[MAX_CLIENTES];
    int inicio;
    int fim;
    int tamanho;
} Fila;

typedef struct {
    bool aberto;
    bool atendendo;
    Fila fila;
    Cliente atual;
    int id;
} Caixa;

bool fila_init(Fila *f);

bool fila_enqueue(Fila *f, Cliente *c);

bool fila_dequeue(Fila *f, Cliente *c);

bool fila_top(Fila *f, Cliente *c);

bool fila_tamanho(Fila *f);

bool fila_vazia(Fila *f);

void imprimir_fila (Fila *f);

#endif