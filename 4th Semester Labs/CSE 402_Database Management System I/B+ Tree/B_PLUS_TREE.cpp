#include <bits/stdc++.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
using namespace std;
using namespace std::chrono;

// NUMBER OF MAX CHILD;
int n, maxNodes;

struct NODE
{
    int totalNodes;
    NODE *parentNode, *nextNode;
    string *ENGLISH, *BANGLA;
    bool isLeaf;
    NODE **nodePointers;
};

NODE *root;

// CREATE NEW NODE ADDING NEW ADDRESS SPACE DYNAMICALLY
NODE *CREATE_NODE()
{
    NODE *newNode = new NODE(); // DYNAMICALLY ALLOCATE SPACE

    newNode->totalNodes = 0;
    newNode->ENGLISH = new string[n];
    newNode->BANGLA = new string[n];
    newNode->parentNode = NULL;
    newNode->nextNode = NULL;
    newNode->isLeaf = true;
    newNode->nodePointers = new NODE *[n+1]; // THIS NEW NODE CAN POINT N+1 OTHER NODES

    return newNode;
}

// NEW ROOT NODE
void CREATE_NEW_ROOT(NODE *parentNode, string value, NODE *leftNode, NODE *rightNode)
{
    parentNode = CREATE_NODE();
    parentNode->ENGLISH[0] = value;
    parentNode->nodePointers[0] = leftNode;
    parentNode->nodePointers[1] = rightNode;
    parentNode->totalNodes++;
    parentNode->isLeaf = false;

    root = parentNode;                  // ASSIGN NEW NODE AS CURRENT NODE
    leftNode->parentNode = parentNode;  // ASSIGN LEFT NODE OF ROOT
    rightNode->parentNode = parentNode; // ASSIGN RIGHT NODE OF ROOT
}

// SEARCH NODE
NODE *SEARCH_NODE(NODE *tempRoot, string english)
{
    while (tempRoot->isLeaf == false)
    {
        int i;
        for (i = 0; i < tempRoot->totalNodes; i++)
        {
            // cout << tempRoot->ENGLISH[i] << endl;
            if (english < tempRoot->ENGLISH[i])
                break;
        }
        // cout << endl;

        tempRoot = tempRoot->nodePointers[i];
    }

    return tempRoot;
}

// ADD NODE WITH PARENT NODE
void ADD_NODE_WITH_PARENT(NODE *parentNode, string value, NODE *rightNode)
{
    int i = parentNode->totalNodes - 1; // TO ENSURE 0 BASED INDEXING

    for (; i >= 0; i--)
    {
        if (parentNode->ENGLISH[i] <= value)
            break;
        else
        {
            parentNode->ENGLISH[i + 1] = parentNode->ENGLISH[i];
            parentNode->nodePointers[i + 2] = parentNode->nodePointers[i + 1];
        }
    }
    parentNode->ENGLISH[i + 1] = value;
    parentNode->nodePointers[i + 2] = rightNode;
    parentNode->totalNodes++;
}

// RECURSIVELY CHECK TO INSERT NEW NODE
// IN THE MIDDLE OF SPLITTED NODE
void INSERT_NODE_IN_MIDDLE(NODE *parentNode, string value, NODE *leftNode, NODE *rightNode)
{
    // IF NO ROOT EXISTS, CREATE A ROOT
    if (parentNode == NULL)
    {
        CREATE_NEW_ROOT(parentNode, value, leftNode, rightNode);
        return;
    }

    // (WHEN ROOT EXISTS) ADD CHILD NODE WITH PARENT NODE
    rightNode->parentNode = parentNode;
    ADD_NODE_WITH_PARENT(parentNode, value, rightNode);

    // WHEN NODE VALUE OVERFLOWS, POINT TO NEXT NODE
    if (parentNode->totalNodes == maxNodes)
    {
        NODE *nextNode = CREATE_NODE();
        nextNode->isLeaf = false;

        int j = 0;
        for (int i = parentNode->totalNodes - (n) / 2; i < maxNodes; i++)
        {
            nextNode->ENGLISH[j] = parentNode->ENGLISH[i];
            if (j == 0)
            {
                nextNode->nodePointers[0] = parentNode->nodePointers[i];
                nextNode->nodePointers[0]->parentNode = nextNode;
            }

            nextNode->nodePointers[j + 1] = parentNode->nodePointers[i + 1];
            nextNode->nodePointers[j + 1]->parentNode = nextNode;
            j++;
        }
        parentNode->totalNodes -= (n) / 2 + 1;
        nextNode->totalNodes = (n) / 2;

        // RECURSIVE CALL
        INSERT_NODE_IN_MIDDLE(parentNode->parentNode, parentNode->ENGLISH[parentNode->totalNodes], parentNode, nextNode);
    }
}

