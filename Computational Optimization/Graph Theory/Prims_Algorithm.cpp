#include <bits/stdc++.h>
using namespace std;

#define NIL -1
const int N = 100;
const int INF = 1000000009;
int v, e;
int adj_matrix[N][N];
int key[N];
int parent[N];

bool Q[N];

void mst_prim(int r)
{
    for (int i = 1; i <= v; i++)
    {
        key[i] = INF;
        parent[i] = NIL;
        // to[i] = -1;
    }

    key[r] = 0;
    int in_Q = v;

    for (int i = 1; i <= v; i++)
    {
        Q[i] = 1;
    }

    while (in_Q)
    {
        int u = -1;
        int tmp_key = INF;

        for (int i = 1; i <= v; i++)
        {
            if (Q[i] == 1)
            {
                if (key[i] < tmp_key)
                {
                    tmp_key = key[i];
                    u = i;
                }
            }
        }

        Q[u] = 0;
        for (int i = 1; i <= v; i++)
        {
            if (Q[i] == 1 && adj_matrix[u][i] != 0)
            {
                if (adj_matrix[u][i] < key[i])
                {
                    parent[i] = u;
                    key[i] = adj_matrix[u][i];
                }
            }
        }

        in_Q--;
    }
}

void print_path(int u)
{
    if (parent[u] == -1)
        return;

    print_path(parent[u]);
    cout << u << endl;
}

int main()
{

    freopen("in.txt", "r", stdin);
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int u, vv, w;
        cin >> u >> vv >> w;
        adj_matrix[u][vv] = w;
        adj_matrix[vv][u] = w;
    }

    mst_prim(1);
    // print_path(v);

    for (int i = 0; i <= v; i++)
    {
        printf("par[%d] = %d\n", i, parent[i]);
    }

    print_path(9);
}
