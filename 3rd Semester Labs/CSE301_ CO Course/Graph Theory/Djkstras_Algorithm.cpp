#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

void dijkstra(int s, vector<int> &d, vector<int> &p, vector<vector<pair<int, int>>> adj)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);   // marked or unmarked

    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        // this loop extracts the vertex v which has smallest distance among all the unmarked vertices.
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        // cout << "V: " << v << endl;

        // this loop checks all the adjecent vertices related to v
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            // relaxation performed
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> pathFinder(int src, int dest, vector<int> &p){

    vector<int> ans;
    cout << "Shorted path of " << dest << " From source is: \n";

    for(int v = dest; v != src; v = p[v]){
        ans.push_back(v);
    }

    ans.push_back(src);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    freopen("din.txt", "r", stdin);

    int nodes, edges;
    vector<int> dist, path, shortestPath;
    
    cin >> nodes >> edges;

    vector<vector<pair<int, int>>> adj(nodes+1);    //==> you must specify the size (nodes+1), else you'll get segmentation fault


    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        //cout << adj[u][0].first << " ";
    }


    dijkstra(1, dist, path, adj);

    for (int i = 1; i <= nodes; i++)
    {
        cout << i << " " << dist[i] << endl;
    }

    shortestPath = pathFinder(1, 4, path);
    for(auto x: shortestPath) cout << x << " ";
}
