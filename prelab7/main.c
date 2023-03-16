#include "prelab7.h"

void printQueue(Queue * q) {
        printf("{");
        while (q != NULL) {
                printf("%p ", q->data);
                q = q->next;
        }
        printf("}\n");
}

int main(void) {
        int i;
        Queue head;
        head = queueInit();
	int hi = 7;
        for (i=0; i<100; i++) {
                enqueue(&hi, head);
        }
        printQueue(&head);
}
