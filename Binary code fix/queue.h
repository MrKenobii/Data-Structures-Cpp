//
// Created by ANIL on 12/3/2020.
//

#ifndef LABWORK_RANDOM_QUEUE_H
#define LABWORK_RANDOM_QUEUE_H
#include <stack>
using namespace std;
class Queue {
private:
    stack<int> s1, s2;
public:
    void enQueue(int x);
    int deQueue();

};


#endif //LABWORK_RANDOM_QUEUE_H
