#include <stdio.h>
#include "fila.h"
#include "mercado.h"
#include <unistd.h>

int main(void) {

    printf("=== Caso de teste simples ===\n");

    mercado m;
    mercado_init(&m);

    printf("\nMercado iniciado!\n");

    printf("\n--- Antes do atendimento ---\n");

    int i;

    for (i = 0; i < MAX_CAIXAS; i++) {
        abrir_caixa(&m.caixas[i]);
    }

    printf("\nCaixas abertos!\n");

    Cliente c1 = {"Cliente 1", {{2, 1, "Produto A"}, {3, 2, "Produto B"}}};
    Cliente c2 = {"Cliente 2", {{1, 3, "Produto C"}}};
    Cliente c3 = {"Cliente 3", {{4, 4, "Produto D"}, {2, 5, "Produto E"}}};
    Cliente c4 = {"Cliente 4", {{1, 6, "Produto F"}}};
    Cliente c5 = {"Cliente 5", {{3, 7, "Produto G"}}};
    Cliente c6 = {"Cliente 6", {{2, 8, "Produto H"}}};
    Cliente c7 = {"Cliente 7", {{1, 9, "Produto I"}}};

    // irei reaproveitar clientes apenas para teste

    fila_enqueue(&m.caixas[0].fila, &c1);
    fila_enqueue(&m.caixas[0].fila, &c2);

    fila_enqueue(&m.caixas[1].fila, &c2);
    fila_enqueue(&m.caixas[1].fila, &c3);

    fila_enqueue(&m.caixas[2].fila, &c3);

    fila_enqueue(&m.caixas[3].fila, &c4);
    fila_enqueue(&m.caixas[3].fila, &c5);
    fila_enqueue(&m.caixas[3].fila, &c6);

    fila_enqueue(&m.caixas[4].fila, &c5);
    fila_enqueue(&m.caixas[5].fila, &c6);
    fila_enqueue(&m.caixas[6].fila, &c7);

    printf("\nClientes adicionados as fila!\n\n");

    printf("(Sera usados clientes repetidos apenas para teste, nao se preocupe com isso)\n\n");

    for (i = 0; i < MAX_CAIXAS; i++) {
        imprimir_fila(&m.caixas[i].fila);
    }

    atender_caixa(&m.caixas[0]);
    atender_caixa(&m.caixas[3]);
    atender_caixa(&m.caixas[5]);

    printf("\n--- Após atendimento ---\n");

    for (i = 0; i < MAX_CAIXAS; i++) {
        imprimir_fila(&m.caixas[i].fila);
    }

    printf("\n=== Casos de testes especiais ===\n");

    printf("\n--- Estrutura vazia ---\n");

    Fila f;
    fila_init(&f);

    Cliente c;
    
    if (!fila_dequeue(&f, &c)) {
        printf("ERRO: Fila vazia nao, e possível remover elementos!\n");
    }

    printf("\n--- Estrutura cheia ---\n");

    int j;

    for (j = 0; j < MAX_CLIENTES_FILA; j++) {
        Cliente ct;
        fila_enqueue(&f, &ct);
    }

    printf("\nEstrutura cheia!\n");

    if (!fila_enqueue(&f, &c)) {
        printf("ERRO: Fila cheia nao, e possível adicionar elementos!\n");
    }

    printf("\n--- Valor invalido ---\n");

    if (!fila_enqueue(&f, NULL)) {
        printf("ERRO: Fila nao aceita valor nulo!\n");
    }

    return 0;
}