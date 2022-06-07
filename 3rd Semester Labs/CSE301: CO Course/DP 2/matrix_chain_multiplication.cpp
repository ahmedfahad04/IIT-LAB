/*	
	input format:
	size
	values...

	output format:
	Optimal Parenthesis sequence
*/


#include <bits/stdc++.h>
#define N 10005
#define INF 1000009
using namespace std;

int p[N], m[N][N], s[N][N], a[N];

int lookup_chain(int i, int j){

	if(m[i][j] < INF){
		return m[i][j];
	}

	if(i == j){
		m[i][j] = 0;
	}

	else{
		for(int k=i; k<=j-1; k++){
			int q = lookup_chain(i, k) + lookup_chain(k+1,j) + p[i-1]*p[k]*p[j];
			if (q < m[i][j]){
				m[i][j] = q;
				s[i][j] = k; // this array track from which kth calculation, the min value was obtained
			}
		}
	}

	return m[i][j];
}

void print_mcm(int i, int j){

	if(i == j){
		cout << " A" << i << " ";
	}
	else{
		cout << "(";
		print_mcm(i, s[i][j]);
		print_mcm(s[i][j]+1, j);
		cout << ")";
	}
}

int main(){

	freopen("in.txt", "r", stdin);

	int n;
	cin >> n;

	for(int i=0; i<n; i++)
		cin >> p[i];

	// initializing m[i][j]  with infinity
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			m[i][j] = INF;
		}
	}

	lookup_chain(1, n-1);

	cout << "Optimal Parenthesis sequence is: \n";

	print_mcm(1, n-1);

	cout << "\n\n";

}