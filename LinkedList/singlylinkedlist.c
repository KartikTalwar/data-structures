#include <stdio.h>
#include <stdlib.h> 


struct Node {
  int value;
  struct Node *next;
};

struct SinglyLinkedList {
  int size;
  struct Node *head;
};


typedef struct Node Node;
typedef struct SinglyLinkedList SinglyLinkedList;


void init(SinglyLinkedList *);
void insert(SinglyLinkedList *, int value);
void is_empty(SinglyLinkedList *);
void reverse(SinglyLinkedList *);
int  delete(SinglyLinkedList *, int value);
int  contains(SinglyLinkedList *, int value);


void init(SinglyLinkedList *list) {
  list->head = NULL;
  list->size = 0;
}


void insert(SinglyLinkedList *list, int value) {
  if(list->head != NULL) {
    Node *temp = malloc(sizeof(Node));
    temp->value = value;
    temp->next = list->head;
    list->head = temp;
    list->size++;
  } else {
    list->head = malloc(sizeof(Node));
    list->head->value = value;
    list->size++;
  }
}


int contains(SinglyLinkedList *list, int value) {
  Node *curr = list->head;
  int found = 0;

  while(!found && curr != NULL) {
    if(curr->value == value) {
      found = 1;
    } else {
      curr = curr->next;
    }
  }

  return found;
}


int delete(SinglyLinkedList *list, int value) {
  Node *curr = list->head;
  Node *prev = NULL;
  int found  = 0;

  while(found == 0) {
    if(curr->value == value) {
      list->size--;
      found = 1;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }

  if(prev == NULL) {
    list->head = curr->next;
  } else {
    prev->next = curr->next;
  }

  return found;
}


void reverse(SinglyLinkedList *list) {
  Node *curr = list->head;
  Node *last = NULL;

  while(curr != NULL) {
    Node *temp = curr->next;
    curr->next = last;
    last = curr;
    curr = temp;
  }

  list->head = last;
}



void main() {

  SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));

  insert(list, 2);
  insert(list, 3);
  insert(list, 42);
  insert(list, 4);

  printf("List size: %d\n", list->size);
  printf("Searching for 42: %d\n", contains(list, 42));
  printf("Removing 42: %d\n", delete(list, 42));
  printf("Searching for 42: %d\n", contains(list, 42));

  printf("Getting first value: %d\n", list->head->value);

  printf("Reversing\n");
  reverse(list);

  printf("Getting first value: %d\n", list->head->value);

}
