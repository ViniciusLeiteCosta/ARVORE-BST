#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    // Declarar uma árvore
    arvore raiz;
    int opcao, n, aux;
    int percentual;

    //inicializando a árvore.
    raiz = NULL;

    while (1) {
        scanf("%d", &opcao);

        switch (opcao) {
            
            case 1:
                scanf("%d", &n);
                raiz = inserir_bst(raiz, n);
                break;
            case 2:               
                preorder_bst(raiz);
                printf("\n");
                break;
            case 3:
                inorder_bst(raiz);
                printf("\n");
                break;
            case 4:
                posorder_bst(raiz);
                printf("\n");
                break;
            case 5:
                reverso_bst(raiz);
                printf("\n");
                break;
            case 6:
                printf("%d\n", qtdPrimo(raiz)); 
                printf("\n");
                break;
            case 7:
                scanf("%d", &n);
                sucessor_bst(n, raiz);
                break;
            case 8:
                scanf("%d", &n);
                caminho_bst(n, raiz);
                printf("\n");
                break;
            case 9:
                scanf("%d", &n);
                raiz = remover_bst(raiz, n);
                break;
            case 10:
                printf("%d\n", somatorio_bst(raiz));
                break;
            case 11:
                scanf("%d", &n);
                raiz = podar_bst(n, raiz);
                break;
            case 12:
                scanf("%d", &n);
                raiz = reajusta_bst(raiz, n);
                break;
            case 13:
                scanf("%d", &n);
                if (existe_bst(raiz, n)) {
                    printf("1.\n");
                } else {
                    printf("0.\n");
                }
                printf("\n");
                break;
            case 14:
                scanf("[%d]", &n);
                descendentes_bst(n, raiz);
                printf("\n");
                break;
            case 15:
                printf("%d\n", altura_bst(raiz));
                break;
            case 99:
                exit(0);
                break;
            default:
                printf("ERRO!\n");
                break;
        }
    }

    return 0;
}

