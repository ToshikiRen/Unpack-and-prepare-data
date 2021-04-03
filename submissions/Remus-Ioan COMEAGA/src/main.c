#include "tree.h"
#include "utils.h"

int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.
	TreeNode *root, **arr;
	int size, i;
	FILE *f;
	f = openFile("test-createbalanced.txt", READ_MODE);
	fscanf(f, "%d", &size);
	arr = (TreeNode**)malloc(size*sizeof(TreeNode));
	root = createBalanced(size, f);
	inorderIterative(root, arr, size);
	for(i = 0; i < size; i++)
	{
		printf("%d ", arr[i]->val);
	}
	deleteTree(root);
	return 0;
}
