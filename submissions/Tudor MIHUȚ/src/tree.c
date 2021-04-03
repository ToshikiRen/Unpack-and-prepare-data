#include "tree.h"
#include "stack.h"

TreeNode* createBalanced(int N, FILE *f)
{
    TreeNode* lpTree = NULL;
    if (N > 0)
    {
        lpTree = (TreeNode*) malloc(sizeof(TreeNode));
        fscanf(f, "%d", &(lpTree->val));

        lpTree->left = createBalanced( N/2, f);
        lpTree->right = createBalanced( N - 1 - N/2, f);
    }
    return lpTree;
}

void inorderIterative(TreeNode* root, TreeNode **arr, int size)
{
    Stack* s = createStack(size);
    if (s == NULL)
        return;

    int n = 0;
    while(1)
    {
        while(root != NULL)
        {
            push(s, root);
            root = root->left;
        }

        root = pop(s);
        if (root == NULL)
            break;
        
        arr[n] = root;
        n++;

        root = root->right;
    }

    // deleteStack() unde e?
    free(s->arr);
    free(s);
}

void deleteTree(TreeNode* root) 
{
    if (root == NULL)
        return;
    
    if (root->left != NULL)
        deleteTree(root->left);
    if (root->right != NULL)
        deleteTree(root->right);
    
    free(root);
}


void FindWay(TreeNode* lpCurrentNode, TreeNode* lpTargetNode, TreeNode** lpPath, unsigned long uLength, char* bStatus)
{
    if (lpCurrentNode == NULL)
        return;

    lpPath[uLength] = lpCurrentNode;

    if (lpCurrentNode == lpTargetNode)
    {
        *bStatus = 1;
        return;
    }

    if (*bStatus == 0)
        FindWay(lpCurrentNode->left, lpTargetNode, lpPath, uLength+1, bStatus);
    
    if (*bStatus == 0)
        FindWay(lpCurrentNode->right, lpTargetNode, lpPath, uLength+1, bStatus);

    if (*bStatus == 0)
        lpPath[uLength] = NULL;
}


TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) 
{
    if (n1 == root) return n1;
    if (n2 == root) return n2;
    if (n1 == n2) return n1;
    
    
    TreeNode** Path1 = (TreeNode**) calloc(256, sizeof(TreeNode*));
    TreeNode** Path2 = (TreeNode**) calloc(256, sizeof(TreeNode*));
    

    {
        char bStatus = 0;
        FindWay(root, n1, Path1, 0, &bStatus);

        bStatus = 0;
        FindWay(root, n2, Path2, 0, &bStatus);
    }
    

    unsigned long i = 0;
    while(Path1[i] == Path2[i])
        i++;
    
    TreeNode* p = Path1[i-1];
    free(Path1);
    free(Path2);
    return p;
}