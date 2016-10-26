/* Program to search an element in a sorted and pivoted array*/
#include <stdio.h>
 
int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);
int binarySearch_recursive(int arr[], int l, int r, int x);

/* Searches an element key in a pivoted sorted array arrp[]
   of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot;
    /* without pivot, normal b_search */
    if ((pivot = findPivot(arr, 0, n-1)) == -1)
    {   printf("case1 no pivot\n");
        return   binarySearch_recursive(arr, 0, n-1, key);

    }

    if (key == arr[pivot])
        return pivot;
    
    printf("case2 pivot: %d\n", pivot);
    /* with pivot, separate two parts then b_search */
    if (arr[0] > key)
    {
        return binarySearch_recursive(arr, pivot+1, n-1, key);
    }
    else
    {
        return binarySearch_recursive(arr, 0, pivot-1, key);
    }
}

/* Function to get pivot (ascending). For array 3, 4, 5, 6, 1, 2 it returns
   3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
    int index;
    int left = low;
    int right = high;

    index = (left+right)/2;
    printf("left: %d, right: %d, index: %d\n", left, right, index);

    /* move: left -->  <--light */
    if (right < left) 
        return -1;
    if (left == right) 
        return left;    

    if (arr[index] > arr[index+1])    
        return index; 

    /* with pivot: left[0] big than any element in right part*/
    /* left < index, pivot at => */
    if (arr[index] > arr[left]) {
        printf("=>\n");
        return findPivot(arr, index+1, right);    
    }
    else {/* left >= index, pivot at <= */
        printf("<=\n");
        return findPivot(arr, left, index-1);      
    }    
}

int binarySearch_recursive(int arr[], int l, int r, int x)
{
    int index;
    int left = l;
    int right = r;

    while (left <= right)
    {      
        index = (left + right)/2;       
        if (arr[index] == x)
        {
            return index;
        }
        else if (arr[index] > x)
        {
            return binarySearch_recursive(arr, left, index - 1, x);   
        }
        else if (arr[index] < x)
        {
            return binarySearch_recursive(arr, index + 1, right, x);   
        }                           
    }

    return -1;

}


/* Driver program to check above functions */
int main()
{
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   //int arr1[] = {0,1,2,3,4,5,6,7,8,9};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 10;
   printf("Index: %d\n", pivotedBinarySearch(arr1, n, key));
   return 0;
}

