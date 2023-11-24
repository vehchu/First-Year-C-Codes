#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

typedef struct node{
	char elem;
	int next;
} nodetype;

typedef struct {
	nodetype Nodes[MAX];
	int Avail;
} VHeap;

typedef int LIST;

typedef enum {
	FALSE, TRUE
} boolean;

int allocSpace(VHeap *VH) {
	int ret;
	ret = VH->Avail;
	if(ret != -1) {
		VH->Avail = VH->Nodes[ret].next;
		VH->Nodes[ret].next = -1;
	}
	return ret;
}

void deallocSpace(VHeap *VH, int ndx) {
	if(ndx >= 0 && ndx < MAX) {
		VH->Nodes[ndx].next = VH->Avail;
		VH->Avail = ndx;
	}
}

void initQueue(VHeap *VH, LIST *L) {
	int x;
	
	for(x = 0; x < MAX; x++) {
		VH->Nodes[x].next = x-1;
	}
	VH->Avail = MAX-1;
	*L = -1;
}

boolean isFull(VHeap *VH) {
	return (VH->Avail == -1) ? TRUE : FALSE;
}

boolean isEmpty(LIST L) {
	return (L == -1) ? TRUE : FALSE;
}

void enqueue(VHeap *VH, LIST *L, char elem) {
	int cell;
	if(isFull(VH) == FALSE) {
		cell = allocSpace(VH);
		VH->Nodes[cell].elem = elem;
		VH->Nodes[cell].next = *L;
		*L = cell;
	}
}

void dequeue(VHeap *VH, LIST *L) {
	int temp;
	if(isEmpty(VH) == FALSE) {
		temp = *L;
		*L = VH->Nodes[*L].next;
		deallocSpace(VH, temp);
	}
}

char front(VHeap *VH, LIST L) {
	return VH->Nodes[L].elem;
}

void display(Queue Q) {
	while(isEmpty(Q) == FALSE) {
		printf("%c", front(Q));
		dequeue(&Q);
	}
}

#endif
