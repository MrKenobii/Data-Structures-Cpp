#include <iostream>
#include "Queue.h"
using namespace std;
int main() {
    Queue *q=new Queue();
    for(int i=0;i<15;i++) q->enqueue(i);
    q->print();
    cout<<endl;
    q->dequeue();
    q->print();
    cout<<endl;
    Queue *q1=new Queue(*q);
    q1->print();
    return 0;
}
