//
// Created by ANIL on 11/26/2020.
//

#ifndef SUPERMARKET_QUEUE_SUPERMARKET_H
#define SUPERMARKET_QUEUE_SUPERMARKET_H
#include <queue>
using namespace std;

class Supermarket {
private:
    queue<int> reg1;
    queue<int> reg2;
    queue<int> express;
public:
    void add_customer(int items);
    void add_customer_smart(int items);
    void simulate();

private:
    int processing_time(int items);
};


#endif //SUPERMARKET_QUEUE_SUPERMARKET_H
