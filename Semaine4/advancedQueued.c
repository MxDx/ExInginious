#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node* next;
  int value;
} node_t;

typedef struct queue{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val) {
  node_t* newNode = malloc(sizeof(node_t));
  if (newNode == NULL) return -1;

  if (q->size == 0) {
    q->size++;
    q->tail = newNode;
    newNode->next = newNode;
    return 0;
  }
  newNode->next = q->tail->next;
  newNode->value = val;
  q->tail->next = newNode;
  q->size++;

  return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q) {
  int value;
  if (q->size == 1) {
    free(q->tail);
    value = q->tail->value;
    q->tail = NULL;
    q->size = 0;
    return value;
  }
  node_t* newTail = q->tail;
  for (int i = 0; i < q->size-1; i++) {
    newTail = newTail->next; 
  }
  newTail->next = q->tail->next;
  free(q->tail);
  value = q->tail->value;
  q->tail = newTail;
  q->size--;
  return value;
}

int main() {
  node_t* node12 = malloc(sizeof(node_t));
  node12->value = 12;
  node12->next = node12;
  queue_t* q = malloc(sizeof(queue_t));
  q->size = 1;
  q->tail = node12;

  printf("%d \n", q->tail->value);
  printf("%d \n", q->size);

  enqueue(q, 99);
  printf("%d \n", q->tail->value);
  printf("%d \n", q->tail->next->value);
  printf("%d \n", q->size);

  dequeue(q);
  printf("%d \n", q->tail->value);
  printf("%d \n", q->tail->next->value);
  printf("%d \n", q->size);
}