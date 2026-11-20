FLAGS = -Wall -Wextra

PROGRAM = teste

OBJETOS = main.o pilha.o

all: $(PROGRAM)

$(PROGRAM): $(OBJETOS)
	gcc $(FLAGS) $(OBJETOS) -o teste

main.o: main.c pilha.h
	gcc $(FLAGS) -c main.c

pilha.o: pilha.c pilha.h
	gcc $(FLAGS) -c pilha.c

clean: 
	rm -f $(OBJETOS) $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)