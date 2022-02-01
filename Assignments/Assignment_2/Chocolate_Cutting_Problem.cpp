#include <bits/stdc++.h>
using namespace std;

const int INF = -1e5 + 5;

int r[100][100];

int chocolate_cut(int p[100][100], int m, int n)
{ // array size must be mentioned

    //m - columns
    //n - rows

    r[0][0] = 0;

    for (int k = 0; k < m; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            int q = INF;

            for (int i = 1; i <= j; i++)
            {

                if (q < p[i - 1][k] + r[j - i][k])
                {
                    q = p[i - 1][k] + r[j - i][k];
                }
            }

            r[j][k] = q;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int j = 1; j <= m; j++)
        {
            int q = INF;

            for (int i = 1; i <= j; i++)
            {

                if (q < p[k][i - 1] + r[k][j - i])
                {
                    q = p[k][i - 1] + r[k][j - i];
                }
            }

            r[m][j] = q;
        }
    }

    int max_revenue = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout << r[i][j] << " ";
            max_revenue = max(max_revenue, r[i][j]);
        }
        //cout << endl;
    }

    return max_revenue;
}

int main()
{

    freopen("in.txt", "r", stdin);

    int p[100][100], r, c;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> p[i][j];
        }
    }

    int p1 = chocolate_cut(p, c, r); // cols

    cout << "Max Revenue: " << p1 << endl;
}