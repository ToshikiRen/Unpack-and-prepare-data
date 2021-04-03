#include "tree.h"
#include "utils.h"

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
	FILE*f = fopen("C:\\Users\\Bogdan\\CLionProjects\\PC\\SDA\\lab5_sda\\lab-05-tasks-main\\data\\test-createbalanced.txt","r");
	int N;
	fscanf(f,"%d",&N);
	TreeNode*root = NULL ;
    TreeNode** arr = (TreeNode**)malloc(sizeof(TreeNode) * N);
	root = createBalanced(N,f);
	inorderIterative(root,arr,N);
	int i ;
	for(i=0;i<N;i++)
	    printf("%d ",arr[i]->val);
	TreeNode*rootLCA = newNode(1);
    rootLCA->left = newNode(2);
    rootLCA->left->left = newNode(4);
    rootLCA->left->right = newNode(5);
    rootLCA->right = newNode(3);
    rootLCA->right->left = newNode(6);
    rootLCA->right->right = newNode(7);
	rootLCA = LCA(root, root->left, root->left->left);
	printf("%d",rootLCA->val);
   deleteTree(root);
	return 0;
}
