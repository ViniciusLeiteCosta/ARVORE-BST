#include "bst.h"
#include <locale.h>
#include <stdio.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    arvore raiz = NULL;
    int opcao, valor, n;
    double percentual;

    do {
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("  ____   _____ _______  \n");
        printf(" |  _ \\ / ____|__   __| \n");
        printf(" | |_) | (___    | |    \n");
        printf(" |  _ < \\___ \\   | |    \n");
        printf(" | |_) |____) |  | |    \n");
        printf(" |____/|_____/   |_|    \n");
        printf("                        \n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("1 - INSERIR - BST\n");
        printf("2 - REMOVER - BST\n");
        printf("3 - PREORDER - BST\n");
        printf("4 - INORDER - BST\n");
        printf("5 - POSORDER - BST\n");
        printf("6 - REVERSO - BST\n");
        printf("7 - QUANTIDADE DE NÚMEROS PRIMOS - BST\n");
        printf("8 - SUCESSOR - BST\n");
        printf("9 - CAMINHO - BST\n");
        printf("10 - SOMATÓRIO - BST\n");
        printf("11 - PODAR - BST\n");
        printf("12 - REAJUSTE - BST\n");
        printf("13 - VERIFICAR EXISTÊNCIA DE NÚMERO - BST\n");
        printf("14 - DESCENDENTES DE UM NÚMERO - BST\n");
        printf("15 - ALTURA - BST\n");
        printf("16 - IMPRIMIR ARVORE - BST\n");
        printf("99 - FECHAR PROGRAMA\n");
        printf("-----------------------------------------------\n");
        printf("OPÇÃO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 99:
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
                posorder_bst(raiz);
                printf("\n");
                break;
            case 6:
                printf("ORDEM REVERSA: \n");
                reverso_bst(raiz);
                printf("\n");
                break;
            case 7:
                printf("A QUANTIDADE DE PRIMOS NA BST É: %d\n", qtdPrimo(raiz));
                break;
            case 8:
                printf("DIGITE O NÚMERO: ");
                scanf("%d", &n);
                sucessor_bst(n, raiz);
                break;
            case 9:
                printf("DIGITE O NÚMERO: ");
                scanf("%d", &n);
                caminho_bst(n, raiz);
                break;
            case 10:
                printf("O SOMATÓRIO DOS ELEMENTOS DA BST É: %d\n", somatorio_bst(raiz));
                break;
            case 11:
                printf("DIGITE O NÚMERO: ");
                scanf("%d", &n);
                raiz = podar_bst(n, raiz);
                break;
            case 12:
                printf("DIGITE O PERCENTUAL DE REAJUSTE: ");
                scanf("%lf", &percentual);
                raiz = reajusta_bst(raiz, percentual);
                break;
            case 13:
                printf("DIGITE O NÚMERO: ");
                scanf("%d", &n);
                if (existe_bst(raiz, n)) {
                    printf("O NÚMERO %d EXISTE NA BST.\n", n);
                } else {
                    printf("O NÚMERO %d NÃO EXISTE NA BST.\n", n);
                }
                break;
            case 14:
                printf("DIGITE O NÚMERO: ");
                scanf("%d", &n);
                descendentes_bst(n, raiz);
                break;
            case 15:
                printf("ALTURA DA BST É: %d\n", altura_bst(raiz));
                break;
            case 16:
                printf("IMPRIMIR ARVORE:\n");
                imprimir_arvore(raiz, 0);
                sleep(10);
                break;
            default:
                printf("OPÇÃO INVÁLIDA!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
