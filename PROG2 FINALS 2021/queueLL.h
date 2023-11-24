#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

typedef struct node{
	char elem;
	struct node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
} Queue;

typedef enum {
	FALSE, TRUE
} boolean;

void initQueue(Queue *Q) {
	Node *trav, *del;
	
	trav = del = Q->front;
	while(trav != NULL) {
		trav = Q->front->next;
		free(del);
		del = trav;
	}
	Q->front = NULL;
	Q->rear = NULL;
}

boolean isEmpty(Queue Q) {
	return (Q.front == NULL) ? TRUE : FALSE;
}

void enqueue(Queue *Q, char elem) {
	Node *newNode;
	
	newNode = (Node*)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->elem = elem;
		newNode->next = NULL;
		
		if(isEmpty(*Q) == TRUE) {
			Q->front = Q->rear = newNode;
		} else {
			Q->rear->next = newNode;
		}
	}
}

void dequeue(Queue *Q) {
	Node *del;
	if(isEmpty(*Q) == FALSE) {
		del = Q->front;
		Q->front = Q->front->next;
		free(del);
	}
}

char front(Queue Q) {
	return Q.front->elem;
}

void display(Queue Q) {
	while(isEmpty(Q) == FALSE) {
		printf("%c", front(Q));
		dequeue(&Q);
	}
}

#endif
