#include <bits/stdc++.h>
#define start first
#define finish second
#define ll long long int
#define mk make_pair
using namespace std;

bool compsec(const pair<int, int> &a, const pair<int, int> &b){
	return(a.finish<b.finish);
}

vector<pair<int,int>> activity_selector (vector<pair<int,int>> data, int initial_point){

	vector<pair<int,int>> result;

	result.push_back(data[initial_point]);
	int k=initial_point;

	for(int m=initial_point+2; m<data.size(); m++){
		if(data[m].start >= data[k].finish){
			result.push_back(data[m]);
			k = m;
		}
	}

	return result;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);   //file output.txt is opened in writing mode i.e "w"
	#endif

	vector<pair<int, int>> p, ans;

	int n;

	cin >> n;

	for(int i=0; i<n; i++){

		int a, b;
		cin >> a >> b;

		p.push_back(mk(a,b));
	}

	sort(p.begin(), p.end(), compsec);



	// cout << "Before: " << endl;

	// for(int i=0; i<n; i++){
	// 	cout << "Start: " << p[i].start << ", End: " << p[i].finish << endl;
	// }

	for(int i=0; i<n; i++){

		ans = activity_selector(p, i);

		for(int i=0; i<ans.size(); i++){
			cout << "Start: " << ans[i].start << ", End: " << ans[i].finish << endl;
		}

		cout << "Total Work Done: " << ans.size() << "\n\n";
	}

}
