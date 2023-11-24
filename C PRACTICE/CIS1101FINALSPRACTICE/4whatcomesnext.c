#include<stdio.h>
#include<stdlib.h>

//complete the function prototype
int *getSequenceTerms(int term[], int M, int N);

void main(){
   int terms[3], M, N, *count;
   int *answer;

   printf("Input first three terms: ");
   scanf("%d %d %d", &terms[0], &terms[1], &terms[2]);
   printf("Input the nth term ranges: ");
   scanf("%d %d",&M, &N);
   
   //complete the function call
   answer = getSequenceTerms(terms, M, N);
   
   //print the final lines of the display here
    if(answer[0] != 0){
    printf("{");
        for(int i = 0; i <  N - M + 1; i++){
            printf("%d ", *(answer+i));
        }
    printf("}");
    }
    
}

int *getSequenceTerms(int terms[], int M, int N){
   //write your code here

    int d = terms[1] - terms[0];
    int gap = N - M + 1;

    M = terms[0] + (M -1)*d; // 99 + (51-1)*-1 = 49
    N = terms[0] + (N -1)*d;
    
    int *count = malloc(sizeof(int) * gap);

   //printf("gap: %d, M: %d, N: %d", gap, M, N);
   // a_n = a_1 + (n-1)*d
   // d = common diff
   // a_1 = first term
    /*for(int i = 0; i < 3-1; i++){
        for(int j = 0; j < 3-1; j++){
            if(terms[i] > terms[j+1]){
                int temp = terms[i];
                terms[i] = terms[j+1];
                terms[j+1] = temp;
            }
        }
    }*/

   //1. find common diff (d)
   if( ((terms[1] - terms[0]) == (terms[2] - terms[1])) ){
    //2. check if sequence with nth and mth terms is valid
        //   2.a. IF VALID: find the terms n to m of the sequence
        int j = 0;
        for (int i = M; i != N; i += d){
            count[j] = i;
            j++;
        }
        count[gap - 1] = N;
    }
    else{
        //   2.b. IF NOT: print sequence is not valid inside the function
        printf("Sequence is not valid!");
        count[0] = 0;
    }

   //3. return those terms

    return count;
}
