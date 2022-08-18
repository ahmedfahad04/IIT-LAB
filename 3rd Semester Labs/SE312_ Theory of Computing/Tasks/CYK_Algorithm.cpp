#include <bits/stdc++.h>
using namespace std;

#define N 50

vector<string> solution[N];
string w;
vector<pair<char, string>> production;

string getValue(string text)
{

    string ans = "";

    for (auto u : production)
    {
        if (u.second == text)
        {
            ans += u.first;
        }
    }

    return ans;
}

vector<string> curtesianProduct(string a, string b)
{

    vector<string> ans;

    for (int i = 0; i < a.size(); i++)
    {

        for (int j = 0; j < b.size(); j++)
        {
            string temp = "", u = "", v = "";

            u = a[i];
            v = b[j];

            temp += (u + v);
            ans.push_back(temp);
        }
    }

    return ans;
}

string removeDuplicate(string x)
{

    set<char> alpha;
    string ans = "";

    for (int i = 0; i < x.size(); i++)
    {
        if (alpha.count(x[i]) == 0)
        {
            ans += x[i];
            // cout << "###->" << x[i];
            alpha.insert(x[i]);
        }
    }

    // cout << "ANS: " << ans;

    return ans;
}

// calculating the index for each cell
string evalEachCell(int i, int j)
{

    if (i == j)
    {
        string xij = "";

        xij += w[i - 1];
        return getValue(xij);
    }

    int level = j - i;
    int l1 = i;
    int r1 = i;
    int l2 = l1 + 1;
    int r2 = j;
    string xij = "";
    // cout << "\n**[" << i << ", "  << j << "]: \n";

    for (int k = 1; k <= level; k++)
    {
        string a, b;
        vector<string> temp;

        // cout << l1 << ", " << r1 << "---";
        // cout << l2 << ", " << r2 << endl;

        if (solution[l1 - 1][r1 - 1] == "")
        {
            a = getValue(evalEachCell(l1, r1));
        }
        else
            a = solution[l1 - 1][r1 - 1];

        if (solution[l2 - 1][r2 - 1] == "")
        {
            b = getValue(evalEachCell(l2, r2));
        }
        else
            b = solution[l2 - 1][r2 - 1];

        temp = curtesianProduct(a, b);
        for (string x : temp)
        {

            xij += getValue(x);
        }

        r1++;
        l2++;
    }

    return removeDuplicate(xij);
}

int main()
{
    freopen("cyk1.txt", "r", stdin);

    int num;
    //cout << "How many production to be entered: ";
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

    cout << endl;
    cin >> w;

    int len = w.size();
    int level = len;
    int dif = 0;

    // calculate the value of each cell of the TABLE
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            solution[i].push_back("null");
    }

    for (int i = 0; i < len; i++)
    {

        for (int row = 1; row <= level; row++)
        {
            // cout << "(" << row-1 << ", " << row + dif - 1 << ")";
            int u = row;
            int v = row + dif;
            solution[u - 1][v - 1] = evalEachCell(row, row + dif);   
        }

        dif++;
        level--;
    }


    // print the table
    int id = 0, k = 0;
    for (int i = 0; i < len; i++)
    {
        id = 0;
        for (int j = len - 1 - k; j < len; j++)
        {
            // cout << id++ << "," << j << " ";
            if (solution[id][j] == "null")
                continue;
            else if (solution[id][j] == "")
                cout << "-\t ";
            else
                cout << solution[id][j] << "\t ";
            id++;
        }
        k++;

        cout << endl;
    }


    // show the descision, if it's accepted or rejected
    int flag = 0;
    for (int i = 0; i < solution[0][len - 1].size(); i++)
    {

        if (solution[0][len - 1][i] == 'S')
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << " >> ACCEPTED! << \n";
    else
        cout << " >> REJECTED! <<\n";
}