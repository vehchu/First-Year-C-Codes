/*----------------------------------------------------------------------------------------------

1. Write a C program to accept two integers and check whether they are equal or not.
Test Data : 15 15
Expected Output :
Number1 and Number2 are equal

-----------------------------------------------------------------------------------------------*/

#include <stdio.h>
int main(){

    int x, y;

        do{

        printf("Enter two integers: ");
        scanf("%d %d", &x, &y);

        if(x!=y){
            printf("The two integers are not equal!\n");
        }
        
        else{
                printf("The two integers are equal!");
            } 
        }

        while(x!=y);

    return 0;
}