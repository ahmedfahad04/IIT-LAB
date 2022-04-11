/*
	### LIS using Time Efficient DP ###
	
	input format:
	size of array
	array elements....

	output format:
	Length of LIS:
	LIS: 
*/

#include <bits/stdc++.h>
#define N 1000
#define mINF -100005
using namespace std;

int L[N], L2[N], pre[N], a[N];


int LIS_FAST_DP(int n){
	
	L[0] = mINF;
	L2[0] = 0;
	pre[0] = -1;

	int len = 0;

	for(int i=1; i<=n ;i++){

		// append
		if(L[len] < a[i]){
			len++;
			L[len] = a[i];
			L2[len] = i;
			pre[i] = L2[len-1];	
		}

		// replace
		else{

			int s = 0, m;
			int h = len;

			while(s<h){
				m = floor((s+h)/2);

				if(L[m] < a[i]) s = m+1;
				else h = m;
			}

			L[s] = a[i];
			L2[s] = i;
			pre[i] = L2[s-1];
		}
	}

	return len;
}


void print (int n){ // problem

	if(pre[n] == 0){
		cout << a[n] << " ";
		return;
	}

	else{
		print(pre[n]);
		cout << a[n] << " ";
	}
}


int main(){

	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	
	int size;
	cin >> size;

	for(int i=1; i<=size; i++){
		cin >> a[i];
	}

	int ll = LIS_FAST_DP(size);

	cout << "Length of LIS: " << ll << "\nLIS: ";

	print(L2[ll]);

	cout << endl;

}
