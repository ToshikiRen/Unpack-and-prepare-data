#include "tree.h"
#include "stack.h"
#include <math.h>
#include <stdbool.h>
#include "utils.h"

TreeNode* createNode(int value)
{
    TreeNode *aux = (TreeNode*)malloc(sizeof(TreeNode));

    assert(isNotNull((void*)aux));

    aux->right = NULL;
    aux->left = NULL;
    aux->val = value;

    return aux;
}

TreeNode* createBalanced(int N, FILE *f) 
{
    if(N<=0)
        return NULL;

    int value;

    assert(fscanf(f, "%d ", &value) != EOF);

    TreeNode *aux = createNode(value);

    assert(isNotNull((void*)aux));

    *aux = (TreeNode){value, createBalanced(N / 2, f), createBalanced(N - 1 - N / 2, f)};

    return aux;
}

void inorderIterative(TreeNode* root, TreeNode **arr, int size) 
{
    /*static int k = 0;   //Varianta recursiva, extrasa din teste ;)
    if(root!=NULL)
    {
        inorderIterative(root->left, arr, size);
        arr[k++] = root;
        inorderIterative(root->right, arr, size);
    }*/

    Stack *stack = createStack(size);

    TreeNode *aux = root;

    int k = 0;
 
    while (true)
    {
        if(!(isNotNull((void*)aux) || isNotEmpty(stack)))
            break;

        while (true)
        {
            if(!(isNotNull((void*)aux)))
                break;

            push(stack, aux);
            aux = aux->left;
        }
 
        aux = pop(stack);
        arr[k++] = aux;
 
        aux = aux->right;
    } 
}

void deleteTree(TreeNode* root)//Setergerea recursiva, chiar daca nu exista teste ptr asta
{
    if(isNull((void*)root))
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}
 
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2)//Varianta recursiva
{
    if(root == n1 || root == n2 || isNull((void*)root))//Cele doua cazuri: daca am gasit nodul sau daca an ajuns la un nod terminal
        return root;

    TreeNode *eastside = LCA(root->right, n1, n2);//Cautam recursiv printre subarbori
    TreeNode *westside = LCA(root->left, n1, n2);

    //Ori returnam nodul de legatura, ori pastram subarborii in care am gasit n1 sau n2
    return (isNotNull((void*)westside) && isNotNull((void*)eastside)) ? root : (isNotNull((void*)westside) ? westside : eastside);
}
