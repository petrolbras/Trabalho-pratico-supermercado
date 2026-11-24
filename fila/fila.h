#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define MAX_NOME 20
#define MAX_PRODUTOS 10
#define MAX_CLIENTES 5

typedef struct {
    int quantidade;
    int id;
    char nome[MAX_NOME];
} produto;
typedef struct {
    char nome[MAX_NOME];
    produto produtos[MAX_PRODUTOS];
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

bool fila_isfull(Fila *f);

bool fila_vazia(Fila *f);

bool fila_enqueue(Fila *f, Cliente *c);

bool fila_dequeue(Fila *f, Cliente *c);

bool fila_top(Fila *f, Cliente *c);

int fila_tamanho(Fila *f);

void imprimir_fila (Fila *f);

#endif