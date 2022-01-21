#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	string data;
	cin >> data;

	cout << "Transition State: ";

	char current_state = 'a';

	for(int i=0; i<data.size(); i++){

		if(current_state == 'a'){
		
			if (data[i] == '0'){
				
				cout << "A ";
				current_state = 'a';

			}
			else{

				cout << "B ";
				current_state = 'b';
			}
		}

		else if(current_state == 'b'){
			
			if (data[i] == '0'){

				cout << "A ";
				current_state = 'a';

			}
			
			else{
				
				cout << "*C ";
				current_state = 'c';
				
			}	
		}

		else if(current_state == 'c'){
			
			if (data[i] == '0'){
				
				cout << "A " ;
				current_state = 'a';

			}
			
			else{

				cout << "*C ";
				current_state = 'c';

			}
		}

	}

	if(current_state == 'c') cout << "\nACCEPTED!!!";
	else cout << "\nREJECTD!";

}