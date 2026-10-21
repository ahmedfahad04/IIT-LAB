#include <bits/stdc++.h>
#define N 30
using namespace std;

string tree[N];
int node_num=1;

// root node
void root(string value)
{
    if(tree[1] != "") cout << "Already Have a ROOT";
    
    else tree[1] = value;
    
}

// assigning LEFT node
void left_node(string value, int parent)
{

    int x = (2 * parent);  //2k

    if (x >= N)
    { //check if the index is out of SIZE
        cout << "Overflow.\n";
        return;
    }

    if (tree[parent] == "")
    { //check if I have any parent node at this index
        cout << "No Parent Node Found at " << parent << ". Cant Insert Child Node\n";
        return;
    }

    if (tree[x] == "")
    { //check if I already filled this node
        tree[x] = value;
        cout << tree[x] << " has been added as LEFT node of NODE_NO: " << parent << endl;
    }
    else
    {
        cout << "Error!!! Already Initalized with " << tree[x] << ". Try other Nodes" << endl;
    }
}

// assigning RIGHT node
void right_node(string value, int parent)
{
    int x = (2 * parent) + 1; //2k+1

    if (x >= N)
    { //check if the index is out of SIZE
        cout << "Overflow.\n";
        return;
    }

    if (tree[parent] == "")
    { //check if I have any parent node at this index
        cout << "No Parent Node Found at " << parent << ". Cant Insert Child Node\n";
        return;
    }

    if (tree[x] == "")
    { //check if I already filled this node
        tree[x] = value;
        cout << tree[x] << " has been added as RIGHT node of NODE_NO: " << parent << endl;
    }
    else
    {
        cout << "Error!!! Already Initalized with " << tree[x] << ". Try other Nodes" << endl;
    }
}

// getting index of LEFT node
int get_left_child(int index){
    
    int x = (2 * index); //2k
    if(tree[x] != "" && x<N){
        return (2*index);
    }
    else return -1;
}

// getting index of RIGHT node
int get_right_child(int index){
    
    int x = (2 * index) + 1; //2k+1
    if(tree[(2*index)+1] != "" && x<N){
        return (2*index)+1;
    }
    else return -1;
}

// PREODRDER Traversal 
void PreOrder_Traverse(int id){
    
    if(tree[id] != "" && id > 0){
        cout << tree[id] << " ";
        PreOrder_Traverse(get_left_child(id));
        PreOrder_Traverse(get_right_child(id));
    }
}

// INORDER Traversal
void InOrder_Traverse(int id){
    
    if(tree[id] != "" && id > 0){
        InOrder_Traverse(get_left_child(id));
        cout << tree[id] << " ";
        InOrder_Traverse(get_right_child(id));
    }
}

// POSTORDER Traversal
void PostOrder_Traverse(int id){
    
    if(tree[id] != "" && id > 0){
        PostOrder_Traverse(get_left_child(id));
        PostOrder_Traverse(get_right_child(id));
        cout << tree[id] << " ";
    }
}

// printing Binary Tree
void printTree()
{
    int level = floor(log2(node_num));

    cout  << "TREE upto Level "<< level << " : ";
    for (int i = 1; i <= pow(2,level+1); i++)
    {
        
        if (tree[i] == "")
        {
            cout << "_ ";
        }
        else{   
            cout << tree[i] <<'('<< i << ')'<< " ";
        }
    }
    puts("");
}

int main()
{
    for (int i = 0; i < N; i++)
        tree[i] = "";

    // assigning root value
    string r; cout << "Enter the value of Root node: " ;cin >> r ;
    root(r); 
    
    // list of variables
    int count = 0,choice, p_node;
    string l_node, r_node;
    char exit;

    //loop for taking inputs
    while (1)
    {
        
        printf("Enter your choice: \n");
        printf("\tPress 1 for Add Left Child\n\tPress 2 for Add Right Child \n\tPress 3 for Exit\n>> ");
        cin >> choice;
        fflush(stdin);

        if (choice == 1)
        {
            cout << "Enter LEFT Node and Parent Node respectively: ";
            cin >> l_node;
            cin >> p_node;
            puts("");
            node_num++;
            left_node(l_node, p_node);
        }

        else if (choice == 2)
        {
            cout << "Enter RIGHT Node and Parent Node respectively: ";
            cin >> r_node;
            cin >> p_node;
            puts("");
            node_num++;
            right_node(r_node, p_node);
        }

        else if(choice == 3){
            break;
        }

        else
        {
            cout << "Wrong Input. Enter Again.\n";
            continue;
        }

        
    }


    // printing Binary Tree as Array
    puts("\nBinary Tree Representation Using Array(Number in braces indicate the index & underscore means absence of node): ");
    printTree();
    puts("");

    // printing Tree Traversal Sequence
    puts("Binary Tree Traversal: ");
    puts("Pre Order Traversal:\n>>");
    PreOrder_Traverse(1);
    puts("");
    puts("In Order Traversal:\n>>");
    InOrder_Traverse(1);
    puts("");
    puts("Post Order Traversal:\n>>");
    PostOrder_Traverse(1);
    puts("");
}