#include "prelab7.h"

Queue * createObj(void * obj) {
        Queue * q = malloc(sizeof(Queue));
        q->data = obj;
        q->next = NULL;
        return q;
}

Queue queueInit() {
	Queue * q = createObj(0);
	return *q;
}

int getQueueErrorCode(Queue q) {
	return 0;
}

int enqueue(void * p, Queue q) {
	Queue * qp = &q;
	Queue * newQueue = createObj(p);
	newQueue->next = qp->next;
	qp->next = newQueue;
	return 1;
}

void * dequeue(Queue q) {
	free(q.tail);
	return NULL;
}

