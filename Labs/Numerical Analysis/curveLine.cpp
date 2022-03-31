#include <stdio.h>
#include <math.h>

#define f(x) ((x) * (sin(x)))
#define PI 3.1416
#define size 200
#define EPS 1e-9
#define N 200

double x[N+1];
double fx[N+1];

double bisection(double a, double b){
    double c;
    int itr = 0;

    while (1)
    {
        itr++;
        c = (a + b) / 2;

        printf("%-3d  a:%lf   b:%lf    c:%lf     (b-c):%lf     f(c):%lf\n", itr, a, b, c, (b-c), f(c));
        if (fabs(f(c)) <= EPS)
        {
            printf("Root (Bisection Method) is: %0.9lf\n", c);
            printf("Iteration: %d\n", itr);
            break;
        }

        else if (f(a) * f(c) < 0.0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

    }  

    return c;
}

int main()
{
    double a = 0.0, b = (4*PI), odd = 0.0, even = 0.0, h = fabs(b - a) / size, summation = 0.0;
    
    // x[0] = 0.0;
    // fx[0] = 0.0;
    // for (int i = 1; i < size; i++)
    // {   
    //     x[i] = x[i-1] + h;
    //     fx[i] = f(x[i]);

    //     // if(i&1) odd += f(x);
    //     // else even += f(x);
    // }

    // x[N] = size;
    // fx[N] = f(x[N]);

    double y=0.0;
    for(int i=0; i<=N; i++){
        y += h;
        printf("%lf, %lf\n", y, f(y));
    }

    // summation += (f(a) + f(b)) + (4*odd + 2*even);
    // summation = (h * summation) / 3;

    // printf("%lf\n", summation);
}