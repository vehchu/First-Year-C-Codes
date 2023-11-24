#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// complete the function prototypes
void getInputs(int arr[], int *size, char ch);
int isSubset(int A[], int B[], int Asize, int Bsize);

void main()
{
    int A[MAX], B[MAX], Asize, Bsize;
    int answer;

    getInputs(A, &Asize, 'A');
    getInputs(B, &Bsize, 'B');

    // complete the function call
    answer = isSubset(A, B, Asize, Bsize);

    // print the final lines of the display here
    printf("Is set B a subset of set A? %d", answer);
}

void getInputs(int arr[], int *size, char ch)
{
    // complete the code of the function
    printf("Input set %c size: ", ch);
    scanf("%d", size);
    printf("Input set %c elements: ", ch);
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int isSubset(int A[], int B[], int Asize, int Bsize)
{

    int i, j;
    int count;

    // 1. check if all elements of B are in A
    for (i = 0; i < Bsize; ++i)
    {
        for (j = 0; j != Asize; ++j)
        {
            if (B[i] != A[j])
            {
                count = 0;
            }
            else
            {
                count = 1;
                break;
            }
        }
    }

    return count;
}