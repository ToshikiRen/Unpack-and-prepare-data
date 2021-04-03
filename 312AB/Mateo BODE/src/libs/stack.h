#pragma once
#include "tree.h"

typedef struct Stack {
    int top;
    int capacity;
    TreeNode** arr;
} Stack;

/**
 * @brief Functie ce creaza o stiva implementata cu vector de capacitate data prin parametru
 * @param capacity - capacitatea stivei
 * @return Stack* - stiva creata
 */
Stack* createStack(int capacity);

/**
 * @brief Functie ce verifica daca o stiva data ca si parametru este goala sau nu
 * @param stack - stiva de verificat
 * @return 0 daca stiva NU este goala
 */
int isEmpty(Stack* stack);

/**
 * @brief Functie ce verifica daca o stiva data ca si parametru este plina sau nu
 * @param stack - stiva de verificat
 * @return 0 daca stiva NU este plina
 */
int isFull(Stack* stack);

/**
 * @brief Functie ce adauga un nou element in stiva.
 * @param item - itemul de adaugat
 */
void push(Stack* stack, TreeNode* item);

/**
 * @brief Functie ce scoate un  element din stiva. Scade capacitatea acesteia cu 1
 * @param stack - stiva din care se va scoate item-ul
 * @return - Nodul de arbore(item-ul) eliminat din stiva
 */
TreeNode* pop(Stack* stack);

/**
 * @brief Functie ce returneaza elementul din varful stivei fara a-l elimina.
 * @param stack - stiva din care se va scoate item-ul
 * @return - Nodul de arbore(item-ul) din varful stivei
 */
TreeNode* peek(Stack* stack);
