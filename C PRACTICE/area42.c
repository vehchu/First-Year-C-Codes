#include <stdio.h>
#include <stdlib.h>

// complete the function prototype
// inputs:
// An array of three integers representing the first
// three numbers of an arithmetic sequence.
// Two integers M and N to determine the range
// of the terms to be obtained.
// Pointer to an integer count which stores the
// number of values in the new array containing
// the results
// output:
int* getSequenceTerms(int terms[], int M, int N, int* count);

void main() {
  int terms[3], M, N, count;
  int *answer;

  printf("Input first three terms: ");
  scanf("%d %d %d", &terms[0], &terms[1], &terms[2]);
  printf("Input the nth term ranges: ");
  scanf("%d %d", &M, &N);

  // complete the function call
  answer = getSequenceTerms(terms, M, N, &count);

  if (count != 0) {
    printf("{");
    for (int i = 0; i < count; i++) {
      printf("%d", answer[i]);
      if (i < count - 1) printf(" ");
    }
    printf("}");
  }

}

int* getSequenceTerms(int terms[], int M, int N, int* count) {

  int num_of_elements = N - M + 1;
  int* array = malloc(sizeof(int) * num_of_elements);

  // 1. check if it's an arithmetic sequence
  if (terms[2] - terms[1] == terms[1] - terms[0]) {

    // 1a. if it is a sequence, generate the terms
    // get the common difference
    int d = terms[1] - terms[0];

    // generate the arithmetic sequence
    int t0 = terms[0];
	
    int idx = 0;
    for (int i = 2; i <= N; i++) {
      t0 += d;
      // if the term generated is between the Mth and the Nth terms,
      if (i >= M && i <= N) {
        // store it in the array
        array[idx] = t0;
        idx++;
      }
      
    }

    *count = num_of_elements;

  } else {
    // 1b. if it's not a sequence, error out accordingly
    // i'll error out
    printf("Sequence is not valid!\n");
    // i'll say that we generated 0 terms
    *count = 0;
  }

  return array;
}
