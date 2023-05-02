#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int max = root;  // Initialize the root
    int lt = 2 * root + 1;  // left value
    int rt = 2 * root + 2;  // right value
    
    // If right child is larger than the max
    if (rt < n && arr[rt] > arr[max])
        max = rt;
    
    // If left child is larger than the max
    if (lt < n && arr[lt] > arr[max])
        max = lt;
        
    if (max != root) {
        swap(arr[root], arr[max]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, max);
    }
} 
  

//  heap sort
void heapSort(int arr[], int n)
{
    // Rearrange heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Get elements from heap one at a time   
    for (int j = n - 1; j >= 0; j--) {
        // Move current root to end
        swap(arr[0], arr[j]);
 
        heapify(arr, j, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int size;
   cout << "Enter the number of elements in the array: ";
   cin >> size;
   int heap_arr[size];
   cout << "Enter the elements of the array:\n";
   for (int i = 0; i < size; i++)
      cin >> heap_arr[i];

   cout<<"Input array:"<<endl;
   displayArray(heap_arr,size);

   heapSort(heap_arr, size);

   cout << "Sorted array:"<<endl;
   displayArray(heap_arr, size);
}