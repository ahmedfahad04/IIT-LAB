#include <stdio.h>
#include <math.h>
#define EPS 1e-9
#define f(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)

int main()
{

    double a = 1, b = 2, c;
    int itr = 0;

    while (1)
    {
        itr++;
        c =  (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (fabs(f(c)) <= EPS)
        {
            printf("Root (Secant Method) is: %0.9lf\n", c);
            printf("Iteration: %d\n", itr);
            break;
        }

        else 
        {
            a = b;
	        b = c;
        } 
    }
}
