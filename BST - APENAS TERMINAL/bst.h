#ifndef BST_H
#define BST_H

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

typedef No* arvore;

arvore inserir_bst(arvore raiz, int aux);
arvore remover_bst(arvore raiz, int aux);
void preorder_bst(arvore raiz);
void inorder_bst(arvore raiz);
void posorder_bst(arvore raiz);
void reverso_bst(arvore raiz);
int Primo(int n);
int qtdPrimo(arvore raiz);
void sucessor_bst(int aux, arvore raiz);
void caminho_bst(int aux, arvore raiz);
int somatorio_bst(arvore raiz);
arvore podar_bst(int aux, arvore raiz);
arvore reajusta_bst(arvore raiz, int percentual);
int existe_bst(arvore raiz, int aux);
void descendentes_bst(int aux, arvore raiz);
int altura_bst(arvore raiz);

#endif

