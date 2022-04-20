#include <bits/stdc++.h>
using namespace std;

string info;
vector<string> states, inputState, nfaState;

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

int evenPalindrome()
{
    int flag = 1, rej = 1;

    for (int k = 2; k < info.size(); k++)
    {
        // here k means estimated middle point
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
            {
                inputState.push_back("e");

                if (pda.top() == 'Z')
                {
                    nfaState.pop_back();
                    nfaState.push_back("Q3");
                }
            }
            else
                inputState.push_back(x);
        }

        if (flag)
        {
            if (pda.top() == 'Z')
            {
                cout << "\n** ACCEPTED **\n\n";
                rej = 0;
                break;
            }
        }

        flag = 1;

        if (k != info.size() - 1)
        {
            states.clear();
            inputState.clear();
            nfaState.clear();
        }
    }

    return rej;
}

int oddPalindrome()
{
    int flag = 1, rej = 1;
    states.clear();
    inputState.clear();
    nfaState.clear();

    for (int k = 2; k < info.size(); k++)
    {
        // here k means estimated middle point
        stack<char> pda;
        pda.push('Z');

        for (int i = 0; i < info.size(); i++)
        {
            if (i == k)
                continue; // odd length palindrome

            else if (i < k)
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
            {
                inputState.push_back("e");

                if (pda.top() == 'Z')
                {
                    nfaState.pop_back();
                    nfaState.push_back("Q3");
                }
            }
            else
                inputState.push_back(x);
        }

        if (flag)
        {
            if (pda.top() == 'Z')
            {
                cout << "\n** ACCEPTED **\n\n";
                rej = 0;
                break;
            }
        }

        flag = 1;

        if (k != info.size() - 1)
        {
            states.clear();
            inputState.clear();
            nfaState.clear();
        }
    }

    return rej;
}

int main()
{

    cout << "Enter string to Test: ";
    cin >> info;

    fflush(stdin);
    int stat = 0;

    int evPal = evenPalindrome();
    if (evPal == 1)
    {
        if (evPal == 1)
            // cout << "\n** REJECTED **\n\n";
        stat = 1;
    }
    else
    {
        for (int i = 0; i < states.size(); i++)
        {
            cout << "delta(" << nfaState[i] << ", " << inputState[i] << ", " << states[i] << ")" << endl;
        }
        // stat = 1;
    }

    if (stat)
    {

        int oddPal = oddPalindrome();
        if (oddPal == 1)
        {
            if (evPal == 1)
                cout << "\n** REJECTED **\n\n";
            
        }
        else
        {
            for (int i = 0; i < states.size(); i++)
            {
                cout << "delta(" << nfaState[i] << ", " << inputState[i] << ", " << states[i] << ")" << endl;
            }
        }
    }

    
}