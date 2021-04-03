#include "tree.h"
#include "stack.h"

int height(TreeNode *root){
    int hl, hr;
    if (root == NULL) return 0;
    if((hl = height(root->left)) >= (hr = height(root->right))) return 1+hl;
    return 1+hr;
}

/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/
TreeNode* createBalanced(int N, FILE *f) {
    if(N > 0) {
        TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
        fscanf(f, "%d", &(n->val));
        n->left = createBalanced(N/2, f);
        n->right = createBalanced(N-1-N/2, f);
        return n;
    } else
        return NULL;
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
  Stack *stack = createStack(height(root));
  int i = 0;
  while(1) {
      while(root) {
        push(stack, root);
        root = root->left;
      }
      if(isEmpty(stack)) break;
      root = pop(stack);
      arr[i++] = root;
      root = root->right;
  }
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {
    if(root) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

/**
 * CERINTA 4
 * TODO: Implementarea functiei pentru gasirea celui mai apropiat stramos comun(LCA) a doua noduri date(LCA)
 *  pentru doua noduri n1 si n1.LCA este cel mai adanc(de jos nod) care ii are pe n1 si n1 ca descendenti
 * @param root - nodul radacina al arborelui
 * @param n1 - nodul 1 pentru cautare LCA
 * @param n2 - nodul 2 pentru cautare LCA
 */ 
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    int s = height(root);
    Stack *stack1 = createStack(s), *stack2 = createStack(s);
    TreeNode **s1 = stack1->arr, **s2 = stack2->arr;
    TreeNode *r = root;
    char g1 = 0, g2 = 0;
    while(1) {
        while(r && !(g1 && g2)) {
            if(r == n1) g1 = 1;
            if(r == n2) g2 = 1;
            if(!g1) push(stack1, r);
            if(!g2) push(stack2, r);
            r = r->left;
         }
        if((isEmpty(stack1) || isEmpty(stack2)) || (g1 && g2)) break;
        if(!g1) r = pop(stack1);
        if(!g2) r = pop(stack2);
        r = r->right;
    }
    while(*(s1+1) == *(s2+1)) {
        s1++;
        s2++;
    }
    return *s1;
}