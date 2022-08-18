// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

// Number of vertices in given graph
#define V 50
int capacity[V];

/* Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills parent[] to store the
path */
bool bfs(int rGraph[V][V], int s, int t, int parent[], int nodes)
{
	// Create a visited array and mark all vertices as not
	// visited
	bool visited[nodes + 1];
	memset(visited, false, sizeof(visited));

	// Create a queue, enqueue source vertex and mark source
	// vertex as visited
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// Standard BFS Loop
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 1; v <= nodes; v++)
		{
			if (visited[v] == false && rGraph[u][v] > 0)
			{
				// cout << "src: " << u << ", dest: " << v << endl;
			
				if (v == t)
				{
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
int fordFulkerson(int graph[V][V], int s, int t, int nodes)
{
	int u, v;

	// Create a residual graph and fill the residual graph
	// with given capacities in the original graph as
	// residual capacities in residual graph
	int rGraph[V]
			  [V]; // Residual graph where rGraph[i][j]
				   // indicates residual capacity of edge
				   // from i to j (if there is an edge. If
				   // rGraph[i][j] is 0, then there is not)
	for (u = 1; u <= nodes; u++)
		for (v = 1; v <= nodes; v++)
			rGraph[u][v] = graph[u][v];

	int parent[nodes + 1]; // This array is filled by BFS and to
						   // store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink
	while (bfs(rGraph, s, t, parent, nodes))
	{
		// cout << "HELLO\n";
		// cout << "SRC: " << s << ", Dest: " << t << endl;
		
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
			// cout << "CAP: " << capacity[u] << endl;
			path_flow = min(capacity[u], path_flow);
		}
	
		// cout << "MAXFLOW: " << path_flow << endl;


		
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];

			rGraph[u][v] -= path_flow;
			rGraph[u][v] -= capacity[u];
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
	int graph[V][V];

	freopen("in2.txt", "r", stdin);

	int nodes, edges;
	cin >> nodes >> edges;
	int src, dest, cost;

	for (int i = 0; i < edges; i++)
	{
		cin >> src >> dest >> cost;
		graph[src][dest] = cost;
	}

	for (int i = 1; i <= nodes; i++)
	{
		cin >> capacity[i];
	}

	cout << "The maximum possible flow is: "
		 << fordFulkerson(graph, 1, nodes, nodes);

	return 0;
}
