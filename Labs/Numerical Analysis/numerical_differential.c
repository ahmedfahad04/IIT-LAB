#include <stdio.h>
#include <math.h>

#define N 300
#define func(x) (((x)*(x)*(x)) + (4*(x)*(x)) - 10)
#define df(x) ((3*(x)*(x)) + (8*(x)))

double x[N+1];
double f[N+1];
double calculated_df[N+1];
double dynamic_df[N+1];


double ford(int x2, int x1)
{
    return ((f[x2] - f[x1]) / (x[x2] - x[x1]));
}

double cent(int x2, int x0)
{
    return ((f[x2] - f[x0]) / (x[x2] - x[x0]));
}

double back(int x1, int x0)
{
    return ((f[x1] - f[x0]) / (x[x1] - x[x0]));
}

int main()
{


    // variable declaration
    double a = 0.0;
    double b = 10.0;
    double max_diff = -1000009;
    dynamic_df[0] = ford(1, 0);
    dynamic_df[0] = back(N, N-1);
    x[0] = 0;
    f[0] = func(0);


    // build x
    for(int i=1; i<=N; i++){
        x[i] = x[i-1] + (b-a)/N;  // making the array of x
        f[i] = func(x[i]);  // making the array of f
        calculated_df[i] = df(x[i]);
    }


    // define the max difference
    double diff = fabs(calculated_df[0] - ford(1, 0));
    if(max_diff <= diff) max_diff = diff;

    diff = fabs(calculated_df[N] - back(N, N-1));
    if(max_diff <= diff) max_diff = diff;
        
  

    // printing the values as table formate
    printf("x             f             df               calculated df\n");
    printf("--------      ---------     ---------        --------\n");
    printf("%lf      %lf      %lf        %lf\n", x[0], f[0], ford(1, 0), calculated_df[0]);

    for (int i = 1; i < N; i++)
    {
        // calculating the dfs...
        dynamic_df[i] = cent(i-1,i+1);
        double calc_df = calculated_df[i];
        printf("%lf      %lf      %lf          %lf\n", x[i], f[i], dynamic_df[i], calc_df);
        
        // calculating max differences
        diff = fabs(calc_df - dynamic_df[i]);
        if(max_diff <= diff) max_diff = diff;
    }

    printf("%lf      %lf      %lf          %lf\n", x[N], f[N], back(N, N-1), calculated_df[N]);

    printf("\nMAX DIFFERECE: %lf\n", max_diff);

}