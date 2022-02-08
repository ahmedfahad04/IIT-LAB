#include <bits/stdc++.h>
#define N 10005
using namespace std;

int coins[N], ways[N][N];

int dp(int n, int w){

	// initialize the first column only
	// starting from i=0 is a must!
	for(int i=0; i<=n; i++) ways[i][0] = 1; 


	for(int i=1; i<=n; i++){
		
		for(int j=0; j<=w; j++){

			if(coins[i] > j) 
				ways[i][j] = ways[i-1][j];

			else 
				ways[i][j] = ways[i][j-coins[i]] + ways[i-1][j];
		
		}
	}

	return ways[n][w];
}

int main(){

	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, w;
	cin >> n >> w;

	for(int i=1; i<=n; i++) cin >> coins[i];

	int max_ways = dp(n,w);

	cout << "Total ways of making the coins are: " << max_ways << endl;
}