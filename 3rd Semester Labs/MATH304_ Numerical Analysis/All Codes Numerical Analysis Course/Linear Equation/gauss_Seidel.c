// author: Fahad

#include <stdio.h>
#include <math.h>
#define N 3
#define EPS 1e-9
#define f1(x, y, z) ((85 - 3 * (y) + 2 * (z)) / 15)
#define f2(x, y, z) ((51 - 2 * (x) -z) / 10)
#define f3(x, y, z) ((5 - (x) + 2 * (y)) / 8)

int a[N][N], b[N], x[N], nx[N], e[N]; 

int main()
{

    double ox1 = 0, ox2 = 0, ox3 = 0, nx1, nx2, nx3, e1, e2, e3;

    int cnt = 0;

    while (1)
    {

        nx1 = f1(ox1, ox2, ox3);
        nx2 = f2(nx1, ox2, ox3);    // just placed new x1 value insead of old x1
        nx3 = f3(nx1, nx2, ox3);    // just placed new x1,x2 value insead of old x1,x2

        e1 = fabs(nx1 - ox1);
        e2 = fabs(nx2 - ox2);
        e3 = fabs(nx3 - ox3);

        cnt++;
        
        if (e1 < EPS && e2 < EPS && e3 < EPS)
        {
            printf("X: %lf, Y: %lf, Z: %lf\n", nx1, nx2, nx3);
            printf("itr: %d\n", cnt);
            break;
        }

        else
        {
            ox1 = nx1;
            ox2 = nx2;
            ox3 = nx3;
        }

    }
}