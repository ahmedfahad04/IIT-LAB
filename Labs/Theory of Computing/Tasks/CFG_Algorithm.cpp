#include <bits/stdc++.h>
using namespace std;

int substrmatch(string data, string sub)
{

    for (int i = 0; i < data.size(); i++)
    {
        int cnt = 0;
        int id = i;
        int start = i;

        for (int j = 0; j < sub.size(); j++)
        {

            if (data[id++] == sub[j])
            {
                cnt++;
                // printf("%c--%c\n", data[i], sub[j]);
                if (cnt == sub.size())
                {
                    return start;
                }
            }
            else
            {
                break;
            }
        }
    }

    return -1;
}

string strreplace(string info, int pos, int lastPos, string with)
{

    string ans = "";

    for (int i = 0; i < info.size(); i++)
    {

        if (i == pos)
        {
            // replace

            for (int j = 0; j < with.size(); j++)
            {
                ans += with[j];
            }

            i += lastPos;
        }
        else
            ans += info[i];
    }

    return ans;
}

int main()
{

    freopen("cfg.txt", "r", stdin);

    vector<pair<string, string>> formates;
    formates.push_back({"0", "E"});
    formates.push_back({"1", "E"});

    int productions;
    cin >> productions;

    // taking user input
    for (int i = 0; i < productions; i++)
    {
        string form, to;
        cin >> to >> form;

        formates.push_back({form, to});
    }


    string user_input, updated_input = "";
    cin >> user_input;

    int terminal = 1;

    // initilize the input with "E"
    for (int i = 0; i < user_input.size(); i++)
    {
        if (user_input[i] == '1' || user_input[i] == '0')
        {
            terminal += 1;
            updated_input += 'E';
        }
        else
        {
            updated_input += user_input[i];
        }
    }

    // main execution point
    while (terminal--)
    {
        int flag = 0;

        for (int i = 2; i < productions + 2; i++)
        {
            int matchingIdStart = substrmatch(updated_input, formates[i].first);

            if (matchingIdStart != -1)
            {
                int endpos = formates[i].first.size();
                updated_input = strreplace(updated_input, matchingIdStart, endpos - 1, formates[i].second);
                cout << updated_input << endl;
            }
        }
    }


    // cout << updated_input << endl;
    if (updated_input.size() == 1)
    {
        cout << "ACCEPTED\n";
    }
    else
        cout << "REJECTED\n";
        
}