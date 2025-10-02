CFLAGS = -Wall -ansi -Iinclude -g

lista2_ex3: ./build/lista2_ex3.o ./build/arvore_avl.o
	gcc $(CFLAGS) -o lista2_ex3 ./build/lista2_ex3.o ./build/arvore_avl.o
	@echo ""
	@echo "Exercício 3 da lista 2 disponível no arquivo \"lista2_ex3\""

./build/lista2_ex3.o: ./exercicios/lista2_ex3.c 
	gcc $(CFLAGS) -c -o ./build/lista2_ex3.o ./exercicios/lista2_ex3.c

./build/arvore_avl.o: ./estruturas/arvore_avl.c
	gcc $(CFLAGS) -c -o ./build/arvore_avl.o ./estruturas/arvore_avl.c

clean:
	@echo "Limpando arquivos de build"
	rm -f ./build/*.o
	rm -f ./lista2_ex3
