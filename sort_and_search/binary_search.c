
#include <stdio.h>

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
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

// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch_iterative(int arr[], int l, int r, int x)
{
    int index;
    int left = l;
    int right = r;
    //{2, 3, 4, 10, 40};// 0 1 2 3 4
    //l:0, r:4, x:3, i:2(4)
    //l:0, r:1, x:3, i:0(2)
    //l:1, r:1, x:3, i:1(3) got

    while (left <= right)
    {   
        index = (left + right)/2;    
        if (arr[index] == x)
        {
            return index;
        }
        else if (arr[index] > x)
        {
            right = index - 1;   
        }
        else if (arr[index] < x)
        {
            left = index + 1;
        }                           
    }

    return -1;
}

int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};// 0 1 2 3 4
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 12;
   int result = binarySearch_recursive(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array \n")
                 : printf("Element is present at index %d \n", result);
   return 0;
}

