#include <stdio.h>
#include <stdlib.h>

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

//INORDER 
arvore inorder_bst(arvore raiz){
    if (raiz != NULL){
        //Ainda há nós para visitar
        //Visite o nó filho da esquerda.
        inorder_bst(raiz->esq);
        
        //Imprimir o valor do nó atual.
        printf("[%d]", raiz->valor);
        
        //Recursão novamente para visitar o nó filho da direita.
        inorder_bst(raiz->dir);
    }
}   

//POSORDER
arvore posorder_bst(arvore raiz){
    if (raiz != NULL){
        
        //Recursão novamente para visitar os nós esq e dir.
        posorder_bst(raiz->esq);
        posorder_bst(raiz->dir);
        
        //Imprimir o valor do nó atual.
        printf("[%d]", raiz->valor);
    }
}

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

//REVERSO (PRINT DECRESCENTE)
arvore reverso_bst(arvore raiz) {
    
    //Verifica se a árvore é vazia.
    if (root == NULL) {
        return;
    }
    
    //Percorre as subárvores direitas (maiores);
    reverso_bst(root->right);
    //Mostra na tela;
    printf("[%d]", root->data);
    //Percorre as subárvores esquerda (menores);
    reverso_bst(root->left);
    printf("\n");
}

//VERIFICAR SE UM NÚMERO É PRIMO.
int Primo(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// QUANTIDADE DE PRIMOS
int qtdPrimo(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int total = 0;

    if (Primo(raiz->valor)) {
        total++;
    }

    total += qtdPrimo(raiz->esq);
    total += qtdPrimo(raiz->dir);

    return total;
}

arvore sucessor_bst(int n, arvore raiz) {
    if (raiz == NULL) {
        printf("-1\n");
        return;
    }

    arvore sucessor = NULL;
    arvore atual = raiz;

    // Encontrar o nó com o valor n na árvore
    while (atual != NULL) {
        if (n < atual->valor) {
            sucessor = atual;
            atual = atual->esq;
        } else if (n > atual->valor) {
            atual = atual->dir;
        } else {
            break;
        }
    }

    // Verificar se o nó com o valor n foi encontrado
    if (atual == NULL) {
        printf("-1\n");
        return;
    }

    // Encontrar o nó sucessor
    if (atual->dir != NULL) {
        sucessor = atual->dir;
        while (sucessor->esq != NULL) {
            sucessor = sucessor->esq;
        }
        printf("%d\n", sucessor->valor);
    } else if (sucessor != NULL) {
        printf("%d\n", sucessor->valor);
    } else {
        printf("-1\n");
    }
}

arvore caminho(int n, arvore raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("[%d]", raiz->valor);

    if (n < raiz->valor) {
        caminho(n, raiz->esq);
    } else if (n > raiz->valor) {
        caminho(n, raiz->dir);
    } else {
        printf("\n");
    }
}

    
