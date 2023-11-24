/*----------------------------------------------------------------------------------------------

4. Write a C program to find whether a given year is a leap year or not. Go to the editor
Test Data : 2016
Expected Output :
2016 is a leap year.

-----------------------------------------------------------------------------------------------*/

#include <stdio.h>
int main(){

    int x;

    do{
        printf("\nEnter a year: ");
        scanf("%d", &x);

        if(x%4!=0){
            printf("%d is not a leap year.", x);
        }
        else{
            printf("%d is a leap year!", x);
        }
    }
    while(x%4!=0);

    return 0;
}