#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

string uniqChar(string x, string y)
{
    set<char> res;

    for (int i = 0; i < x.size(); i++)
    {
        if (!res.count(x[i]))
            res.insert(x[i]);
    }

    for (int i = 0; i < y.size(); i++)
    {
        if (!res.count(y[i]))
            res.insert(y[i]);
    }

    string ans = "";
    for (char a : res)
    {
        ans += a;
    }

    return ans;
}

int main()
{

    freopen("ENFA2.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int nState, nAlphabets, nFinishStates;
    string startState;
    vector<char> states, alphabets;
    vector<pair<string, vector<string>>> table, FinalAns;
    vector<pair<string, string>> dTable, eClosure;
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
    alphabets.push_back('e');
    for (int i = 0; i < nAlphabets; i++)
    {
        // cout << "Alphabet " << i+1 << ": ";

        char a;
        cin >> a;
        alphabets.push_back(a);
    }

    nAlphabets += 2; // for e closure

    // cout << "Enter the state Transition Table: ";
    for (int i = 0; i < nState; i++)
    {

        string parent;
        cin >> parent;

        vector<string> child;
        string eChild;
        eChild += parent;

        for (int j = 0; j < nAlphabets - 1; j++) // +1 for handing epsilon col
        {
            string c;
            cin >> c;
            child.push_back(c);

            if (j == 0 and c != "phi")
                eChild += c; // only for e closure
        }

        table.push_back({parent, child});
        eClosure.push_back({parent, eChild});
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

    cout << "\nTransition Table for E-NFA\n";
    // header of the table
    for (int i = 0; i < nAlphabets - 1; i++) // -1 for epsilon col
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << "\t\t"
         << "e-closure";
    cout << "\n--------------------------------------------------------------------\n";

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
            // cout << table[i].second[j] << "\t\t";

            if (j == nAlphabets - 1)
            {
                cout << eClosure[i].second;
            }
            else
            {
                cout << table[i].second[j] << "\t\t";
            }
        }

        cout << endl;
    }

    cout << "\n\n";

    // //--------------------------------------NFA TO DFA PROCESSING---------------------------------------

    // now making the dfa table from NFA; a , a bc
    // dTable.push_back({table[0].first, table[0].second});
    dTable.push_back({table[0].first, eClosure[0].second});

    // compute the DFA named set
    // ===> for (int i = 0; i < nAlphabets; i++)
    track.push(dTable[0].second);

    // enlist those states that's processing is over
    // ==> done.insert(table[0].first);

    // cout << dTable[0].first << " " << dTable[1].second[0] << endl;

    while (1)
    {
        if (track.empty())
            break;

        string pState = track.top();
        // cout << ">> " <<pState << endl;
        track.pop();

        if (done.count(pState) or pState == "X")
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

        } // A, C

        // for (string a : indivStates)
        //     cout << "EXTRACTED State Length: " << a << endl;

        // now find corresponding sub states of each singly identified states
        for (int i = 1; i < nAlphabets - 1; i++) // 0
        {
            // in each turn I have to calculate for a single alphabet...
            for (string singleState : indivStates) // first A and then C
            {
                // cout << "STATE: " << singleState << endl;
                for (int j = 0; j < nState; j++)
                {
                    if (table[j].first == singleState)
                    {
                        /*
                        e closure special starts
                        */

                        string toFind = table[j].second[i];
                        // cout << "TOFIND: " << toFind << endl;

                        for (int c = 0; c < toFind.size(); c++) // CD
                        {
                            for (int k = 0; k < nState; k++)
                            {
                                string point = "";
                                point += toFind[c];

                                if (table[k].first == point)
                                {
                                    // cout << "LEFT: " << table[j].first << ", RIGHT: " << eClosure[k].second << endl;

                                    newDFASubState = uniqChar(newDFASubState, eClosure[k].second);
                                    newDFASubState += "";
                                    break;
                                }
                            }
                        }

                        /*
                        e closure special ends
                        */
                    }
                }

            }
            
            if(newDFASubState.size() == 0) newDFASubState = "X";
            tmp.push_back(newDFASubState);

            if (!DFA.count(newDFASubState))
            {
                DFA.insert(newDFASubState);
                track.push(newDFASubState);
            }

            // cout << "ALPHA: " << i << ", STATE: " << newDFASubState << endl;
            newDFASubState.clear();
            // fflush(stdin);
        }

        done.insert(pState);
        FinalAns.push_back({pState, tmp});
        for (string u : tmp)
        {
            // cout << "*** ANS: " << u << endl;            
            dTable.push_back({pState, u}); // ==>
        }
        tmp.clear();
        // cout << endl;
    }

    // //--------------------------------------FINAL OUTPUT---------------------------------------

    cout << "\nTransition Table for DFA\n";
    // header of the table
    for (int i = 1; i < nAlphabets-1; i++)
    {
        cout << "\t\t" << alphabets[i];
    }

    cout << "\n-----------------------------------------\n";

    // DFA table info
    for (int i = 0; i < FinalAns.size(); i++)
    {

        if (i == 0)
            cout << "->" << FinalAns[i].first << "\t\t";
        else
        {
            int flag = 1;
            for (int j = 0; j < FinalAns[i].first.size(); j++)
            {

                char ch = FinalAns[i].first[j];
                string s;
                s += ch;

                if (finishingStates.count(s))
                {
                    cout << " *" << FinalAns[i].first << "\t\t";
                    flag = 0;
                    break;
                }
            }

            if (flag)
                cout << setw(4) << FinalAns[i].first << "\t\t";
        }

        for (int j = 0; j < nAlphabets - 2; j++)
        {
            cout << FinalAns[i].second[j] << "\t\t";
        }

        cout << endl;
    }
}
