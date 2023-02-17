//
// Created by ANIL on 11/26/2020.
//

#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue() :backPtr(NULL),frontPtr(NULL){}
Queue::Queue(const Queue& Q) {
    if(Q.frontPtr==NULL)
        frontPtr=NULL;
    else{
        frontPtr=new QueueNode;
        frontPtr->item=Q.frontPtr->item;
        QueueNode* newPtr;
        for (QueueNode *origPtr =Q.frontPtr->next;origPtr != NULL;origPtr = origPtr->next){
            newPtr->next = new QueueNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;

    }
    if(Q.backPtr==NULL)
        backPtr=NULL;
    else{
        backPtr=new QueueNode;
        backPtr->item=Q.backPtr->item;
        QueueNode* newPtr;
        for (QueueNode *origPtr =Q.backPtr->next;origPtr != NULL;origPtr = origPtr->next){
            newPtr->next = new QueueNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;

    }

}

Queue::~Queue() {
    while (!isEmpty())
        dequeue();
}
bool Queue::isEmpty() const {
    return backPtr==NULL;
}
bool Queue::enqueue(int newItem) {
    QueueNode* newPtr=new QueueNode;
    newPtr->item=newItem;
    newPtr->next=NULL;
    if(isEmpty()) frontPtr=newPtr;
    else backPtr->next=newPtr;
    backPtr=newPtr;
    return true;
}
bool Queue::dequeue() {
    if (isEmpty()) return false;
    else{
        QueueNode* tempPtr=frontPtr;
        if(frontPtr==backPtr){
            frontPtr=NULL;
            backPtr=NULL;
        }
        else frontPtr=frontPtr->next;
        tempPtr->next=NULL;
        delete tempPtr;
        return true;
    }
}
bool Queue::dequeue(int& queueFront){

    if (isEmpty())
        return false;

    else{
        queueFront = frontPtr->item;
        dequeue();

        return true;
    }

}
bool Queue::getFront(int &queueFront) const {
    if (isEmpty()) return false;
    else{
        queueFront=frontPtr->item;
        return true;
    }
}
void Queue::print() {
    for(QueueNode *temp=frontPtr;temp!=NULL;temp=temp->next)
        cout << temp->item << " ";
    cout << endl;
}