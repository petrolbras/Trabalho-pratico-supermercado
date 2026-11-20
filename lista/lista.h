#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>

#define MAX_NOME 30
#define MAX_ARMAZEM 30
#define MAX_QUANTIDADE_PRODUTO 99

typedef struct {
    int quantidade;
    int id;
    char nome[MAX_NOME];
} produto;

typedef struct {
    produto armazem[MAX_ARMAZEM];
    int tamanho;
} estoque;

bool est_cheio(estoque *l);

bool est_remover(estoque *l, int posicao, produto *val);

bool est_insert(estoque *l, produto val, int posicao);

bool est_buscar(estoque *l, int id);

bool est_atualizar_quantidade(estoque *l, int id, int quantidade);

void imprimir_lista(estoque *l);

#endif