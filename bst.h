#ifndef BST_H
#define BST_H

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

typedef No* arvore;

arvore inserir_bst(arvore raiz, int valor);
arvore remover_bst(arvore raiz, int valor);
void preorder_bst(arvore raiz);
void inorder_bst(arvore raiz);
void posorder_bst(arvore raiz);
void reverso_bst(arvore raiz);
int Primo(int n);
int qtdPrimo(arvore raiz);
void sucessor_bst(int valor, arvore raiz);
void caminho_bst(int valor, arvore raiz);
int somatorio_bst(arvore raiz);
arvore podar_bst(int valor, arvore raiz);
arvore reajusta_bst(arvore raiz, double percentual);
int existe_bst(arvore raiz, int valor);
void descendentes_bst(int valor, arvore raiz);
int altura_bst(arvore raiz);
void imprimir_arvore(arvore raiz, int nivel);

#endif
