#include <stdio.h>
int main(){
    int x=0, y=0, r=0, c=0, c1=0;

    printf("Enter n: ");
    scanf("%d", &x);
    y=x;

    do{
        y = y/10;
        r = x-y*10;
        
        if (r>3){
            printf("%d\n", r);
            c1++;
        }
        
        else{
            c++;
        }
        
        x=y;
    }
    
    while(y>0);

    if(c>0 && c1==0){
        printf("none");
    }
    return 0;
}

/*
#include<stdio.h>

int main(){
    int n, c;

    printf("Input integer: ");
    scanf("%d", &n);

    if(n>=0 && n<=2147483647){
        while(n!=0){
            if(n%10>3){
                printf("%d\n", n%10);
                c++;
            }
            n/=10;
        }
        if(c==0){
            printf("none");
        }
    } else{
        printf("INVALID");
    }
    return 0;
}
*/