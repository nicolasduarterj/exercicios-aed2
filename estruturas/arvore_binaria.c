#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct _node_t
{
    int chave;
    struct _node_t *esq, *dir;
} node_t;

node_t *cria_no(int chave)
{
    node_t *no;

    no = (node_t *)calloc(1, sizeof(node_t));
    if (no == NULL)
        exit(1);

    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

node_t *cria_arvore_vazia()
{
    return NULL;
}

int arvore_esta_vazia(node_t *arv)
{
    return arv == NULL;
}

int inserir(node_t **arv, int valor)
{
    node_t *novo_no, *raiz = *arv;
    novo_no = cria_no(valor);
    /*----------[Árvore vazia]-------------*/
    if (arvore_esta_vazia(*arv))
    {
        *arv = novo_no;
        return 1;
    }
    /*-----------[Igual]-------------------*/
    if (raiz->chave == valor)
        return -1;
    /*-----------[Menor]-------------------*/
    if (valor < raiz->chave)
    {
        if (raiz->esq == NULL)
        {
            raiz->esq = novo_no;
            return 3;
        }

        inserir(&(raiz->esq), valor);
        return 4;
    }
    /*-----------[Maior]--------------------*/
    if (raiz->dir == NULL)
    {
        raiz->dir = novo_no;
        return 5;
    }

    inserir(&(raiz->dir), valor);
    return 6;
}

void remover(node_t **arv, int valor)
{
}
