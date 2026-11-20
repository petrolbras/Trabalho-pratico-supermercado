FLAGS = -Wall -Wextra

PROGRAM = teste

OBJETOS = main.o fila.o

all: $(PROGRAM)

$(PROGRAM): $(OBJETOS)
	gcc $(FLAGS) $(OBJETOS) -o teste

main.o: main.c fila.h
	gcc $(FLAGS) -c main.c

fila.o: fila.c fila.h
	gcc $(FLAGS) -c fila.c

clean: 
	rm -f $(OBJETOS) $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)