CFLAGS = -Wall -ansi -Iinclude -g
CC=gcc

lista1_ex2: ./build/lista1_ex2.o ./build/arvore_binaria.o
	$(CC) $(CFLAGS) -o lista1_ex2 ./build/arvore_binaria.o ./build/lista1_ex2.o

./build/lista1_ex2.o: ./exercicios/lista1_ex2.c
	$(CC) $(CFLAGS) -c -o ./build/lista1_ex2.o ./exercicios/lista1_ex2.c

./build/arvore_binaria.o: ./estruturas/arvore_binaria.c
	$(CC) $(CFLAGS) -c -o ./build/arvore_binaria.o ./estruturas/arvore_binaria.c

lista2_ex3: ./build/lista2_ex3.o ./build/arvore_avl.o
	$(CC) $(CFLAGS) -o lista2_ex3 ./build/lista2_ex3.o ./build/arvore_avl.o
	@echo ""
	@echo "Exercício 3 da lista 2 disponível no arquivo \"lista2_ex3\""

./build/lista2_ex3.o: ./exercicios/lista2_ex3.c 
	$(CC) $(CFLAGS) -c -o ./build/lista2_ex3.o ./exercicios/lista2_ex3.c

./build/arvore_avl.o: ./estruturas/arvore_avl.c
	$(CC) $(CFLAGS) -c -o ./build/arvore_avl.o ./estruturas/arvore_avl.c

clean:
	@echo "Limpando arquivos de build"
	rm -f ./build/*.o
	rm -f ./lista2_ex3
	rm -f ./lista1_ex2
