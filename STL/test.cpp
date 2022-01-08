#include <bits/stdc++.h>
#define pi pair<int, string>
#define mk make_pair
#define f first
#define s second
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); // if I comment out this line then the code works correctly

    int n;

    // declaration and initialization using macro
    pi rec[10];


    cout << "Enter how many records you want to store: ";
    cin >> n;

    for(int i=0; i<n; i++){
        int sl;
        string name;
        cout << "Enter serial: ";
        //cout << flush; // point to be noted

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
