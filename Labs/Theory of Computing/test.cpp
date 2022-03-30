#include <bits/stdc++.h>
using namespace std;

string uniqChar(string x, string y){
    set<char> res;

    for(int i=0; i<x.size(); i++){
        if(!res.count(x[i])) res.insert(x[i]);
    }

    for(int i=0; i<y.size(); i++){
        if(!res.count(y[i])) res.insert(y[i]);
    }

    string ans = "";
    for(char a: res){
        ans += a;
    }

    return ans;
}

int main(){
    // vector<int> x;

    // x.push_back(15);

    // for(int a: x){

    //     if(a < 20){
    //         cout << a << endl;
    //         int b;
    //         cin >> b;
    //         x.push_back(b);
    //         x.resize(3);
    //     }
        
    // }

    cout << uniqChar("bc", "abc");
}