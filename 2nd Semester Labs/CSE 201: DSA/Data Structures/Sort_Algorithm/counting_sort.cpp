#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int a[100];
int b[100];
int cnt[100];

void counting_sort(int size,int start, int end){
	
	
	for(int i=1;i<100;i++) cnt[i] = 0;

	
	for(int i=1;i<=size;i++) cnt[a[i]]+=1;


	for(int i=start+1;i<=end;i++) cnt[i] = cnt[i]+cnt[i-1];
	

	for(int j=size;j>=0;j--) b[cnt[a[j]]--] = a[j] ;

	
		
}


int main(){

	srand(time(0)); // ssrand() creating problem of not selecting cnt as a global variable
	int n,mi=100000,ma=0;
	cout << "Elements: "<< endl;
	n = rand()%20;
	
	for(int i=1;i<=n;i++) a[i] = rand()%200;
	
	for (int i=1;i<=n;i++){ // why i should take input from 1?? why not index=0??(****)
	mi = min(a[i],mi);
	ma = max(a[i],ma);
	}
	
	cout << "Before sorting: "<< endl;
	for (int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	puts("");
	
	counting_sort(n,mi,ma); //sort function
	
	cout << "After sorting: "<< endl;
	for (int i=1;i<=n;i++){
		cout << b[i] << " ";
	}
	puts("");
	
	
	
	
}
