#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long int
#define mk make_pair
using namespace std;

bool compsec(const pair<int, int> &a, const pair<int, int> &b){
	return(a.s<b.s);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif


	vector<pair<int, int>> p;

	int n;

	cin >> n;

	for(int i=0; i<n; i++){
		
		int a;
		cin >> a;
		int b;
		cin >> b;

		p.push_back(mk(a,b));
	}

	sort(p.begin(), p.end(), compsec);

	
	for(int i=0; i<n; i++){
		cout << "Start: " << p[i].f << ", End: " << p[i].s << endl;
	}

}