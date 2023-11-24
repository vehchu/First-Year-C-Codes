#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

typedef struct {
	char elem[MAX];
	int front;
	int rear;
} Queue;

typedef enum {
	FALSE, TRUE
} boolean;

void initQueue(Queue *Q) {
	Q->front = 1;
	Q->rear = 0;
}

boolean isFull(Queue Q) {
	return (Q.front == (Q.rear + 2) % MAX) ? TRUE : FALSE;
}

boolean isEmpty(Queue Q) {
	return (Q.front == (Q.rear + 1) % MAX) ? TRUE : FALSE;
}

void enqueue(Queue *Q, char elem) {
	if(isFull(*Q) == FALSE) {
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = elem;
	}
}

void dequeue(Queue *Q) {
	if(isEmpty(*Q) == FALSE) {
		Q->front = (Q->front + 1) % MAX;
	}
}

char front(Queue Q) {
	return Q.elem[Q.front];
}

void display(Queue Q) {
	while(isEmpty(Q) != FALSE) {
		printf("%c", front(Q));
		dequeue(&Q);
	}
}

#endif
