#ifndef BST_INCLUDE
#define BST_INCLUDE

typedef struct no{
    int numero;
    struct no *esq, *dir;
} Arvore;

void inserir_bst(Arvore *no, int valor);
/*Recebe como parâmetros um número inteiro e a ponteiro para raiz de uma
árvore BST, retorna o ponteiro para árvore após a inclusão do valor passado
como primeiro parâmetro.*/

void preorder_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela
todos seus elementos, seguindo a ordem pré-order. Os valores dos elementos
devem ser impressos entre colchetes, sem espaço entre dois elementos.
Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [20][10][30].*/

void inorder_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela
todos seus elementos, seguindo a ordem in-order. Os valores dos elementos
devem ser impressos entre colchetes, sem espaço entre dois elementos.
Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [10][20][30]*/

void posorder_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela
todos seus elementos, seguindo a ordem pós-order. Os valores dos elementos
devem ser impressos entre colchetes, sem espaço entre dois elementos.
Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [10][30][20]*/

void reverso_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e imprime na tela
todos seus elementos, ordenados de forma decrescente. Os valores dos
elementos devem ser impressos entre colchetes, sem espaço entre dois
elementos. Acrescentar um ‘\n’ após imprimir todos os elementos.
Ex: [30][20][10]*/

void qtdPrimo_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e retorna a
quantidade de nós que armazenam um número primo. Na função main, deve
ser impresso apenas o número inteiro seguido por ‘\n’. Ex: 2*/

void sucessor_bst();
/*Recebe como parâmetros um número inteiro n e o ponteiro para uma árvore
BST e imprime o valor do nó sucessor do parâmetro n. Considerando que
todas os nós possuem valores distintos, o sucessor de um nó n é o nó maior
que n com o menor valor. Caso o número n não exista na árvore ou caso o
número n não possua sucessor, deve ser impresso na tela o valor -1. Na
função main, deve ser impresso apenas o resultado da função, seguido por um
‘\n’.*/

void caminho_bst();
/*Recebe como parâmetro um número inteiro n e um ponteiro para uma
árvore BST e imprime na tela os elementos existentes no caminho da raiz
até o nó n (inclusos). Acrescentar um ‘\n’ após imprimir todos os
elementos. Ex: [10][20][30]*/

void remover_bst();
/*Recebe como parâmetros um número inteiro e a ponteiro para raiz de uma
árvore BST, retorna o ponteiro para árvore após a remoção do valor passado como primeiro parâmetro.*/

void somatório_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e retorna o
somatório do valor de todos os seus elementos. Na função main, deve ser
impresso apenas a soma (número inteiro) seguido por ‘\n’. Ex: 2*/

void podar_bst();
/*Recebe como parâmetros um número inteiro n e o ponteiro para raiz de uma
árvore BST, retorna o ponteiro para árvore após a remoção do valor n e todos
os seus descendentes.*/

void reajusta_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST, um valor
percentual de reajuste (positivo) e modifica o valor de todos os seus nós da
árvore, aplicando o valor percentual. Atenção: considere que a árvore contém
apenas valores positivos.*/

void existe_bst();
/*Recebe como parâmetro o ponteiro para uma árvore BST e o valor de uma
chave de procura. A função deve retornar o valor 1, caso a chave exista na
árvore e 0 em caso contrário. Esse valor (0 ou 1) deve ser impresso na função
main, seguido por um ‘\n’*/

void descendentes();
/*Recebe como parâmetro um número inteiro n e um ponteiro para uma árvore
BST e imprime na tela todos elementos descendentes do nó n, em ordem
crescente. Acrescentar um ‘\n’ após imprimir todos os elementos. Ex: [10]
[20][30]*/

void altura();
/*Recebe como parâmetro o ponteiro para uma árvore BST e retorna a altura da
árvore. O valor da altura da árvore deve ser impresso na função main,
seguido por um ‘\n’*/

void sair();
/*Fecha o programa.*/

#endif
