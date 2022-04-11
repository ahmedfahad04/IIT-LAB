// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

const int N = 50;

int graph[N][N];
int rGraph[N][N];


// Number of vertices in given graph

/* Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills parent[] to store the
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

		for (int v = 1; v < nodes; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				// If we find a connection to the sink node,
				// then there is no point in BFS anymore We
				// just have to set its parent and can return
				// true
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

	// We didn't reach sink in BFS starting from source, so
	// return false
	return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int s, int t, int nodes)
{
	int u, v;

	// Create a residual graph and fill the residual graph
	// with given capacities in the original graph as
	// residual capacities in residual graph
	 // Residual graph where rGraph[i][j]
				// indicates residual capacity of edge
				// from i to j (if there is an edge. If
				// rGraph[i][j] is 0, then there is not)
	for (u = s; u < nodes; u++)
		for (v = s; v < nodes; v++)
			rGraph[u][v] = graph[u][v];

	int parent[nodes+1]; // This array is filled by BFS and to
				// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink

	while (bfs(s, t, parent, nodes)) {
		// Find minimum residual capacity of the edges along
		// the path filled by BFS. Or we can say find the
		// maximum flow through the path found.
		int path_flow = INT_MAX;
		// for(int i=1; i<nodes; i++) cout << parent[i] << endl;
		// cout << endl;
       
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			cout << u << endl;
			path_flow = min(path_flow, rGraph[u][v]);
		}

		cout << endl;

		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = t; v != s; v = parent[v]) {

			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
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
	// Let us create a graph shown in the above example
	// int graph[V][V]
	// 	= { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
	// 		{ 0, 4, 0, 0, 14, 0 }, { 0, 0, 9, 0, 0, 20 },
	// 		{ 0, 0, 0, 7, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };

	freopen("maxflow.txt", "r", stdin);
    
    int nodes, edges;
    cin >> nodes >> edges;
    int u, v, w;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
        // cout << graph[u][v] << " ";
    }

	cout << "The maximum possible flow is \n"
		<< fordFulkerson(1, 5, nodes) << endl;

	return 0;
}
