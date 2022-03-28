#include <stdio.h>
#include <stdlib.h>

/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

typedef struct bt{
    struct node* root;
} bt_t;

/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value) {
    if (tree == NULL) {
        return 0;
    } else {
        node_t* currentNode = tree->root;
        
        while (currentNode != NULL) {
            if (currentNode->value == value) {
                return 1;
            }
            else if (value < currentNode->value) {
                currentNode = currentNode->left; 
            }
            else {
                currentNode = currentNode->right;
            }
        }
        return 0;
    }
}

node_t* init_node(int value, node_t* left, node_t* right) {
    node_t* newNode = malloc(sizeof(node_t));
    if (newNode == NULL) {
        return 0;
    }
    newNode->left=left;
    newNode->right=right;
    newNode->value=value;
    return newNode;
}

int main(int argc, char* argv[]) {
    node_t* n17 = init_node(17, NULL, NULL);
    node_t* n13 = init_node(13, NULL, NULL);
    node_t* n16 = init_node(16, n13, n17);
    node_t* n7 = init_node(7, NULL, NULL);
    node_t* n11 = init_node(11, n7, n16);
    node_t* n23 = init_node(23, NULL, NULL);
    node_t* n35 = init_node(35, n23, NULL);
    node_t* n19 = init_node(19, n11, n35);
    bt_t* bt = malloc(sizeof(bt_t));
    bt->root=n19;
    printf("Value node : %d\n", n19->right->value);
    printf("Root node : %d\n", bt->root->value);
    printf("Find 4 = %d \n", contains(bt, 35));
}