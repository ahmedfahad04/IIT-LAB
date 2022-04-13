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
int rGraph[N][N];
map<string, int> G;

int main(){

    //freopen("in2.txt", "r", stdin);

    int nodes, edges;
    cin >> nodes >> edges;

    int track = 1;

    for (int i = 0; i < edges; i++)
    {
        string src;
        cin >> src;
        fflush(stdin);
        G[src] = track;

        int dest, weight;

        cin >> dest >> weight;
        graph[track][dest] = weight;

        track++;
        // cout << graph[u][v] << " ";
    }

    for(int i = 0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

}