#include "tree.h"
#include "stack.h"
#include "utils.h"

/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/

/*
am implementat o functie de a crea un nou nod in arbore ca sa folosesc
pentru implementarea la functia createBalanced
*/

TreeNode* newNode(int value){
  
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    
    isNull((TreeNode*)node);

    node -> right = node -> left = NULL;
    node -> val = value;
    return node;

}


TreeNode* createBalanced(int N, FILE *f) {
     
    int value;
        
    if(N>0){
       while(fscanf(f, "%d ", &value) != EOF){
            TreeNode *root = newNode(value);
            isNull((TreeNode*)root);
            root -> left = createBalanced(N/2, f);
            root -> right = createBalanced(N-1-N/2, f);
            return root;
        }
    }else return NULL;
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
void inorderIterative(TreeNode* root, TreeNode **arr, int size) {

    Stack *stiva = createStack(size);
    TreeNode *node = root;
    int i=0;

    while(1){
        if(!(isNotNull((TreeNode*)node) || !(isEmpty(stiva))))
            break;

    while(1){
        if(!(isNotNull((TreeNode*)node)))
            break;
        push(stiva, node);
        node = node -> left;
    }

        node = pop(stiva);
        arr[i++] = node;
        node = node -> right;
    }

}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {
    if(root == NULL)

    deleteTree(root -> left);
    deleteTree(root -> right);
    free(root);
}

/**
 * CERINTA 4
 * TODO: Implementarea functiei pentru gasirea celui mai apropiat stramos comun(LCA) a doua noduri date(LCA)
 *  pentru doua noduri n1 si n1.LCA este cel mai adanc(de jos nod) care ii are pe n1 si n1 ca descendenti
 * @param root - nodul radacina al arborelui
 * @param n1 - nodul 1 pentru cautare LCA
 * @param n2 - nodul 2 pentru cautare LCA
 */ 
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2){
    // functia asta nu face ce trebuie si nu am putut sa inteleg care a fost problema
    // ca sa o rezolv :)

    TreeNode *k1 , *k2;
	if(root != NULL)
	{
		if(root -> val > n1 -> val || root -> val < n2 -> val){
				return root;
			}
		else{
			k1 = LCA(root->left, n1, n2);
			k2 = LCA(root->right, n1, n2);
			if(k1)
				return k1;
			if(k2)
				return k2;
		}
	}
}