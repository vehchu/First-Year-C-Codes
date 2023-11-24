#include <stdio.h>

int main(){
    int score[20], scoreg, c, x, y, i;
    
    printf("Enter the number of goal-scorers: ");
    scanf("%d", &scoreg);

    //loop for input from each player
    for(c = 0; c < scoreg; c++){
        printf("Score of player #%d: ", c+1);
        scanf("%d", &score[c]);
    }

    //bubble sort: arranging the values in my currently katag array
    for(x = 0; x < scoreg - 1; x++){
        for(y = 0; y < scoreg - 1; y++){
            if(score[y] < score[y + 1]){
                i = score[y];
                score[y] = score[y + 1];
                score[y + 1] = i;
            }
        }
    }

    printf("\nHighest to lowest:\n");
    for(c = 0; c < scoreg; c++){
        printf("Player #%d: %d\n", c+1, score[c]);
    }
    

    return 0;
}