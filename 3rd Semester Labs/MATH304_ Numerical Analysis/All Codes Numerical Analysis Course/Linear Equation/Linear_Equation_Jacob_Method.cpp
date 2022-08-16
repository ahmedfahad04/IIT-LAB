// author: Jubayer Vai

#include <bits/stdc++.h>
using namespace std;

// we have to check the matrix is diagonally dominated or not, if yes then this method is applicable otherwise not

const double eps = 1e-9;
const int N = 10;
double x0[N], x1[N], b[N], a[N][N];

double g(int i, int n)
{
    double sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (i != j)
            sum += (a[i][j] * x0[j]);
    }
    sum = b[i] - sum;
    sum /= a[i][i];
    return sum;
}

bool valid(int n)
{
    double mx = -100;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, abs(x1[i] - x0[i]));
    }
    if (abs(mx) <= eps)
        return true;
    else
        return false;
}

void jacob_method()
{
    int n = 3;

    b[0] = 85, b[1] = 51, b[2] = 5;

    a[0][0] = 15, a[0][1] = 3, a[0][2] = -2;
    a[1][0] = 2, a[1][1] = 10, a[1][2] = 1;
    a[2][0] = 1, a[2][1] = -2, a[2][2] = 8;

    for (int i = 0; i < n; i++)
        x0[i] = 0;

    int it = 0;
    while (true)
    {
        it += 1;
        for (int i = 0; i < n; i++)
        {
            x1[i] = g(i, n);
        }

        if (valid(n))
            break;

        for (int i = 0; i < n; i++)
            x0[i] = x1[i];
    }

    printf("No of iteration: %d\n", it);
    
    for (int i = 0; i < n; i++)
        printf("%.9lf  ", x1[i]);
    printf("\n");
}

int main(void)
{
    jacob_method();
    return 0;
}
