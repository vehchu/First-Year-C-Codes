#include <stdio.h>
#include <string.h>

typedef struct {
    char monthName[100];
    int monthNumber;
} month;

typedef struct {
    month birthMonth;
    int day;
    int year;
} birthday;

typedef struct {
    char firstname[50];
    char lastname[50];
    char middle;
} names;

typedef struct {
    birthday birthdate;
    names name;
} friends;

void display(friends friend_list[], int size);

//answer these:
friends findOlder(friends friend_list[], int size);


int main() {
    int n;

    printf("How many friends do you have? ");
    scanf("%d", &n);

    friends friend_list[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter name of friend %d (First name, Middle Initial, Lastname) ", 1 + i);
        scanf("%s", friend_list[i].name.firstname);
        scanf(" %c", &friend_list[i].name.middle);
        scanf("%s", friend_list[i].name.lastname);
        printf("\nEnter birthday of friend %d (MM DD YYYY) ", 1 + i);
        scanf("%s", friend_list[i].birthdate.birthMonth.monthName);
        // assigns number to month name 
        friend_list[i].birthdate.birthMonth.monthNumber = getMonthNumber(friend_list[i].birthdate.birthMonth.monthName);

        scanf(" %d", &friend_list[i].birthdate.day);
        scanf(" %d", &friend_list[i].birthdate.year);
    }

    display(friend_list, n);

    findOlder(friend_list, n);

    return 0;
}

void display(friends friend_list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\n%s %c. %s's birthday is %s %d, %d\n", friend_list[i].name.firstname,
               friend_list[i].name.middle, friend_list[i].name.lastname, friend_list[i].birthdate.birthMonth.monthName,
               friend_list[i].birthdate.day, friend_list[i].birthdate.year);
    }
}

friends findOlder(friends friend_list[], int size) {
   
}

