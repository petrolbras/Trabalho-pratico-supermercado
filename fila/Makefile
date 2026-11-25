FLAGS = -Wall -Wextra

PROGRAM = teste

OBJETOS = main.o fila.o mercado.o

all: $(PROGRAM)

$(PROGRAM): $(OBJETOS)
	gcc $(FLAGS) $(OBJETOS) -o teste

main.o: main.c fila.h mercado.h
	gcc $(FLAGS) -c main.c

fila.o: fila.c fila.h mercado.h
	gcc $(FLAGS) -c fila.c

mercado.o: mercado.c mercado.h fila.h
	gcc $(FLAGS) -c mercado.c

clean: 
	rm -f $(OBJETOS) $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)