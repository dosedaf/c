#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

node *createNode(int val) {
    node* res = malloc(sizeof(node));
    if(res != NULL) {
        res->left = NULL;
        res->right = NULL;
        res->val = val;
    }

    return res;
}

void printTree(node *root) {
   if(!root) {
       printf("---<empty>---\n");
       return;
   }
}

int main() {
    node *n1 = createNode(10);
    node *n2 = createNode(11);
    node *n3 = createNode(12);
    node *n4 = createNode(13);
    node *n5 = createNode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;
}
