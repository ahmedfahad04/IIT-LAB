#include <bits/stdc++.h>
#define N 100
using namespace std;

int a[N];
int n=0;

void print()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    puts("");
}

void heapify(int arr[],int size ,int i)
{
    int largest, right, left;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) largest = left;
    
    if (right < size && arr[right] > arr[largest]) largest = right;
    
    //if largest is not the root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr,size ,largest);
    }
    
}

void insert(int value){
 
    a[n++] = value;
  
    for(int i=n/2-1; i>=0 ;i--){
        heapify(a,n,i);
    }
    
   
}

void delete_element(int value){
    
    int i;
    for(i=0;i<n;i++){
        if(a[i] == value) break;
    }
    swap(a[i], a[n-1]);

    n--;
    for(int i=n/2-1; i>=0 ;i--){
        heapify(a,n,i);
    }
   

}


int main(){
    int i=0,x;

    freopen("data.txt","r",stdin);
    while(cin >> x){
        a[i++] = x;
        n++;
    }

    cout << "\nBefore Insertion: ";
    print();

    insert(155);
    insert(55);
    insert(65);
    delete_element(35);
    delete_element(14);
    delete_element(155);
    delete_element(31);
    
    cout << "\nAfter Insertion: ";
    print();
    puts("");
}