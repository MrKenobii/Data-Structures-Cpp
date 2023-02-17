//
// Created by ANIL on 11/26/2020.
//

#ifndef QUEUE_LINKEDLIST_QUEUE_H
#define QUEUE_LINKEDLIST_QUEUE_H
class Queue {
public:
    Queue();
    Queue(const Queue& Q);
    ~Queue();

    bool isEmpty() const;
    bool enqueue(int newItem);
    bool dequeue();
    bool dequeue(int& queueFront);
    bool getFront(int& queueFront)const;
    void print();
private:
    struct QueueNode{
        int item;
        QueueNode* next;
    };
    QueueNode* backPtr;
    QueueNode* frontPtr;

};


#endif //QUEUE_LINKEDLIST_QUEUE_H
