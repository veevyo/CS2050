#include "prelab7.h"

Queue queueInit() {
	q = NULL;
	return q;
}

int getQueueErrorCode(Queue q) {
	if (!q) {
		return 1;
	}
	return 0;
}

int enqueue(void * p, Queue p);
