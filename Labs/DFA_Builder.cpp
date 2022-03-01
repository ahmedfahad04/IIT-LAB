#include <bits/stdc++.h>
using namespace std;

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    vector<pair<char, vector<char>>> transition_table;

    vector<char> states;
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

        states.push_back(ch);
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

        transition_table.push_back({start, temp});
        temp.clear();
    }

    cout << "\nTransition Table: \n";
    printf("states      %-5c     %-5c\n", alphabets[0], alphabets[1]);
    printf("------    -----     -----\n");

    for (int i = 0; i < n; i++)
    {

        printf("%-10c", transition_table[i].first);
        for (char ch : transition_table[i].second)
        {
            // cout << ch << "         ";
            printf("%-10c", ch);
        }
        cout << endl;
    }

    char start_state, finish_state, current_state;
    cout << "\nEnter starting state: ";
    cin >> start_state;
    cout << "\nEnter finishing state: ";
    cin >> finish_state;
    current_state = start_state;
    cout << "\nEnter -1 to terminate the program...\n";

    string data;

    while (1)
    {
    
    	cout << "-----------------------------------------\n";
        cout << "\nEnter your string: ";
        cin >> data;

        current_state = start_state;

        if (data == "-1")
            break;

        cout << "Transition states: ";

        for (int i = 0; i < data.size(); i++)   // string to be tested...
        {
            for (int j = 0; j < transition_table.size(); j++)   // number of rows in transition table
            {
                if (current_state == transition_table[j].first) // a, it checks whether I am in the correct row of table or not
                {
                    // when get to the correct table row, check the alphabet of corresponding state
                    for (int st = 0; st < alpha; st++)  
                    {
                        if (data[i] == alphabets[st]) // 0
                        {
                            cout << transition_table[j].second[st] << " ";  // show the alphabet
                            current_state = transition_table[j].second[st]; // now point to that alphabet
                        }
                    }

                    break;
                }
            }
        }

        cout << endl;

        // cout << "\nFINISHING STATE: " << current_state << endl;

        if (current_state == finish_state)
            cout << "\nString ACCEPTED!!\n";
        else
            cout << "\nString REJECTED!\n";
            
          
    }
}
