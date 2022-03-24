#include <stdio.h>
#include <math.h>

#define f(x) ((x * x) + 1)
#define size 200


int main()
{
    double a = 0.0, b = 1.0, x = 0.0;
    double h = fabs(b - a) / size, summation = 0.0;

    for (int i = 1; i < size; i++)
    {
        x += h;
        summation += f(x);
    }

    summation += (f(a) + f(b)) / 2;
    summation = h * summation;

    printf("%lf\n", summation);
}