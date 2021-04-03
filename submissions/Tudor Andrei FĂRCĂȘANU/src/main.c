#include "tree.h"
#include "utils.h"
#include "stack.h"

int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.
	FILE *f = openFile("../data/test-createbalanced.txt", READ_MODE);
	int treeSize;
	fscanf(f, "%d\n", &treeSize);
	TreeNode *root = createBalanced(treeSize, f);
	TreeNode *temp = root;
	int i = 0;
	Stack *S = createStack(treeSize);
	while (1)
	{
		while (root)
		{

			printf("%d ", root->val);
			push(S, root);
			root = root->left;
		}
		if (isEmpty(S))
			break;
		root = pop(S);
		root = root->right;
	}
	printf("\n\n");
	deleteTree(temp);
	// Stack *G = createStack(treeSize);
	// while (1)
	// {
	// 	while (temp)
	// 	{

	// 		printf("%d ", temp->val);
	// 		push(G, temp);
	// 		temp = temp->left;
	// 	}
	// 	if (isEmpty(G))
	// 		break;
	// 	temp = pop(G);
	// 	temp = temp->right;
	// }
	return 0;
}
