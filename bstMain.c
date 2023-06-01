#include "bst.h"
#include <stdio.h>

int main() {
    arvore raiz = NULL;
    int opcao, valor, n;
    double percentual;

    do {
        printf("\n");
        printf("1 - INSERIR - BST\n");
        printf("2 - REMOVER - BST\n");
        printf("3 - PREORDER - BST\n");
        printf("4 - INORDER - BST\n");
        printf("5 - POSORDER - BST\n");
        printf("6 - REVERSO - BST\n");
        printf("7 - VERIFICA SE E PRIMO - BST\n");
        printf("8 - QUANTIA DE NUMEROS PRIMOS - BST\n");
        printf("9 - SUCESSOR - BST\n");
        printf("10 - CAMINHO - BST\n");
        printf("11 - SOMATORIO - BST\n");
        printf("12 - PODAR - BST\n");
        printf("13 - REAJUSTE - BST\n");
        printf("14 - VERIFICAR EXISTENCIA DE NUMERO - BST\n");
        printf("15 - DESCENDENTES DE UM NUMERO - BST\n");
        printf("16 - ALTURA - BST\n");
        printf("0 - FECHAR PROGRAMA\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                sair();
                break;
            case 1:
                printf("DIGITE O VALOR A SER INSERIDO: ");
                scanf("%d", &valor);
                raiz = inserir_bst(raiz, valor);
                break;
            case 2:
                printf("DIGITE O VALOR A SER REMOVIDO: ");
                scanf("%d", &valor);
                raiz = remover_bst(raiz, valor);
                break;
            case 3:
                printf("PREORDER: ");
                preorder_bst(raiz);
                printf("\n");
                break;
            case 4:
                printf("INORDER: ");
                inorder_bst(raiz);
                printf("\n");
                break;
            case 5:
                printf("POSORDER: ");
                postorder_bst(raiz);
                printf("\n");
                break;
            case 6:
                printf("ORDEM REVERSA: \n");
                reverso_bst(raiz);
                printf("\n");
                break;
            case 7:
                printf("DIGITE UM NUMERO: ");
                scanf("%d", &valor);
                if (Primo(valor)) {
                    printf("O NUMERO %d E PRIMO.\n", valor);
                } else {
                    printf("O NUMERO %d NAO E PRIMO.\n", valor);
                }
                break;
            case 8:
                printf("A QUANTIDADE DE PRIMOS NA BST E: %d\n", qtdPrimo(raiz));
                break;
            case 9:
                printf("DIGITE O NUMERO: ");
                scanf("%d", &n);
                sucessor_bst(n, raiz);
                break;
            case 10:
                printf("DIGITE O NUMERO: ");
                scanf("%d", &n);
                caminho_bst(n, raiz);
                break;
            case 11:
                printf("O SOMATORIO DOS ELEMENTOS DA BST E: %d\n", somatorio_bst(raiz));
                break;
            case 12:
                printf("DIGITE O NUMERO: ");
                scanf("%d", &n);
                raiz = podar_bst(n, raiz);
                break;
            case 13:
                printf("DIGITE O PERCENTUAL DE REAJUSTE: ");
                scanf("%lf", &percentual);
                raiz = reajusta_bst(raiz, percentual);
                break;
            case 14:
                printf("DIGITE O NUMERO: ");
                scanf("%d", &n);
                if (existe_bst(raiz, n)) {
                    printf("O NUMERO %d EXISTE NA BST.\n", n);
                } else {
                    printf("O NUMERO %d NAO EXISTE NA BST.\n", n);
                }
                break;
            case 15:
                printf("DIGITE O NUMERO: ");
                scanf("%d", &n);
                descendentes_bst(n, raiz);
                break;
            case 16:
                printf("ALTURA DA BST E: %d\n", altura_bst(raiz));
                break;
            default:
                printf("OPCAO INVALIDA!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
