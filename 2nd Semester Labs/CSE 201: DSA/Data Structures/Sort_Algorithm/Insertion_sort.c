#include <bits/stdc++.h>
using namespace std;


void insertion_sort(int a[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; i++)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
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

    
    insertion_sort(a, n);
    
	
	cout <<"\nAfter sorting...." << endl;
    for(i=0;i < n;i++){
        cout << a[i] <<" ";
    }
	

	
		
}
