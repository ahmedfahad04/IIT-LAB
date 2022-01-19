#include <bits/stdc++.h>
using namespace std;

int main(){

	// taking input form txt file
	freopen("input.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);   //file output.txt is opened in writing mode i.e "w"

	int size, maxWeight;
	cin >> size >> maxWeight;

	vector<int> profit, weight, perWeightBenefit;

	for(int i = 0; i < size; i++){
		int x;
		cin >> x;
		profit.push_back(x);
	}

	for(int i = 0; i < size; i++){
		int x;
		cin >> x;
		weight.push_back(x);
		perWeightBenefit.push_back(x/profit[i]);
	}

	sort(perWeightBenefit.rbegin(), perWeightBenefit.rend());

	for(int i = 0; i < size; i++){
		cout << perWeightBenefit[i] << " ";
	}

	
}