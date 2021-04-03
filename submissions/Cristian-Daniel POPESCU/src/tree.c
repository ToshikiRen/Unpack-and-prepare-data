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
    int n;
    if(N>0)
    {
        fprintf(f,"%d",&n);
        TreeNode *nod;
        nod=(TreeNode*)malloc(sizeof(TreeNode));
        nod->val=n;

        nod->left=createBalanced((N/2),f);
        nod->right=createBalanced((N-1-N/2),f);
        return nod;
    }
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
  // TODO
    Stack *st=createStack(size);
   int n=0;

    while(1)
    {
        while(root)
        {
            root=root->left;
            push(&st,root);
        }
        if(isEmpty)break;
        arr[n]=peek(st);
        n++;
        root=pop(st);
        root=root->right;
    }
   

}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {

    // TODO
    if(root)
    {
        deleteTree(root->left);
        
        deleteTree(root->right);

        free(root);
       
    }
    root=NULL;
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
    // TODO 
     int ok=0,i=0;
     TreeNode *copy;
     Stack *st1,*st2;
     st1=createStack(30);
     st2=createStack(30);
     copy=root;
    while(1)
    {
        while(root&&ok!=1)
        {
            root=root->left;
            if (n1->val==root->val)ok=1;
            push(&st1,root);
        }
        if(ok!=1)break;
        
        root=pop(st1);
        root=root->right;
    }
    while(1)
    {
        while(copy&&ok!=1)
        {
            copy=copy->left;
            if (n2->val==copy->val)ok=1;
            push(&st2,copy);
        }
        if(ok!=1)break;
        
        copy=pop(st2);
        copy=copy->right;
    }
    while(i<=st1->top&&i<=st2->top)
    while(st1->arr[i]->val==st2->arr[i]->val)i++;

    return st1->arr[i-1];
}