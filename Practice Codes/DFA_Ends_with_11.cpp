#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	string data;
	cin >> data;

	cout << "Transition State: ";

	// 5 tuple explained

	char states[] = {'a', 'b', 'c'};
	char alphabets[] = {'0', '1'};
	char starting_state = states[0];
	char finishing_state = states[2];
	char current_state = starting_state;


	for(int i=0; i<data.size(); i++){

		if(current_state == states[0]){
		
			if (data[i] == alphabets[0]){
				
				cout << "A ";
				current_state = states[0];

			}
			else{

				cout << "B ";
				current_state = states[1];
			}
		}


		else if(current_state == states[1]){
			
			if (data[i] == alphabets[0]){

				cout << "A ";
				current_state = states[0];

			}
			
			else{
				
				cout << "*C ";
				current_state = states[2];
				
			}	
		}


		else if(current_state == states[2]){
			
			if (data[i] == alphabets[0]){
				
				cout << "A " ;
				current_state = states[0];

			}
			
			else{

				cout << "*C ";
				current_state = states[2];

			}
		}

	}


	if(current_state == finishing_state) cout << "\nACCEPTED!!!";
	else cout << "\nREJECTD!";

}