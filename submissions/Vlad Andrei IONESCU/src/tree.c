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
    if (N > 0)
    {
        int n;
        fscanf(f, "%d", &n);
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = n;
        root->left = createBalanced(N / 2, f);
        root->right = createBalanced(N - 1 - N / 2, f);
        return root;
    }
    else
        return NULL;
    // TODO
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
//SRD
void inorderIterative(TreeNode *root, TreeNode **arr, int size)
{
    Stack *S = NULL;
    int i = 0;
    S = createStack(size);
    printf("inorderIterative:\n");

    while (1)
    {
        while (root)
        {
            push(S, root);
            root = root->left;
        }

        if (isEmpty(S))
            break;

        root = pop(S);
        printf("%d ", root->val);
        TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
        temp->left = temp->right = NULL;
        temp->val = root->val;
        arr[i] = temp; //*(arr+i) = temp;
        i++;
        root = root->right;
    }

    deleteStack(&S);
    printf("\n");
    // TODO
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
        //printf("Sterg nodul cu valoarea: %d\n", root->val);
        free(root);
    }
    // TODO
}

int isPresent(TreeNode *root, TreeNode *node)
{
    if (!root)
    {
        return 0;
    }
    if (root == node)
    {
        return 1;
    }
    return isPresent(root->left, node) || isPresent(root->right, node);
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
    Stack *S = NULL;
    Stack *S1 = NULL;
    Stack *S2 = NULL;
    TreeNode *copie = root;

    S = createStack(100);
    S1 = createStack(100);
    S2 = createStack(100);
    printf("caut LCA pentru nodurile : %d si %d\n", n1->val, n2->val);

    if (root == NULL)
        return NULL;
    if (root->val == n1->val || root->val == n2->val)
        return root;

    //n1
    while (1)
    {
        while (root)
        {
            if (root->right)
                push(S, root->right); // daca are dreapta atunci push dreapta
            push(S, root);
            root = root->left;
        }

        if (isEmpty(S))
            break;

        root = pop(S);
        if (root->right && peek(S) == root->right)
        {
            pop(S);             // sterg dreapta
            push(S, root);      // resalvez root
            root = root->right; // ma duc pe dreapta
        }
        else
        {
            //printf("%d ", root->val);
            if (isPresent(root, n1))
            {
                push(S1, root);
            }
            root = NULL;
        }
    }
    deleteStack(&S);

    root = copie;
    S = createStack(100);
    //n2
    while (1)
    {
        while (root)
        {
            if (root->right)
                push(S, root->right); // daca are dreapta atunci push dreapta
            push(S, root);
            root = root->left;
        }

        if (isEmpty(S))
            break;

        root = pop(S);
        if (root->right && peek(S) == root->right)
        {
            pop(S);             // sterg dreapta
            push(S, root);      // resalvez root
            root = root->right; // ma duc pe dreapta
        }
        else
        {
            //printf("%d ", root->val);
            if (isPresent(root, n2))
            {
                push(S2, root);
            }
            root = NULL;
        }
    }
    deleteStack(&S);
    /*
    printf("\nstiva 1: "); 
    while( !isEmpty(S1) )
    {
        root = pop(S1);
        printf("%d ", root->val); 
    }

    printf("\nstiva 2: "); 
    while( !isEmpty(S2) )
    {
        root = pop(S2);
        printf("%d ", root->val); 
    }
  */

    root = peek(S1);
    //printf("\nS1->top este: %d", S1->top);
    //printf("\nS2->top este: %d", S2->top);
    while (1)
    {
        if (isEmpty(S1) || isEmpty(S2))
            break;
        if (peek(S1) == peek(S2))
        {
            root = peek(S1);
            pop(S1);
            pop(S2);
        }
        else
            break;
    }

    deleteStack(&S1);
    deleteStack(&S2);

    return root;
    // TODO
}

//*************************************************************************
void postOrderIterative(TreeNode *root, int size)
{
    Stack *S = NULL;
    S = createStack(size);

    printf("postOrderIterative:\n");
    while (1)
    {
        while (root)
        {
            if (root->right)
                push(S, root->right); // daca are dreapta atunci push dreapta
            push(S, root);
            root = root->left;
        }

        if (isEmpty(S))
            break;

        root = pop(S);
        if (root->right && peek(S) == root->right)
        {
            pop(S);             // sterg dreapta
            push(S, root);      // resalvez root
            root = root->right; // ma duc pe dreapta
        }
        else
        {
            printf("%d ", root->val);
            root = NULL;
        }
    }

    deleteStack(&S);
    printf("\n");
}
