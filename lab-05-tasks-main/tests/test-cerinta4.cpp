#include "test-utils.hpp"

TEST_CASE("Cerinta 4: LCA")
{
	TreeNode* root = createTreeForLCATest();

	SECTION("Verificare LCA pentru nodurile 4 si 5 din arbore")
    {
        TreeNode* aux = LCA(root, root->left->left, root->left->right);
        REQUIRE(aux->val == 2);
    }

    SECTION("Verificare LCA pentru nodurile 4 si 6 din arbore")
    {
        TreeNode* aux = LCA(root, root->left->left, root->right->left);
        REQUIRE(aux->val == 1);
    }

    SECTION("Verificare LCA pentru nodurile 3 si 4 din arbore")
    {
        TreeNode* aux = LCA(root, root->right, root->left->left);
        REQUIRE(aux->val == 1);
    }

    SECTION("Verificare LCA pentru nodurile 2 si 4 din arbore")
    {
        TreeNode* aux = LCA(root, root->left, root->left->left);
        REQUIRE(aux->val == 2);
    }
}