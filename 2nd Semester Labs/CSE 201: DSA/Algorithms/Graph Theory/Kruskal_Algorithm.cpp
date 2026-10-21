#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100;
int parent[N];

struct we_ed
{
    int weight;
    int node1;
    int node2;
};


struct we_ed graph[N];

bool cmp(struct we_ed a, struct we_ed b)
{
    return a.weight <= b.weight;
}

// make
void make_set(int x)
{
    parent[x] = x;
}

// find
int Find_set(int n)
{
    if (parent[n] == n)
        return n;
    return Find_set(parent[n]);
}

// union
void Union(int n1, int n2)
{
    int parent_n1 = Find_set(n1);
    int parent_n2 = Find_set(n2);
    
    if (parent_n1 != parent_n2)
    {
        parent[parent_n2] = parent_n1;
    }
}

int main()
{

    freopen("in2.txt", "r", stdin);
    int node, edge;
    // graph input
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i].weight = w;
        graph[i].node1 = u;
        graph[i].node2 = v;
    }

    for (int i = 0; i < node; i++)
        make_set(i);

    // sort
    sort(graph, graph + edge, cmp);

    int total_cost = 0;
    cout << "MST\n";

    for (int i = 0; i < edge; i++)
    {
        if (Find_set(graph[i].node1) != Find_set(graph[i].node2))
        {
            // cout<<"before: ";
            // cout<<"parent of "<<(char)(graph[i].node1+97)<<": "<<(char)(Find_set(graph[i].node1)+97)<<" parent of "<<(char)(graph[i].node2+97)<<": "<<(char)(Find_set(graph[i].node2)+97)<<"\n";
            cout << (char)(graph[i].node1 + 97) << " " << (char)(graph[i].node2 + 97) << " " << graph[i].weight << endl;
            Union(graph[i].node1, graph[i].node2);
            // cout<<"after: ";
            // cout<<"parent of "<<(char)(graph[i].node1+97)<<": "<<(char)(Find_set(graph[i].node1)+97)<<" parent of "<<(char)(graph[i].node2+97)<<": "<<(char)(Find_set(graph[i].node2)+97)<<"\n";
            total_cost += graph[i].weight;
        }
    }

    cout << "Total Cost: " << total_cost;
}