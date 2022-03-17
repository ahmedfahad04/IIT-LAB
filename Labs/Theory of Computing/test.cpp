#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> x;

    x.push_back(15);

    for(int a: x){

        if(a < 20){
            cout << a << endl;
            int b;
            cin >> b;
            x.push_back(b);
            x.resize(3);
        }
        
    }
}