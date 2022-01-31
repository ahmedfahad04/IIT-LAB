#include <bits/stdc++.h>
#define DELETE -1
#define INSERT -2
#define SUBSTITUE -3
#define UNCHANGED -4
using namespace std;


int c[100][100], b[100][100];
int m, n;

void ED(char x[], char y[], int row, int col){


    // initialize
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
        	
            c[i][j] = 0;
            b[i][j] = 0;
        }
    }

    
    for(int i=0; i<row; i++){
        c[0][i] = i; 
        b[0][i] = -2;
    }
    for(int i=0; i<row; i++){
        c[i][0] = i; 
        b[i][0] = -1;
    }


    // calculation
    for(int i=1; i<row; i++){

        for(int j=1; j<col; j++){
            
            int subs = c[i-1][j-1];
            int del = c[i-1][j];
            int insert = c[i][j-1];
            
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1];
                b[i][j] = UNCHANGED;
                
            }

            else{

            	int m1 = min(subs, del);
            	int minimum = min(m1, insert);

                //cout << x[i] << " " << y[j] << endl;
                if (minimum == subs){

                	// min = substitute
                    c[i][j] = c[i-1][j-1]+1;
                    b[i][j] = SUBSTITUE;
                    //cout << "SUBSTITUTE\n";
                       
                    
                }

                else if (minimum == c[i][j-1]){
                        // min = insert
                        c[i][j] = c[i][j-1]+1;
                        b[i][j] = INSERT;
                        //cout << "INSERT\n";
                }

                else{
                    
                    // min = del
                    c[i][j] = c[i-1][j]+1;
                    b[i][j] = DELETE;
                    //cout << "DEL\n";
                }
            }
        }
    }
}


void PRINT(char x[], char y[], int i, int j){

    if(j == 0 or i == 0) return;

    // cout << i << " " << j << endl;

    if(b[i][j] == SUBSTITUE){

        //cout << i << " " << j << endl;
        PRINT(x, y, i-1, j-1);
        cout << "substitue " << x[i] << " by "  << y[j] << endl;
    }

    else if(b[i][j] == INSERT){
        //cout << i << " " << j << endl;
        PRINT(x, y, i, j-1);
        cout << "insert " << y[j]  << endl; 
    }

    else if (b[i][j] == DELETE){
        //cout << i << " " << j << endl;
        PRINT(x, y, i-1, j);
        cout << "delete " << x[i] << endl; 
    }

    else if(b[i][j] == UNCHANGED){

        //cout << i << " " << j << endl;
        PRINT(x, y, i-1, j-1);

    }
    
}

int main(){

	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    
    string a,d;
	

    cin >> a >> d;

    m = a.size()+1;
    n = d.size()+1;

    char xx[m+1], yy[n+1];

    xx[0] = ' ';
    yy[0] = ' ';

    for(int i=1; i<m; i++) xx[i] = a[i-1];
    for(int i=1; i<n; i++) yy[i] = d[i-1];


    ED(xx, yy, m, n); 

    cout << "Edit Distance: " << c[m-1][n-1] << "\n\n";

    int i = m-1;
    int j = n-1;

    PRINT(xx, yy, i, j);

}