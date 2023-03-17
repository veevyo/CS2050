#include "prelab7.h"

void printQueue(Queue q) {
        printf("{");
        while (q.item->next != NULL) {
                printf("%p ", q.item->next);
                q.item->next = q.item->next->next;
        }
        printf("}\n");
}

int main(void) {
        int i;
        Queue q;
        q = queueInit();
	int hi = 7;
        for (i=0; i<100; i++) {
                enqueue(&hi, q);
        }
        printQueue(q);
}
