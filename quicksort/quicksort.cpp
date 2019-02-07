#include<iostream>
using namespace std;

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
	//int i = (low - 1);  // Index of smaller element
    int i = low;  // Index of smaller element
    cout<<endl<<"Partitioning the array - "<<endl;
	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
        cout<<"Index i - "<<i<<", arr[j] - "<<arr[j]<<", Pivot - "<<pivot<<endl;
		if (arr[j] < pivot)
		{
			//i++;    // increment index of smaller element
            cout<<arr[i]<<" "<<arr[j]<<endl;
			swap(&arr[i], &arr[j]);
            i++;
		}
	}
	swap(&arr[i], &arr[high]);
    printArray(arr,6);
	return (i);
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main(){
	cout<<"Test program for quick sort"<<endl;
	int arr[] = {22,20,6,10,12,22};
    //int arr[] = {8,10,2,7,5};
	int n = sizeof(arr) / sizeof(int);
	printArray(arr,n);
	quickSort(arr,0,n-1);
	cout<<"Sorted Array is - "<<endl;
	printArray(arr,n);
	return 0;
	
}
