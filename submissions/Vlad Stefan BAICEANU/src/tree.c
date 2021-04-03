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
TreeNode* createBalanced(int N, FILE *f) {
    int num;
    if(N<=0){
        return NULL;
    }
    else{
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        fscanf(f,"%d",&num);
        (root->val) = num;
        root->left = createBalanced(N/2,f);
        root->right = createBalanced(N-1-N/2,f);
        return root;
    }
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
    int i = 0;
    TreeNode* temp = root;
    Stack* stack = createStack(size);

    while(root != NULL){
        if(!(!isEmpty(stack) || isNotNull((void*)temp))){
            break;
        }

       while(root != NULL){
           if(!(isNotNull((void*)temp))){
               break;
           }
           push(stack,temp);
           temp = temp->left;
       }

       temp = pop(stack);
       arr[i++] = temp;
       temp = temp->right;
    }
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {

    if(isNull((void*)root)){
        return;
    }
    deleteTree(root->right);
    deleteTree(root->left);
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

    if(root == n1 || root == n2 || isNull((void*)root)){
        return root;
    } 
    TreeNode *stanga = LCA(root->left,n1,n2);
    TreeNode *dreapta = LCA(root->right,n1,n2);

    return (isNotNull((void*)stanga) && isNotNull((void*)dreapta)) ? root : (isNotNull((void*)stanga) ? stanga : dreapta);
}