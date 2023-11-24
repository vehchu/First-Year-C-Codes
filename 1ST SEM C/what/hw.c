#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, total = 1, a, b;

    printf("Enter a number: ");
    scanf("%d", &n);

    int *num=(int*)malloc(sizeof(int)*n);

    printf("Fibonacci Numbers: ");

    for (i = 0; i < n; i++){
        if(i>1){
            num[i] = num[i-1] + num[i-2];
            printf("%d ",num[i]);
        }
        else if(i==0){
            num[i] = 0;
            printf("0 ");
        }
        else if(i==1){
            num[i] = 1;
            printf("1 ");
        }
    }

    printf("\nMiddle Number: %d",num[i/2]);
    free(num);
}