#include <bits/stdc++.h>
#define value first
#define wi second
using namespace std;


void fractionKnapSack(vector<pair<double,double>> valueWeightPair, double maxWeight){
	double maxProfit = 0;

	for(int i=0; i<valueWeightPair.size(); i++){

		double xi = valueWeightPair[i].wi;
		
		if(maxWeight >= xi){ 
			maxWeight -= xi;
			maxProfit += valueWeightPair[i].value * xi;
		}
		else{
			double x = min(maxWeight, abs(xi - maxWeight));
			maxWeight -= x;
			maxProfit += x * valueWeightPair[i].value;
		}

		cout << maxWeight << "---" << maxProfit << endl;

		if(maxWeight <= 0) break;
		
	}

	cout << "Maximum Profit Earned: " << maxProfit << endl;
}


int main(){

	// taking input form txt file
	freopen("input.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);   //file output.txt is opened in writing mode i.e "w"
	

	// input formate------
	// total items, total Weight of container
	// list of items' profit
	// list of items' weight


	int size;
	double maxWeight;
	cin >> size >> maxWeight;

	vector<double> benefit, weight;
	vector<pair<double,double>> valueWeightPair;

	for(int i = 0; i < size; i++){
		double x;
		cin >> x;
		benefit.push_back(x);
	}

	for(int i = 0; i < size; i++){
		double x;
		cin >> x;
		weight.push_back(x);
		valueWeightPair.push_back(make_pair(benefit[i]/x, x));
	}

	sort(valueWeightPair.rbegin(), valueWeightPair.rend());

	fractionKnapSack(valueWeightPair, maxWeight);
}