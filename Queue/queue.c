#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10


struct Queue {
  int data[MAXSIZE];
  int first;
  int last;
  int size;
};

typedef struct Queue Queue;


void init(Queue *);
void enqueue(Queue *, int item);
int  dequeue(Queue *);
int  length(Queue *);
int  empty(Queue *);


void init(Queue *data) {
  data->first = 0;
  data->last  = MAXSIZE-1;
  data->size  = 0;
}


int empty(Queue *data) {
  return data->size == 0;
}


int length(Queue *data) {
  return data->size;
}


void enqueue(Queue *data, int item) {
  if(data->size < MAXSIZE) {
    data->last = (data->last + 1) % MAXSIZE;
    data->data[data->last] = item;
    data->size++;
  }
}


int dequeue(Queue *data) {
  if(!empty(data)) {
    int last = data->data[data->first];

    data->first = (data->first + 1) % MAXSIZE;
    data->size--;

    return last;
  }
  return -1;
}


void main() {
  Queue *q = malloc(1 * sizeof(Queue));

  init(q);
  enqueue(q, 2);
  enqueue(q, 3);

  printf("Dequeue: %d\n", dequeue(q));  
  printf("Dequeue: %d\n", dequeue(q));  
}

