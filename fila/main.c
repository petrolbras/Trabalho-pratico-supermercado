#include <stdio.h>
#include "fila.h"

int main(void) {

    Fila teste;

    Cliente c1 = {"Cliente 1"};
    Cliente c2 = {"Cliente 2"};
    Cliente c3 = {"Cliente 3"};

    fila_init(&teste);

    fila_enqueue(&teste, &c1);
    fila_enqueue(&teste, &c2);
    fila_enqueue(&teste, &c3);

    imprimir_fila(&teste);

    fila_top(&teste, &c1);
    printf("Cliente no topo: %s\n", c1.nome);

    printf("Tamanho da fila: %d\n", fila_tamanho(&teste));

    fila_dequeue(&teste, &c1);
    printf("Cliente removido: %s\n", c1.nome);

    imprimir_fila(&teste);

    fila_dequeue(&teste, &c1);
    printf("Cliente removido: %s\n", c1.nome);

    fila_dequeue(&teste, &c1);
    printf("Cliente removido: %s\n", c1.nome);

    imprimir_fila(&teste);

    printf("Tamanho da fila: %d\n", fila_tamanho(&teste));

    return 0;
}