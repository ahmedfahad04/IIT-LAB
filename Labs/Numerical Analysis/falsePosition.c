#include <stdio.h>
#include <math.h>
#define EPS 1e-9

double func(double x)
{
    double eqn = x * x * x + 4 * x * x - 10;
    //printf("RES: %lf\n", eqn);
    return eqn;
}

int main()
{

    double a = 1, b = 2, c;
    int itr = 0;

    while (1)
    {
        itr++;
        c = (a*func(b) - b*func(a)) / (func(b) - func(c));

        if (fabs(func(c)) <= EPS)
        {
            printf("Root is: %0.9lf", c);
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
