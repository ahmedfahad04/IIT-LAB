#include <bits/stdc++.h>
#define N 200
using namespace std;

int q[N];
int head = 0;
int tail = 0;
int size = 0;

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
        //cout << "Queue is Full. Cant Insert element\n";
        return;
    }

    q[tail] = value;
    tail++;
    //cout << value << " has been pushed in queue.\n";
}

void dequeue(){
    if(isempty()){
        cout << -1 ;
        //cout << "Queue is Empty. Nothing to be poped out.\n";
        return;
    }
    cout << q[head];
    head++;
}


void printq(){
    for(int i =head; i<tail;i++){
        cout << "Element: " << q[i] << endl;
    }
}

int main(){
   int nop;
   cin >> nop;

   while(nop--){
       char ch;
       cin >> ch;
       if(ch == 'E'){
            int x;
            cin >> x;
            enqueue(x);
            cout << fabs(tail - head) << endl;
       }
       else{
        dequeue();
        cout << " " << fabs(tail - head) << endl;
    
       }
   }
 
}