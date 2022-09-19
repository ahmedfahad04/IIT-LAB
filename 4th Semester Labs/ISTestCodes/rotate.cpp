#include <bits/stdc++.h>
using namespace std;

#define tot_bits 32

int rotateRight(int n, int d)
{
    int c = (n >> d) | (n << (tot_bits - d));
    return c;
}

int main()
{
    int n, d;
    cin >> n >> d;
    std::bitset<tot_bits> x(rotateRight(n, d));
    std::bitset<tot_bits> y(n);

    cout << y << endl;
    cout << x << endl;
    cout << n << endl;
    cout << rotateRight(n, d) << endl;
    return 0;
}