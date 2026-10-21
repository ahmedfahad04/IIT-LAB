#include <bits/stdc++.h>
using namespace std;
int a[100];

void selection_sort(int a[], int n)
{
	int i, j, temp;

	for (i = 0; i < n; i++)
	{
		int min_id = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_id])
			{
				min_id = j;
			}
		}
		temp = a[i];
		a[i] = a[min_id];
		a[min_id] = temp;
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

    
    //selection_sort
	selection_sort(a, n);
    
	
	cout <<"\nAfter sorting...." << endl;
    for(i=0;i < n;i++){
        cout << a[i] <<" ";
    }

	

}
