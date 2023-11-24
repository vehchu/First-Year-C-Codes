/*----------------------------------------------------------------------------------------------

3. Write a C program to check whether a given number is positive or negative. Go to the editor
Test Data : 15
Expected Output :
15 is a positive number

-----------------------------------------------------------------------------------------------*/

#include <stdio.h>
int main(){
    int x;

    do{

        printf("\nEnter an integer: ");
        scanf("%d", &x);

        if(x<0){
            printf("The integer is negative.");
        }
        else{
            printf("The integer is positive!");
        }
    }

    while(x<0);

    return 0;
}