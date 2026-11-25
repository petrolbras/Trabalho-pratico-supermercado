Nosso sistemas com a lógica de filas foi implementado com o objetivo de gerenciar os clientes nos caixas do mercado, onde eles serão atendidos. No nosso código, ele permite adicionar clientes na fila do caixa (enqueue) e remover da fila (dequeue) por exemplo

Também foi implementado a lógica gulosa de redistribuição dos clientes, onde eles são realocados, caso um caixa feche ou esteja cheio, para o caixa com menor quantidade de clientes.

Algo importante de se ressaltar é que nossos clientes estão dentro de um vetor fixo, assim como seus produtos. E usamos as filas circulares tanto para evitar a realocação O(n) quanto para reaproveitar os espaços deixados pelos clientes atendidos na nossa fila, assim as filas circulares são mais eficientes e "fancy".
 
Um exemplo é inicializar o mercado através das funções disponibilizadas que, também, acaba iniciando os caixas. Após isso, você pode criar clientes e, através do enqueue, colocá-los na fila de certos caixas. Depois, usar a função de atender_caixa para atender esses clientes (lembrando que essa função só atende o primeiro cliente, isto é, o que foi inserido primeiro na fila) e assim o sistema de mercado funciona.

Para compilar e rodar utilize: 

1 - Para compilar os arquivos base -> make;

2 - Para rodar o arquivo criado -> make run;

3 - Para limpar - make clean.
