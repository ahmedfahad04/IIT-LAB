// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int graph[N][N];
int resedualGraph[N][N];
int capacity[N];
map<string, int> G[N];


// Number of vertices in given graph

/* Returns true if there is a path from source 's' to sink
't' in resdestual graph. Also fills parent[] to store the
path */
bool bfs(int s, int t, int parent[], int nodes)
{
	// Create a visited array and mark all vertices as not
	// visited
	bool visited[nodes+1];
	memset(visited, 0, sizeof(visited));

	// Create a queue, enqueue source vertex and mark source
	// vertex as visited
	queue<int> q;
	q.push(s);

	visited[s] = true;
	parent[s] = -1;

	// Standard BFS Loop
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 1; v <= nodes; v++) {
			if (visited[v] == false && resedualGraph[u][v] > 0) {
				
				if (v == t) {
					parent[v] = u;
					return true;
				}

				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// We ddestn't reach sink in BFS starting from source, so
	// return false
	return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int s, int t, int nodes)
{
	int u, dest;

	for (u = s; u <= nodes; u++)
		for (dest = s; dest <= nodes; dest++)
			resedualGraph[u][dest] = graph[u][dest];

	int parent[N]; // This array is filled by BFS and to
				// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink

	while (bfs(s, t, parent, nodes)) {
	
		int path_flow = INT_MAX;
		
       
		for (dest = t; dest != s; dest = parent[dest]) {
			u = parent[dest];
			path_flow = min(path_flow, resedualGraph[u][dest]);
		}

		
		for (dest = t; dest != s; dest = parent[dest]) {

			u = parent[dest];
			
			resedualGraph[u][dest] -= path_flow;
            
            
			resedualGraph[dest][u] += path_flow;
		}

        cout << "Resedual Graph: \n";
        for(int i=0; i<nodes; i++){
            for(int j=0; j<nodes; j++){
                cout << resedualGraph[i][j] << " ";
            }
            cout << endl;
        }

		// Add path flow to overall flow
		max_flow += path_flow;
        
	}

	// Return the overall flow
	return max_flow;
}

// Driver program to test above functions
int main()
{

	freopen("in3.txt", "r", stdin);
    
    int nodes, edges;
    cin >> nodes >> edges;
    int src, dest, cost;

    for (int i = 0; i < edges; i++)
    {
        cin >> src >> dest >> cost;
        graph[src][dest] = cost;
        // cout << graph[u][v] << " ";
    }

    for(int i=0; i<nodes; i++){
        cin >> capacity[i];
    }

	cout << "The maximum possible flow is \n"
		<< fordFulkerson(1, 3, nodes) << endl;

	return 0;
}
