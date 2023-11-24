/*Write a program that accepts 3 numbers a, b, and c.
The program will display numbers from a to b (inclusive) that are multiples of c.

Sample input 1: 
3 10 3

Sample output 1: 
3 6 9

Sample input 2: 
10 49 6

Sample output 2: 
12 18 24 30 36 42 48*/

#include <stdio.h>
int main(){

    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", a, b, c);

    if(a%c==0){
        printf("%d", a);
    }
        a++;
        
    return 0;
}