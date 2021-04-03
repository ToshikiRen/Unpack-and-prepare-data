#include "tree.h"
#include "stack.h"

TreeNode *createBalanced(int N, FILE *f)
{
    int aux, mij = N / 2;
    TreeNode *root;
    if (N >= 1 && fscanf(f, "%d", &aux) != EOF)
    {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = aux;
        root->left = createBalanced(mij, f);
        root->right = createBalanced(N - mij - 1, f);
        return root;
    }
    else
        return NULL;
}


void inorderIterative(TreeNode *root, TreeNode **arr, int size)
{
    Stack *aux;
    TreeNode *c = root;
    aux = createStack(size);
    int i = 0;
    while (size - i >= 1)
    {
        if (c != NULL)
        {
            push(aux, c);
            c = c->left;
        }
        else
        {
            if (aux != NULL)
            {
                c = pop(aux);
                arr[i] = c;
                i++;
                c = c->right;
            }
        }
    }
    free(aux->arr);
    aux->arr=NULL;
    free(aux);
    aux=NULL;
}


void deleteTree(TreeNode *root)
{
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    root = NULL;
}


TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    TreeNode *l = NULL, *r = NULL;
    if (root == NULL)
        return root;
    if ((root->val == n1->val && root->left == n1->left && root->right == n1->right) || (root->val == n2->val && root->left == n2->left && root->right == n2->right))
        return root;
    l = LCA(root->left, n1, n2);
    r = LCA(root->right, n1, n2);
    if (l != NULL && r != NULL)
        return root;
    if (r == NULL)
        return l;
    return r;
}