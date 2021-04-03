#include "tree.h"
#include "stack.h"

TreeNode *createBalanced(int N, FILE *f)
{
    int val;

    if (N > 0)
    {
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        while (fscanf(f, "%d ", &val) != EOF)
        {

            (root->val) = val;

            root->left = createBalanced(N / 2, f);
            root->right = createBalanced(N - 1 - N / 2, f);
            return root;
        }
    }
    else
        return NULL;
}

void inorderIterative(TreeNode *root, TreeNode **arr, int size)
{
    int i = 0;
    Stack *S = createStack(size);

    while (!isEmpty(S) || root != NULL)
    {

        if (root != NULL)
        {
            push(S, root);
            root = root->left;
        }
        else
        {
            root = peek(S);
            root = pop(S);

            arr[i] = root;
            i++;

            root = root->right;
        }
    }
}

void deleteTree(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{

    if (root == NULL)
    {
        return NULL;
    }
    else if (root == n1 || root == n2)
    {
        return root;
    }

    TreeNode *lca_l = LCA(root->left, n1, n2);
    TreeNode *lca_r = LCA(root->right, n1, n2);

    if (lca_l != NULL && lca_r != NULL)
    {
        return root;
    }
    else if (lca_l != NULL)
    {
        return lca_l;
    }
    else
    {
        return lca_r;
    }

    return NULL;
}
