#include "test-utils.hpp"

TEST_CASE("Cerinta 2: Parcurgere SRD Iterativ")
{
	int* testData = initCreateBalanced(TASK1_TEST_FILENAME_EXPECTED);
	FILE *f = openFile(TASK1_TEST_FILENAME, READ_MODE);
	int treeSize;
	fscanf(f, "%d\n", &treeSize);
	TreeNode* root = createBalanced(treeSize, f);

	TreeNode** arr = (TreeNode**)malloc(sizeof(TreeNode) * treeSize);

	inorderIterative(root, arr, treeSize);

	SECTION("Verificare elemente ordine corecta a elementelor")
	{
		for (int i = 0; i < treeSize; i++) {
			REQUIRE(testData[i] == arr[i]->val);
		}
	}
}