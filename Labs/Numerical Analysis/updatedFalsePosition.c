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

    printf("\"itr\",\"Root\"\n");

    while (1)
    {
        c = (a * func(b) - b * func(a)) / (func(b) - func(c));
        itr++;

        if (fabs(func(c)) <= EPS)
        {
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

        printf("%d,%lf\n", itr, c);
    }  

    
}
