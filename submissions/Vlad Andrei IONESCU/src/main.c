#include "tree.h"
#include "utils.h"

//RSD
void preorder(TreeNode *root) 
{
	if (root)
	{
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

//SRD
void inorder(TreeNode *root) 
{
	if (root)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

//SDR
void postorder(TreeNode *root) 
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}
}


int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.
 	FILE *F;
	TreeNode *root=NULL;
	int noduri=0;
	F=openFile(TEST_FILE2, READ_MODE);
	fscanf(F, "%d", &noduri);

	root = createBalanced(noduri,F);


	TreeNode **rootNew = (TreeNode**)malloc(sizeof(TreeNode) * noduri);
	//inorderIterative(root, rootNew, noduri);
	printf("\n\n");	
	
	TreeNode *temp = LCA(root, root->right->left, root->right->right);
	printf("\nParintele comun este: %d", temp->val);
	//postOrderIterative(root, noduri);
	//printf("postordine SDR :\n");	
	//postorder(root);
	//printf("\n\n");

	//deleteTree(root);

	/*
	printf("preordine RSD :\n");	
	preorder(root);
	printf("\n\n");

	printf("inordine SRD :\n");	
	inorder(root);
	printf("\n\n");
		
	*/

	fclose(F); 
	return 0;
}
