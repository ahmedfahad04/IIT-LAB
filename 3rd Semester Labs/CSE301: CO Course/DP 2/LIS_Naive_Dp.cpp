/*
    ### LIS using NAIVE DP approach ###
    
    input format:
    size of array
    array elements....

    output format:
    Length of LIS:
    LIS: 
*/

#include <bits/stdc++.h>
#define N 1000
using namespace std;

int x[N], L[N], pre[N], maxlen, maxid;

void LIS_NAIVE(int n)
{

    L[0] = 0;
    pre[0] = -1;

    for (int i = 1; i <= n; i++)
    {
        L[i] = 0;

        for (int j = 0; j <= i; j++)
        {

            if (x[j] < x[i] and L[j] + 1 > L[i])
            {
                L[i] = L[j] + 1;
                pre[i] = j;
            }

            if (L[i] >= maxlen)
            {
                maxlen = L[i];
                maxid = i;
            }
        }
    }
}

void print(int id)
{

    if (pre[id] == 0)
    {
        cout << x[id] << " ";
        return;
    }

    else
    {
        // cout << "ID: " << id << ", PRE: " << pre[id] << endl;
        print(pre[id]);
        cout << x[id] << " ";
    }
}

int main()
{

    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    
    int size;
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        cin >> x[i];
    }

    LIS_NAIVE(size);

    cout << "Length of LIS: " << maxlen << "\nLIS: ";

    print(maxid);

    cout << endl;
}


