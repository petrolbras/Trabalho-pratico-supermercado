FLAGS = -Wall -Wextra

PROGRAM = teste

OBJETOS = main.o lista.o

all: $(PROGRAM)

$(PROGRAM): $(OBJETOS)
	gcc $(FLAGS) $(OBJETOS) -o teste

main.o: main.c lista.h
	gcc $(FLAGS) -c main.c

lista.o: lista.c lista.h
	gcc $(FLAGS) -c lista.c

clean: 
	rm -f $(OBJETOS) $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)