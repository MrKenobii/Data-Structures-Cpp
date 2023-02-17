#include <iostream>
#include<time.h>
#include "Supermarket.h"
using namespace std;

int main() {
    Supermarket m1,m2;
    for(int i=0;i<500;i++){
        int items=rand()%20;
        m1.add_customer(items);
        m2.add_customer_smart(items);
    }
    cout << "Results for supermarket 1: \n ----------------" << endl;
    m1.simulate();
    cout << "Results for supermarket 2: \n ----------------" << endl;
    m2.simulate();
    return 0;
}
