#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

/**
 * @brief Functie ce creaza un arbore dupa implementarea descrisa in curs
 * @param N - dimensiunea arborelui
 * @param f - pointer catre fisierul din care se citeste valoarea nodurilor
 * @return TreeNode* - nodul radacina al arborelui
 */
TreeNode* createBalanced(int N, FILE *f);

/**
 * @brief Functie de parcurgere a arborelui dat prin radacina in stil SRD
 * @param root - nodul radacina al arborelui
 * @param arr - vector in care se vor stoca nodurile arborelui atunci cand este parcurs in stil SRD
 * @param size - dimensiunea arborelui
 */
void inorderIterative(TreeNode* root, TreeNode **arr, int size);

/**
 * @brief Functie ce elibereaza spatiul ocupat de un arbore dat prin radacina
 * @param root - nodul radacina al arborelui
 */ 
void deleteTree(TreeNode* root);

/**
 * @brief Functie pentru gasirea celui mai apropiat stramos comun(LCA) a doua noduri date
 * LCA pentru doua noduri a si b este cel mai adanc(de jos nod) care ii are pe a si b ca descendenti
 * @param root - nodul radacina al arborelui
 * @param n1 - nodul 1 pentru cautare LCA
 * @param n2 - nodul 2 pentru cautare LCA
 */ 
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2);