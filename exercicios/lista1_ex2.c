#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "arvore_binaria.h"

int main(int argc, char **argv)
{
    node_t *arv;
    int i, i_a_remover;

    srand(time(NULL));

    if (argc < 2)
    {
        printf("Argumentos insuficientes! Insira uma lista de inteiros como argumentos da linha de comando. (e.g. 1 7 2 4 18 13)\n");
        return EXIT_FAILURE;
    }

    cria_vazia(&arv);
    printf("Inserindo todos os números...\n\n");
    for (i = 1; i < argc; i++)
    {
        inserir(&arv, atoi(argv[i]));
    }
    printf("Árvore percorrida em ordem:");
    percorrer_em_ordem(arv);
    printf("\n");

    printf("Árvore percorrida em pré-ordem:");
    percorrer_pre_ordem(arv);
    printf("\n");

    printf("Árvore percorrida em pós-ordem:");
    percorrer_pos_ordem(arv);
    printf("\n");

    i_a_remover = rand() % (argc - 1);

    printf("\n\nRemovendo o %dº número inserido (valor escolhido aleatoriamente)...\n", i_a_remover + 1);
    remover(&arv, atoi(argv[i_a_remover + 1]));
    printf("Sua árvore em ordem após a remoção:");
    percorrer_em_ordem(arv);
    printf("\n");
    return 0;
}