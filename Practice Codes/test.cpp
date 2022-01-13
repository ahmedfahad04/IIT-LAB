#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long int
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif


	pair<int, int> p[100];
	int n;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> p[i].f >> p[i].s;
	}

	for(int i=0; i<n-1; i++){

		for(int j=0; j<n-i-1; j++){

			if(p[j].s>p[j+1].s){

				swap(p[j], p[j+1]);
			}
		}
	}

	
	for(int i=0; i<n; i++){
		cout << "Start: " << p[i].f << ", End: " << p[i].s << endl;
	}

}