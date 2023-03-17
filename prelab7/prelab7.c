#include "prelab7.h"

queueItem * createObj(void * obj, queueItem * item) {
       	queueItem * new = malloc(sizeof(queueItem));
        new->data = obj;
        new->next = item;
        return new;
}

Queue queueInit() {
	queueItem * q = NULL;
	Queue queue;
	queue.item = q;
	return queue;
}

int getSize(Queue q) {
        int counter;
        while (q.item->next != NULL) {
                counter++;
                q.item->next = q.item->next->next;
        }
        return counter;
}


int getQueueErrorCode(Queue q) {
	return q.error;
}

int enqueue(void * p, Queue q) {
	queueItem * newItem = createObj(p, q.item->next);
	q.item->next = newItem;
	//q.size++;
	//printf("%p\n",p);
	return 1;
}

/*void * dequeue(Queue q) {
	free(q.tail);
	return NULL;
}*/


