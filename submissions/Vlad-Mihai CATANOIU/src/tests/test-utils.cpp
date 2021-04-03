#include "test-utils.hpp"

TreeNode* newNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderRec(TreeNode* root, TreeNode **arr, int size) {
	static int idx = 0;
	if (root) {
        inorderRec(root->left, arr, size);
        arr[idx++] = root;
        inorderRec(root->right, arr, size);
    }
}

int* initCreateBalanced(const char* fileName) {
	FILE *f = openFile(fileName, READ_MODE);
	int size;
	fscanf(f, "%d\n", &size);
	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		int val;
		fscanf(f, "%d ", &val);
		arr[i] = val;
	}

	return arr;
}

TreeNode* createTreeForLCATest() {
    TreeNode* rootLCA = newNode(1);
    rootLCA->left = newNode(2);
    rootLCA->left->left = newNode(4);
    rootLCA->left->right = newNode(5);
    rootLCA->right = newNode(3);
    rootLCA->right->left = newNode(6);
    rootLCA->right->right = newNode(7);

    return rootLCA;
}