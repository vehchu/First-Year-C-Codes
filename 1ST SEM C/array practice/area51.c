/* input the weight of three contestants and print out the smallest digit */

#include <stdio.h>
#define SIZE 3

int bubbleSort(int *awp, int n);
int main(){
    int arr_weight[SIZE];
    int small;

    printf("Enter the first weight: ");
    scanf("%d", &arr_weight[0]);
    printf("Enter the second weight: ");
    scanf("%d", &arr_weight[1]);
    printf("Enter the third weight: ");
    scanf("%d", &arr_weight[2]);

    //arr_weight[3] now has values from user
    bubbleSort(arr_weight, SIZE);

    return 0;
}

int bubbleSort(int *awp, int n){
    int i, j; 
    int temp;

    for (i = 0; i < n - 1; i++){
        //the sort from lowest to highest
        for (j = 0; j < n - 1; j++){
            if (*(awp) > *(awp + 1)){
            temp = *(awp);
            *(awp) = *(awp + 1);
            *(awp +1) = temp;
            }
        }
    }

    printf("The smallest weight = %d\n", temp);
}