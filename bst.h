#ifndef BST_H
#define BST_H

//Estrutura do no.
typedef struct no {
    int valor;
    struct no* esq;
    struct no* dir;
} *arvore;

//Cabeçalho das funções.
arvore preorder_bst(arvore raiz);
arvore inorder_bst(arvore raiz);
arvore posorder_bst(arvore raiz);
arvore inserir_bst(arvore raiz, int valor);
arvore remover_bst(arvore raiz, int valor);
arvore reverso_bst(arvore raiz);
int Primo(int num);
int qtdPrimo(arvore raiz);
arvore sucessor_bst(int n, arvore raiz);
arvore caminho_bst(int n, arvore raiz);
int somatorio_bst(arvore raiz);
arvore podar_bst(int n, arvore raiz);
arvore reajusta_bst(arvore raiz, double percentual);
int existe_bst(arvore raiz, int chave);
arvore descendentes_bst(int n, arvore raiz);
int altura_bst(arvore raiz);
void sair();

#endif



