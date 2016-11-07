#include <stdio.h>
void printArray(int arr[], int size);

// swap
void swap(int* a, int* b)
{
    if (a == b)
        return;
    
    int *element1 = a;
    int *element2 = b;   
    
    *element1 = *element1 ^ *element2;
    *element2 = *element1 ^ *element2;
    *element1 = *element1 ^ *element2;  
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    int left = low;
    int right = high -1;
    int pivot = high;

    if (left >= right){
        //printf("left(%d) >= right(%d)\n",left,right);
        return;
    }        
    
    //printf("before left: %d right: %d pivot: %d\n",left,right,pivot);
    while (left < right) {
        while (arr[left] < arr[pivot] && left < high)
            left++;
        while (arr[right] > arr[pivot] && right > low)
            right--;

        //printf("left: %d right: %d\n",left,right);
        if (left < right)
            swap(&arr[left], &arr[right]);
        //printArray(arr, 6);        
    }

    //printf("swap pivot to real position \n");
    swap(&arr[left], &arr[pivot]);
    //printArray(arr, 6);
    //printf("\n");
    
    quickSort(arr, low, left-1);
    quickSort(arr, left+1, high);    
}

/* A utility function to print array of size n */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {6, 3, 4, 5, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    printf("\n");
    
    quickSort(arr, 0, n-1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}


