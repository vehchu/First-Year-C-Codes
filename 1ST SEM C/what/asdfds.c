#include <stdio.h>
//#include <bits/stdc++.h>

int main(){
    int arr[50][50];
    int num, size;
    int sum = 0;

    int i, j;
    for (i = 0; arr[i][j] >= 0 || arr[i][j] <= 2000; i++){
        for (j = 0; arr[i][j] >= 0 || arr[i][j] <= 2000; j++){
        printf("Enter value: ");
        scanf("%d", &arr[i][j]);
        
        //make posText function
            if (arr[i][j] >= 499){
            printf("You're off to a good start!\n");
            j++;
            }

            else if (arr[i][j] >= 999){
            printf("You're halfway through\n");
            j++;
            }

            else if (arr[i][j] >= 1499){
            printf("You're almost there!\n");
            j++;
            }

            else if (arr[i][j] == -1){
            printf("");
            j++;
            break;
            }

        }
    }

    size = sizeof(arr) / sizeof (arr[0][0]);

    //insert getSum function here

    int x;
    for (x = 0; x < size; x++){
        sum += arr[x];
    }

    if (arr[i][j] < 0){
        printf("Program was terminated. Your total sales are: %d", sum);
    } else {
        printf("Congratulations! Your total sales are: %d", sum);
    }


    return 0;
}