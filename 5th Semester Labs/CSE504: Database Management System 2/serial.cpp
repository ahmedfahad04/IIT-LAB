#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int var_cnt = 1;
map<char,int> var_map;
map<int, char> reverse_var_map;
vector<int> r[N], w[N];

using Pair = struct{
    char operation;
    int t_id;
};
vector<Pair> vars[N];
vector<int> nodes[N];

int vis[N] = {0};
bool flag = 0;
void dfs(int x){
    if (vis[x] == 1){
        cout << "Cycle found\n";
        cout << x << " ";
        flag = 1;
        return;
    }
    if (vis[x] == 2){
        return;
    }

    vis[x] = 1;
    for (int i : nodes[x]){
        dfs(i);
        if (flag == 1) break;
    }
    vis[x] = 2;
    if (flag and nodes[x].size()){
        cout << x << " ";
    }
    return;
}

int main (){
    char op, var, lp, rp, transaction_no_ch;
    int transaction_no, var_int;
    while(cin >> op){
        cin >> transaction_no_ch >> lp >> var >> rp;
        // cout << op << transaction_no_ch << lp << var << rp << var_cnt << endl;
        // cout << var << " : " << var_map[var] << endl;
        if (var_map[var] == 0){
            var_map[var] = var_cnt++;
        }
        // cout << var << " : " << var_map[var] << endl;
        reverse_var_map[var_map[var]] = var;
        transaction_no = transaction_no_ch - '0';
        vars[var_map[var]].push_back({op,transaction_no});  
    }

    for (int i=0;i<N;i++){
        if ((int)vars[i].size() > 0){
            for (int j=0;j<(int)vars[i].size();j++){
                for (int k=j+1;k<(int)vars[i].size();k++){
                    if (vars[i][j].operation == 'r'){
                        if (vars[i][k].operation == 'w'){
                            if (vars[i][j].t_id != vars[i][k].t_id){
                                nodes[vars[i][j].t_id].push_back(vars[i][k].t_id);
                            }
                        }
                    }
                    else{
                        if (vars[i][j].t_id != vars[i][k].t_id){
                            nodes[vars[i][j].t_id].push_back(vars[i][k].t_id);
                        }
                    }
                }
            }
        }
    }
    for (int i=0;i<N;i++){
        dfs(i);
        if (flag){
            cout << endl;
            break;
        }
    }
    // for (int i=0;i<N;i++){
    //     if ((int)nodes[i].size() > 0){
    //         cout << i << " ";
    //         for (int j : nodes[i]){
    //             cout << j << " ";
    //         }
    //         cout << endl;
    //     }
    // }
}