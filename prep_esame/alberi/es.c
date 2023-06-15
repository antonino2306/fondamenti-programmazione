#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree{
    struct tree *left;
    int data;
    struct tree *right;
};

typedef struct tree Tree;

void insert(Tree **root, int num);
void free_tree(Tree *node);
void in_order(Tree *root);
void pre_order(Tree *root);
void post_order(Tree *root);
Tree *binary_search_tree(Tree *root, int key);

int main() {

    Tree *root = NULL;

    size_t num_elementi;

    puts("Quanti numeri vuoi inserire nell'albero:");
    scanf("%lu", &num_elementi);

    srand(time(NULL));

    for (size_t i = 0; i < num_elementi; i++) {
        int num = rand() % 100 + 1;
        insert(&root, num);
    }

    puts("Inserimento completato");
    
    puts("In order");
    in_order(root);
    puts("");
    
    int key;
    puts("che elemento vuoi cercare:");
    scanf("%d", &key);
    Tree *found = binary_search_tree(root, key);

    if (found != NULL) {
        printf("Il valore cercato è %d all'indirizzo %p\n", found->data, found);
    }
    else {
        puts("Valore non presente nell'albero");
    }
    // puts("Pre order");
    // pre_order(root);
    // puts("");
    // puts("Post order");
    // post_order(root);
    // puts("");


    free_tree(root);
}

void insert(Tree **root, int num)
{
    if ((*root) == NULL) {
        (*root) = (Tree*)malloc(sizeof(Tree));

        if ((*root) != NULL) {
            (*root)->data = num;
            (*root)->left = NULL;
            (*root)->right = NULL;
        }

    }
    else {

        if (num < (*root)->data) {
            insert(&((*root)->left), num);
        }
        else {
            insert(&((*root)->right), num);
        }

    }

}

void free_tree(Tree *node){
   //post-order like FatalError hinted at
    if (node != NULL) {
        free_tree(node->right);

        free_tree(node->left);
        
        free(node); 
    }
}

void in_order(Tree *root)
{
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

void pre_order(Tree *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(Tree *root)
{
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

Tree *binary_search_tree(Tree *root, int key)
{
    if (root != NULL) {
        if (root->data == key) {
            return root;
        }
        else if (key > root->data) {
            return binary_search_tree(root->right, key);
        }
        else {
            return binary_search_tree(root->left, key);
        }
    }
    else {
        return NULL;
    }
}
