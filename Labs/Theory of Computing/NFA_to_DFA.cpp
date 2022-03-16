#include <bits/stdc++.h>
using namespace std;

int main()
{

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    vector<pair<char, vector<string>>> transition_table;

    vector<char> states;
    vector<char> alphabets;
    vector<string> temp;

    int n;
    cout << "Enter number of states in DFA: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char ch;
        cout << "State " << i + 1 << ": "; // a,b,c..
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
        cout << "Alphabet " << i + 1 << ": "; // 0,1
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
            // char ch;
            // cin >> ch;          // states input..... now we'll take the input as string
            string innerStates;
            getline(cin, innerStates);

            temp.push_back(innerStates);
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
        for (string str : transition_table[i].second)
        {
            // cout << ch << "         ";
            printf("%s", str);
        }
        cout << endl;
    }
}
