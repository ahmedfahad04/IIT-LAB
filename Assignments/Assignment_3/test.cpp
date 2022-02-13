#include <bits/stdc++.h>
using namespace std;

int L[10];

int size(int a[]){

    
}
int count(int p[], int n, int m)
{

    int dp[n + 1][m];

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = 0, y = 0;
            if (i - p[j] >= 0)
            {
                x = dp[i - p[j]][j];
            }
            if (j >= 1)
            {
                y = dp[i][j - 1];
            }
            dp[i][j] = x + y;
        }
    }

    return dp[n][m - 1];
}
int min_coins(int p[], int m, int n)
{
    int dp[n][m + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    // just added this 42th line to initialize the first row with +infinity
    // so that we can compare the 1st row with 0th row to get the min value
    for (int i = 1; i <= m; i++) dp[0][i] = INT_MAX;


    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[i] > j) // coin er value total er theke beshi, copy from above
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - p[i]] + 1); // minumum of guy in the top or go back p[i] steps to the left+1
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n - 1][m];
}
int main()
{

    // freopen("in.txt", "r", stdin);

    // int val; // total value
    // cin >> val;

    // int m; // total number of coins
    // cin >> m;
    // int p[m]; // array of coins

    // for (int i = 0; i < m; i++)
    // {
    //     cin >> p[i];
    // }

    // cout << "Coin change count: " << count(p, val, m) << endl;
    // cout << "Minimum coins: " << min_coins(p, val, m) << endl;

    
    int len = sizeof(L)/sizeof(L[0]);
    cout << "SIZE: " << len << endl;
}
