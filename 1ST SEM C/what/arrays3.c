#include <stdio.h>
int main(){

    int num;
    printf("Enter an integer: ");
    scanf("%i", &num);
    printf("\nMultiplication Table\n");
    
    int n[num][num];

    int x = 1;
    int y = 1;
    while(x<num+1){
        y = 1;
        while(y<num+1){
            n[x-1][y-1] = y*x;
            y++;
        }
        x++;
    }

    x = 0;
    while(x<num){
        y = 0;
        while(y<num){
            printf("%i    ",n[x][y] );
            y++;
        }
        printf("\n");
        x++;
    }
    
    
}