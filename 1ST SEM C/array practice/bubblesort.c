#include <stdio.h>
int main(){

    int number[50];
    int max_num, temp;
    int i, j;

    printf("Enter size of list: ");
    scanf("%d", &max_num);

    printf("Enter numbers: ");
    
    for(i = 0; i < max_num; i++){
        scanf("%d", &number[i]);
    }

    for(i = 0; i < max_num - 1; i++){
        for(j = i + 1; j < max_num - 1; j++){
            if(number[i] < number[j]){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }

    printf("Sorted Numbers (high to low): ");

    for( i = 0; i < max_num; i++){
        printf("%d ", number[i]);
    }

    printf("\nSorted Numbers (low to high): ");

    for( i = max_num ; i != 0; i--){
        printf("%d ", number[i]);
    }

return 0; 

}



