/*Write a program that accepts two nonnegative integers a and b, and two more integers c and d. 
The program shall display consecutive integers starting from c whose interval is determined by d. 
The display shall follow a format where there will be a numbers per line which will recur for b lines. 
The display action terminates right after the final line of numbers is printed. 

Example 1: 
Input : 2 4 10 1
Output:
10 11
12 13
14 15
16 17

Example 2: 
Input : 3 3 30 -1
Output:
30 29 28
27 26 25
24 23 22


#include <stdio.h>
int main(){

    int a, b, c, d, row, col, f;

    printf("Input: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(d>0){
        for(int row=0; row<b; row++){
            for(int col=0; col<a; col++){
            printf("%d ", c);
            c++;}
            printf("\n");
        }
    }

    else{
        for(int row=0; row<b; row++){
            for(int col=0; col<a; col++){
            printf("%d ", c);
            c--;}
            printf("\n");
        }
    }

    return 0;
}

*/

//shorter and better code victorienne u are dogwater

#include <stdio.h>
int main(){

    int a, b, c, d, row, col;

    printf("Input : ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a>=0 && b>=0){
        for(int row=0; row<b; row++){
            for(int col=0; col<a; col++){
            printf("%d ", c);
            c += d;}
            printf("\n");}
    }

    return 0;
}
