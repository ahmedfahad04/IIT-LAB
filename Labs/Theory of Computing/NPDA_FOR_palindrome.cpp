#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<char> pda;
    pda.push('Z');

    int mid = 2, flag = 1;
    vector<char> state;

    string input;
    cin >> input;

    int len = input.size();

    fflush(stdin);

    for (int i = 2; i < len; i++)
    {
        for (int j = 0;; j++)
        {
            // cout << "TOP: " << pda.top() << endl;

            if (input[j] == '\0')
            {
                if (pda.top() == 'Z')
                {
                    state.push_back('C');
                    cout << "C ";
                }
                else
                {
                    state.push_back('B');
                    cout << "B ";
                }

                break;
            }

            if ((j) < mid)
            {
                // push - A
                // state = 'A';
                state.push_back('A');
                pda.push(input[j]);
                cout << "push " << input[j] << endl;
            }
            else
            {
                // pop - B
                // state = 'B';
                state.push_back('B');

                if (!pda.empty())
                {
                    if(pda.top() == input[j]){
                        state.push_back('B');
                        pda.pop();

                    } else {
                        flag = 0;
                        break;
                    }
                    cout << "pop " << pda.top() << endl;
                }
            }

            
        }

        if(flag == 0) break;

        state.clear();
        mid++;
        cout << mid << endl;
        cout << endl;
    }


    if(flag == 0) cout << "REJECTED\n";
    else cout << "AC:\n";
}