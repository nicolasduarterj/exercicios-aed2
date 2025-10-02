#include <stdlib.h>
#include <stdio.h>
#include "arvore_avl.h"

/* Isso essencialmente faz um depth-first search, mas printando tudo */
void printar_arvore_em_ordem(node_t *arv)
{
    if (arvore_e_vazia(arv))
        return;

    printar_arvore_em_ordem(arv->esq);
    printf("%c ", (char)arv->chave);
    printar_arvore_em_ordem(arv->dir);
}

int main(void)
{
    node_t *arvore;
    cria_vazia(&arvore);
    inserir(&arvore, 'N');
    inserir(&arvore, 'I');
    inserir(&arvore, 'C');
    inserir(&arvore, 'O');
    inserir(&arvore, 'L');
    inserir(&arvore, 'A');
    inserir(&arvore, 'S');
    inserir(&arvore, 'D');
    inserir(&arvore, 'U');
    inserir(&arvore, 'A');
    inserir(&arvore, 'R');
    inserir(&arvore, 'T');
    inserir(&arvore, 'E');

    printf("Printando os caractéres de \"NICOLASDUARTE\" em ordem alfabética...\n");
    printar_arvore_em_ordem(arvore);
    printf("\n");
    return 0;
}
