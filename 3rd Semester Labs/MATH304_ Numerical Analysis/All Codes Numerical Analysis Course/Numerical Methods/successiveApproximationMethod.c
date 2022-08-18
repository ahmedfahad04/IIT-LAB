// author: Asif

#include <stdio.h>
#include <math.h>

#define f(x) ((cos(x)) - (3 * x) + 5)
#define phi(x) ((5 + cos(x)) / 3)
#define ep 1e-3

int main(void)
{
    double a = 1, b = 2;

    if (f(a) * f(b) > 0)
    {
        printf("Root doesn't lies in this interval.");
        return 0;
    }

    double x0 = a; // initial approximation
    double xn;

    while (1)
    {
        xn = phi(x0);
        if (fabs(xn - x0) < ep)
        {
            printf("Root is: %.3lf", xn);
            break;
        }
        x0 = xn;
    }

    return 0;
}
