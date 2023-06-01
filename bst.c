#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

//INSERIR
arvore inserir_bst(arvore raiz, int valor) {
    if (raiz == NULL) {
        arvore novoNo = (arvore)malloc(sizeof(No));
        novoNo->valor = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        return novoNo;
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir_bst(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir_bst(raiz->dir, valor);
    }

    return raiz;
}

//REMOVER
arvore remover_bst(arvore raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esq = remover_bst(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover_bst(raiz->dir, valor);
    } else {
        if (raiz->esq == NULL) {
            arvore temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            arvore temp = raiz->esq;
            free(raiz);
            return temp;
        }

        arvore temp = raiz->dir;
        while (temp && temp->esq != NULL) {
            temp = temp->esq;
        }

        raiz->valor = temp->valor;
        raiz->dir = remover_bst(raiz->dir, temp->valor);
    }

    return raiz;
}

//PREORDER
void preorder_bst(arvore raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preorder_bst(raiz->esq);
        preorder_bst(raiz->dir);
    }
}

//INORDER
void inorder_bst(arvore raiz) {
    if (raiz != NULL) {
        inorder_bst(raiz->esq);
        printf("%d ", raiz->valor);
        inorder_bst(raiz->dir);
    }
}

//POSORDER
void posorder_bst(arvore raiz) {
    if (raiz != NULL) {
        posorder_bst(raiz->esq);
        posorder_bst(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

//REVERSO
void reverso_bst(arvore raiz) {
    if (raiz != NULL) {
        reverso_bst(raiz->dir);
        printf("%d ", raiz->valor);
        reverso_bst(raiz->esq);
    }
}

//QUANTIDADE DE PRIMOS NA ÁRVORE
int qtdPrimo(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int count = Primo(raiz->valor) ? 1 : 0;
    count += qtdPrimo(raiz->esq);
    count += qtdPrimo(raiz->dir);

    return count;
}

//SUCESSOR
void sucessor_bst(int valor, arvore raiz) {
    if (raiz == NULL) {
        printf("Nao existe sucessor.\n");
        return;
    }

    arvore sucessor = NULL;
    while (raiz != NULL) {
        if (valor < raiz->valor) {
            sucessor = raiz;
            raiz = raiz->esq;
        } else if (valor > raiz->valor) {
            raiz = raiz->dir;
        } else {
            if (raiz->dir != NULL) {
                raiz = raiz->dir;
                while (raiz->esq != NULL) {
                    raiz = raiz->esq;
                }
                printf("O sucessor de %d e %d.\n", valor, raiz->valor);
            } else {
                if (sucessor != NULL) {
                    printf("O sucessor de %d e %d.\n", valor, sucessor->valor);
                } else {
                    printf("Nao existe sucessor.\n");
                }
            }
            return;
        }
    }
}

//CAMINHO DA BST
void caminho_bst(int valor, arvore raiz) {
    if (raiz == NULL) {
        printf("O valor %d nao existe na BST.\n", valor);
        return;
    }

    printf("Caminho ate %d: ", valor);
    while (raiz != NULL) {
        printf("%d ", raiz->valor);
        if (valor < raiz->valor) {
            raiz = raiz->esq;
        } else if (valor > raiz->valor) {
            raiz = raiz->dir;
        } else {
            printf("\n");
            return;
        }
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
arvore podar_bst(int valor, arvore raiz) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esq = podar_bst(valor, raiz->esq);
    } else if (valor > raiz->valor) {
        raiz->dir = podar_bst(valor, raiz->dir);
    } else {
        if (raiz->esq == NULL) {
            arvore temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            arvore temp = raiz->esq;
            free(raiz);
            return temp;
        }

        arvore temp = raiz->dir;
        while (temp && temp->esq != NULL) {
            temp = temp->esq;
        }

        raiz->valor = temp->valor;
        raiz->dir = podar_bst(temp->valor, raiz->dir);
    }

    return raiz;
}

//REAJUSTAR
arvore reajusta_bst(arvore raiz, double percentual) {
    if (raiz == NULL) {
        return raiz;
    }

    raiz->valor = (int)(raiz->valor * (1 + percentual / 100));
    raiz->esq = reajusta_bst(raiz->esq, percentual);
    raiz->dir = reajusta_bst(raiz->dir, percentual);

    return raiz;
}

//EXISTE
int existe_bst(arvore raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }

    if (valor < raiz->valor) {
        return existe_bst(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        return existe_bst(raiz->dir, valor);
    } else {
        return 1;
    }
}

//DESCENDENTES
void descendentes_bst(int valor, arvore raiz) {
    if (raiz == NULL) {
        printf("O valor %d nao existe na BST.\n", valor);
        return;
    }

    arvore no = raiz;
    while (no != NULL) {
        if (valor < no->valor) {
            no = no->esq;
        } else if (valor > no->valor) {
            no = no->dir;
        } else {
            break;
        }
    }

    if (no == NULL) {
        printf("O valor %d nao existe na BST.\n", valor);
        return;
    }

    printf("Descendentes de %d: ", valor);
    if (no->esq != NULL) {
        inorder_bst(no->esq);
    }
    if (no->dir != NULL) {
        inorder_bst(no->dir);
    }
    printf("\n");
}

//ALTURA
int altura_bst(arvore raiz) {
    if (raiz == NULL) {
        return -1;
    }

    int altura_esq = altura_bst(raiz->esq);
    int altura_dir = altura_bst(raiz->dir);

    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

//IMPRIMIR ÁRVORE
void imprimir_arvore(arvore raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    // Imprimir valor do nó
    printf("[%d] ", raiz->valor);

    // Recursivamente imprimir os filhos da esquerda e da direita
    imprimir_arvore(raiz->esq, nivel + 1);
    imprimir_arvore(raiz->dir, nivel + 1);
}

//FINALIZAR PROGRAMA
void sair() {
    printf("\n----- FINALIZANDO PROGRAMA -----\n");
    exit(0);
}
