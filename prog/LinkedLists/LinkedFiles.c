#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int month;
    int day;
    int year;
}date;

typedef struct{
    char name[50];
    int age;
    char gender;
    int idNum;
    date bday;
}student;

typedef struct node{
    student person;
    struct node *link;
} List, *NodePtr;

NodePtr create_node();

bool insertFrontLL(List **head, student item);
bool insertRearLL(List **head, student item);
bool insertAtLL(List **head, student item, int position);
bool insertSortedLL(List **head, student item);

bool deleteFrontLL(List **head);
bool deleteRearLL(List **head);
bool deleteAtLL(List **head, int position);
bool deleteItemLL(List **head, int ID);
bool deleteAllItemLL(List **head, int ID);

void displayListLL(List *head);

bool searchItemLL(List *head, int ID);
int getPositionOfItemLL(List *head, int ID);

void readFile(FILE *fp, List* head, int count);
void writeFile(FILE *fp, List *head, int count);
void updateFile(FILE *fp, List *head, int count);

int main(int argc, char*argv[]){
    
    FILE *fp = fopen("LinkedFiles.txt", "w+");
    NodePtr head = NULL;

    student newStud;

    int action=0, value=0, pos=0, ID, count=0; 

    question: 
    
    printf("\n\t [1] insertFront");
    printf("\n\t [2] insertRear");
    printf("\n\t [3] insertAt");
    printf("\n\t [4] deleteFront");
    printf("\n\t [5] deleteAt");
    printf("\n\t [6] deleteRear");
    printf("\n\t [7] deleteItem");
    printf("\n\t [9] displayList");
    printf("\n\t [10] searchItem");
    printf("\n\t [11] getPositionOfItem");
    printf("\n\t [12] insertSorted");
    printf("\n\t [13] deleteAllItem");
    printf("\n\t [14] writeFile");
    printf("\n\t [15] readFile");
    printf("\n\t [0] END\n");
    printf("\n\tWhat would you like to do? : ");
    fflush(stdin);
    scanf("%d", &action);
    printf("\n\n");
    system("pause");
	system("cls");

    switch(action){
        case 0:
            printf("Thank you and goodbye !");
            fclose(fp);
        break;

        case 1: 
            printf("\n\tPerforming insertFront...\n");
            printf("\n\tInsert all the necessary items: ");

            printf("\n\t\tID: ");
            scanf("%d", &newStud.idNum);
            printf("\n\t\tNAME: ");
            fflush(stdin);
            fgets(newStud.name, sizeof(newStud.name), stdin);
            fflush(stdin);
            fflush(stdin);
            printf("\n\t\tAGE: ");
            scanf("%d", &newStud.age);
            fflush(stdin);
            printf("\n\t\tGENDER: ");
            scanf("%c", &newStud.gender);
            fflush(stdin);
            printf("\n\t\tBirthday MM/DD/YYYY: ");
            scanf("%d %d %d", &newStud.bday.month, &newStud.bday.day, &newStud.bday.year);
            fflush(stdin);

            insertFrontLL(&head, newStud);
            count++;
            printf("\n\t\tSUCCESS!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

       case 2: 
           printf("\n\tPerforming insertRear...");

           printf("\n\t\tID: ");
           scanf("%d", &newStud.idNum);
           printf("\n\t\tNAME: ");
           fflush(stdin);
           fgets(newStud.name, sizeof(newStud.name), stdin);
           fflush(stdin);
           fflush(stdin);
           printf("\n\t\tAGE: ");
           scanf("%d", &newStud.age);
           fflush(stdin);
           printf("\n\t\tGENDER: ");
           scanf("%c", &newStud.gender);
           fflush(stdin);
           printf("\n\t\tBirthday MM/DD/YYYY: ");
           scanf("%d %d %d", &newStud.bday.month, &newStud.bday.day, &newStud.bday.year);
           fflush(stdin);

           insertRearLL(&head, newStud);
           count++;
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 3: 
           printf("\n\tPerforming insertAt...");
       
           printf("\n\t\tID: ");
           scanf("%d", &newStud.idNum);
           printf("\n\t\tNAME: ");
           fflush(stdin);
           fgets(newStud.name, sizeof(newStud.name), stdin);
           fflush(stdin);
           fflush(stdin);
           printf("\n\t\tAGE: ");
           scanf("%d", &newStud.age);
           fflush(stdin);
           printf("\n\t\tGENDER: ");
           scanf("%c", &newStud.gender);
           fflush(stdin);
           printf("\n\t\tBirthday MM/DD/YYYY: ");
           scanf("%d %d %d", &newStud.bday.month, &newStud.bday.day, &newStud.bday.year);
           fflush(stdin);

           printf("\n\tWhere would you like to insert: ");
           scanf("%d", &pos);

           fflush(stdin);
           insertAtLL(&head, newStud, pos);
           count++;
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 4: 
           printf("\n\tPerforming deleteFront...");
           deleteFrontLL(&head);
           count--;
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

        case 5: 
           printf("\n\tPerforming deleteAt...");
           printf("\n\tWhat position would you like to delete: ");
           scanf("%d", &pos);
           deleteAtLL(&head, pos);
           count--;
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 6: 
           printf("\n\tPerforming deleteRear...");
           deleteRearLL(&head);
           printf("\n\t\tSUCCESS!\n");
           count--;
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 7: 
           printf("\n\tPerforming deleteItem...");
           printf("\n\tEnter the ID number of the student you want to delete: ");
           scanf("%d", &ID);
           deleteItemLL(&head, ID);
           printf("\n\t\tSUCCESS!\n");
           count--;
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

        case 9: 
            printf("\n\tPerforming displayList...");
            displayListLL(head);
            printf("\n\t\tSUCCESS!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

       case 10: 
           printf("\n\tPerforming searchItem...");
           printf("\n\t\tSUCCESS!\n");
           printf("\n\tEnter ID you'd like to search: ");
           scanf("%d", &ID);
           searchItemLL(head, ID);
           printf("\n\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 11: 
           printf("\n\tPerforming getPositionOfItem...");
           printf("\n\tWhat item would you like to get the position of: ");
           scanf("%d", &ID);
           pos = getPositionOfItemLL(head, ID);
           printf("\n\tItem is at position [%d]", pos);
           printf("\n\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 12:
           printf("\n\tPerforming insertSorted...");

           printf("\n\t\tID: ");
           scanf("%d", &newStud.idNum);
           printf("\n\t\tNAME: ");
           fflush(stdin);
           fgets(newStud.name, sizeof(newStud.name), stdin);
           fflush(stdin);
           fflush(stdin);
           printf("\n\t\tAGE: ");
           scanf("%d", &newStud.age);
           fflush(stdin);
           printf("\n\t\tGENDER: ");
           scanf("%c", &newStud.gender);
           fflush(stdin);
           printf("\n\t\tBirthday MM/DD/YYYY: ");
           scanf("%d %d %d", &newStud.bday.month, &newStud.bday.day, &newStud.bday.year);
           fflush(stdin);
           
           insertSortedLL(&head, newStud);
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

       case 13:
           printf("\n\tPerforming deleteAllItem...");
           printf("\n\t\tEnter ID occurences you want to delete: ");
           scanf("%d", &newStud.idNum);
           deleteAllItemLL(&head, ID);
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;

        case 14:
           printf("\n\tPerforming writeFile...");
           writeFile(fp, head, count);
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;   

       case 15:
           printf("\n\tPerforming readFile...");
           readFile(fp, head, count);
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;    

       case 16:
           printf("\n\tPerforming updateFile...");
           updateFile(fp, head, count);
           printf("\n\t\tSUCCESS!\n");
           printf("\n\n");
           system("pause");
           system("cls");
           goto question;
       break;  
    }

}

NodePtr create_node() {
	
    student item;
	
   NodePtr new_node = (NodePtr)malloc(sizeof(List));
   new_node->person = item;
   new_node->link = NULL;
   
   return new_node;
}


bool insertFrontLL(List **head, student item){
	
	//1. create a new node
    NodePtr temp = (NodePtr)malloc(sizeof(List));  
  
    //2. populate values
    temp->person = item;    //value is the data that will be inserted

    //3. save value of new nodes link at address of previous first node
    temp->link = *head;

    //4. point head to new address of created node
    *head = temp;
	
}

bool insertRearLL(List **head, student item){

   NodePtr temp = *head; 
   NodePtr newNode = (NodePtr)malloc(sizeof(List)); 

    newNode->person = item;

    if(*head == NULL){ 
        *head = newNode;
        newNode->link = NULL;
    }
    else{
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode; 
        newNode->link = NULL;
    }
    
}

bool insertAtLL(List **head, student item, int position){
   
   //1. create traversal node
   //2. create temp node to store insert item

   NodePtr trav = *head; 
   NodePtr temp = (NodePtr)malloc(sizeof(List)); 

   temp->person = item;

   //3. traverse
   if(position == 0){
        temp->link = (*head);
        *head = temp;
   }
   else{
        for(int i = position-1; trav != NULL && i > 0; --i){
                trav = trav->link;
        } 
        temp->link = trav->link;
        trav->link = temp;
   }

}

bool insertSortedLL(List **head, student item){

    //1. create trav node
    //2. create new storage node

    NodePtr trav = *head; 
    NodePtr temp = (NodePtr)malloc(sizeof(List)); 

   temp->person = item;
    //3. check each node if its correct pos 

    while(trav!=NULL){
        if(trav->link->person.idNum > item.idNum){
            temp->link = trav->link;
            trav->link = temp;
            return true;
        }
    }
}

bool deleteFrontLL(List **head){
   
   *head = (*head)->link;

}

bool deleteRearLL(List **head){

    NodePtr temp = *head;

    if(*head == NULL){ 
        return false;
    }
    else{
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        temp->link = NULL;
    }

}

bool deleteAtLL(List **head, int position){

   NodePtr trav = *head; 

    if(position == 0){
        *head = (*head)->link;
    }
    else{
        for(int i = position-1; trav != NULL && i > 0; --i){
            trav = trav->link;
        }
        trav->link = trav->link->link;
    }

}

bool deleteItemLL(List **head, int ID){

    NodePtr trav = *head; 

     while(trav!=NULL){
        if(trav->person.idNum == ID){
            trav->link = trav->link->link;
            return true;
        }
    }
   
}

bool deleteAllItemLL(List **head, int ID){

    NodePtr trav = *head; 

     while(trav!=NULL){
        if(trav->person.idNum == ID){
            trav->link = trav->link->link;
        }
    }
   
}

void displayListLL(List *head){
    
    printf("\n\t-------- CURRENT LIST --------");
    for(; head != NULL ; head = head->link){
        printf("\n\t[Student %d]", head->person.idNum);
        printf("\n\t Name: %s", head->person.name);
        printf("\t Age: %d", head->person.age);
        printf("\n\t Gender: %c", head->person.gender);
        printf("\n\t Birthday: %d/%d/%d \n", head->person.bday.month, head->person.bday.day, head->person.bday.year);
    }
}

bool searchItemLL(List *head, int ID){

    NodePtr list = head;

    while(list != NULL){
        if(list->person.idNum == ID){
            printf("\nStudent %d exists in the system\n", ID);
            return true;
        }
        else{
           list = list->link;
       }
    }
    printf("\nStudent %d does not exist in the system\n", ID);
    return false;
}

int getPositionOfItemLL(List *head, int ID){

    NodePtr list = head;

    int pos = 0;

    while(list != NULL){
        if(list->person.idNum == ID){
            pos++;
            return pos; 
        }
        else{
            pos++;
            list = list->link;
        }
    }

}
 

void readFile(FILE *fp, List* head, int count){

    List* buffer;
    
    if(fp == NULL || count == 0){
        printf("\nThere is an error with the file");
    }

    fread(buffer, sizeof(List), count, fp);
    displayListLL(buffer);
    
}

void writeFile(FILE *fp, List* head, int count){

    List* buffer = head;

    fseek(fp, 0, SEEK_SET);

    while(buffer != NULL || count != 0){
        fwrite(buffer, sizeof(List), count, fp);
        buffer = buffer->link;
    }
   //printf("%d", count);

}


void updateFile(FILE *fp, List* head, int count){

    List* buffer = head;

    fseek(fp, 0, SEEK_END);
    fwrite(buffer, sizeof(List), count, fp);
    fseek(fp, 0, SEEK_SET);

}