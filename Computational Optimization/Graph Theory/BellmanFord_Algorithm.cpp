#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int a, b, cost;
};

int n, ed, src;
vector<edge> e;
vector<int> path;
const int INF = 1000000000;

void solve(vector<int> &d, int t)
{
    d.assign(n, INF);
    d[src] = 0;
    vector<int> p(n, -1);

    for (;;)
    {
        bool any = false;
        for (int j = 0; j < ed; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if (!any)
            break;
    }

    if (d[t] == INF)
        cout << "No path from " << src << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back(cur);

        reverse(path.begin(), path.end());

        cout << "Path from " << src << " to " << t << ": ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}

int main()
{

    freopen("din.txt", "r", stdin);
    cin >> n >> ed;
    vector<int> dist, shortestPath;

    for (int i = 0; i < ed; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        e.push_back({u, v, w}); // ==> this is the way to use vector of structure
    }

    src = 1;

    solve(dist, 4);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dist[i] << " " << path[i] << endl;
    }

    // shortestPath = pathFinder(1, 4, path);

    // for(auto x: shortestPath) cout << x << " ";
}