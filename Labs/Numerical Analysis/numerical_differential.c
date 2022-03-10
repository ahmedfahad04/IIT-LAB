#include <stdio.h>
#define N 5

double x[N] = {0, 1, 2, 3, 4};
double f[N] = {1, 2, 2.5, 2.8, 3.0};

double ford(int x2, int x1)
{
    return ((f[x2] - f[x1]) / (x[x2] - x[x1]));
}

double cent(int x2, int x0)
{
    return ((f[x2] - f[x0]) / (x[x2] - x[x0]));
}

double back(int x1, int x0)
{
    return ((f[x1] - f[x0]) / (x[x1] - x[x0]));
}

int main()
{

    printf("x: %lf      f: %lf      df: %lf\n", x[0], f[0], ford(1, 0));

    for (int i = 1; i < N - 1; i++)
    {
        printf("x: %lf      f: %lf      df: %lf\n", x[i], f[i], cent(i-1,i+1));
    }

    printf("x: %lf      f: %lf      df: %lf\n", x[N - 1], f[N - 1], back(N-1, N - 2));
}