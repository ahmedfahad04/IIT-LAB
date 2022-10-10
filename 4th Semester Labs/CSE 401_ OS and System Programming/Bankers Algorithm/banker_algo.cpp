#include <bits/stdc++.h>
#define N 10
using namespace std;
int need[N][N];
int allocation[N][N];
int Max[N][N];
int work[N]; // available
bool finish[N];


int main()
{

    freopen("input.txt", "r", stdin);

    // initialize finish to FALSE
    for(int i=0; i<N; i++){
        finish[i] = false;
    }

    int p, rs;
    // cout << "Enter number of Process and Resource: ";
    cin >> p >> rs;


    for(int i=0; i<p; i++){
        for(int j=0; j<rs; j++){
            int al;
            // cout << "Process " << i << " & " << "Allocation[" << j << "] = ";
            cin >> al;
            allocation[i][j] = al;   
        }
        // cout << endl;
    }

    for(int i=0; i<p; i++){
        for(int j=0; j<rs; j++){
            int mx;
            cin >> mx;
            // cout << "Max Resource[" << j << "] = " << mx;
            Max[i][j] = mx;
        }
        // cout << endl;
    }
  

    // cout << "Enter Available Resource: ";

    for(int i=0; i<rs; i++){
        int av;
        cin >> av;
        work[i] = av;
    }

    // calculate NEED
    for(int i=0; i<p; i++){
        for(int j=0; j<rs; j++){
            need[i][j] = Max[i][j] - allocation[i][j];
        }
    }
    
    queue<int> q, ans;
    for(int i=0; i<p; i++) q.push(i);

    int limit = N*N;
    int track = 0;

    while(!q.empty()){
        int i, j, pi, flag;
        
        for(i=0; i<q.size(); i++){
            pi = q.front();

            for (j=0; j<rs; j++){
                if(need[pi][j] > work[j]) {
                    flag = 0;
                    break;
                }
                else{
                    flag = 1;
                }
            }

            if(flag == 0){
                cout << "Process " << pi << " MUST WAIT.\n";
                q.pop();
                q.push(pi);

            } else {
                cout << "Process " << pi << " is safe.\n";

                for(int k=0; k<rs; k++) {
                    work[k] = work[k] + allocation[pi][k];
                }
                finish[pi] = true;
                q.pop(); 
                ans.push(pi);
            }
        }
        track++;
        if(track > limit) break;
    }

    while(!ans.empty()){
        if(ans.size() != p) {
            cout << "INVALID\n";
            break;
        }
        else {
            cout << ans.front() << " ";
            ans.pop();
        }
    }

    cout << endl;
}