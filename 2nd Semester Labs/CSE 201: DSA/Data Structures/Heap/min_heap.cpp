#include <iostream>
#include <math.h>

#define N 100
using namespace std;

//1 3 5 4 6 13 10 9 8 15 17 test case

void heapify(int arr[],int n ,int i)
{
    int smallest, right, left;
    smallest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    
    //if smallest is not the root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(arr,n ,smallest);
    }
    
}

void min_heap(int a[],int n){

    for (int i = n; i >= 0; i--) heapify(a,n,i);
}

void print(int a[],int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    puts("");
}

int main()
{
    int x, n = 0, i = 0;
    int a[N];

    // freopen("data.txt", "r", stdin); 

    cout << "Enter elements: " << endl;
    while((cin >> x)){ //taking input until EOF is pressed
        a[i] = x;
        i++;
        n++;
    }

    
    cout << "\nMAIN TREE: " << endl;
    print(a,n);

    min_heap(a,n);
    cout << "\nMIN_HEAP: " << endl;
    print(a,n);

    puts("");

}
