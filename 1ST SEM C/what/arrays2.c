#include <stdio.h>
#include <string.h>
#include <conio.h> 
int main()
{
  	char w1[100], w2[100], ch, x;
  	int i, l1, l2, j;
 
  	printf("Enter the first word: ");
  	gets(w1);

  	printf("Enter the second word: ");
  	gets(w2);
  
	l1 = strlen(w1);
	l2 = strlen(w2); 
	 
	 if(l1 != l2){
	    printf("not anagram");
	    exit(0);
	 }
	    
	 for (i = 0; i < l1-1; i++) {
      for (j = i+1; j < l1; j++) {
         if (w1[i] > w2[j]) {
            x  = w1[i];
            w1[i] = w1[j];
            w1[j] = x;
         }
         if (w2[i] > w2[j]) {
            x  = w2[i];
            w2[i] = w2[j];
            w2[j] = x;
         }
      }
   }   
	    
	for(i = 0; i<l1; i++) {
      if(w1[i] != w2[i]) {    
         printf("not anagram", w1, w1);
         return 0;
      }
   }    
	   	
  	printf("anagram");
  	getch();
} 