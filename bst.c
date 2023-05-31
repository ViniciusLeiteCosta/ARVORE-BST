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

//REMOVER
arvore remover_bst(arvore raiz, int valor){
    
    //Remover de uma subárvore vaiza / remover elemento inexistente
    if (raiz == NULL){
        return raiz;
    }
    
    if (raiz->valor == valor){
        
        //CASO 1: NÃO TEM FILHOS.
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }
        
        //CASO 2: TEM UM FILHO ESQUERDO.
        if(raiz->esq != NULL && raiz->dir == NULL){
            arvore aux = raiz->esq;
            free(raiz);
            return aux;
        }
        
        //CASO 3: QUANDO O NÓ TEM DOIS FILHOS.
        //NÃO PRECISA DE CONDICIONAL 
       
        int maiorValorSubarvoreEsquerda = maior(raiz->esq)->valor;
        raiz->valor = maiorValorSubarvoreEsquerda;
        raiz->esq = remover_bst(raiz->esq, maiorValorSubarvoreEsquerda);
        
        return raiz;
    }
    
    /*Se o valor a ser removido for maior que o valor da raiz atual, chame recursivamente a função remover_bst na subárvore direita.
    Caso contrário, chame recursivamente a função remover_bst na subárvore esquerda.
    Retorne a raiz atual após a remoção ter sido feita em uma das subárvores (ou sem alterações se o valor não for encontrado).*/
    if(valor > raiz->valor) {
       raiz->dir = remover_bst(raiz->dir, valor);
    } else {
        //É simétrico
    }
    return raiz;
}
