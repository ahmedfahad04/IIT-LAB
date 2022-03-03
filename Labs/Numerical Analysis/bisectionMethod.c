#include <stdio.h>
#include <math.h>
#define EPS 1e-9

double func(double x)
{
    double eqn = x * x * x + 4 * x * x - 10;
    return eqn;
}

int main()
{

    double a = 1, b = 2, c;
    int itr = 0;

    while (1)
    {
        c = (a + b) / 2;
        itr++;

        if (fabs(func(c)) <= EPS)
        {
            printf("Root (Bisection Method) is: %0.9lf\n", c);
            printf("Iteration: %d\n", itr);
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
