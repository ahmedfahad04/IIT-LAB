#include <bits/stdc++.h>
using namespace std;

string stackState(stack<char> st)
{

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infoState(string str, int id)
{

    string ans = "";
    for (int i = id; i < str.size(); i++)
    {
        ans += str[i];
    }

    return ans;
}

int main()
{

    string info;
    vector<string> states, inputState, nfaState;
    cin >> info;

    fflush(stdin);

    int flag = 1, rej = 1;

    for (int k = 2; k < info.size(); k++)
    {
        stack<char> pda;
        pda.push('Z');

        for (int i = 0; i < info.size(); i++)
        {
            if (i < k)
            {
                pda.push(info[i]);
                // cout << "PUSH: " << info[i] << endl;
                nfaState.push_back("Q1");
            }
            else
            {
                if (pda.top() == info[i])
                {
                    // cout << "POP: " << pda.top() << endl;
                    pda.pop();
                    nfaState.push_back("Q2");
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            states.push_back(stackState(pda));
            string x = infoState(info, i + 1);

            if (x.size() == 0)
                inputState.push_back("e");
            else
                inputState.push_back(x);
        }

        if (flag)
        {
            if (!pda.empty() and pda.top() == 'Z')
            {
                cout << "\n** ACCEPTED **\n\n";
                rej = 0;
                break;
            }
        }

        flag = 1;

        if (k != info.size()-1)
        {
            states.clear();
            inputState.clear();
            nfaState.clear();
        }
    }

    if (rej == 1)
        cout << "\n** REJECTED **\n\n";

    for (int i = 0; i < states.size(); i++)
    {
        cout << "delta(" << nfaState[i] << ", " << inputState[i] << ", " << states[i] << ")" << endl;
    }
}