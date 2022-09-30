#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK  1
#define NG -1

typedef struct _queue {
  int front;
  int back;
  int size;
  int *array;
} QUEUE;

/*queue function*/
QUEUE *new_queue(int n);
void   delete_queue(QUEUE *que);
int    dequeue(QUEUE *que, int *x);
int    enqueue(QUEUE *que, int x);
void   clean_queue(QUEUE *que);


QUEUE *new_queue(
  int n
)
{
  if (n <= 0) {
    return NULL;
  }

  QUEUE *que = (QUEUE*)malloc(sizeof(QUEUE));
  if (!que) {
    return NULL;
  }

  que->front = 0;
  que->back  = 0;
  que->size  = n;
  que->array = (int*)malloc(sizeof(int) * n);
  if (!que->array) {
    goto l_end;
  }

l_end:
  if (que) {
    free(que);
  }
  return que;
}

void delete_queue(
  QUEUE *que
)
{
  if (que) {
    if (que->array) {
      free(que->array);
    }
    free(que);
  }
  return ;
}


int dequeue(
  QUEUE *que,
  int   *x
)
{
  if (!que || !x) {
    return NG;
  }

  if (que->front == que->back) {
    return NG;
  }

  *x = que->array[que->front];
  que->front++;
  if (que->front >= que->size) {
    que->front = 0;
  }

  return OK;
}

int enqueue(
  QUEUE *que,
  int    x
)
{
  if (!que) {
    return NG;
  }

  que->array[que->back] = x;
  que->back++;
  if (que->back >= que->size) {
    que->back = 0;
  }

  return OK;
}


void clean_queue(
  QUEUE *que
)
{
  if (que) {
    que->front = 0;
    que->back  = 0;
    memset(que->array, 0, sizeof(int)*que->size);
  }

  return ;
}
