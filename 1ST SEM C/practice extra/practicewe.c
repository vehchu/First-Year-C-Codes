#include <stdio.h>
int main(){

    float a1, a2, a3, a4, a5, a6, a7, a8, a9, b, ave;

    printf("Enter 10 numbers: ");
    scanf("%f %f %f %f %f %f %f %f %f %f", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &b);

    ave = (a1+a2+a3+a4+a5+a6+a7+a8+a9+b)/10;

    printf("The average of those 10 numbers is %.2f", ave);

    return 0;
}