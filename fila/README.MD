Nosso sistemas com a lógica de filas foi implementado com o objetivo de gerenciar os clientes nos caixas do mercado, onde eles serão atendidos. No nosso código, ele permite adicionar clientes na fila do caixa (enqueue) e remover da fila (dequeue)

Também foi implementado a lógica gulosa de redistribuição dos clientes, onde eles são realocados, caso um caixa feche ou esteja cheio, para o caixa com menor quantidade de clientes.

Algo importante de se ressaltar é que nossos clientes estão dentro de um vetor fixo, assim como seus produtos. E usamos as filas circulares tanto para evitar a realocação O(n) quanto para reaproveitar os espaços deixados pelos clientes atendidos na nossa fila, assim as filas circulares são mais eficientes e "fancy".
 
Um exemplo é adicionar cliente para um caixa disponível, esse cliente será atendido e os itens (posteriormente) serão atualizados nos estoques e, caso necessário, na pilha de devoluções.

Para compilar e rodar utilize: 

1 - Para compilar os arquivos base -> make
2 - Para rodar o arquivo criado -> make run
3 - Para limpar - make clean