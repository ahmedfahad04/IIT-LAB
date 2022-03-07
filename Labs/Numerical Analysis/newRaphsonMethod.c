#include <stdio.h>
#include <math.h>
#define df(x) (3*x*x + 8*x)
#define f(x) (x*x*x + 4*x*x - 10)
#define EPS 1e-9

double func(double x)
{
    double eqn = x * x * x + 4 * x * x - 10;
    //printf("RES: %lf\n", eqn);
    return eqn;
}

int main()
{

    double a = 1, c;
    int itr = 0;

    while (1)
    {
        itr++;
        c = a - (f(a)/df(a));

        if (fabs(f(c)) <= EPS)
        {
            printf("Root (Newton Raphson Method) is: %0.9lf\n", c);
            printf("Iteration: %d\n", itr);
            break;
        }

        else
        {
            a = c;
        }
    }
}
