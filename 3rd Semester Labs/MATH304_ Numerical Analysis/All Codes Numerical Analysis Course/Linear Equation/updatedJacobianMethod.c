#include <stdio.h>
#include <math.h>
#define N 4
#define EPS 1e-6

int a[N][N], bb[N], x[N], nx[N], e[N]; 

double f1(double x, double y, double z){

    return ((bb[1] - y * a[1][2] - z * a[1][3])/(a[1][1]));
}

double f2(double x, double y, double z){

    return ((bb[2] - x * a[2][1] - z * a[2][3])/(a[2][2]));

}

double f3(double x, double y, double z){

    return ((bb[3] - x * a[3][1] - y * a[3][2])/(a[3][3]));

}


int main()
{
    freopen("in.txt", "r", stdin);

    //printf("Enter the value of a: \n");
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            //printf("a[%d][%d]: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }

    //printf("\nEnter value of b: \n");
    for(int i=1; i<=3; i++){
        //printf("b[%d]: ", i);
        scanf("%d", &bb[i]);
    }

    // check diagonally dominance or not
    int flag = 0;
    for(int i=1; i<=3; i++){
        int tmp = 0;

        for(int j=1; j<=3; j++){
            if(i != j) tmp += abs(a[i][j]);
        }

        if(abs(a[i][i]) >= tmp) flag = 1;
        //printf("%d---%d\n", abs(a[i][i]), tmp);
    }

    if(flag) printf("Possible\n");
    else {
        printf("Impossible to solve this equation");
        return;
    }

    int cnt = 0;
    double ox1 = 0, ox2 = 0, ox3 = 0, nx1, nx2, nx3, e1, e2, e3;


    while (1)
    {
        nx1 = f1(ox1, ox2, ox3);
        nx2 = f2(ox1, ox2, ox3);
        nx3 = f3(ox1, ox2, ox3);

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