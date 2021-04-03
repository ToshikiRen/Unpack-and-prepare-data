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
    if(N>0)
    {
TreeNode* root= (TreeNode*)malloc(sizeof(TreeNode));
int val;
printf("Val nod");
 fscanf(f,"%d", &val);
(root->val)=val;
root->left= createBalanced (N/2,f);
root->right= createBalanced(N-1-N/2,f); // un nod a fost folosit pt radacina
return root; //si N/2 pt subarb. stg.
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
 
  int k=0;
  TreeNode*current=root;
  Stack*s=createStack(size);  
  int done=0;
  while(done!=1)
  {
    if(current!=NULL)
    { 
      push(s,current);                                              
      current=current->left; 
    }
    else                                                             
    {
      if (!isEmpty(s))
      {
        current=pop(s);
        arr[k]=current;
        k++;
        printf("%d ",current->val);
        current=current->right;
      }
      else
        done=1;
    }
  } 
  
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {
     if (root == NULL) 
     return ;
    deleteTree(root->left);
    deleteTree(root->right);
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
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
      if (root == NULL) 
      return NULL;
    if (root->val == n1->val||root->val==n2->val)
        return root;
    TreeNode*left_lca=LCA(root->left,n1,n2);
    TreeNode*right_lca=LCA(root->right,n1,n2);
 
    if (left_lca&&right_lca) 
     return root;

    return (left_lca);
}