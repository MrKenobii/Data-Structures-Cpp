#include <iostream>
#include "queue.h"
using namespace std;
void print_pattern(string pattern){
// create an empty stack (we can also use set, queue, vector
    // or any other container)
    stack<string> list;
    list.push(pattern);        // push the pattern into the stack

    size_t index;

    // loop till stack is empty
    while (!list.empty())
    {
        // pop string from stack and process it
        string curr = list.top();
        list.pop();

        // index stores position of first occurrence of wildcard
        // pattern in curr
        if ((index = curr.find_first_of('?')) != string::npos)
        {
            for (int i = 0; i < 2; i++)
            {
                // replace '?' with 0 and 1 and push it to the stack
                curr[index] = i + '0';
                list.push(curr);
            }
        }

            // If no wildcard pattern is found, print the string
        else
            cout << curr << endl;
    }

}
int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << "Queue question" << endl;
    cout << "-----------------" << endl;
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << "-----------------" << endl;
    cout << " " << endl;
    cout << "All possible patterns" << endl;
    cout << "-----------------" << endl;

    string str = "1?11?00?1?";

    print_pattern(str);
    cout << "-----------------" << endl;
    return 0;
}
