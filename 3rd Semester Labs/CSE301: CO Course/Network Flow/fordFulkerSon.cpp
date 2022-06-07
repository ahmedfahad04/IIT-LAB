#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int graph[N][N];
int residual_graph[N][N];
int parent[N];                    // FILLED BY BFS
bool bfs(int s, int t, int nodes) // searching for augmenting path, if bfs traversal is possible there is augmenting path
{
    queue<int> q;
    q.push(s);
    bool visited[N] = {false};
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= nodes; i++)
        {
            if (residual_graph[u][i] > 0 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
                parent[i] = u;
            }
        }
    }
    return visited[t];
}
int ford_fulkerson(int s, int t, int nodes)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            residual_graph[i][j] = graph[i][j];
        }
    }
    int max_flow = 0;

    while (bfs(s, t, nodes))
    {
        int path_flow = INT_MAX; // max flow through the path

        for (int i = t; i != s; i = parent[i])
        {
            int j = parent[i];
            path_flow = min(path_flow, residual_graph[j][i]);
        }

        for (int i = t; i != s; i = parent[i])
        {
            int j = parent[i];

            residual_graph[j][i] -= path_flow; // subtract current flow from residual graph(capacity-pathflow)
            // cout << residual_graph[j][i] << "Forward edge\n";
            residual_graph[i][j] += path_flow; // add current flow to residual graph in opposite direction
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int nodes, edges;
    cin >> nodes >> edges;
    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout << "Max flow: " << ford_fulkerson(1, 6, nodes) << endl;
}