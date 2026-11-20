#include "lista.h"
#include <stdio.h>
#include <string.h>

int main(void) {

    // Aplicação simples

    printf(" -- APLICACAO SIMPLES DO ESTOQUE -- ");

    estoque A = {0};

    produto produtoTeste;

    produtoTeste.id = 55;
    produtoTeste.quantidade = 10;
    strcpy(produtoTeste.nome, "arroz");

    printf("\nproduto criado: %s, quantidade: %d, id: %d\n", produtoTeste.nome,
           produtoTeste.quantidade, produtoTeste.id);

    printf("\nEstoque antes: \n");

    imprimir_lista(&A);

    est_insert(&A, produtoTeste, 0);

    printf("\n\n Estoque depois: \n");

    imprimir_lista(&A);

    // Casos especiais

    estoque l = {0};

    produto p;
    produto p2;

    printf("\n-- Teste 1: A estrutura está vazia --\n");

    if (!est_remover(&l, 0, &p2)) {
        printf("Erro: nao e possivel remover de uma estrutura vazia!\n");
    }

    if (!est_buscar(&l, 10)) {
        printf("Erro: produto nao encontrado!\n");
    }

    printf("\n-- Teste 2: A estrutura está cheia --");

    for (int i = 0; i < MAX_ARMAZEM; i++) {
        p.id = 1;
        p.quantidade = 10;
        sprintf(p.nome, "Produto %d", i);

        if (!est_insert(&l, p, l.tamanho)) {
            printf("Erro: falha ao inserir produto!\n");
        }
    }

    printf("\n o estoque esta cheio? %s \n", est_cheio(&l) ? "SIM" : "NAO");

    p.id = 99;
    p.quantidade = 5;

    printf("\nproduto extra criado: %s", p.nome);
    if (!est_insert(&l, p, l.tamanho)) {
        printf("\nErro: nao e possivel inserir! estoque cheio.\n");
    }

    printf("\n-- Teste 3: produto invalido --\n");

    if (!est_remover(&l, -1, &p2)) {
        printf("Erro: posicao de remocao invalida.\n");
    }

    if (!est_insert(&l, p, -1)) {
        printf("Erro: posicao de insercao invalida!\n");
    }

    if (!est_buscar(&l, 9999)) {
        printf("Erro: esse id de produto nao existe!\n");
    }

    printf("\n-- lista final --\n\n");
    imprimir_lista(&l);

    return 0;
}