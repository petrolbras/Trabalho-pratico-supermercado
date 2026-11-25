#include <stdio.h>
#include "fila.h"
#include "mercado.h"

bool fila_init(Fila * f){
    f->tamanho = f->inicio = f->fim = 0;
    return true;
}

bool fila_isfull(Fila *f) {
    return f->tamanho == MAX_CLIENTES_FILA;
}

bool fila_vazia(Fila  *f){
    return f->tamanho == 0;
}

bool fila_enqueue(Fila * f, Cliente * c){
    if(fila_isfull(f) || c == NULL) return false;
    f->clientes[f->fim] = *c;
    f->fim = (f->fim + 1) % MAX_CLIENTES_FILA;
    f->tamanho++;
    return true;
}

bool fila_dequeue(Fila * f, Cliente * c){
    if(fila_vazia(f)) return false;
    *c = f->clientes[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_CLIENTES_FILA;
    f->tamanho--;
    return true;
}

bool fila_top(Fila * f, Cliente * c){
    if(fila_vazia(f)) return false;
    *c = f->clientes[f->inicio];
    return true;
}

int fila_tamanho(Fila * f){
    return f->tamanho;
}

void imprimir_fila (Fila *f){
    int i = f->inicio, j;

    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    for(j = 0; j < f->tamanho; j++){
        if (j == f->tamanho - 1)
            printf("[%s]", f->clientes[i].nome);
        else {
            printf("[%s] -> ", f->clientes[i].nome);
        }

        i = (i + 1) % MAX_CLIENTES_FILA;
    }

    printf("\n");

}
