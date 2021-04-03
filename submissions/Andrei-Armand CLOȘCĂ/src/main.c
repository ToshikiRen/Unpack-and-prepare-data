#include "tree.h"
#include "utils.h"

void inordine(TreeNode *root) {
	if(root != NULL) {
		inordine(root -> left);
		printf("%d ", root -> val);
		inordine(root -> right);
	}
}

TreeNode* newNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.
	
	TreeNode* rootLCA = newNode(1);
    rootLCA->left = newNode(2);
    rootLCA->left->left = newNode(4);
    rootLCA->left->right = newNode(5);
    rootLCA->right = newNode(3);
    rootLCA->right->left = newNode(6);
    rootLCA->right->right = newNode(7);

	printf("%d", LCA(rootLCA, rootLCA -> left -> left, rootLCA -> left -> right) -> val);

	deleteTree(rootLCA);

	return 0;
}
