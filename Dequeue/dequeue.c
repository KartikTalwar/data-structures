#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10


struct Dequeue {
  int data[MAXSIZE];
  int first;
  int last;
  int size;
};

typedef struct Dequeue Dequeue;


void init(Dequeue *);
void add_front(Dequeue *, int item);
void add_rear(Dequeue *, int item);
int  remove_front(Dequeue *);
int  remove_rear(Dequeue *);
int  size(Dequeue *);
int  empty(Dequeue *);


void init(Dequeue *data) {
  data->size  = 0;
  data->first = 0;
  data->last  = 0;
}


int empty(Dequeue *data) {
  return data->size == 0;
}


int size(Dequeue *data) {
  return data->size;
}


void add_front(Dequeue *data, int item) {
  if(size(data) < MAXSIZE) {
    data->data[--data->first] = item;
    data->size++;
  }
}


void add_rear(Dequeue *data, int item) {
  if(size(data) < MAXSIZE) {
    data->data[++data->last] = item;
    data->size++;
  }
}


int remove_front(Dequeue *data) {
  if(!empty(data)) {
    int val = data->data[data->first];

    if(data->first == data->last) {
      data->first = 0;
      data->last  = 0;
    } else {
      data->first++;
    }

    data->size--;

    return val;
  }
  return -1;
}


int remove_rear(Dequeue *data) {
  if(!empty(data)) {
    int val = data->data[data->last];

    if(data->first == data->last) {
      data->first = 0;
      data->last  = 0;
    } else {
      data->last--;
    }

    data->size--;

    return val;
  }
  return -1;
}


void main() {
  Dequeue *q = malloc(1 * sizeof(Dequeue));

  init(q);
  add_front(q, 2);
  add_front(q, 1);
  add_rear(q, 3);
  add_rear(q, 4);

  printf("Dequeue: %d\n", remove_front(q));  
  printf("Dequeue: %d\n", remove_front(q));  
  printf("Dequeue: %d\n", remove_rear(q));  
  printf("Dequeue: %d\n", remove_rear(q));  
}

