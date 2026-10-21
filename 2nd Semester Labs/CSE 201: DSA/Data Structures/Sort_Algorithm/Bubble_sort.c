#include <stdio.h>
int a[100];
void bubble_sort(int a[], int n){
	int i,j,temp;
	
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
}

int main(){
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

    
    bubble_sort(a,n);
    
	
	cout <<"\nAfter sorting...." << endl;
    for(i=0;i < n;i++){
        cout << a[i] <<" ";
    }
	
}
