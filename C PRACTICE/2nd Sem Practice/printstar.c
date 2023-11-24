//print an 8 star

#include <stdio.h>
int main(){

    int n, bases;
    int i, j;
   
    printf("Enter size of 8 star: ");
    scanf("%d", &n);

    bases = (((n*2)-1)-3)/2;

    printf("%d", bases);
    
    printf("\n");

    for(i = 0; i < (n*2)-1; ++i){
        printf("\n");
        for(j = 0; j < n; ++j){
            if(j < 1 || j == n){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        if(i == bases || i == bases*2 || i == 0){
            printf("\n");
            for( i = 0; i < n-2; ++i){
                printf("*");
            }
        }
    }

    return 0;
}