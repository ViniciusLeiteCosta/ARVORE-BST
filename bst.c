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

//SUCESSOR
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

//CAMINHO
arvore caminho_bst(int n, arvore raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("[%d]", raiz->valor);

    if (n < raiz->valor) {
        caminho_bst(n, raiz->esq);
    } else if (n > raiz->valor) {
        caminho_bst(n, raiz->dir);
    } else {
        printf("\n");
    }
}

//SOMATÓRIO
int somatorio_bst(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int soma = raiz->valor;
    soma += somatorio_bst(raiz->esq);
    soma += somatorio_bst(raiz->dir);

    return soma;
}

//PODAR
arvore podar_bst(int n, arvore raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    if (n < raiz->valor) {
        raiz->esq = podar_bst(n, raiz->esq);
    } else if (n > raiz->valor) {
        raiz->dir = podar_bst(n, raiz->dir);
    } else {
        raiz = remover_no(raiz);
    }

    return raiz;
}

arvore removerNo_bst(arvore no) {
    if (no == NULL) {
        return NULL;
    }

    no->esq = removerNo_bst(no->esq);
    no->dir = removerNo_bst(no->dir);

    free(no);

    return NULL;
}

//REAJUSTA
arvore reajusta_bst(arvore raiz, double percentual) {
    if (raiz != NULL) {
        // Aplica o reajuste ao valor do nó atual
        raiz->valor = raiz->valor * (1 + percentual);

        // Recursivamente aplica o reajuste aos nós filhos
        raiz->esq = reajusta_bst(raiz->esq, percentual);
        raiz->dir = reajusta_bst(raiz->dir, percentual);
    }
    
    return raiz;
}

//EXISTE
int existe_bst(arvore raiz, int chave) {
    if (raiz == NULL) {
        return 0; // Árvore vazia, chave não encontrada
    }

    if (raiz->valor == chave) {
        return 1; // Chave encontrada na raiz
    } else if (chave < raiz->valor) {
        return existe_bst(raiz->esq, chave); // Busca na subárvore esquerda
    } else {
        return existe_bst(raiz->dir, chave); // Busca na subárvore direita
    }
}

//DESCENDENTES
arvore descendentes_bst(int n, arvore raiz) {
    if (raiz == NULL) {
        return NULL; // Árvore vazia, não há descendentes
    }
    
    if (raiz->valor == n) {
        // Encontrou o nó n, retorna a árvore com os descendentes
        return raiz;
    } else if (n < raiz->valor) {
        return descendentes_bst(n, raiz->esq); // Busca na subárvore esquerda
    } else {
        return descendentes_bst(n, raiz->dir); // Busca na subárvore direita
    }
}

//ALTURA
int altura_bst(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    int altura_esq = altura(raiz->esq); // Altura da subárvore esquerda
    int altura_dir = altura(raiz->dir); // Altura da subárvore direita
    
    // A altura da árvore é a altura da subárvore mais alta, mais um
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

//SAIR
void sair() {
    exit(0);
}
    
