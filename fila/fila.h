#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define MAX_NOME 20
#define MAX_PRODUTOS 10
#define MAX_CLIENTES_FILA 5
#define MAX_AUX 20

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
    Cliente clientes[MAX_CLIENTES_FILA];
    int inicio;
    int fim;
    int tamanho;
} Fila;

bool fila_init(Fila *f);

bool fila_isfull(Fila *f);

bool fila_vazia(Fila *f);

bool fila_enqueue(Fila *f, Cliente *c);

bool fila_dequeue(Fila *f, Cliente *c);

bool fila_top(Fila *f, Cliente *c);

int fila_tamanho(Fila *f);

void imprimir_fila (Fila *f);

#endif