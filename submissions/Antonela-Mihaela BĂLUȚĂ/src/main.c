#include "tree.h"
#include "utils.h"

void inorderRec(TreeNode* root) {
	if (root) {

        inorderRec(root->left);
		printf("Valoare din nod: %d\n", root->val);
        inorderRec(root->right);
    }
}

int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.

	FILE *f = openFile("../data/test-createbalanced.txt", READ_MODE);
	int treeSize;
	fscanf(f, "%d\n", &treeSize);

	TreeNode *root = createBalanced(treeSize, f);
	TreeNode **arr = (TreeNode**)malloc(sizeof(TreeNode) * treeSize);

	printf("Numar de noduri: %d", getNumberOfNodes(root));
	printf("\nParcurgerea inorder recursiva:\n");
	inorderRec(root);

	printf("\n");
	printf("Parcurgerea inorder iterativa:\n");
	inorderIterative(root, arr, treeSize);

	// deleteTree(root);

	printf("\n");
	return 0;
}


