#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs with pointers and nested structures

// NESTED STRUCTS - structs that also have members that use a data-type that is another structure

/* typedef struct{
    studentInfo *studentList;
    char class[50];
}classList; */

typedef struct
{
    int month;
    int date;
    int year;
} bday;

typedef struct{
    char schoolName[50];
    int yrLvl;
} schoolInfo;

typedef struct
{
    char name[50];
    int age;
    bday birthday;
    schoolInfo schoolData;
} studentInfo;

/* void structPointerFunction(studentInfo *student)
{

    // student->age = 30 == (*student).age = 30
    // arrow is only for pointer structs

    strcpy((*student).name, "Patrick");
    printf("Print inside Function: ");
    printf("%s -- %d\n\n", (*student).name, (*student).age);

    

                THIS IS PASS BY VALUE

        (strcpy(student.name, "Patrick");
        student.age=30;
        printf("Print inside Function: ");
        printf("%s -- %d\n\n", student.name, student.age);

    
} */

int main()
{

    studentInfo student1;

    //studentInfo *studentPtr = &student1;

    strcpy(student1.name, "Ean");
    student1.age = 25;

    student1.birthday.month=1;
    student1.birthday.date=31;
    student1.birthday.year=1996;

    strcpy(student1.schoolData.schoolName, "USC");
    student1.schoolData.yrLvl=5;

    printf("%s -- %d -- %d-%d-%d -- %s - %d\n\n", student1.name, student1.age, student1.birthday.month, student1.birthday.date, student1.birthday.year, student1.schoolData.schoolName, student1.schoolData.yrLvl );

    //structPointerFunction(&student1);

   /*  printf("Print inside Main: ");
    printf("%s -- %d\n\n", student1.name, student1.age); */
}