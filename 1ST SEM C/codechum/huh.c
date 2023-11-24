#include<stdio.h>

    int main(){
    int n, min;

    printf("Enter the integer: ");
    scanf("%d", &n);

    if(n>=9999 && n<=9223372036854775807){
        for(min=0;n!=0;n/=10){
            if(n%10>min){
                min=n%10;
            }
        }
        printf("Biggest digit = %d", min);
    } 
        else{
            printf("\n");
    }
    return 0;
}