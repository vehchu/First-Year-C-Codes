// even now

#include<stdio.h>

int main(){
    int n1, n2;
    int num;
    
    printf("Enter value of n1: ");
    scanf("%d", &n1);

    printf("Enter value of n2: ");
    scanf("%d", &n2);

    
    for (num = n2; num >= n1; num--)
    {
        if (num%2 == 0)
        {
            printf("%d ", num);
        }
    }
    return 0;
}