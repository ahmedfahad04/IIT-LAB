#include <bits/stdc++.h>

using namespace std;
const int total_transaction = 100;

//  R1(A) , R2(A) , R1(B) , R2(B) , R3(B) , W1(A) , W2(B)

vector<pair<pair<char, int>, string>> transaction, a;
set<int> Node[total_transaction];
set<int> tr_size;

int vis[total_transaction] = {0};
int parent = 0;
bool flag = true;

/*
    0 - not visited
    1 - visiting not
    2 - completed
*/

void dfs(int x)
{
    if (vis[x] == 1)
    {
        flag = false;
        cout << "\nCycle found\n";
        cout << parent << " -- " << x << " ";
        return;
    }
    if (vis[x] == 2)
    {
        return;
    }

    vis[x] = 1;
    parent = x;
    for (int i : Node[x])
    {
        dfs(i);
    }
    vis[x] = 2;
    return;
}

int main()
{

    fstream new_file;
    int N = 0;

    new_file.open("in.txt", ios::in);

    if (new_file.is_open())
    {
        string sa;
        while (getline(new_file, sa))
        {
            pair<pair<char, int>, string> operation;
            operation.first.first = sa[0];
            operation.first.second = sa[1] - 48;
            operation.second = sa[3];
            transaction.push_back(operation);
        }
        new_file.close();
    }
    else cout << "FIle not found\n";
    

    for (int i = 0; i < transaction.size(); i++)
    {
        char cur_op_type = transaction[i].first.first;
        int cur_tran_no = transaction[i].first.second;
        string cur_var = transaction[i].second;

        tr_size.insert(cur_tran_no);
        for (int j = i + 1; j < transaction.size(); j++)
        {
            char next_op_type = transaction[j].first.first;
            int next_tran_no = transaction[j].first.second;
            string next_var = transaction[j].second;

            if (tolower(cur_op_type) == 'w' or (tolower(cur_op_type) == 'r' and tolower(next_op_type) == 'w'))
            {
                if (cur_var == next_var and cur_tran_no != next_tran_no)
                {
                    Node[cur_tran_no].insert(next_tran_no);
                }
            }
        }
    }

    for (int tr : tr_size)
    {
        dfs(tr);
    }

    if (flag)
        cout << "\nconflict serializable\n";
    else
        cout << "\nnot conflict serializable\n";
}