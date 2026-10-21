#include <bits/stdc++.h>
using namespace std;

// all global variables
string  tree[500];
string pre[100];
string post[100];
string in[100];
int pre_id = 0;
int n;

// building tree from PreOrder and InOrder traversal
void PreOrderTree(int start, int end, int tid)
{
    if (start > end || pre_id > n) // check if array traversing is completed or not
        return;

    string cur = pre[pre_id++]; // current index of PreOrder array

    if (start == end) 
    {
        tree[tid] = cur;
        return;
    }

    int i;
    for (i = start; i <= end; i++) // finding out the index of current element
    {
        if (in[i] == cur)
            break;
    }

    // recursion 
    PreOrderTree(start, i - 1, (2 * tid));
    PreOrderTree(i + 1, end, (2 * tid) + 1);
    tree[tid] = cur;
}

// building tree from PostOrder and InOrder traversal
void PostOrderTree(int start, int end, int *post_id, int tid)
{

    if (start > end || post_id < 0) // check if array traversing is completed or not
        return;

    string cur = post[(*post_id)--]; // current element of PostOrder traversal

    if (start == end)
    {
        tree[tid] = cur;
        return;
    }

    int i;
    for (i = start; i <= end; i++) // finding index of current element
    {
        if (in[i] == cur)
            break;
    }

    // recursion
    PostOrderTree(i + 1, end, post_id, (2 * tid) + 1);
    PostOrderTree(start, i - 1, post_id, (2 * tid));
    tree[tid] = cur;
}

int main()
{

    // initialize binary tree node value as NULL string
    for (int i = 0; i < 500; i++)
        tree[i] = "";

    string x;
    

    cout << "Enter you choice" << endl;
    cout << "Press 1: InOrder and PreOrder" << endl;
    cout << "Press 2: InOrder and PostOrder" << endl;
    
    int choice;
    cin >> choice;

    // Inorder and PreOrder
    if(choice == 1){

        cout << "Enter Number of Total Nodes: ";
        cin >> n;

        cout << "\nEnter InOrder Traversal Sequence: ";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            in[i] = x;
        }
       

        cout << "\nEnter PreOrder Traversal Sequence: ";
        for(int i=0;i<n;i++) {
            cin >> x;
            pre[i] = x;
        }

        PreOrderTree(0,n-1,1); //converter function

    }

    // InOrder and PostOrder
    else if(choice == 2){

        cout << "Enter Number of Total Nodes: ";
        cin >> n;

        cout << "\nEnter InOrder Traversal Sequence: ";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            in[i] = x;
        }


        cout << "\nEnter PostOrder Traversal Sequence: ";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            post[i] = x;
        }

        int post_id = n - 1;

        PostOrderTree(0, n-1, &post_id, 1); // converter function

    }

    
    int level = ceil(log2(n)); // level of binary tree starts from 0

    // printing Binary Tree as Array
    puts("\nBinary Tree Representation Using Array (underscore means absence of node): ");
    for (int i = 1; i < pow(2, level + 1); i++)
    {
        if (tree[i] != "")
            cout << tree[i] << " ";
        else
            cout << "_ ";
    }
}
