#include <iostream>
#include <math.h>

#define N 100
using namespace std;


void heapify(int arr[],int n ,int i)
{
    int largest, right, left;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    
    if (right < n && arr[right] > arr[largest]) largest = right;
    
    //if largest is not the root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr,n ,largest);
    }
    
}

void heap_sort(int a[], int size){

    for (int i = size ; i >= 0; i--) //build heap
        heapify(a, size, i); 

    for(int i = size-1; i>=0 ; i--){
        swap(a[0], a[i]); //swap the top and bootm element and reduce the array size by 1

        heapify(a,i,0); //perform heapify from 0 to ith position
    }
}

void print(int a[],int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    puts("");
}

int main()
{
    int x, n,i;
    int a[N];
    
    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter element: " ;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << "\nUnsorted Array: " << endl;
    print(a,n);

    heap_sort(a,n);
    cout << "\nSorted Array: " << endl;
    print(a,n);

    puts("");

}
