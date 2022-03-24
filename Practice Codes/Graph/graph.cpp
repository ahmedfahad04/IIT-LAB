#include <bits/stdc++.h>
using namespace std;

vector<int> graph[N];

int main(){

	int node, edge;
	cin >> node >> edge;

	for(int i=0; i<edge; i++){
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}


}