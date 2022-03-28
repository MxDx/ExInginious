#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *next;
	int hash;
    int id;
    char name[20]; 
    char buffer[100]; 
    unsigned int timestamp;
    char acl;
    short flow;
    char *parent;
    void *fifo;

};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head) {
    if (head == NULL) return NULL;

    struct node* repHead = malloc(sizeof(*head));
    memcpy(repHead, head, sizeof(*head));
    if (head->next != NULL) repHead -> next = pair_filter(head->next->next);
    return repHead;
}

int main() {
    struct node* testNode = malloc(sizeof(struct node));
    pair_filter(testNode);
}