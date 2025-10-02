#include <stdlib.h>
#include "arvore_avl.h"

#define ARVORE_VAZIA 0
#define REBALANCEADA 1

int balancear(node_t **p_arv);
int altura(node_t *arv);
void rot_esquerda(node_t **p_arv);
void rot_direita(node_t **p_arv);

node_t *cria_no(int chave)
{
    node_t *no;

    no = (node_t *)calloc(1, sizeof(node_t));
    no->chave = chave;
    no->fb = 0;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void cria_vazia(node_t **p_arv)
{
    *p_arv = NULL;
}

int arvore_e_vazia(node_t *arv)
{
    return (arv == NULL);
}

int inserir(node_t **p_arv, int valor)
{
    node_t *novo_no, *arv;
    int insercao_status;

    novo_no = cria_no(valor);
    arv = *p_arv;

    if (arvore_e_vazia(*p_arv))
    {
        *p_arv = novo_no;
        return 1;
    }

    if (valor == arv->chave)
        return JA_INSERIDO;
    if (valor < arv->chave)
        insercao_status = inserir(&(arv->esq), valor);
    if (valor > arv->chave)
        insercao_status = inserir(&(arv->dir), valor);

    /* Isso evita ter que rebalancear a árvore se valor já tiver sido inserido */
    if (insercao_status == JA_INSERIDO)
        return JA_INSERIDO;

    arv->fb = altura(arv->dir) - altura(arv->esq);
    *p_arv = arv;
    balancear(p_arv);
    return SUCESSO_INSERCAO;
}

int altura(node_t *arv)
{
    int alt_esq, alt_dir;

    if (arvore_e_vazia(arv))
        return 0;

    alt_esq = altura(arv->esq);
    alt_dir = altura(arv->dir);

    if (alt_esq > alt_dir)
        return alt_esq + 1;
    else
        return alt_dir + 1;
}

int balancear(node_t **p_arv)
{
    node_t *arv;
    arv = *p_arv;

    if (arvore_e_vazia(arv))
        return ARVORE_VAZIA;

    arv->fb = altura(arv->dir) - altura(arv->esq);

    if (arv->fb == -2) /* desbalanceada para a esquerda */
    {
        if (arv->esq->fb != -1) /* desbalanceados opostamente */
            rot_esquerda(&(arv->esq));

        rot_direita(&arv);
    }

    if (arv->fb == 2) /* desbalanceado para a direita */
    {

        if (arv->dir->fb != 1) /* desbalanceados opostamente */
            rot_direita(&(arv->dir));

        rot_esquerda(&arv);
    }

    *p_arv = arv;
    balancear(&(arv->esq));
    balancear(&(arv->dir));
    return REBALANCEADA;
}

void rot_direita(node_t **p_raiz)
{
    node_t *pai, *filho;
    pai = *p_raiz;
    filho = pai->esq;
    pai->esq = filho->dir;
    filho->dir = pai;
    *p_raiz = filho;
    return;
}

void rot_esquerda(node_t **p_raiz)
{
    node_t *pai, *filho;
    pai = *p_raiz;
    filho = pai->dir;
    pai->dir = filho->esq;
    filho->esq = pai;
    *p_raiz = filho;
    return;
}