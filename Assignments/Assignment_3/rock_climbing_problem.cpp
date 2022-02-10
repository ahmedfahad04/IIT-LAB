#include <bits/stdc++.h>
#define N 1000
#define INF 1000005
using namespace std;

int c[N][N], A[N][N];

int dp(int row, int col){

	int minVal = INF;
	int minID = -1;

	for(int i=0; i<=row; i++){
		A[i][0] = INF;
		A[i][col+1] = INF;
	}

	for(int i=1; i<=col; i++){
		c[0][i] = 0;
	}

	for(int i=1; i<=row; i++){

		for(int j=1; j<=col; j++){

			A[i][j] = c[i][j] + min(A[i-1][j-1], min(A[i-1][j], A[i-1][j+1]));

			if(i == row) {
				
				if(minVal > A[i][j]){
				minID = j;
				minVal = A[i][j];
				cout << minVal << " " << minID << endl;
			}
			}
		}

	}


	return minID;
}

void print(int i, int j, int  m){

	if( i == 0 || j == 0 || j == m+1) 
		return;

	if ((A[i-1][j-1] <= A[i-1][j]) && (A[i-1][j-1] <= A[i-1][j+1])){
		print(i-1, j-1, m);
	}

	else if ((A[i-1][j] <= A[i-1][j-1]) && (A[i-1][j] <= A[i-1][j+1])){
		print(i-1, j, m);
	} 

	else if ((A[i-1][j+1] <= A[i-1][j]) && (A[i-1][j+1] <= A[i-1][j-1])){
		print(i-1, j+1, m);
	} 

	cout << c[i][j] << " -> (" << i << ", " << j << ")\n";

}

int main(){

	freopen("in.txt", "r", stdin);

	int r, cl;
	cin >> r >> cl;

	for(int i=1; i<=r; i++){
		for(int j=1; j<=cl; j++){
			cin >> c[i][j];
		}
	}

	int ans = dp(r, cl);

	for(int i=1; i<=r; i++){
		for(int j=1; j<=cl; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << "ANS: " << ans << endl;

	print(r, ans, cl);

}