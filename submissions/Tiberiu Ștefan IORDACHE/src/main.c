#include "tree.h"
#include "utils.h"
#include "stack.h"

void inorder(TreeNode *root)
{
		if(root)
		{
			inorder(root->left);
			printf("%d ",root->val);
			inorder(root->right);
		}
}

int isEmpty(TreeNode *root)
{
	if(root==NULL)
		return 1;
	else return 0;
}


int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.
	

	TreeNode *root,*n1,*n2,*n3,*n4,*n5,*n6;

	root=(TreeNode*)malloc(sizeof(TreeNode));
	n1=(TreeNode*)malloc(sizeof(TreeNode));
	n2=(TreeNode*)malloc(sizeof(TreeNode));
	n3=(TreeNode*)malloc(sizeof(TreeNode));
	n4=(TreeNode*)malloc(sizeof(TreeNode));
	n5=(TreeNode*)malloc(sizeof(TreeNode));
	n6=(TreeNode*)malloc(sizeof(TreeNode));
	
root->val=0;
n1->val=1;
n2->val=2;
n3->val=3;
n4->val=4;
n5->val=5;
n6->val=6;

root->left=n1;
root->right=n4;

n1->left=n2;
n1->right=n3;

n2->left=n2->right=NULL;
n3->left=n3->right=NULL;

n4->left=n5;
n4->right=n6;

n5->left=n5->right=NULL;
n6->left=n6->right=NULL;

printf(" %p ",n1);

printf(" %p ",LCA(root,n2,n3));

	return 0;
}
