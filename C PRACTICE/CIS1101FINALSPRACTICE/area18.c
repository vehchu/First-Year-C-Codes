int *sorting_souls(int arr[]);

index 0 = number of souls 

rest = soul scores 

arr[]

index = 2

i = 5

    5  -  2   +  1  = 4
new[i - index + 1]
new[4] = arr[5]


                     *
 0   1   2   3
[5] [1] [2] [1] [3] [1] [2] [3]
 ^   ^   ^   ^
 |   soul scores
 |
 |
#ofSouls