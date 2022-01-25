#include <iostream>
using namespace std;

double k (double m, double v);


int main(){

	freopen("in.txt", "r", stdin);
	
	double m, v;
	cout << "Enter the mass; ";
	cin >> m;

	cout << "Enter the velocity: ";
	cin >> v;

	cout << k (m,v) << endl;
}

double k (double m, double v){
	return 0.5*m*v*v;
}
