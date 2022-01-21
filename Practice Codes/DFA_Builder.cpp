#include <bits/stdc++.h>
using namespace std;

int main()
{

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	vector<pair<char, vector<char>>> states;

	vector<char> given_st;
	vector<char> alphabets, temp;

	int n;
	cout << "Enter number of states in DFA: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char ch;
		cout << "State " << i + 1 << ": ";
		cin >> ch;
		fflush(stdin);

		given_st.push_back(ch);
	}

	int alpha;
	cout << "\nHow many alphabets are there in your DFA: ";
	cin >> alpha;

	for (int i = 0; i < alpha; i++)
	{
		char k;
		cout << "Alphabet " << i + 1 << ": ";
		cin >> k;

		alphabets.push_back(k);
	}

	cout << "\nEnter the state transition table: \n";
	for (int i = 0; i < n; i++)
	{
		char start;
		cin >> start;

		for (int j = 0; j < alpha; j++)
		{
			char ch;
			cin >> ch;
			temp.push_back(ch);
		}

		states.push_back({start, temp});
		temp.clear();
	}

	cout << "\nTransition Table: \n";
	for (int i = 0; i < n; i++)
	{

		cout << states[i].first << "----";
		for (char ch : states[i].second)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	char start_state, finish_state, current_state;
	cout << "\nEnter starting state: ";
	cin >> start_state;

	cout << "\nEnter finishing state: ";
	cin >> finish_state;

	current_state = start_state;

	cout << "\nEnter -1 to terminate the program...\n.";

	string data = "5";

	while (1)
	{
		cout << "\nEnter your string: ";
		cin >> data;

		current_state = start_state;

		if (data == "-1") break;

		cout << start_state << " ";

		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < states.size(); j++)
			{
				if (current_state == states[j].first) // a
				{
					for (int st = 0; st < alpha; st++)
					{
						if (data[i] == alphabets[st]) // 0
						{
							cout << states[j].second[st] << " ";
							current_state = states[j].second[st];
						}
					}

					break;
				}
			}
		}

		cout << endl;

		cout << "\nFINISHING STATE: " << current_state << endl;

		if (current_state == finish_state)
			cout << "\nString ACCEPTED!!";
		else
			cout << "\nString REJECTED!";
	}
}
