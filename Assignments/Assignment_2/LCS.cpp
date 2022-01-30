#include <bits/stdc++.h>
#define UP 1
#define LEFT 2
#define DIAGONAL 3
using namespace std;

int c[100][100], b[100][100];

void LCS_LENGTH(char x[], char y[], int row, int col){

    // initialize
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            c[i][j] = 0; 
            b[i][j] = 0;
        }
    } 


    // calculation
    for(int i=1; i<row; i++){

        for(int j=1; j<col; j++){
            
            
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 3;
                cout << x[i] << " " << y[j] << endl;
            }

            else{
                if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = 1;
                }
                else{
                    c[i][j] = c[i][j-1];
                    b[i][j] = 2;
                }
            }
        }
    }

}

void Print_LCS(char x[], int i, int j){

    if (i==0 or j ==0) return;

    if (b[i][j] == 3){
        Print_LCS(x, i-1, j-1);
        cout << x[i] << " "; 
    }

    else if (b[i][j] == 1){
        Print_LCS(x, i-1, j);
        
    }

    else if (b[i][j] == 2){
        Print_LCS(x, i, j-1);
    }

}


int main(){
    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    char x[100], y[100];
    int m, n;

    // taking input
    cin >> m >> n;

    m++;
    n++;

    x[0] = ' ';
    y[0] = ' ';

    for(int i=1; i<m; i++) cin >> x[i];
    for(int i=1; i<n; i++) cin >> y[i];


    // funtion call
    LCS_LENGTH(x, y, m, n);
    Print_LCS(x, m-1, n-1);

    
}