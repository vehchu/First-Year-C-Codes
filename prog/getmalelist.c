#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct
{
    int age;
    char firstname[50];
    char gender;
} person;

person *birthDayList(person list[], int count);

person *getMaleList(person list[], int* count);

// getMaleList returns a new array that contains only M

int main()
{

    person arr[5];
    person *updatedList;
    person *notWomen;
    int count = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("Input age of person %d: ", i + 1);
        scanf("%d", &arr[i].age);
        printf("Input first name of person %d: ", i + 1);
        scanf("%s", &arr[i].firstname);
        printf("Input gender of person %d: ", i + 1);
        scanf(" %c", &arr[i].gender);
    }

    printf("\n\nBIRTHDAY LIST\n\n");

    updatedList = birthDayList(arr, count);

    for (int i = 0; i < count; i++)
    {
        printf("%s %d\n", updatedList[i].firstname, updatedList[i].age);
    }

    printf("\n\nMALE LIST\n\n");

    notWomen = getMaleList(arr, &count);

    for (int i = 0; i < count; i++)
    {
        printf("%s %c\n", notWomen[i].firstname, notWomen[i].gender);
    }

    free(notWomen);
}

person *birthDayList(person list[], int count)
{
    person *returnArr;

    returnArr = (person *)malloc(sizeof(person) * count);

    for (int i = 0; i < count; i++)
    {
        returnArr[i] = list[i];
        returnArr[i].age++;
    }

    return returnArr;
}

person *getMaleList(person list[], int *count)
{

    person *newArr;

    newArr = (person *)malloc(sizeof(person) * (*count));

    int j = 0;

    for (int i = 0; i < (*count); i++)
    {
        if (list[i].gender == 'M' || list[i].gender == 'm')
        {
            newArr[j] = list[i];
            j++;
        }
    }

    return newArr;
}