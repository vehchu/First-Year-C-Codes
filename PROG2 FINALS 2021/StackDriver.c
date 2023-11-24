#include<stdio.h>
/*change the header file below to test different stack implementations*/
#include <ADTStackLL.h>

/*Sample stack functions*/
void insertBottom(Stack *S, char elem);
void displayStack(Stack *S); /* top to bottom*/

void main(){
	
	Stack A;
	initialize(&A);
	push(&A,'a');
	push(&A,'b');
	push(&A,'c');
	displayStack(&A); /* c b a */
	insertBottom(&A,'d');
	displayStack(&A); /* c b a d */
	displayStack(&A); /* c b a d */
}

void insertBottom(Stack *S, char elem){
	Stack temp;
	
	initialize(&temp);
	char ch;
	while(isEmpty(*S) == 0){
		ch = top(*S);
		pop(S);
		push(&temp,ch);
	}
	push(S,elem);
	while(isEmpty(temp) == 0){
		ch = top(temp);
		pop(&temp);
		push(S,ch);
	}	
}

void displayStack(Stack *S){
	Stack temp;
	
	initialize(&temp);
	char ch;
	while(isEmpty(*S) == 0){
		ch = top(*S);
		printf("%c",ch);
		pop(S);
		push(&temp,ch);
	}
	printf("\n");
	
	/*This area is optional for Arrays but mandatory for Linked List*/
	/*But its placed here for uniformity*/
	while(isEmpty(temp) == 0){
		ch = top(temp);
		pop(&temp);
		push(S,ch);
	}	
}
