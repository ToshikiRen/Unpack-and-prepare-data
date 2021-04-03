#include "tree.h"
#include "stack.h"
/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/
TreeNode *createBalanced(int N, FILE *f)
{
	int val;

	if (N > 0)
	{
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

		fscanf(f, "%d", &val);

		root->val = val;
		root->left = createBalanced(N / 2, f);
		root->right = createBalanced(N - 1 - N / 2, f);

		return root;
	}
	return 0;
}

/**
 * CERINTA 2
 * TODO: implementarea ITERATIVA functiei de parcurgere SRD(inordine) a unui arbore binar.
 * Stiva este implementata folosind un vector(vezi stack.h). In functia inorderIterative, se transmite
 * radacina arborelui si un vector in care sa stocati valorile obtinute in urma parcurgerii precum si numarul
 * de elemente din arbore presupus cunoscut(cel de la cerinta 1).
 * @param root - nodul radacina al arborelui creat la cerinta anterioara cu functia createBalanced
 * @param arr - vector in care trebuie sa adaugati nodurile arborelui pe masura ce il parcurgeti
 * @param size - numarul de noduri din arbore.
 * HINT: Pentru implementare folositi-va de implementarea stivei, vedeti fisierul stack.h
 * OBSERVATIE: Odata parcurs un nod, acesta trebuie adaugat in vectorul arr. Trebuie adaugat tot nodul, NU valoarea.
 */
void inorderIterative(TreeNode *root, TreeNode **arr, int size)
{
	Stack *s = createStack(size);

	int i = 0;

	while (true)
	{
		while (root)
		{
			push(s, root);
			root = root->left;
		}

		if (isEmpty(s))
		{
			break;
		}
		else
		{
			root = pop(s);
			arr[i++] = root;
			root = root->right;
		}
	}
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode *root)
{
	if (root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}

bool getPath(TreeNode *root, TreeNode *n, Stack *s)
{
	if (!root)
	{
		return false;
	}

	push(s, root);

	if (root->val == n->val)
	{
		return true;
	}

	if (getPath(root->left, n, s) || getPath(root->right, n, s))
	{
		return true;
	}

	pop(s);

	return false;
}

/**
 * CERINTA 4
 * TODO: Implementarea functiei pentru gasirea celui mai apropiat stramos comun(LCA) a doua noduri date(LCA)
 *  pentru doua noduri n1 si n1.LCA este cel mai adanc(de jos nod) care ii are pe n1 si n1 ca descendenti
 * @param root - nodul radacina al arborelui
 * @param n1 - nodul 1 pentru cautare LCA
 * @param n2 - nodul 2 pentru cautare LCA
 */
TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
	Stack *s1, *s2;
	s1 = createStack(30);
	s2 = createStack(30);

	if (getPath(root, n1, s1))
	{
		if (getPath(root, n2, s2))
		{
			int i = 0;
			while ((s1->arr)[i] == (s2->arr)[i] && (s1->arr)[i] && (s2->arr)[i])
			{
				i++;
			}

			return s1->arr[i - 1];
		}
	}

	return NULL;
}
