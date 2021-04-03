#include "utils.h"

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Fisierul %s nu a putut fi deschis!", filename);
        printf("Iesire program!");
        exit(EXIT_FAILURE);
    }
    return file;
}

bool isNull(void *argument)
{
    return argument == NULL;
}

bool isNotNull(void *argument) {
    return !isNull(argument);
}

int getNumberOfNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + getNumberOfNodes(root->left) + getNumberOfNodes(root->right);
    }
}