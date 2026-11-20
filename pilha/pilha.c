#include "pilha.h"
#include <stdio.h>
#include <string.h>

int pilha_tamanho(devolucoes *a) { return a->top + 1; }

bool pilha_init(devolucoes *a) {
    a->top = -1;

    return true;
}

bool pilha_vazio(devolucoes *a) { return a->top == -1; }

bool pilha_cheia(devolucoes *a) { return a->top == MAX_DADOS - 1; }

bool pilha_topo(devolucoes *a, produto *p) {

    if (pilha_vazio(a)) {
        printf("a pilha esta vazia!");
        return false;
    }

    *p = a->dados[a->top];

    return true;
}

bool pilha_push(devolucoes *a, produto *p) {
    if (pilha_cheia(a)) {
        printf("A pilha ja esta cheia");
        return false;
    }

    if (p->quantidade <= 0 || p->id < 0 || strlen(p->nome) == 0) {
        return false;
    }

    a->dados[++a->top] = *p;

    printf("voce adicionou: %s!\n", p->nome);

    return true;
}

bool pilha_pop(devolucoes *a, produto *p) {
    if (pilha_vazio(a)) {
        printf("a pilha esta vazia\n");
        return false;
    }

    *p = a->dados[a->top];

    printf("voce removeu: %s!\n", p->nome);

    a->top--;

    return true;
}

void imprimir_pilha(devolucoes *a) {
    int i;
    for (i = 0; i <= a->top; i++) {
        printf(" [%s: %d] ->", a->dados[i].nome, a->dados[i].quantidade);
    }

    if (a->top + 1 == 0) {
        printf("- Pilha vazia!\n");
    } else {
        printf(" COMECO\n");
    }
}