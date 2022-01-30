#include <bits/stdc++.h>
using namespace std;

int rod_cut(int p[], int n){
    
    int r[100];

    r[0] = 0;

    for(int j = 1; j <= n; j++){
        int q = -10000;

        for(int i=1; i <= j; i++){
            q = max(q, p[i]+r[j-i]);
            cout << "id: " << i << endl;
        }

        r[j] = q;
        cout << "R: " << r[j] << endl;
        cout << endl;
    }

    // for(int i=1; i<n; i++){
    //     cout << "FINAL: " << r[i] << endl;
    // }

    return r[n];
}

int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int len;
    //cout << "Enter the length to be cut: ";
    cin >> len;

    int price[] = { -1, 2, 5, 9, 6};

    cout << "\n\n";

    int ans = rod_cut(price, len);

    cout << "MAX revenue: " << ans << endl;

}