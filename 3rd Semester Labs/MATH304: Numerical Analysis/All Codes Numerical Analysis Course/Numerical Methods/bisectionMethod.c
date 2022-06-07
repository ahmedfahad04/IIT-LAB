// author: Fahad

#include <stdio.h>
#include <math.h>
#define func(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define EPS 1e-9


int main()
{

    double a = 1, b = 2, c;
    int itr = 0;

    while (1)
    {
        itr++;
        c = (a + b) / 2;

        // printf("%-3d  a:%lf   b:%lf    c:%lf     (b-c):%lf     f(c):%lf\n", itr, a, b, c, (b-c), func(c));

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
