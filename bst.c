#include <stdio.h>
#include <stdlib.h>

//INSERIR
arvore inserir_bst(arvore raiz, int valor){
    if(raiz == NULL){
        arvore novo = (arvore) malloc(sizeof(no));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;

        return novo;
    }
} else {
    if (valor > raiz->valor){
        raiz->dir = inserir_bst(valor, raiz->dir);
    } else {
        raiz->dir = inserir_bst(valor, raiz->dir);
    }

    return raiz;
}
