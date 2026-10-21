#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;

//int a[] = {100, 29, 29, 89, 159, 891, 68, 74, 12, 1, 156, 89, 78, 1, 2, 36, 5} ;
int a[100];

int part(int array[], int left, int right){
	int pivot  = array[left], l = left, r = right;
	
	while(l<r){
		while(l<right && array[l] <= pivot) l++;
		while(r>left && array[r] > pivot) r--;
		if(l<r) swap(array[l],array[r]);
	}
	swap(array[left],array[r]);
	
	return r;
}


void quick_sort(int ar[], int bam, int dan){
	if(bam<dan) {
		int p = part(a,bam,dan);
		quick_sort(a,bam,p-1);
		quick_sort(a,p+1,dan);
	}
}


int main(){

	srand(time(0)); 
	int n;
	cout << "Elements: "<< endl;
	n = rand()%10;
	
	for(int i=0;i<n;i++) a[i] = rand()%200;
	
	cout << "Before sorting: "<< endl;
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	puts("");
	
	
	quick_sort(a,0,n-1); //sort function
	
	
	cout << "After sorting: "<< endl;
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	puts("");		
	
}
