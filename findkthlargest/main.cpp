#include<iostream>
using namespace std;


// QuickSelect Algorithm

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = low;
    cout<<endl<<"Partitioning the array - "<<endl;
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is larger than or
        // equal to pivot
        if (arr[j] >= pivot)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            swap(&arr[i], &arr[j]);
            i++; // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]);
    printArray(arr,6);
    return (i);
}

int findKth(int k, int arr[], int size){
    int left = 0,right = size - 1;
    
    while(left<=right){
        int pivot_idx = partition(arr,left,right);
        
        if(pivot_idx == k - 1){
            return(arr[pivot_idx]);
        } else if (pivot_idx > k - 1){
            right = pivot_idx - 1;
        } else{
            left = pivot_idx + 1;
        }
    }
    return 0;
}

int main(){
    cout<<"Program to find the Kth Largest element in array"<<endl;
   // int arr[] = {8,20,6,10,12,15};
    int arr[] = {3,2,1,5,6,4};
    int n = sizeof(arr) / sizeof(int);
    cout<<"Length - "<<n<<endl;
    printArray(arr,n);
    int k = findKth(2, arr, n );
    cout<<"Kth Largest element in Array is - "<<k<<endl;
    return 0;
    
}



