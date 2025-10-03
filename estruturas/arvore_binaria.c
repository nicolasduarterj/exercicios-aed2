#include <stdlib.h>
#include <stdio.h>

#include "arvore_binaria.h"

int remover_com_um_filho(node_t **p_arv, int valor);
int remover_com_dois_filhos(node_t **p_arv, int valor);

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

void cria_vazia(node_t **p_arv)
{
    *p_arv = NULL;
    return;
}

int arvore_e_vazia(node_t *arv)
{
    return arv == NULL;
}

int inserir(node_t **p_arv, int valor)
{
    node_t *novo_no, *raiz = *p_arv;
    novo_no = cria_no(valor);
    /*----------[Árvore vazia]-------------*/
    if (arvore_e_vazia(*p_arv))
    {
        *p_arv = novo_no;
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

node_t *busca(node_t *arv, int valor)
{
    if (arvore_e_vazia(arv))
    {
        return NULL;
    }

    if (arv->chave == valor)
        return arv;

    if (arv->chave > valor)
        return busca(arv->dir, valor);

    return busca(arv->esq, valor);
}

node_t *sucessor(node_t *atual)
{
    atual = atual->dir;
    while (atual != NULL && atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

int remover(node_t **p_arv, int valor)
{
    node_t *substituto, *no_sucessor, *arv;

    if (arvore_e_vazia(*p_arv))
        return DELETADO_COM_SUCESSO;

    arv = *p_arv;

    if (valor > arv->chave)
        return remover(&(arv->dir), valor);
    if (valor < arv->chave)
        return remover(&(arv->esq), valor);

    /* arv->chave == valor */

    if (arv->esq == NULL)
    {
        substituto = arv->dir;
        free(arv);
        *p_arv = substituto;
        return DELETADO_COM_SUCESSO;
    }

    if (arv->dir == NULL)
    {
        substituto = arv->esq;
        free(arv);
        *p_arv = substituto;
        return DELETADO_COM_SUCESSO;
    }

    no_sucessor = sucessor(arv);
    arv->chave = no_sucessor->chave;
    remover(&(arv->dir), no_sucessor->chave);
    return DELETADO_COM_SUCESSO;
}

void percorrer_em_ordem(node_t *arv)
{
    if (arvore_e_vazia(arv))
        return;

    percorrer_em_ordem(arv->esq);
    printf("%d ", arv->chave);
    percorrer_em_ordem(arv->dir);
}

void percorrer_pre_ordem(node_t *arv)
{
    if (arvore_e_vazia(arv))
        return;

    printf("%d ", arv->chave);
    percorrer_pre_ordem(arv->esq);
    percorrer_pre_ordem(arv->dir);
}

void percorrer_pos_ordem(node_t *arv)
{
    if (arvore_e_vazia(arv))
        return;

    percorrer_pos_ordem(arv->esq);
    percorrer_pos_ordem(arv->dir);
    printf("%d ", arv->chave);
}