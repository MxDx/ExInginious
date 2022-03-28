#include <stdio.h>
#include <stdlib.h>

/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
typedef struct node {
  struct node *next;
  int value;
} node_t;

/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
typedef struct list {
  struct node *first;
  int size;
} list_t;

/*
* Create a new node containing the value @value.
*
* @value: value stored in the node
* @next : pointer to next node, initialised to NULL.
* @return: returns the pointer to the newly created node, or NULL if an error occured.
*/
node_t *init_node(int value) {
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL) {
      return NULL;
    } else {
      newNode->value = value;
      newNode->next = NULL;
      return newNode;
    } 
}

/*
* Add a node at the head of the list @list and increment the number of nodes in the list (member `size`)
*
* @l: linked list
* @value: value to add to the list
*
* @return: 0 if success, 1 otherwise
*/
int add_node(list_t *list, int value) {
    if (list == NULL) {
      return 1;
    } else {
      node_t* newNode = malloc(sizeof(node_t));
      if (newNode == NULL) {
        return 1;
      } else {
        newNode->value = value;
        newNode->next = list->first;
        list->first = newNode;
        list->size = list->size+1;
        return 0;
      }
    }   
}

int main(int arc, char* argv[]) {
    node_t *node = init_node(4);
    printf("Node val = %d\n", (*node).value);
    list_t* testList;
    printf("Head node val = %d\n", testList->first->value);
    add_node(testList, 2);
    printf("Head node val = %d\n", testList->first->value);
    add_node(testList, 12);
    printf("Head node val = %d\n", testList->first->value);

}