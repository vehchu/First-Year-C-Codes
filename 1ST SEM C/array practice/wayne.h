void initialize(int arr[], int* count){
    
    for(int i  = 0; i < *count; i++){
        arr[i] = 0;
    }
    *count = 0;
    
}

void display(int arr[], int count){

    if(count == 0){
        printf("List is empty");
    }

    else{
        for(int i = 0; i < count; i++){     
            printf("%d ", arr[i]);  
        }
    }     
}

int searchElem(int arr[], int count, int elem){

    int index = -1;
    int i = 0;

        do{
            if(arr[i] == elem){
            index = i;
            }
                i++;
            }

        while(i < count && index == -1);

    printf("%i", index);

    return index; 
}

int insertLast(int arr[], int* count, int elem){

    if(*count > 10){
        printf("List is full");

        return 0;
    }
    
    else{
        do{
            arr[*count] = elem;

            *count += 1;

            return 1;
        }

        while(elem != searchElem(arr, *count, elem));
        
        if(elem == searchElem(arr, *count, elem)){
            printf("Element already exists");
        }

    }
}

int insertFirst(int arr[], int* count, int elem){

    int n = 0;

    if(*count > 10){
        printf("List is full");

        return 0;
    }

    else{
        do{
            for(int i = *count; i >= n; i--){
                arr[i] = arr[i-1];
            }

            arr[0] = elem;
            *count += 1;

            return 1;
        }

        while(elem != searchElem(arr, *count, elem));
        
        if(elem == searchElem(arr, *count, elem)){
            printf("Element already exists");
        }
    }
	
}

int insertAtPos(int arr[], int* count, int elem, int pos){

    if(*count > 10){
        printf("List is full");

        return 0;
    }

    else{
        do{
            for (int i = *count; i >= pos; i--)
            arr[i] = arr[i - 1];

            arr[pos + 1] = elem;
            *count += 1;

            return 1;
        }

        while(elem != searchElem(arr, *count, elem));
        
        if(elem == searchElem(arr, *count, elem)){
            printf("Element already exists");
        }
    }
	
}

int removeLast(int arr[], int* count){

    if(*count <= 0){
        printf("List is empty");

        return 0;
    }
    
    else{
            for (int i = *count; i <= 1; i--)
            arr[i] = arr[i - 1];
            arr[*count] = 0;

            *count -= 1;

            return 1;
        }
	
}

int removeFirst(int arr[], int* count){

    if(*count <= 0){
        printf("List is empty");

        return 0;
    }

    else{

        arr[0] = 0;

        for(int i = 0; i < *count - 1 ; i++)
            arr[i] = arr[i+1];
       
        *count -= 1;

        return 1;
    }
       
}

int removeAtPos(int arr[], int* count, int pos){

    if (pos >= *count+1){  
        printf (" \n Deletion is not possible in the array.");  
    }  

    else{
	    if(*count <= 0){
            printf("List is empty");

        return 0;
        }

        else{

            arr[pos] = 0;
      
            for (int i = pos; i < *count - 1 ; i++)
                arr[i] = arr[i + 1];

            *count -= 1;

            return 1;
        
        }

    }
}

int removeElem(int arr[], int* count, int elem){
    
    if (elem != searchElem(arr, *count, elem)){  
        printf (" \n Element does not exist");  
    }  

    else{
	    if(*count <= 0){
            printf("List is empty");

        return 0;
        }

        else{
            
            elem = 0;
      
            for (int i = elem; i < *count - 1 ; i++)
                arr[i] = arr[i + 1];

            *count -= 1;

            return 1;
        
        }

    }
	
}

int getRange(int arr[], int count){
	
}

int* getEven(int arr[], int count){
	
}

int isSortedAscending(int arr[], int count){
	
}

void moveSmallestToFirst(int array[], int count){
	
}

void sortArray(int arr[], int count){
	
}
