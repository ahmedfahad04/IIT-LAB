#include <bits/stdc++.h>
#define ll int
#define N 100005
using namespace std;

ll a[N], sum[N], previous[N];

ll LIS(ll n){

    ll maxsum = 0, id = -1;

    for(int i=1; i<=n; i++){

        ll m1 = sum[i-1]+a[i];

        if(m1 >= a[i]){
            sum[i] = m1;
            previous[i] = i-1;
        }
        else{
            sum[i] = a[i];
            previous[i] = 0;
        }

        if(maxsum <= sum[i]){
            id = i;
            maxsum = sum[i];
        }
    }

    return id;
}   

// creating core dump error .... but why??
void print_LIS(ll id){
    
    if (previous[id] > 0){
        print_LIS(previous[id]);
        cout << a[id] << " ";
    }
    else{
        cout << a[id] << " ";
        return;
    }
}

int main(){

    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    ll index = LIS(n);
    print_LIS(index);

}