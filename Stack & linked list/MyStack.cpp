#include "intSLList.h"

class MyStack {
private:
	IntSLList mylist;
	int size;
public:
	MyStack()
	{
		size = 0;
	}
	void push(int el) {
		mylist.addToHead(el);
		size++;
	}
	int top() {
		return mylist.firstEl();
	}
	int pop()
	{
		size--;
		return mylist.deleteFromHead();
	}

	int getSize() {
		return size;
	}
	void print() {
		mylist.printAll();
	}

};
