#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define intmin -2147483648
#define intmax 2147483648

void display(int arr[]);
int *soul_sorting(int arr[]);

void main(){

	int arr[MAX];

	printf("Enter size: ");
	scanf("%d", &arr[0]);

	printf("Enter soul scores: ");

	for(int i = 1; i <= arr[0]; i++){
		scanf("%d", &arr[i]);
	}

	printf("Initial list: ");
	display(arr);

	printf("Final list: ");
	int *soul = soul_sorting(arr);
	display(soul);


}

void display(int arr[]){

	printf("[");
	for(int i = 1; i <= arr[0]; i++){
		printf("%d", arr[i]);
		if(i < arr[0]){
			printf("|");
		}
	}
	printf("]");

	printf("soul count = %d\n", arr[0]);
}

int* soul_sorting(int arr[]){

	int highest = intmin;
	int second = intmin;
	int i;
	int secondindex = arr[0] + 1;

	for(int i = 1; i <= arr[0]; i++){
		if(arr[i] > highest){
			highest = arr[i];
		}
	}

	for(int i = 1; i <= arr[0]; i++){
		if(arr[i] > second && arr[i] != highest){
			second = arr[i];
			secondindex = i;
		}
	}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 0xFF

typedef struct {
    char FName[24], MI, LName[16];
    unsigned int ID;
    char course[8];
    int yearLevel;
} studtype;

typedef struct node {
    studtype stud;
    struct node* link;
}* LinkedList;

typedef struct {
    studtype stud[SIZE];
    int count;
}ArrayList;

void displayList(LinkedList list) {
    LinkedList trav;

    for (trav=list ; trav!=NULL ; trav=trav->link) {
        printf("%s ", trav->stud.LName);
    }
}

void displayArray(ArrayList array) {
    int trav;

    for (trav=0 ; trav<array.count ; trav++) {
        printf("%s ", array.stud[trav].LName);
    }
}

LinkedList removeByCourse(ArrayList* studArray, char* course) {
    LinkedList head=NULL;

    int count;
    for (count=0 ; count<studArray->count ; count++) {
        if (strcmp(studArray->stud[count].course, course) == 0) {
            LinkedList* trav;

            for (trav=&head ; trav!=NULL && strcmp((trav)->stud.LName, studArray->stud[count].LName)<=0 ; trav=&(trav)->link) {}

            LinkedList newNode = malloc(sizeof(struct node));

            newNode->stud = studArray->stud[count];
            newNode->link =trav;

            *trav = newNode;

            int temp;
            for (temp=count ; temp<studArray->count-1 ; temp++) {
                studArray->stud[temp] = studArray->stud[temp+1];
            }
            (studArray->count)--;
            count--;
        }
    }

    return head;
}
int main() {
    ArrayList studArray;

    studArray.stud[0].ID = 1;
    strcpy(studArray.stud[0].LName, "Uytengsu");
    strcpy(studArray.stud[0].course, "BSCS");
    studArray.stud[0].yearLevel = 1;

    studArray.stud[1].ID = 2;
    strcpy(studArray.stud[1].LName, "Panganiban");
    strcpy(studArray.stud[1].course, "BSIS");
    studArray.stud[1].yearLevel = 1;

    studArray.stud[2].ID = 3;
    strcpy(studArray.stud[2].LName, "Absin");
    strcpy(studArray.stud[2].course, "BSIT");
    studArray.stud[2].yearLevel = 1;

    studArray.stud[3].ID = 4;
    strcpy(studArray.stud[3].LName, "Bayer");
    strcpy(studArray.stud[3].course, "BSIT");
    studArray.stud[3].yearLevel = 1;

    studArray.stud[4].ID = 5;
    strcpy(studArray.stud[4].LName, "Arriesgado");
    strcpy(studArray.stud[4].course, "BSCS");
    studArray.stud[4].yearLevel = 1;

    studArray.count = 5;

    LinkedList studList = removeByCourse(&studArray, "BSCS");

    displayList(studList);
    printf("\n\n\n");
    displayArray(studArray);

    return 0;
}

	//create new array

	int *sorted = malloc(4 * MAX);

	for(int i = secondindex; i <= arr[0]; i++){
		sorted[i - secondindex + 1] = arr[i];
	}

	*sorted = arr[0] - secondindex + 1;

	return sorted;
}