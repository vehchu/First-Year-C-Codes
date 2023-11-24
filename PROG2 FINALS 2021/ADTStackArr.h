/*
 *   ADT Stack - Array Implementation
 *   Header file for stack operations
 *
 *   By Wayne Dayata
 *   9/12/2021
 *
 *   Note: In driver program, define the DATATYPE through typedef
 */

#define MAX 128

#ifndef STACK_H
#define STACK_H
#endif

typedef char DATATYPE;

typedef struct{
	DATATYPE data[MAX];
	int top;
}Stack;

void initialize(Stack *S); /* initializes stack to be logically empty */
void push(Stack *S, DATATYPE elem); /* inserts the element x at the top of the stack */
void pop(Stack *S); /* deletes the top element of the Stack S */
DATATYPE top(Stack S); /* returns the element at the top of the Stack S */
int isEmpty(Stack S); /* returns 1 if stack is empty and 0 if false */

void initialize(Stack *S){
	S->top = 0;
}

void push(Stack *S, DATATYPE elem){ /*insertLast() in arrays*/
	if (S->top < MAX){
		S->data[S->top] = elem;	
		S->top++;
	}
}

void pop(Stack *S){
	if (S->top > 0){
		S->top--;	
	}
}

DATATYPE top(Stack S){
	return S.data[S.top-1];
}

int isEmpty(Stack S){
	return (S.top == 0) ? 1 : 0;
}

