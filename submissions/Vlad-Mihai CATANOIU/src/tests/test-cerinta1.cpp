#include "test-utils.hpp"


TEST_CASE("Cerinta 1: Creati un arbore folosind functia createBalanced")
{
	int* testData = initCreateBalanced(TASK1_TEST_FILENAME_EXPECTED);
	FILE *f = openFile(TASK1_TEST_FILENAME, READ_MODE);
	int treeSize;
	fscanf(f, "%d\n", &treeSize);
	TreeNode* root = createBalanced(treeSize, f);

	TreeNode** arr = (TreeNode**)malloc(sizeof(TreeNode) * treeSize);
	inorderRec(root, arr, treeSize);

	SECTION("Verificare elemente arbore creat cu createBalanced")
	{
		for (int i = 0; i < treeSize; i++) {
			REQUIRE(testData[i] == arr[i]->val);
		}
	}
}



