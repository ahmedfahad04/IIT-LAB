#include <bits/stdc++.h>
using namespace std;
int a[100];
int b[100];

void merge(int arr[], int low, int middle, int high){
    int l = low,r = middle+1,k = low ;
    
    while(l<=middle && r<=high){
        if(arr[l]<arr[r]) b[k++] = arr[l++];
        else b[k++] = arr[r++];
    }

    if(l>middle){
        while(r<=high){
            b[k++] = arr[r++];
        }
    }
    else{
        while(l<=middle){
            b[k++] = arr[l++];
        }
    }

    for(l=low;l<=high;l++) a[l] = b[l];
}

void merge_sort(int ar[], int lower, int upper){
    int mid;
    if(lower < upper){
        mid = (lower+upper)/2;

        merge_sort(ar, lower, mid);
        merge_sort(ar, mid+1, upper);
        merge(ar, lower, mid, upper);
    }
}

int main()
{
    srand(time(0));
	int i;
    int n = rand()%20;
    
    for(i=0;i<n;i++){
        a[i] = rand()%10000;
    }
    
    cout << "Before sorting...." << endl;
    for(i=0;i<n;i++){
        cout << a[i] <<" ";
    }

    
    //merge sort
    merge_sort(a,0,n);
    
	
	cout <<"\nAfter sorting...." << endl;
    for(i=0;i < n;i++){
        cout << a[i] <<" ";
    }

}
