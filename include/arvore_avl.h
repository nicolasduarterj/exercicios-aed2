#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#define JA_INSERIDO -1
#define SUCESSO_INSERCAO 1

typedef struct _tnoe
{
    int chave;
    int fb;
    struct _tnoe *esq;
    struct _tnoe *dir;
} node_t;

node_t *cria_no(int chave);
void cria_vazia(node_t **p_arv);
int arvore_e_vazia(node_t *arv);
int inserir(node_t **p_arv, int valor);

#endif