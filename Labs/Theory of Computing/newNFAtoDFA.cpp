#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

string uniqChar(string x, string y){
    set<char> res;

    for(int i=0; i<x.size(); i++){
        if(!res.count(x[i])) res.insert(x[i]);
    }

    for(int i=0; i<y.size(); i++){
        if(!res.count(y[i])) res.insert(y[i]);
    }

    string ans = "";
    for(char a: res){
        ans += a;
    }

    return ans;
}

int main()
{

    freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);

    int nState, nAlphabets, nFinishStates;
    string startState;
    vector<char> states, alphabets;
    vector<pair<string, vector<string>>> table, dTable;
    set<string> finishingStates, done, DFA;
    stack<string> track;


    //--------------------------------------INPUT---------------------------------------
    // cout << "Enter number of states: ";
    cin >> nState;

    for (int i = 0; i < nState; i++)
    {
        // cout << "State " << i+1 << ": ";

        char s;
        cin >> s;
        states.push_back(s);
    }

    // cout << "Enter number of alphabets: ";
    cin >> nAlphabets;

    for (int i = 0; i < nAlphabets; i++)
    {
        // cout << "Alphabet " << i+1 << ": ";

        char a;
        cin >> a;
        alphabets.push_back(a);
    }

    // cout << "Enter the state Transition Table: ";
    for (int i = 0; i < nState; i++)
    {

        string parent;
        cin >> parent;

        vector<string> child;
        for (int j = 0; j < nAlphabets; j++)
        {
            string c;
            cin >> c;
            child.push_back(c);
        }

        table.push_back({parent, child});
    }

    // cout << "Enter the start state: ";
    cin >> startState;

    // cout << "How many finishing states do you have: ";
    cin >> nFinishStates;

    for (int i = 0; i < nFinishStates; i++)
    {
        string b;
        cin >> b;
        finishingStates.insert(b);
    }

    //--------------------------------------OUTPUT 1---------------------------------------


    cout << "STT for NFA\n";
    // header of the table
    for (int i = 0; i < nAlphabets; i++)
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << endl;

    // table info
    for (int i = 0; i < nState; i++)
    {
        if (table[i].first == startState)
            cout << "->" << table[i].first << "\t\t";
        else if (finishingStates.count(table[i].first))
            cout << " *" << table[i].first << "\t\t";
        else
            cout << "  " << table[i].first << "\t\t";

        for (int j = 0; j < nAlphabets; j++)
        {
            cout << table[i].second[j] << "\t\t";
        }

        cout << endl;
    }

    cout << "\n\n";

    //--------------------------------------NFA TO DFA PROCESSING---------------------------------------

    // now making the dfa table from NFA; a , a bc
    dTable.push_back({table[0].first, table[0].second});

    // compute the DFA named set
    for (int i = 0; i < nAlphabets; i++) track.push(dTable[0].second[i]);
        
    // enlist those states that's processing is over
    done.insert(table[0].first);

    //cout << dTable[0].first << " " << dTable[1].second[0] << endl;



    while (1)
    {
        if (track.empty())
            break;

        string pState = track.top();
        cout << pState << endl;
        track.pop();

        if (done.count(pState))
        {
            continue;
        }

        string newDFASubState;
        vector<string> indivStates;
        vector<string> tmp;

        // extract states from the clutter
        for (int k = 0; k < pState.size(); k++)
        {
            if (isalpha(pState[k]))
            {
                string xx;

                xx += pState[k];
                indivStates.push_back(xx);
            }

        } // a and b

        cout << "EXTRACT: " << indivStates.size() << endl;


        // now find corresponding sub states of each singly identified states
        for (int i = 0; i < nAlphabets; i++) // 0
        {
            // ==> need to debug
            // in each turn I have to calculate for a single alphabet...
           for (string singleState : indivStates) // first a and then b
            {
                for (int j = 0; j < nState; j++)
                {
                    if (table[j].first == singleState && table[j].second[i] != "phi")
                    {
                        newDFASubState = uniqChar(newDFASubState, table[j].second[i]);
                        newDFASubState += "";
                        break;
                    }
                }
            }

            tmp.push_back(newDFASubState);

            if (!DFA.count(newDFASubState))
            {
                DFA.insert(newDFASubState);
                track.push(newDFASubState);
            }
            cout << "ALPHA: " << i << "DFA: " << newDFASubState << endl;
            newDFASubState.clear();
            //fflush(stdin);
        }


        done.insert(pState);
        dTable.push_back({pState, tmp});
        tmp.clear();
    }

    //--------------------------------------FINAL OUTPUT---------------------------------------

    cout << "STT for DFA\n";
    // header of the table
    for (int i = 0; i < nAlphabets; i++)
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << endl;


    // DFA table info
    for (int i = 0; i < dTable.size(); i++)
    {

        if (i == 0)
            cout << "-> " << dTable[i].first << "\t\t";
        else
        {
            int flag = 1;
            for (int j = 0; j < dTable[i].first.size(); j++)
            {

                char ch = dTable[i].first[j];
                string s;
                s += ch;

                if (finishingStates.count(s))
                {
                    cout << " *" << dTable[i].first << "\t\t";
                    flag = 0;
                    break;
                }
            }

            if (flag)
                cout << setw(4) <<dTable[i].first << "\t\t";
        }

        for (int j = 0; j < nAlphabets; j++)
        {
            cout << dTable[i].second[j] << "\t\t";
        }

        cout << endl;
    }
}
