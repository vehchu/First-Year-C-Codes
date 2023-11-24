#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedLists.h"
#include "LinkedLists.c"

int main(int argc, char*argv[]){

    int action=0, value=0, pos=0, ID; 

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
    printf("\n\t [12] getFemale");
    printf("\n\t [13] getMale");
    printf("\n\t [14] editList");
    printf("\n\t [15] sortListAge");
    printf("\n\t [16] sortListID");
    printf("\n\t [17] sortName");
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
        break;

        case 1: 
            printf("\n\tPerforming insertFront...\n");
            printf("\n\tInsert all the necessary items: ");

            printf("\n\t\tID: ");
            scanf("%d", &newStud.person[0].idNum);
            printf("\n\t\tNAME: ");
            fflush(stdin);
            fgets(newStud.person[0].name, sizeof(newStud.person[0].name), stdin);
            fflush(stdin);
            fflush(stdin);
            printf("\n\t\tAGE: ");
            scanf("%d", &newStud.person[0].age);
            fflush(stdin);
            printf("\n\t\tGENDER: ");
            scanf("%c", &newStud.person[0].gender);
            fflush(stdin);
            printf("\n\t\tBirthday MM/DD/YYYY: ");
            scanf("%d %d %d", &newStud.person[0].bday.month, &newStud.person[0].bday.day, &newStud.person[0].bday.year);
            fflush(stdin);

            printf("\n\t\tSUCCESS!\n");
            insertFront(&stud, newStud);
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 2: 
            printf("\n\tPerforming insertRear...");

            printf("\n\t\tID: ");
            scanf("%d", &newStud.person[0].idNum);
            printf("\n\t\tNAME: ");
            fflush(stdin);
            fgets(newStud.person[0].name, sizeof(newStud.person[0].name), stdin);
            fflush(stdin);
            fflush(stdin);
            printf("\n\t\tAGE: ");
            scanf("%d", &newStud.person[0].age);
            fflush(stdin);
            printf("\n\t\tGENDER: ");
            scanf("%c", &newStud.person[0].gender);
            fflush(stdin);
            printf("\n\t\tBirthday MM/DD/YYYY: ");
            scanf("%d %d %d", &newStud.person[0].bday.month, &newStud.person[0].bday.day, &newStud.person[0].bday.year);
            fflush(stdin);

            printf("\n\t\tSUCCESS!\n");
            insertRear(&stud, newStud);
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 3: 
            printf("\n\tPerforming insertAt...");
        
            printf("\n\t\tID: ");
            scanf("%d", &newStud.person[0].idNum);
            printf("\n\t\tNAME: ");
            fflush(stdin);
            fgets(newStud.person[0].name, sizeof(newStud.person[0].name), stdin);
            fflush(stdin);
            fflush(stdin);
            printf("\n\t\tAGE: ");
            scanf("%d", &newStud.person[0].age);
            fflush(stdin);
            printf("\n\t\tGENDER: ");
            scanf("%c", &newStud.person[0].gender);
            fflush(stdin);
            printf("\n\t\tBirthday MM/DD/YYYY: ");
            scanf("%d %d %d", &newStud.person[0].bday.month, &newStud.person[0].bday.day, &newStud.person[0].bday.year);
            fflush(stdin);

            printf("\n\tWhere would you like to insert: ");
            scanf("%d", &pos);

            fflush(stdin);
            printf("\n\t\tSUCCESS!\n");
            insertAt(&stud, newStud, pos);
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 4: 
            printf("\n\tPerforming deleteFront...");
            deleteFront(&stud);
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
            deleteAt(&stud, pos);
            printf("\n\t\tSUCCESS!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 6: 
            printf("\n\tPerforming deleteRear...");
            deleteRear(&stud);
            printf("\n\t\tSUCCESS!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 7: 
            printf("\n\tPerforming deleteItem...");
            printf("\n\tEnter the ID number of the student you want to delete: ");
            scanf("%d", &ID);
            deleteItem(&stud, ID);
            printf("\n\t\tSUCCESS!\n");
            printf("\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 9: 
            printf("\n\tPerforming displayList...");
            printf("\n\t\tSUCCESS!\n");
            displayList(stud);
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
            searchItem(stud, ID);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 11: 
            printf("\n\tPerforming getPositionOfItem...");
            printf("\n\tWhat item would you like to get the position of: ");
            scanf("%d", &ID);
            pos = getPositionOfItem(stud, ID);
            printf("\n\tItem is at position [%d]", pos);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 12:
            printf("\n\tPerforming getFemale...");
            List fem = *getFemale(&stud);
            printf("\n\tFemale Only List:");
            displayList(fem);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 13:
            printf("\n\tPerforming getMale...");
            List male = *getMale(&stud);
            printf("\n\tMale Only List:");
            displayList(male);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 14:
            printf("\n\tPerforming editList...");
            printf("\n\t\tEnter the ID to edit: ");
            scanf("%d", &ID);
            printf("\n\t\t[1] Edit ID");
            printf("\n\t\t[2] Edit Name");
            printf("\n\t\t[3] Edit Gender");
            printf("\n\t\t[4] Edit Birthday");
            printf("\n\t\t[5] Edit Birthday");
            printf("\n\t\tWhat would you like to edit?: ");
            scanf("%d", &value);
            editItem(&stud, value, ID);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 15:
            printf("\n\tPerforming sortAge...");
            List sorted = *sortListAge(&stud);
            printf("\n\tSorted List by Age:");
            displayList(sorted);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 16:
            printf("\n\tPerforming sortListID...");
            List sorted1 = *sortListID(&stud);
            printf("\n\tSorted List by ID:");
            displayList(sorted1);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;

        case 17:
            printf("\n\tPerforming sortName...");
            List sorted2 = *sortName(&stud);
            printf("\n\tSorted List by Name:");
            displayList(sorted2);
            printf("\n\n\n");
            system("pause");
            system("cls");
            goto question;
        break;
    }


}