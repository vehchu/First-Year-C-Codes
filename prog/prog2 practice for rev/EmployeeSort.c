#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct
{
    char lName[20];
    char fName[20];
    char MI;
} empName;

typedef struct
{
    int empId;
    empName empInfo;
    char pos[20];
    int years;
} companyInfo;

typedef struct
{
    companyInfo record[20];
    int ctr;
} companyRecord;

//=========================================================

    //WRITE THE CODE FOR THESE FUNCTIONS:
    
companyRecord populateList(companyRecord *record); // asks for user how many employees to input and the details of each employee
void SortYears(companyRecord *record);             // sorts the list from highest years
companyRecord *GetLoyal(companyRecord *record);    // get all employees who have served more than 10 years and create a separate list for them
companyRecord *InsertEmp(companyRecord *record);   // insert an employee
//=========================================================

void displayRecord(companyRecord record);         // display the current list
void displayLoyal(companyRecord *record);          // display the current loyal list

int main()
{
    companyRecord records;
    int value;

    records = populateList(&records); // prompt user for employee details and populate list

    printf("What do you want to do now?\n");
    printf("1 | display employee list\n2 | sort by years of service\n3 | display list of employees with 10+ years of service\n4 | insert an employee\n\n");
    scanf("%d", &value);

    switch (value)
    {
    case 1:
        printf("\n\nDisplay the employee list\n");
        displayRecord(records);
        break;

    case 2:
        printf("Sort by years of service\n");
        SortYears(&records);
        displayRecord(records);
        break;

    case 3:
        printf("Display list of employees with 10+ years of service\n");
        companyRecord *loyalList = GetLoyal(&records);
        displayLoyal(loyalList);
        break;

    case 4:
        printf("Insert an employee\n");
        companyRecord *updatedRecord = InsertEmp(&records);
        displayRecord(*updatedRecord);
        break;
    }

    return 0;
}

companyRecord populateList(companyRecord *record)
{
    int numEmployees;

    printf("How many employees do you want to input? ");
    scanf("%d", &numEmployees);

    //write the code to populate employees
    
    return *record;
}

void displayRecord(companyRecord record)
{
    printf("Current employee list:\n");
    printf("%-10s%-20s%-20s%-20s%s\n", "ID", "Last Name", "First Name", "Middle Initial", "Position", "Years of Service");
    for (int i = 0; i < record.ctr; i++)
    {
        printf("%-10d%-20s%-20s%c%-19s%-20d\n", record.record[i].empId, record.record[i].empInfo.lName,
               record.record[i].empInfo.fName, record.record[i].empInfo.MI, record.record[i].pos, record.record[i].years);
    }
}

void displayLoyal(companyRecord *record)
{
    printf("Loyal employees list:\n");
    printf("%-10s%-20s%-20s%-20s%s\n", "ID", "Last Name", "First Name", "Middle Initial", "Position", "Years of Service");
    for (int i = 0; i < record->ctr; i++)
    {
        if (record->record[i].years > 10)
        {
            printf("%-10d%-20s%-20s%c%-19s%-20d\n", record->record[i].empId, record->record[i].empInfo.lName,
                   record->record[i].empInfo.fName, record->record[i].empInfo.MI, record->record[i].pos, record->record[i].years);
        }
    }
}

void SortYears(companyRecord *record)
{

}

companyRecord *GetLoyal(companyRecord *record)
{
   
}

companyRecord *InsertEmp(companyRecord *record)
{
   
}
