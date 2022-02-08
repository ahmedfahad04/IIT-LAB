#include <bits/stdc++.h>
#define ll int
#define UP 1
#define LEFT 2
#define DIAGONAL 3
#define N 100005
using namespace std;

int A[N], previ[N], sum[N], sorted_A[N];

int c[100][100], b[100][100];

void LCS_LENGTH(char x[], char y[], int row){

    row = col;

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
                b[i][j] = DIAGONAL; 
            }

            else{
            	
                if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = UP; 
                }
                
                else{
                    c[i][j] = c[i][j-1];
                    b[i][j] = LEFT; 
                }
            }
        }
    }
}

void Print_LIS(char x[], int i, int j){

    if (i==0 or j ==0) return;

   
    if (b[i][j] == DIAGONAL){  
        Print_LIS(x, i-1, j-1);
        cout << x[i] << " "; 
    }

    
    else if (b[i][j] == UP){
        Print_LIS(x, i-1, j);
        
    }

    
    else if (b[i][j] == LEFT){
        Print_LIS(x, i, j-1);
    }

}

int main(){

    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> A[i];
        cin >> sorted_A[i];
    }

    sort(sorted_A, sorted_A+n);

    ll index = LCS_LENGTH(A, sorted_A, n);
    for(int i=1; i<=n; i++) cout << previ[i] << " ";
    cout << endl;
    //print_LIS(index);

}