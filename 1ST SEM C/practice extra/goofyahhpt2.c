#include <stdio.h>

int function1(int n);  

int main()
{
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("%d", function1(num));

    return 0;
}

int function1(int n) 
{
    int sum = 0;
    int val;
    int c;

    while(n > 0){
        val = n % 10;
        n /= 10;
        sum += val;}

        if(sum >= 15){
            sum = 0;
        }
    
    return sum;
}

/*
#include <stdio.h>

int function1(int n);  

int main()
{
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("%d", function1(num));

    return 0;
}

int function1(int n) 
{
    int sum = 0;
    int val;

    while(n > 0) {
        val = n % 10;
        n /= 10;
        sum += val;

        if(sum >= 15) {
            sum = 0;
            break;
        }
    }

    return sum;
}
*/