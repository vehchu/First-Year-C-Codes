#include <stdio.h>
#include <string.h>

int main(){
    int n=0, i;
    char gift[n][50];
    char temp[50];
    

        printf("Enter the number of gifts: ");
        scanf("%d", &n);
            printf("");
    
                for(i = 0; i < n; i++){
                    printf("Gift %d: ", i+1);
                    scanf("%s", &gift[i]);
                }

                for(i = 0; i < n; i++)
                    for(int j = 0; j < n; j++){
                        if(strcmp(gift[j] ,gift[j+1]) > 0){
                            strcpy(temp, gift[j]);
                            strcpy(gift[j], gift[j+1]);
                            strcpy(gift[j+1], temp);
                            }
                        }
                

                printf("\nSorted Gifts:\n");
    
                for(i = 0; i < n; i++){
                    printf("Gift %d: %s\n", i+1, gift[i+1]);
                    }
    
return 0;
}