#include <bits/stdc++.h>
#define value first
#define wi second
using namespace std;

map<double,int> itemID;


void fractionKnapSack(vector<pair<double,double>> valueWeightPair, double maxWeight){
	double maxProfit = 0;

	for(int i=0; i<valueWeightPair.size(); i++){

		// weight of each item (wi)
		double xi = valueWeightPair[i].wi;
		

		// check if the item weight is less or equal to Max weight
		if(maxWeight >= xi){ 

			// if conditoin satisfys then proceed to adding benefits and 
			// updating the maxWeight value
			maxWeight -= xi;
			maxProfit += valueWeightPair[i].value * xi;
		}
		else{
			
			// if condition doesn't satisfy then the minimum weight
			// and calculate the remainig benefit
			xi = min(maxWeight, abs(xi - maxWeight));
			maxWeight -= xi;
			maxProfit += xi * valueWeightPair[i].value;
		}

		cout << xi << " ml of item " << itemID[valueWeightPair[i].value] <<  " = " << valueWeightPair[i].value*xi << "$" << endl;

		// when item weight exceeds Max weight the loop terminates 
		if(maxWeight <= 0) break;
		
	}

	cout << "\nMaximum Benefit: " << maxProfit << "$" <<endl;
}


int main(){

	// taking input form txt file
	freopen("input.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);   //file output.txt is opened in writing mode i.e "w"
	

	// input formate------
	// total items, total Weight of the container
	// list of items' profit
	// list of items' weight


	int size;
	double maxWeight;

	//cout << "Enter item size: ";
	cin >> size;

	//cout << "Enter Max Weight: ";
	cin >> maxWeight;

	vector<double> benefit, weight;
	vector<pair<double,double>> valueWeightPair;
	

	// taking input of list of benefit
	//cout << "Enter items' benefits: ";
	for(int i = 0; i < size; i++){
		double x;
		cin >> x;
		benefit.push_back(x);
	}


	// taking input of list of weights
	//cout << "Enter items' weights: ";
	for(int i = 0; i < size; i++){
		double x;
		cin >> x;
		weight.push_back(x);
		valueWeightPair.push_back(make_pair(benefit[i]/x, x));
		itemID[benefit[i]/x] = i+1;
	}


	// displaying primary information
	cout << "Total Item: " << size << endl;
	cout << "Max Weight: " << maxWeight << endl;

	cout << "Items:		 ";
	for(int i = 0; i < size; i++){
		cout << i+1 << " ";
	}

	cout << "\nBenefit:     ";
	for(int i = 0; i < size; i++){
		cout << benefit[i] << " ";
	}

	cout << "\nWeights:	 ";
	for(int i = 0; i < size; i++){
		cout << weight[i] << " ";
	}

	cout << "\nUnit Weight: ";
	for(int i = 0; i < size; i++){
		cout << valueWeightPair[i].value << " ";
	}

	cout << "\n\n";


	// sort the array so that we can pick the most valued ratio
	// to ensure best pick
	sort(valueWeightPair.rbegin(), valueWeightPair.rend());


	// perform fractionKnapSack
 	fractionKnapSack(valueWeightPair, maxWeight);
}