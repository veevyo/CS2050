#include <stdio.h>
#include <stdlib.h>

//first in, first out
typedef struct {
	void * data;
	void * next;
	void * tail;
} Queue;

typedef struct {
	void * p;
} PointerWrapper;

int getQueueErrorCode(Queue q);
Queue queueInit();
int enqueue(void * p, Queue q);
void * dequeue(Queue q);
int getQueueSize(Queue q);
void freeQueue(Queue q);