// ADD NODE WITH VALUES (ENGLISH, BANGLA PAIR)
void ADD_LEAF_NODE(string ENGLISH, string BANGLA)
{
    NODE *leaf = SEARCH_NODE(root, ENGLISH); // FIND WHERE WE CAN FIT NEW NODES
    int i = leaf->totalNodes - 1;

    // SHIFT NODE POSITION TO RIGHT
    if (i > -1)
    {
        for (; i >= 0; i--)
        {
            if (ENGLISH < leaf->ENGLISH[i])
            {
                leaf->ENGLISH[i + 1] = leaf->ENGLISH[i];
                leaf->BANGLA[i + 1] = leaf->BANGLA[i];
            }
            else
                break;
        }
    }

    leaf->ENGLISH[i + 1] = ENGLISH;
    leaf->BANGLA[i + 1] = BANGLA;
    leaf->totalNodes++;

    // SPLIT CURRENT NODE TO CREATE TWO LEAF NODE
    if (leaf->totalNodes == maxNodes)
    {
        NODE *splitNODE = CREATE_NODE();

        int j = 0;
        for (int i = leaf->totalNodes - n / 2; i < maxNodes; i++)
        {
            splitNODE->ENGLISH[j] = leaf->ENGLISH[i];
            splitNODE->BANGLA[j] = leaf->BANGLA[i];
            j++;
        }
        leaf->totalNodes -= n / 2;
        splitNODE->totalNodes = n / 2;
        splitNODE->nextNode = leaf->nextNode;
        leaf->nextNode = splitNODE;

        INSERT_NODE_IN_MIDDLE(leaf->parentNode, splitNODE->ENGLISH[0], leaf, splitNODE);
    }
}

// BUILD B+ TREE
int BUILD_TREE()
{
    string ENGLISH, BANGLA;

    root = CREATE_NODE();

    ifstream fileptr;
    fileptr.open("dictionary.txt");

    if (!fileptr)
    {
        cout << "FILE NOT FOUND";
        return 0;
    }

    
    auto START = high_resolution_clock::now();
    // BUILD B+ TREE
    while (fileptr >> ENGLISH)
    {
        getline(fileptr, BANGLA);
        ADD_LEAF_NODE(ENGLISH, BANGLA);
    }
    auto STOP = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(STOP - START);
    cout << "TIME TAKEN TO BUILT B++ TREE: " << (duration.count()) << " MILISECONDS\n";

    return 1;
}

// SEARCH IN ALREADY BUILT B+ TREE
void SEARCH()
{
    int i = 0;
    string SEARCH_KEY;
    NODE *leaf;

    // SEARCH_NODE
    cout << "\nEnter Text: ";
    while (cin >> SEARCH_KEY)
    {
        if (SEARCH_KEY == "exit")
            break;

        auto START = high_resolution_clock::now();
        leaf = SEARCH_NODE(root, SEARCH_KEY);

        for (i = 0; i < leaf->totalNodes; i++)
            if (SEARCH_KEY == leaf->ENGLISH[i])
                break;

        if (i == leaf->totalNodes)
            cout << "WORD NOT FOUND\n";
        else
            cout << SEARCH_KEY << " " << leaf->BANGLA[i] << endl;

        auto STOP = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(STOP - START);

        cout << "ELAPSED TIME: " << duration.count() << " MICROSECONDS\n";
        cout << "\nEnter Text: ";
    }
}


int main(void)
{

    cout << "\nEnter Number of Block Pointer: ";
    cin >> n;
    maxNodes = n;

    if(maxNodes < 2){
        cout << "BLOCK POINTER MUST BE GREATER THAN 1\n";
        return 0;
    }

    cout << "BUILDING B+ TREE...\n";
    if (BUILD_TREE() == 0)
        cout << "FAILD TO BUILD B+ TREE";
    else
        cout << "TREE BUILT SUCCESSFULLY!!\n";

    SEARCH();
}