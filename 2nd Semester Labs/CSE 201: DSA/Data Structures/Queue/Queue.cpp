#include <bits/stdc++.h>
#define N 5
using namespace std;

int q[N];
int head = 0;
int tail = 0;

bool isempty(){
    if(head == tail) return 1;
    else return 0;
}

bool isfull(){
    if(tail == N) return 1;
    else return 0;
}

void enqueue(int value){
    if(isfull()) {
        cout << "Queue is Full. Cant Insert " << value << endl;
        return;
    }
    q[tail] = value;
    tail++;
    cout << value << " has been pushed in queue.\n";
}

void dequeue(){
    if(isempty()){
        cout << "Queue is Empty. Nothing to be poped out.\n";
        return;
    }
    cout << q[head] << " has been deleted.\n";
    head++;

}


void printq(){
    for(int i =head; i<tail;i++){
        cout << "Element: " << q[i] << endl;
    }
}

int main(){
    enqueue(5);
    enqueue(8);
    enqueue(3);
    enqueue(11);
    enqueue(1551);
    enqueue(99);
    dequeue();
    dequeue();

    
    cout << "\nQueue is: \n" ;
    printq();
    cout << "SIZE: " << fabs(tail-head) << endl;
 
}