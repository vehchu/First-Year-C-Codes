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
friends findOlder(friends friend_list[], int size);
int getMonthNumber(char monthName[]);

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

    // display(friend_list, n);

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
    printf("\nWho is older?");

    friends oldest = friend_list[0];

    for (int i = 1; i < size; i++) { // start the loop from the second friend
        oldest = (friend_list[i].birthdate.year < oldest.birthdate.year) ? friend_list[i] :
                 (friend_list[i].birthdate.year > oldest.birthdate.year) ? oldest :
                 (friend_list[i].birthdate.birthMonth.monthNumber < oldest.birthdate.birthMonth.monthNumber) ? friend_list[i] :
                 (friend_list[i].birthdate.birthMonth.monthNumber > oldest.birthdate.birthMonth.monthNumber) ? oldest :
                 (friend_list[i].birthdate.day < oldest.birthdate.day) ? friend_list[i] :
                 (friend_list[i].birthdate.day > oldest.birthdate.day) ? oldest :
                 oldest; // if same birthdate, keep the oldest
    }

    printf("\nThe oldest one is %s", oldest.name.firstname);
    return oldest;
}

int getMonthNumber(char* monthName) {
    if (strcmp(monthName, "January") == 0) {
        return 1;
    } else if (strcmp(monthName, "February") == 0) {
        return 2;
    } else if (strcmp(monthName, "March") == 0) {
        return 3;
    } else if (strcmp(monthName, "April") == 0) {
        return 4;
    } else if (strcmp(monthName, "May") == 0) {
        return 5;
    } else if (strcmp(monthName, "June") == 0) {
        return 6;
    } else if (strcmp(monthName, "July") == 0) {
        return 7;
    } else if (strcmp(monthName, "August") == 0) {
        return 8;
    } else if (strcmp(monthName, "September") == 0) {
        return 9;
    } else if (strcmp(monthName, "October") == 0) {
        return 10;
    } else if (strcmp(monthName, "November") == 0) {
        return 11;
    } else if (strcmp(monthName, "December") == 0) {
        return 12;
    } else {
        return -1;
    }
}
