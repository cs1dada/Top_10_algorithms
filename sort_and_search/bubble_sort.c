// C program for implementation of Bubble sort
#include <stdio.h>
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{


}


/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    //bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
