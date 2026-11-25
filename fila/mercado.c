#include <stdio.h>
#include <stdbool.h>

#include "mercado.h"
#include "fila.h"

bool mercado_init(mercado *m) {
    int i;

    for (i = 0; i < MAX_CAIXAS; i++) {
        m->caixas[i].aberto = false;
        m->caixas[i].atual.nome[0] = '\0';
        fila_init(&m->caixas[i].fila);
        m->caixas[i].id = i + 1;
    }

    return true;
}

bool fechar_caixa(Caixa *c) {
    if (c->aberto) {
        c->aberto = false;
        return true;
    }

    return false;
}

bool abrir_caixa(Caixa *c) {
    if (!c->aberto) {
        c->aberto = true;
        return true;
    }

    return false;
}

bool caixa_fechado(Caixa *c) {
    return !c->aberto;
}

bool caixa_tem_clientes(Caixa *c) {
    return c->fila.tamanho > 0;
}

bool atender_caixa(Caixa *c) {
    if (!c->aberto) {
        return false;
    }

    // atende o cliente, removendo-o da fila e salvando c->atual graças a atribuicao de fila_dequeue

    if (!fila_dequeue(&c->fila, &c->atual)) {
        return false;
    }

    // atende o cliente zerando todos os produtos que ele estava segurando

    // int i;
    // for (i = 0; i < MAX_PRODUTOS; i++) {
        // c->atual.produtos->nome[i] = '\0';
    // }

    // c->atual.produtos->quantidade = 0;

    return true;
}

bool redistribuicao_gulosa_caixas(mercado *c) {
    int i, j;

    Cliente *aux[MAX_AUX];

    for (i = 0; i < MAX_AUX; i++) {
        aux[i] = NULL;
    }

    // traz os clientes do caixa chamado pela funcao caso ele esteja fechado e se tiver clientes, claro. E coloca eles num vetor auxiliar aux

    for (i = 0; i < MAX_CAIXAS; i++) {
        if (caixa_tem_clientes(&c->caixas[i]) && caixa_fechado(&c->caixas[i])) {
            for (j = 0; j < MAX_CLIENTES_FILA; j++) {
                if (c->caixas[i].fila.clientes[j].nome[0] != '\0') {
                    aux[j] = &c->caixas[i].fila.clientes[j];
                    fila_dequeue(&c->caixas[i].fila, &c->caixas[i].fila.clientes[j]);
                }
            }
        }
    }

    int qntd_aux = 0;

    for (i = 0; i < MAX_AUX; i++) {
        if (aux[i] != NULL) {
            qntd_aux++;
        }
    }

    if (qntd_aux == 0) {
        return false;
    }

    int proximo = 0;

    while (proximo < qntd_aux) {

        Caixa *mais_vazio = NULL;

        // descobre o caixa mais vazio no momento

        for (i = 0; i < MAX_CAIXAS; i++) {
            Caixa *candidato = &c->caixas[i];

            if (!candidato->aberto || fila_isfull(&candidato->fila)) {
                continue;
            }

            if (mais_vazio == NULL || candidato->fila.tamanho < mais_vazio->fila.tamanho) {
                mais_vazio = candidato;
            }
        }

        if (mais_vazio == NULL) {
            return false;
        }

        // redistribui os clientes do vetor aux para o caixa mais vazio na iteracao atual do while

        if (!fila_enqueue(&mais_vazio->fila, aux[proximo])) {
            return false;
        }

        proximo++;
    }

    return true;
}