#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main(void) {

    // aplicacao simples

    printf(" -- APLICACAO SIMPLES DA PILHA -- \n\n");

    devolucoes a;

    produto p1;
    strcpy(p1.nome, "arroz");
    p1.quantidade = 12;
    p1.id = 6;

    produto p2;
    strcpy(p2.nome, "batata");
    p2.quantidade = 20;
    p2.id = 10;

    produto p3;
    strcpy(p3.nome, "feijao");
    p3.quantidade = 10;
    p3.id = 20;

    pilha_init(&a);

    pilha_push(&a, &p1);

    pilha_push(&a, &p2);

    pilha_push(&a, &p3);

    printf("\n");

    imprimir_pilha(&a);

    printf("\n");

    pilha_pop(&a, &p1);

    pilha_pop(&a, &p2);

    pilha_pop(&a, &p3);

    printf("\n");

    imprimir_pilha(&a);

    // aplicacao especial

    printf("\n ---- APLICACOES ESPECIAIS DA PILHA ---- \n");

    devolucoes x;

    pilha_init(&x);

    produto t1;
    strcpy(t1.nome, "leite");
    t1.quantidade = 16;
    t1.id = 15;

    printf("\n -- Teste: Pilha vazia -- \n");

    if (!pilha_pop(&x, &t1)) {
        printf("ERRO: A pilha esta vazia!\n");
    };

    produto t2;

    int i;
    for (i = 0; i < MAX_DADOS; i++) {
        t2.quantidade = 5;
        t2.id = 1;
        strcpy(t2.nome, "macarrao");

        if (!pilha_push(&x, &t2)) {
            printf("Falha ao inserir o produto!\n");
        };
    }

    printf("\nA pilha esta cheia? %s\n", x.top == MAX_DADOS - 1 ? "SIM" : "NAO");

    printf("\n -- Teste: Pilha cheia -- \n");

    produto t3;
    strcpy(t3.nome, "ovo");
    t3.quantidade = 9;
    t3.id = 2;

    printf("produto criado! nome: %s, quantidade: %d\n", t3.nome,
           t3.quantidade);

    if (!pilha_push(&x, &t3)) {
        printf("\nERRO: A pilha esta cheia!\n");
    }

    printf("\n -- Teste: valor invalido -- \n");

    produto t4;
    strcpy(t4.nome, "queijo");
    t4.quantidade = -5;
    t4.id = 28;

    produto t5;
    strcpy(t5.nome, "chocolate");
    t5.quantidade = 7;
    t5.id = -1;

    produto t6;
    strcpy(t6.nome, "");
    t6.quantidade = 7;
    t6.id = 10;

    devolucoes c;

    pilha_init(&c);

    if (!pilha_push(&c, &t4)) {
        printf("ERRO: Quantidade invalida!\n");
    }

    if (!pilha_push(&c, &t5)) {
        printf("ERRO: Id invalido!\n");
    }

    if (!pilha_push(&c, &t6)) {
        printf("ERRO: nome invalido!\n");
    }

    return 0;
}