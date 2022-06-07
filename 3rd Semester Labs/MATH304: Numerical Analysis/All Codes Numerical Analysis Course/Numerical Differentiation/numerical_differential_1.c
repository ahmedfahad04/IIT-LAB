// author: Jubayer Vai

#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 305

#define func(x) (((x)*(x)*(x)) + ((4*(x)*(x))) - 10)
#define dfunc(x) ((3*(x)*(x)) + (8*(x)))

double x[N];
double f[N];
double dfT[N];
double dfN[N];

double ford(int x2, int x1) {
    return ((f[x2] - f[x1]) / (x[x2] - x[x1]));
}

double cent(int x2, int x0) {
    return ((f[x2] - f[x0]) / (x[x2] - x[x0]));
}

double back(int x1, int x0) {
    return ((f[x1] - f[x0]) / (x[x1] - x[x0]));
}

double max(double x, double y) {
    if(x > y)
        return x;
    return y;
}


int main() {


    double a = 0, b = 10;
    int n = 6;
    double h = (b-a) / (double)n;

    x[0] = a;
    f[0] = func(x[0]);

    //printf("%lf", x[n]);

    for(int i = 1; i < n; i++) {
        x[i] = x[i-1] + h;
        f[i] = func(x[i]);
    }

    x[n] = b;
    f[n] = func(x[n]);

    dfT[0] = dfunc(x[0]);
    dfN[0] = ford(1, 0);

    
    double mx = -1e9, abs = 0;
    abs = fabs(dfT[0] - dfN[0]);
    mx = max(mx, abs);

    for(int i = 1; i < n; i++) {
        dfT[i] = dfunc(x[i]);
        dfN[i] = cent(i-1, i+1);
        
        abs = fabs(dfT[i] - dfN[i]);
        mx = max(mx, abs);
    }

    dfT[n] = dfunc(x[n]);
    dfN[n] = back(n, n-1);

    abs = fabs(dfT[n] - dfN[n]);
    mx = max(mx, abs);


    printf("MAX DIFF = %lf\n", mx);
    printf("H = %lf\n", h);


    for (int i = 0; i <= n; i++) {
        printf("x: %lf      f: %lf      dfT: %lf     dfN: %lf\n", x[i], f[i], dfT[i], dfN[i]);
    }
}