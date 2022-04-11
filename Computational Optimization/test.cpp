#include <bits/stdc++.h>
using namespace std;


int main() {

    vector<vector<pair<int,int>>> G(10);
    //  insufficient initial size  ^^^

    int p, q, l;
    while ( cin >> p >> q >> l )
    {
        // resize the vector to avoid index out of bound
    
        G[p].push_back(std::make_pair(q, l));
        G[q].push_back(std::make_pair(p, l));
    } 

    for( int r = 0; r < G.size(); ++r )
    {
        for ( int c = 0; c < G[r].size(); ++c ) {
            cout << r << ", " << c << ": " << G[r][c].first << ' ' << G[r][c].second << '\n';
        }
    } 

    return 0;
}