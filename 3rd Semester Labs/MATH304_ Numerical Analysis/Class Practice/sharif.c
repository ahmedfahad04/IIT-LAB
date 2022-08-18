#include <stdio.h>
#include <math.h>
#define epsilon 1.0e-9
#define N 100
int a[N][N];
int b[N];

double f1(double x, double y, double z)
{
    return ((b[1] - y * a[1][2]) - z * (a[1][3])) / a[1][1];
}

double f2(double x, double y, double z)
{
    return ((b[2] - x * a[2][1]) - z * (a[2][3])) / a[2][2];
}

double f3(double x, double y, double z)
{
    return ((b[3] - x * a[3][1]) - y * (a[3][2])) / a[3][3];
}

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{

    double xo1 = 0, xo2 = 0, xo3 = 0;
    double x_error, y_error, z_error;
    double xn1, xn2, xn3;
    int cnt = 0;

    printf("Enter the left part of augmented matrix : \n");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the right part of augmented matrix : \n");
    for (int i = 1; i <= 3; i++)
        scanf("%d", &b[i]);

    if (((a[1][1] <= abs(a[1][2]) + abs(a[1][3])) && (a[2][2] <= abs(a[2][1]) + abs(a[2][3])) && (a[3][3] <= abs(a[3][1]) + abs(a[3][2]))) == 1)
    {
        printf("Can not be solved in Jacobi method\n");
        return 0;
    }

    else
    {
        printf("Enter the right part of augmented matrix : \n");
        for (int i = 0; i < 3; i++)
            scanf("%d", &b[i]);

        while (1)
        {
            xn1 = f1(xo1, xo2, xo3);
            xn2 = f2(xo1, xo2, xo3);
            xn3 = f3(xo1, xo2, xo3);

            x_error = fabs(xo1 - xn1);
            y_error = fabs(xo2 - xn2);
            z_error = fabs(xo3 - xn3);

            if (x_error < epsilon && y_error < epsilon && z_error < epsilon)
            {
                printf("%d iterations, x, y ,z = %lf, %lf, %lf", cnt, xn1, xn2, xn3);
                return 0;
            }

            else
            {
                xo1 = xn1;
                xo2 = xn2;
                xo3 = xn3;
            }
            cnt++;
        }
        return 0;
    }
}