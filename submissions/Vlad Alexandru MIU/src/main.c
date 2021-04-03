#include "tree.h"
#include "utils.h"

int main()
{
	// Daca testati o anumita functie in main, pentru a afla numarul de noduri
	// dintr-un arbore, folositi functia getNumberOfNodes din fisierul utils.h.
	FILE *file;
	file=fopen("x.txt","r");
	int n;
	fscanf(file,"%d",&n);
	TreeNode *nod,*arr;
	nod=(TreeNode*)malloc(sizeof(TreeNode));
	arr=(TreeNode*)malloc(n*sizeof(TreeNode));
	printf("date \n");
	nod=createBalanced(n,file);
	printf("\n ce ar trebui sa arate \n");
	inorderIterative(nod,&arr,n);
	printf(" \n vector arr \n");
	for(int i=0;i<n;i++)
	{
		
		printf("%d  ",arr[i].val);
	}
	return 0;
}
