#include <iostream>
#include "MyStack.cpp"

using namespace std;

int main()
{

   MyStack mystack;
   mystack.push(1);
   mystack.push(4);
   mystack.push(2);
   mystack.push(3);
   cout << "Stack nodes top to bottom is : ";
   mystack.print();

   int size = mystack.getSize();
   cout << "Size of the stack is " << size << endl;

   int popped = mystack.pop();
   cout << "The popped value is : " << popped << endl;
   cout<<"Stack nodes top to bottom is : ";
   mystack.print();

   int a = mystack.top();
   cout << "Top of the stack is : " << a << endl;

   size = mystack.getSize();
   cout << "The size of the stack is "<< size << endl;

    return 0;
}
