#include "lista.h"
#include <stdio.h>
#include <string.h>

bool est_cheio(estoque *l) { return l->tamanho >= MAX_ARMAZEM; }

bool est_remover(estoque *l, int posicao, produto *val) {
    if (l->tamanho == 0 || posicao < 0 || posicao >= l->tamanho) {
        return false;
    }

    (*val) = l->armazem[posicao];

    int i;
    for (i = posicao; i < l->tamanho - 1; i++) {
        l->armazem[i] = l->armazem[i + 1];
    }

    printf("o produto: '%s' foi removido", val->nome);

    l->tamanho--;

    return true;
}

bool est_insert(estoque *l, produto val, int posicao) {
    if (est_cheio(l) || posicao > l->tamanho || posicao < 0 || strlen(val.nome) == 0) {
        return false;
    }
    int i;
    for (i = l->tamanho - 1; i > posicao; i--) {
        l->armazem[i + 1] = l->armazem[i];
    }

    l->armazem[posicao] = val;
    l->tamanho++;

    return true;
}

bool est_buscar(estoque *l, int id) {
    if (id < 0 || id > l->tamanho - 1) {
        return false;
    }

    int i;
    for (i = 0; i < l->tamanho; i++) {
        if (l->armazem[i].id == id) {
            printf("O produto '%s' foi encontrado na posicao: %d",
                   l->armazem[i].nome, i);
            return true;
        }
    }

    return false;
}

bool est_atualizar_quantidade(estoque *l, int id, int quantidade) {
    if (id < 0 || id > l->tamanho - 1 || quantidade > MAX_QUANTIDADE_PRODUTO ||
        quantidade < 0) {
        return false;
    }

    int i;
    for (i = 0; i < l->tamanho; i++) {
        if (l->armazem[i].id == id) {
            l->armazem[i].quantidade = quantidade;
            printf("Quantidade atualizada do produto: '%s' para %d",
                   l->armazem[i].nome, quantidade);
            return true;
        }
    }

    return false;
}

void imprimir_lista(estoque *l) {
    int i;
    for (i = 0; i < l->tamanho; i++) {
        printf(" [%s: %d] ->", l->armazem[i].nome, l->armazem[i].quantidade);
    }

    if (l->tamanho == 0) {
        printf("- Estoque vazio!\n");
    } else {
        printf(" FIM\n");
    }
}
