#include <stdio.h>
#include <string.h>

int main(void) {
	
	char hidden[5], guess[5], stringm[5];
	int t; 
	
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++){
	    scanf("%s", &hidden);
	    scanf("%s", &guess);
	    
	    for(int j = 0; j < 5; j++){
	        if(hidden[j] == guess[j]){
	            printf("G");
	        }
	        else{
	            printf("B");
	        }
	    }
	}
	
	return 0;
}

