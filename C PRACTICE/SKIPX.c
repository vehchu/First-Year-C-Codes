/*
Create a function with two arguments that will return an array of the first n multiples of x.

Assume both the given number and the number of times to count will be positive numbers greater than 0.

Return the results as an array or list (depending on language).

Examples
countBy(1,10)  should return  {1,2,3,4,5,6,7,8,9,10}
countBy(2,5)  should return {2,4,6,8,10}
*/

#include <stdio.h>

// ----------- FUNCTION DECLARATION -----------

int multiplesX(int x, int n);

// ----------- FUNCTION DECLARATION -----------

 int main(){

 // VARIABLES

 int x, n;

 // FUNCTIONS

 printf("Count by ");
 scanf("%d %d", &x, &n);


 multiplesX(x, n);

 return 0;

 }

// ----------- FUNCTION CREATION LAB -----------

int multiplesX(int x, int n){


    for(int i = 0; i <= n; i++){
        if( i % x == 0 && i > 0){
            printf("%d ", i);
        }
    }

    return x;
}