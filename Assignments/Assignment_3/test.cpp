#include <bits/stdc++.h>
#define N 100
using namespace std;

int dp[N][N];
int count(int p[], int n, int m)
{
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

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 1;
    }

    int minc = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i] >= j) // coin er value total er theke beshi, copy from above
            {            
                dp[i][j] = min(minc, dp[i][j - p[i]] + 1); // minumum of guy in the top or go back p[i] steps to the left+1
            }
            cout << dp[i][j] << " ";
        }

        
        cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n-1][m];
}

int main()
{
    freopen("in.txt", "r", stdin);

    int val; // total value
    cin >> val;

    int m; // total number of coins
    cin >> m;
    int p[m]; // array of coins

    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    cout << "Coin change count: " << count(p, val, m) << endl;
    cout << "Minimum coins: " << min_coins(p, val, m) << endl;
}