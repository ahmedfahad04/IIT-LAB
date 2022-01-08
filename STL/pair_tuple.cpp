#include <bits/stdc++.h>
#define s second
#define f first
#define pi pair<int, string>
#define mk make_pair
using namespace std;

int main(){

    // for faster i/o
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // usual declaration and assigning values
    pair<int, string> p;
    p.f = 1;
    p.s = "Fahad";

    int n;

    // declaration and initialization using macro
    pi rec[10];
    cout << "Enter how many records you want to store: ";
    cin >> n;

    for(int i=0; i<n; i++){
        int sl;
        string name;
        cout << "Enter serial: ";
        cin >> sl;
        getchar();

        cout << "Enter name: ";
        getline(cin, name);


        rec[i] = mk(sl, name);
    }

    for (int i=0; i<n; i++){
        cout << rec[i].f << ": " << rec[i].s << endl;
    }


}

