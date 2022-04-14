#include <bits/stdc++.h>
using namespace std;

// calculating the index for each cell
void evalEachCell(int i, int j){

    cout << "[" << i << ", "  << j << "]: \n";

    if(i == j){

        cout << i << ", " << j << endl;

    } else {

        int level = j-i;
        int l1 = i;
        int r1 = i;
        int l2 = l1+1;
        int r2 = j;

        for(int k=1; k<=level; k++){

            cout << l1 << ", " << r1 << "---";
            cout << l2 << ", " << r2 << endl;

            r1++;
            l2++;
        }

    }

}

int main()
{
    freopen("in.txt", "r", stdin);

    string w;
    vector<pair<char, string>> production;

    int num;
    cout << "How many production to be entered: ";
    cin >> num;

    // enter the production
    for(int i=0; i<num; i++){
        char var;
        string terminal;

        cin >> var;
        cin >> terminal;
        production.push_back({var, terminal});
    }

    cout << endl;
    for(auto u: production){
        cout << u.first << "-> " << u.second << endl;
    }

    // cout << ">> ";
    // cin >> w;


    // int len = w.size();
    // int level = len;
    // int dif = 0;


    // for (int i = 0; i < len; i++)
    // {

    //     for (int row = 1; row <= level; row++)
    //     {
    //         //cout << "(" << row << ", " << row+dif << ")";
    //         evalEachCell(row, row+dif);
    //     }

    //     dif++;
    //     level--;
    //     cout << endl;
    // }
}