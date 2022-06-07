/* Here we'll denote the pair of starting and finishing time as (start, finish) == (s,f)

input formate-
total activity
list of activites as pair

sample input:
5
5 7
2 4
3 8
3 6
1 6

The basic implementation of the algorithm is showed in the 'activity_selector' function.
Later on is an extra demonstration on how we can display all of the optimal solutions of "Activity 
Selection Problem"
*/

#include <bits/stdc++.h>
#define start first
#define finish second
#define mk make_pair
using namespace std;

// comparison function to sort the pair of (s,f) according to FINISHING time.
bool compsec(const pair<int, int> &a, const pair<int, int> &b){
	return(a.finish<b.finish);
}


// function to generate optimal activity selection
vector<pair<int,int>> activity_selector (vector<pair<int,int>> data, int initial_point){

	vector<pair<int,int>> result;
	result.push_back(data[initial_point]);

	int k = initial_point;

	for(int m=initial_point + 2; m < data.size(); m++){

		if(data[m].start >= data[k].finish){
			result.push_back(data[m]);
			k = m;
		}

	}

	return result;
}


int main(){

	// taking input form txt file
	freopen("input1.txt","r",stdin); 	//file input.txt is opened in reading mode i.e "r"
	//freopen("output.txt","w",stdout);   //file output.txt is opened in writing mode i.e "w"
	

	// vector of pairs 
	vector<pair<int, int>> p, ans, temp;
	vector<vector<pair<int, int>>> optimal_solutions;
	int n;


	// total number of pairs of (s,f)
	//cout << "How many pairs do you want to enter: ";
	cin >> n;


	// taking input
	//cout << "Enter start time and finish time correspondingly: ";
	for(int i=0; i<n; i++){

		// (start, finish)
		int a, b;
		cin >> a >> b;

		p.push_back(mk(a,b));
	}


	cout << "Given Data: \n";
	for(int i=0; i<n; i++){
		cout << "(" <<p[i].start  << ", " << p[i].finish << ") ";
	}


	// sort the pair of (s,f) using comparator 'compsec'
	sort(p.begin(), p.end(), compsec);


	cout << "\nSorted Data according to Finishing time: \n";
	for(int i=0; i<n; i++){
		cout << "(" <<p[i].start  << ", " << p[i].finish << ") ";
	}

	cout << endl;


	// it'll store the size of optimal (s,f) pair
	int opt_value = 0;


	// this loop will search through every possible pair to find the optimal solutions
	for(int i=0; i<n; i++){

		
		// vector of an optimal solution is returned to 'ans'
		// *** this function shows the basic implementation of the algorithm mentioned above ***
		ans = activity_selector(p, i);

		for(int i=0; i<ans.size(); i++){
			temp.push_back(mk(ans[i].start, ans[i].finish));
			//cout << "Start: " << ans[i].start << ", End: " << ans[i].finish << endl;
		}


		// we store the  vector of optimal solution to another vector so that 
		// we can display all possible optimal solutions we can get from the input 
		optimal_solutions.push_back(temp);
		temp.clear();


		// determining the size of the vector of optimal solution
		if(opt_value<=ans.size()) opt_value = ans.size();

	}



	int sol = 1;
	for(int i=0; i<n; i++){

		// print those vectors whose size is equal to the optimum solution vector size
		if(optimal_solutions[i].size() == opt_value){

			cout << "\nOptimal solution: " <<  sol++ << endl;

			// this loop prints the pairs of the optimal solution
			for(int j=0; j<opt_value; j++){
				cout << "Start: " << optimal_solutions[i][j].start << ", End: " << optimal_solutions[i][j].finish << endl;
			}

		}
	}

}
