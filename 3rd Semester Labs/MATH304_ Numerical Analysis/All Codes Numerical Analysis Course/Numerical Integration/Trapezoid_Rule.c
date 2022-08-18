// author: Jubayer Vai

#include <stdio.h>
#include<math.h>
#include<stdlib.h>

double f(double x) {
    return (x*x) + 1;
}

int main() {
    
    int n = 200;
    double a = 0, b = 1;
    double h = (b-a) / n;


    double x = 0;
    double sum = 0;
    sum = (f(a) + f(b)) / 2;
    
    for(int i = 1; i < n; i++) {
        x += h;
        sum += f(x);
    }

    sum *= h;

    printf("Area(Trapezoid): %.9lf\n", sum);
    
    return 0;
}