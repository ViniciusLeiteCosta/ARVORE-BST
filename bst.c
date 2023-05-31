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

//PREORDER
arvore preorder_bst(arvore raiz){
    if (raiz != NULL){
        //Processar minha raiz relativa.
        printf("[%d]", raiz->valor);
        
        //Encadeamentoso recursivos.
        preorder_bst(raiz->esq);
        preorder_bst(raiz->dir);
    }
}    
