/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int size)
{
    int zeroIndex = 0;
    int oneIndex = 0;
    int twoIndex = size -1;
    
    //for(int i = 0; i < size, oneIndex <= twoIndex; i++)
    while(oneIndex <= twoIndex)
    {
        switch(arr[oneIndex])
        {
            case 0:
                  swap(&arr[zeroIndex], &arr[oneIndex]);
                  zeroIndex++;
                  oneIndex++;
                  break;
            case 1:
                  oneIndex++;
                  break;
            case 2:
                  swap(&arr[oneIndex], &arr[twoIndex]);
                  twoIndex--;
                  break;
        }
    }
}

int main()
{
    int foo[30] = {2,2,1,0,1,0,1,1,0,2,2,1,1,1,2,0,0,1,1,0,1,0,1,2,0,0,0,1,1,2};
    
    sortArray(foo, 30);
    
    for(int i = 0; i < 30; i++)
    {
        printf(" %d ", foo[i]);
    }
    return 0;
}
