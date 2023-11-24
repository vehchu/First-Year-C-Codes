#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct{
    int birthDate;
    int birthYear;
    int birthMonth;
}birthday;

typedef struct{
    char name[20];
    char gender;
    birthday date;
}myFriends;

myFriends genderSort (myFriends friend[]);
myFriends birthdaySort (myFriends friend[]);
void display (myFriends friend[]);

// receive all of the friends first

int main (){

    myFriends friend[MAX];
    int value;

    printf("Enter 3 friends\n\n");

    for (int i = 0; i < 5; ++i){
        printf("Friend %d = ", i+1);
        gets(friend[i].name);
        fflush(stdin);
        printf("Gender = ");
        scanf("%c", &friend[i].gender);
        fflush(stdin);
        printf("Birthday = ");
        scanf("%d %d %d", &friend[i].date.birthMonth, &friend[i].date.birthDate, &friend[i].date.birthYear);
        fflush(stdin);
        printf("\n\n");
    }

    printf("What do you want to do now?\n");
    printf("1 | display your friend list\n2 | sort by birthday\n3 | sort by gender\n\n");
    scanf("%d", &value);

    switch(value){
        case 1: 
        printf("\n\nDisplay your friend list\n");
        display(friend);
        break;

        case 2:
        printf("Sort by birthday\n");
        //birthdaySort(friend);
        break;

        case 3:
        printf("Sort by gender\n");
        break;
    }
    
}

void display (myFriends friend[]){

    for (int i = 0; i < 5; ++i){
        printf("Friend %d = %s, %c, %d-%d-%d\n", i+1, friend[i].name, friend[i].gender, friend[i].date.birthMonth, friend[i].date.birthDate, friend[i].date.birthYear);
    }
}

// myFriends birthdaySort (myFriends friend[]){

//     int min_indx;

//     for (int i = 0; i < 5; ++i){
//         min_indx = i;
//         for(int j = i+1; j < 5; ++i){
//             if(friend[j].date.birthYear < arr[min_indx])
//         }
//     }
// }
