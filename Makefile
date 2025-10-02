CFLAGS = -Wall -ansi -Iinclude -g
CC=gcc

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
