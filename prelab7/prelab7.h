#include <stdio.h>
#include <stdlib.h>

typedef struct queueItem {
	void * data;
	struct queueItem * next;
} queueItem;
typedef struct Queue {	
	int error;
	int size;
	queueItem * item;
} Queue;

int getQueueErrorCode(Queue q);
Queue queueInit();
int enqueue(void * p, Queue q);
void * dequeue(Queue q);
int getQueueSize(Queue q);
void freeQueue(Queue q);
