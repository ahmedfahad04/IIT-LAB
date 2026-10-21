#include <bits/stdc++.h>
using namespace std;

//global variables
map<char, long int> freq;
map<char, string> prefix_code;
set<char> letters;
string encoded_message;
string decoded_message;
string message;
int n, bits, total = 0, new_bits = 0, new_total = 0; //n = heap size

struct node
{
    char data;
    int frequencey;
    node *left, *right;
};

struct node *Q[100];    //min-priority-queue

struct node *newnode(char info, long int freq, node *leftnode, node *rightnode)
{

    struct node *ptr = new node();

    ptr->data = info;
    ptr->frequencey = freq;
    ptr->left = leftnode;
    ptr->right = rightnode;

    return ptr;
}

void Min_heapify(node *ar[], int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && ar[smallest]->frequencey > ar[left]->frequencey)
        smallest = left;

    if (right < n && ar[smallest]->frequencey > ar[right]->frequencey)
        smallest = right;

    // if smallest is not the root
    if (smallest != i)
    {
        swap(ar[smallest], ar[i]);
        Min_heapify(ar, smallest);
    }
}

void min_heap_insert(node *array[], node *z)
{
    int index, parent;

    // heap insert
    index = ++n;
    parent = index / 2;
    array[index] = z;

    // heap increase key
    while (index > 1 && array[parent] > array[index])
    {
        swap(array[parent], array[index]);
        index = index / 2;
        parent = index;
    }

    return;
}

node *extract_min(node *arr[])
{

    node *min;
    min = arr[1];   // store the root node to 'min' named node
    arr[1] = arr[n]; // placed the last node to root node; used n instead of n-1 because we used ++n not n++ each time in insertion of every new node.
    n--;  // decrease the queue size by 1

    Min_heapify(arr, 1);    // heapy everytime so that this modification does not violate the min heap rule.

    return min;     // returing the root node.
}

void prefix_code_generator(node *root, string code)
{

    if (root->left == NULL && root->right == NULL)
    {

        if (root->data == ' ')
        {
            cout << " "
                 << "Space"
                 << "     | " << freq[root->data] << "           | " << code << endl;

            prefix_code[root->data] = code;
            new_bits += freq[root->data] * (code.size()); // for data comparision only
        }

        else if (root->data == '\n')
        {
            cout << " "
                 << "New Line"
                 << "  | " << freq[root->data] << "            | " << code << endl;

            prefix_code[root->data] = code;
            new_bits += freq[root->data] * (code.size()); // for data comparision only
        }

        else
        {
            cout << " " << root->data << "         | " << freq[root->data] << "            | " << code << endl;

            prefix_code[root->data] = code;
            new_bits += freq[root->data] * (code.size()); // for data comparision only
        }

        return;
    }

    prefix_code_generator(root->left, code + "0");
    prefix_code_generator(root->right, code + "1");
}

node *huffman_code()
{
    int i = 0;

    // makes a min heap based on distinct characters.
    for (auto x : letters)
    {
        node *temp = newnode(x, freq[x], NULL, NULL);
        min_heap_insert(Q, temp);
    }

    while (n != 1) // n = heap size
    {

        node *first = extract_min(Q);  // first node of min heap
        node *second = extract_min(Q); // second node of min heap

        node *z = newnode('\0', first->frequencey + second->frequencey, first, second);

        min_heap_insert(Q, z); // create a min heap after every new value insertion.
    }

    cout << "\nLetters    | Frequency    | Prefix Code\n";
    cout << "-----------------------------------------------\n";
    prefix_code_generator(Q[1], ""); // generates prefix codes. Q[1] because we assumed that the root node index would be 1, left = 2*1, right=2*1+1......

    return extract_min(Q);
}

void encode(string data)
{

    for (int i = 0; i < data.size(); i++)
    {
        encoded_message += prefix_code[message[i]];
    }
}

void decode(node *root, string data, int index)
{

    if (index == data.size() + 1)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        decoded_message += root->data;
        root = Q[1];
    }

    if (data[index++] == '0')
        decode(root->left, data, index);
    else
        decode(root->right, data, index);
}

void size_comparasion()
{

    // Before huffman coding
    bits = ceil(log2(message.size()));  //2^bit=total distinct characters => bit = log2(total distinct characters)
    total = bits * message.size();
    cout << "Before Compression: " << total << " bits" << endl;

    // After encoding
    new_total = new_bits * message.size();
    cout << "After Compression: " << new_bits << " bits" << endl;
}

int main()
{

    FILE *file;
    char x;
    file = fopen("data.txt", "r");

    while ((x = fgetc(file)) != EOF)
    {
        message += x;      // saving each character as message in string.
        freq[x]++;         // storing frequency of each char. in a map name 'freq'.
        letters.insert(x); // storing distinct char in a set.
    }

    // implementing huffman code
    node *ptr;
    ptr = huffman_code();

    //string input_message; //enter your message to encode it
    encode(message);
    cout << "\nEncoded Message: " << endl;
    cout << encoded_message << endl;

    //string message; //enter binary representation of your message to decode it
    decode(ptr, encoded_message, 0);
    cout << "\nDecoded Message: " << endl;
    cout << decoded_message << endl;

    // data size comparision
    cout << "\nComparison between data Size: " << endl;
    size_comparasion();
    puts("");
}
