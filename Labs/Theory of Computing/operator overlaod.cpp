#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream &f, const vector<int> &v){
   
    f << "[";
    for (int x : v){
        f << x << " ";
    }
    f << "]";
    return f;
}

int main (){ 

    vector<int> v{2,5,252,2435,5435};
    cout << v << endl;
}