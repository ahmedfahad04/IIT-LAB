/*
	input format:
	total coin, total value
	value of each coins...

	output format:
	Total ways of making the change
	Minimum coins
*/


#include <bits/stdc++.h>
#define N 10005
using namespace std;

int coins[N], ways[N][N], min_coin[N][N];

void dp(int n, int w){

	// initialize the first column only
	// starting from i=0 is a must!
	for(int i=0; i<=n; i++){
		ways[i][0] = 1; 
		min_coin[i][0] = 0;
	}

	// initialize the first row to calculate the min coin
	for(int i=1; i<=w; i++) min_coin[0][i] = INT_MAX;

	for(int i=1; i<=n; i++){
		
		for(int j=0; j<=w; j++){

			if(coins[i] > j){ 
				ways[i][j] = ways[i-1][j];

				// this statement is for calculating the minimum coin
				min_coin[i][j] = min_coin[i-1][j];
			}

			else{ 

				ways[i][j] = ways[i][j-coins[i]] + ways[i-1][j];

				// this statement is for calculating the minimum coin
				min_coin[i][j] = min(min_coin[i][j-coins[i]] + 1, min_coin[i-1][j]);
			}
		}
	}
}

int main(){

	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, w;
	cin >> n >> w;

	for(int i=1; i<=n; i++) cin >> coins[i];

	dp(n,w);

	cout << "Total ways of making the change: " << ways[n][w] << endl;
	cout << "Minimum coins needed to make the change: " << min_coin[n][w] << endl; 
}