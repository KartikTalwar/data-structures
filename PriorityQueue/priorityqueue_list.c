#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10


struct PriorityQueueList {
  int data[MAXSIZE];
  int min_index;
  int min_value;
  int size;
};

typedef struct PriorityQueueList PriorityQueueList;


void init(PriorityQueueList *);
void insert(PriorityQueueList *, int value);
void remove_min(PriorityQueueList *);
int  peek_min(PriorityQueueList *);
int  empty(PriorityQueueList *);


void init(PriorityQueueList *data) {
  data->size = 0;
  data->min_index = -1;
  data->min_value = -1;
}


int empty(PriorityQueueList *data) {
  return data->size == 0;
}


int peek_min(PriorityQueueList *data) {
  if(!empty(data)) {
    return data->min_value;
  }

  return -1;
}


void insert(PriorityQueueList *data, int value) {
  if(data->size < MAXSIZE) {
    if(data->min_index == -1) {
      data->min_index = 0;
      data->min_value = value;
      data->data[data->size++] = value;
    } else {
      if(value < data->min_value) {
        data->min_value = value;
        data->min_index = data->size + 1;
        data->data[data->size++] = value;
      }
    }
  }
}


void remove_min(PriorityQueueList *data) {
  if(!empty(data)) {
    int new_min, i, j;

    for(j=data->min_index; j<data->size-1; j++) {
      data->data[j] = data->data[j+1];
    }

    data->size--;

    for(i=0; i<data->size; i++) {
      if(data->data[i] < new_min) {
        new_min = data->data[i];
        data->min_index = i;
        data->min_value = new_min;
      }
    }
  }
}


int main() {

  PriorityQueueList *pq = malloc(1 * sizeof(PriorityQueueList));

  init(pq);
  insert(pq, 2);
  insert(pq, 1);
  insert(pq, 3);

  printf("Min: %d\n", peek_min(pq));
  remove_min(pq);
  printf("Min: %d\n", peek_min(pq));
}

