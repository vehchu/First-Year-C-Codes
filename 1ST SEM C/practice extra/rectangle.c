/* 
Write a program that accepts two nonnegative integers x and y. The program shall display a rectangle with x columns and y 
rows repeatedly printing the product of x and y. In addition, if the figure formed
is a square, display "Nice".

Sample input 1:
2 4

Sample output 1:
88
88
88
88

Sample input 2:
3 3

Sample output 2:
999
999
999
Nice
 */

#include <stdio.h>
int main(){

    int x=0, y=0, r;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    r=x*y;

    for(int row=0 ; row<y ; row++ ){
        for (int col=0 ; col<x ; col++){
        printf("%d", r);}
        printf("\n");
    }

        if(x == y){
            printf("Nice");
            }

return 0; 
}