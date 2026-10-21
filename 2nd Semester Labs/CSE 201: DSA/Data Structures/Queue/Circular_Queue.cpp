#include <bits/stdc++.h>
using namespace std;
#define N 5

int q[N];
int front = -1;
int rear = -1;

// check if the queue is full
bool isFull()
{
    if (rear == front - 1 || rear == N - 1)
    {
        cout << "Overflow. ";
        return 1;
    }
    return 0;
}

// check if the queue is empty
bool isEmpty(){
    if ((rear == -1 && front == -1) || (front == rear + 1))
    {
        cout << "Empty Queue\n";
        return 1;
    }
    return 0;
}

// push new element
void enqueue(int value)
{
    if(isFull()) {
        cout << "Cant insert " << value << endl;
        return;
    }

    if (front == -1)
    {
        front++;
    }

    rear = (rear % N) + 1;
    q[rear] = value;
    printf("%d is inserted.\n", value);
}

// delete top element
void deq()
{
    if(isEmpty()){
        return;
    }

    cout << q[front] << " has been deleted.\n";
    front = (front % N) + 1;
}

// display the queue
void printq()
{
    for (int i = front; i <= rear; i++)
    {
        printf("Element: %d\n", q[i]);
    }
}

int main()
{
    enqueue(5);
    enqueue(11);
    enqueue(89);
    enqueue(70);
    enqueue(63);
    enqueue(85);
    deq();
    deq();
    
    cout << "\nQueue is: \n" ;
    //cout << "Front: " << front << " END: " << rear << endl;
    printq();
}