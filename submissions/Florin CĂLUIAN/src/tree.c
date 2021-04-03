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
    // TODO
    int point;
    if(N>0)
    {
        TreeNode* rad=(TreeNode*)malloc(sizeof(TreeNode));
        fscanf(f,"%d",&point);
        rad->val=point;
        rad->left=createBalanced(N/2,f);
        rad->right=createBalanced(N-1-N/2,f);
        return rad;
    }
    else
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
  Stack *stiva=createStack(size);
  *arr=(TreeNode*)malloc(sizeof(TreeNode)*size);
  int i=0;
  while(1)
  {
    while(root!=NULL)
    {
         push(stiva,root);
         root=root->left;
    }
    if(isEmpty(stiva))
         break;
    arr[i]=pop(stiva);
    printf("%d ",arr[i]->val);
    root=arr[i]->right;
    i++;
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
    if(root==NULL)
        return NULL;
    if(root==n1 || root==n2)
                return root;
    TreeNode *stanga,*dreapta;
    stanga=LCA(root->left,n1,n2);
    dreapta=LCA(root->right,n1,n2);
    if(stanga==NULL)
       return dreapta;
     if(dreapta==NULL)
       return stanga;
    return root;
    ///Incercarea iterativa mai jos, dar primeam numai erori :(((
    ///Stack *St1,*St2;
    //St1=createStack(cap);
    //St2=createStack(cap);
    //rt=root;
    //cos=NULL;
    
    /*while(1)
    {
        while(rt!=NULL && cos!=rt)
        {
            push(St1,rt);
            if(rt->val==n1->val)
               break;
             
            rt=rt->left;
        }
        rt=peek(St1);
        if(cos!=rt->right || rt->right==NULL)
            rt=rt->right;
        if(rt==NULL || cos==rt->right)
          cos=pop(St1);
       
    }
    
    rt=root;
    cos=NULL;
    while(1)
    {
        while(rt!=NULL && cos!=rt)
        {
            push(St2,rt);
            if(rt->val==n2->val)
               break;
            rt=rt->left;
        }
        rt=peek(St2);
        if(cos!=rt->right || rt->right==NULL)
            rt=rt->right;
        if(rt==NULL || cos==rt->right)
          cos=pop(St2);
       
    }
    int i=0;
    while(St1->arr[i]==St2->arr[i] && (i<=St1->top &&i<=St2->top))
             i++;
    return St1->arr[i];
    */
 
}