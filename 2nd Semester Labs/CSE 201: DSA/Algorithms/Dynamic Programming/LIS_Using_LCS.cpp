/*
    ### LIS using LCS ###
    
	input format:
	size of array
	array elements....

	output format:
	LIS: 
	Length of LIS:
*/

#include <bits/stdc++.h>
#define UP 1
#define LEFT 2
#define DIAGONAL 3
#define N 1000
using namespace std;

int c[100][100], b[100][100], size, a[N], x[N], len;

void LCS_LENGTH(int X[], int sortedX[]){

	int row = size + 1;
	int col = size + 1;

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
            
            
            if(X[i] == sortedX[j] and X[i] != X[i-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = DIAGONAL; 
            }

            else{
            	
                if(c[i-1][j] > c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    b[i][j] = UP; 
                }
                
                else {
                    c[i][j] = c[i][j-1];
                    b[i][j] = LEFT; 
                }
            }
        }
    }
}

void Print_LCS(int x[], int i, int j){

    if (i==0 or j ==0) return;

   
    if (b[i][j] == DIAGONAL){
        Print_LCS(x, i-1, j-1);
        len++;
        cout << x[i] << " "; 
    }

    
    else if (b[i][j] == UP){
        Print_LCS(x, i-1, j);  
    }

    
    else if (b[i][j] == LEFT){
        Print_LCS(x, i, j-1);
    }

}

int main(){

	freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

	cin >> size;

	for(int i=1; i<=size; i++){
		cin >> a[i];
		x[i] = a[i];
	}

	// sort
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size-1; j++){
			if(x[j] > x[j+1]){

				int t = x[j];
				x[j] = x[j+1];
				x[j+1] = t;

			}
		}
	}

	LCS_LENGTH(a, x);
	
	cout << "LIS: ";
	Print_LCS(a, size, size);
	
    cout << "\nLength of LIS: " << len << endl;

}