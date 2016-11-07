#include <stdio.h>
void printArray(int arr[], int size);

// swap
void swap(int* a, int* b)
{
    int *element1 = a;
    int *element2 = b;   
    
    *element1 = *element1 ^ *element2;
    *element2 = *element1 ^ *element2;
    *element1 = *element1 ^ *element2;  
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
//max heap
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left_child;
    int right_child;

    left_child = i*2+1;
    right_child = i*2+2;
    printf("root:%d left:%d right:%d size:%d \n", i, left_child, right_child, n-1);
    
    if ( left_child <= n-1 && arr[largest] < arr[left_child])
        largest = left_child;
    
    if ( right_child <= n-1 && arr[largest] < arr[right_child])
        largest = right_child;

    printf("largest: %d\n",largest);
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }

}


// main function to do heap sort
void heapSort(int arr[], int n)
{
    int i;   
    /* init array (from last parent) */
    for (i= n/2-1; i>=0; i--)
    {
        heapify(arr, n, i); 
        printArray(arr, n);
        printf("\n");
    }
  
    printf("sorting ...\n");  
    /* swap (root,last leaf), then heapify */
    for (i=n; i-1>0; i--) {
        swap(&arr[0], &arr[i-1]);
        printf("swap ");        
        printArray(arr, n); 
        heapify(arr, i-1, 0); 
        printArray(arr, n);
        printf("\n");        
    }

}



/* A utility function to print array of size n */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 
// Driver program
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("unSorted array is \n");
    printArray(arr, n);
    
    heapSort(arr, n);
    
    printf("Sorted array is \n");
    printArray(arr, n);
}

