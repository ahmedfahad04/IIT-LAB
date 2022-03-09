#include <stdio.h>
#include <math.h>
#define EPS 1e-9

double func(double x)
{
    double eqn = x * x * x - 4 * x - 8.95;
    //printf("RES: %lf\n", eqn);
    return eqn;
}

int main()
{

    double a = 2, b = 3, c;
    int itr = 0;

    while (1)
    {
        itr++;
        c = (a + b) / 2;

        printf("%-3d  a:%lf   b:%lf    c:%lf     (b-c):%lf     f(c):%lf\n", itr, a, b, c, (b-c), func(c));
        if (fabs(func(c)) <= EPS)
        {
            printf("Root (Bisection Method) is: %0.9lf\n", c);
            printf("\nIteration: %d", itr);
            break;
        }

        else if (func(a) * func(c) < 0.0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

    }  
}
