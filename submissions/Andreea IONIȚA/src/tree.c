#include "tree.h"
#include "stack.h"

TreeNode* createBalanced(int N, FILE *f) {
    int val;
    if(N > 0)
    {
        TreeNode* root= (TreeNode*)malloc(sizeof(TreeNode));
        printf("valoare nod : ");
        scanf("%d", &val);
        (root->val) = val;
        root->left = createBalanced(N/2,f);
        root->right = createBalanced(N-1/2,f) ;
        return root;
    }
    else return NULL;
}

/**
 * CERINTA 2
 * TODO: implementarea ITERATIVA functiei de parcurgere SRD(inordine) a unui arbore binar.
 * Stiva este implementata folosind un vector(vezi stack.h). In functia inorderIterative, se transmite
 * radacina arborelui si un vector in care sa stocati valorile obtinute in urma parcurgerii precum si numarul
 * de elemente din arbore presupus cunoscut(cel de la cerinta 1).
 * @param root - nodul radacina al arborelui creat la cerinta anterioara cu functia createBalanced
 * @param arr - vector in care trebuie sa adaugati nodurile arborelui pe masura ce il parcurgeti
 * @param size - numarul de noduri din arbore.
 * HINT: Pentru implementare folositi-va de implementarea stivei, vedeti fisierul stack.h
 * OBSERVATIE: Odata parcurs un nod, acesta trebuie adaugat in vectorul arr. Trebuie adaugat tot nodul, NU valoarea.
 */
void inorderIterative(TreeNode* root, TreeNode **arr, int size) {
  
}

void deleteTree(TreeNode* root) {
    if(root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}


TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    if( root == NULL) 
    return NULL;
    if( root->val == n1->val || root->val == n2->val)
    return root;
    TreeNode *left = LCA(root->left,n1,n2);
    TreeNode *right = LCA(root->right,n1,n2);
    if(left && right) return root;
    if(left) return left;
    else return right;

}