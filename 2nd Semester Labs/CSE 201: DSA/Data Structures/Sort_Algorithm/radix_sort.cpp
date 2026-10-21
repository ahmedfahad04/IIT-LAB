#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int max_digit(int n){

    int dig = 0,j;
    while(n--){
        j = n%10;
        n/=10;
        dig++ ;
    }

    return dig;
}

void counting_sort(int arr[],int pos, int size){

    int b[100];
    int cnt[10] = {0};

    for(int i=0;i<size;i++) cnt[(arr[i]/pos)%10]++;

    for(int i=1;i<10;i++) cnt[i] = cnt[i] + cnt[i-1];

    for(int i = size-1;i>=0;i--){
        b[cnt[(arr[i]/pos)%10]-1] = arr[i];
        cnt[(arr[i]/pos)%10]--;
    }

    for(int i=0;i<size;i++) arr[i] = b[i];

}

void radix_sort(int ar[], int ns,int maxn){
    
    for(int i=1;maxn/i>0;i*=10){
        counting_sort(ar,i,ns);
    }
}

int main(){

    int a[] = {12,4,8,6,11,41,15,98,5,45,9};
    int n = sizeof(a)/sizeof(a[0]);

    int ma = 0;
    for (int i=0;i<n;i++)	ma = max(a[i],ma);

    radix_sort(a,n,ma);

    printf("Sorted array is: \n");
    for(int i=0;i<n;i++) cout << a[i] <<" ";
    
}