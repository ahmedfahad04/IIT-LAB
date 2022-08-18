#include <stdio.h>
#include <math.h>

#define f(x) ((x * x) + 1)
#define size 200

int main()
{
    double a = 0.0, b = 1.0, x = 0.0, odd = 0.0, even = 0.0, h = fabs(b - a) / size, summation = 0.0;

    for (int i = 1; i < size; i++)
    {   
        x += h;

        if(i&1) odd += f(x);
        else even += f(x);
    }

    summation += (f(a) + f(b)) + (4*odd + 2*even);
    summation = (h * summation) / 3;

    printf("%lf\n", summation);
}