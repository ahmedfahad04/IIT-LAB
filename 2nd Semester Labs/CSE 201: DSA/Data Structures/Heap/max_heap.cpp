#include <iostream>
#include <math.h>
#include <stdlib.h>
#define N 100
using namespace std;

int a[N];
//1 3 5 4 6 13 10 9 8 15 17

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

void max_heap(int n){

    for (int i = (n/2)-1; i >= 0; i--) heapify(a,n,i);
}

void print(int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    puts("");
}

int main()
{
    int x, n = 0, i = 0;
    freopen("data.txt", "r", stdin);

    while (cin >> x)
    {
        a[i] = x;
        i++;
        n++;
    }

    
    cout << "MAIN TREE: " << endl;
    print(n);

    max_heap(n);
    cout << "MAX_HEAP: " << endl;
    print(n);


}
