#include <bits/stdc++.h>
#define BUFFER_SIZE 1024
using namespace std;

int strcontain(string data, char ch, int pos)
{

    int ans = -1;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == ch and i != pos)
        {
            ans = i;
        }
    }

    return ans;
}

string editString(string str, int pos)
{

    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        if(i == pos) ans += '\0';
        else ans += str[i];
    }

    return ans;
}

void removeEpsilon(string str, int markedPosition, set<string> &ans, char ch)
{

    if (str.size() <= 1)
    {

        // ans.push_back(str);
        return;
    }
    else
    {
        // cout << str << endl;
        int id = strcontain(str, ch, markedPosition);
        if (id > -1)
        {
            string newString;
            markedPosition = id;
            cout << markedPosition;

            // if (id == 0)
            //     newString = createString(str, 0, 1);
            // else
            //     newString = createString(str, 0, id);
            newString = editString(str, id);
            cout << ">> " << newString << endl;
            ans.insert(newString);

            removeEpsilon(str, markedPosition, ans, ch);
        }
    }
}

int main()
{

    freopen("cnf1.txt", "r", stdin);
    vector<pair<char, string>> production;

    int num;
    // cout << "How many production to be entered: ";
    cin >> num;

    // enter the production
    for (int i = 0; i < num; i++)
    {
        char var;
        string terminal;

        cin >> var;
        cin >> terminal;
        production.push_back({var, terminal});
    }

    string test = "AaA";
    set<string> res;
    int marked;
    res.insert(test);

    removeEpsilon(test, -1, res, 'A');

    for (auto x : res)
        cout << x << endl;
}