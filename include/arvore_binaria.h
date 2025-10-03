#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#define JA_INSERIDO -1
#define SUCESSO_INSERCAO 1

#define DELETADO_COM_SUCESSO 1

typedef struct _node_t
{
    int chave;
    struct _node_t *esq, *dir;
} node_t;

void cria_vazia(node_t **p_arv);
int arvore_e_vazia(node_t *arv);
int inserir(node_t **p_arv, int valor);
int remover(node_t **p_arv, int valor);
void percorrer_em_ordem(node_t *arv);
void percorrer_pos_ordem(node_t *arv);
void percorrer_pre_ordem(node_t *arv);

#endif