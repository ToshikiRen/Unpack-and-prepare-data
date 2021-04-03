#include "tree.h"
#include "stack.h"

/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/
TreeNode* createBalanced(int N, FILE *f) {
    // TODO
    int val;
    if(N > 0) {
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

        fscanf(f, "%d", &val);
        root -> val = val;
        root -> left = createBalanced(N/2, f);
        root -> right = createBalanced(N - 1 - N/2, f);
        return root;
    }
    else return NULL;
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
  // TODO
  Stack *stiva = createStack(size);
  TreeNode *curent = root;
  int terminat = 0, index = 0;

  while(!terminat) {
      if(curent != NULL) {
          push(stiva, curent);
          curent = curent -> left;
      }
      else {
          if(!isEmpty(stiva)) {
              curent = pop(stiva);
              arr[index] = curent;
              index += 1;
              curent = curent -> right;
          }
          else {
              terminat = 1;
          }
      }
  }
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {
    // TODO
    if(root != NULL) {
        deleteTree(root -> left);
        deleteTree(root -> right);
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

int findPath(TreeNode *root, TreeNode *nod, TreeNode **drum, int *index) {
    if(root == NULL) {
        return 0;
    }

    drum[*index] = root;
    *index += 1;
    
    if(root -> val == nod -> val) {
        return 1;
    }

    if((root -> left && findPath(root -> left, nod, drum, index))
    || (root -> right && findPath(root -> right, nod, drum, index))) {
        return 1;
    }

    *index -= 1;
    return 0;
}

TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    // TODO
    TreeNode **drum1 = (TreeNode **)malloc(50 * sizeof(TreeNode *));
    TreeNode **drum2 = (TreeNode **)malloc(50 * sizeof(TreeNode *));
    int index1 = 0, index2 = 0;
    TreeNode *rezultat = NULL;

    if(!findPath(root, n1, drum1, &index1) || !findPath(root, n2, drum2, &index2)) {
        return NULL;
    }

    int i;
    for(i = 0; i < index1 && i < index2; i++) {
        if(drum1[i] != drum2[i]) {
            break;
        }
    }
    rezultat = drum1[i-1];

    for(int j = 0; j < 50; j++) {
        drum1[j] = drum2[j] = NULL;
    }
    free(drum1); free(drum2);
    return rezultat;
}