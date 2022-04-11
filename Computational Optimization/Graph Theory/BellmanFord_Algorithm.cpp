#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int a, b, cost;
};

int n, ed, src;
vector<edge> e;
const int INF = 1000000000;

void solve(vector<int> &d, int dest, vector<int>  &p)
{
    
    d.assign(n, INF);
    p.assign(n, -1);
    d[src] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < ed; ++j)
        {
            if (d[e[j].a] < INF)
            {
                d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
                p[e[j].b] = e[j].a;
            }
        }
    }

    // if (d[dest] == INF)
    //     cout << "NO PATH between " << src << " and " << dest << endl;

    // else
    // {

    //     vector<int> path;

    //     for (int v = dest; v != src; v = p[v])
    //     {
    //         cout << v << endl;
    //         path.push_back(v);
    //     }

    //     reverse(path.begin(), path.end());

    //     cout << "Path from " << src << " to " << dest << " is: \n";
    //     for(int i=0; i<path.size(); i++){
    //         cout << path[i] << " ";
    //     }
    // }
}

int main()
{

    freopen("din.txt", "r", stdin);
    cin >> n >> ed;
    vector<int> dist, shortestPath, p;

    for (int i = 0; i < ed; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        e.push_back({u, v, w}); // ==> this is the way to use vector of structure
    }

    src = 1;

    solve(dist, 4, p);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dist[i] << " " << p[i] <<endl;
    }

    // shortestPath = pathFinder(1, 4, path);

    // for(auto x: shortestPath) cout << x << " ";
}