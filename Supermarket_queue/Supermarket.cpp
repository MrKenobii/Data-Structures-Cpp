//
// Created by ANIL on 11/26/2020.
//

#include "Supermarket.h"
#include <iostream>
#include<time.h>
void Supermarket::add_customer(int items){
    int random_number = rand() % 3;
    if(random_number == 0)
        reg1.push(items);
    else if(random_number == 1)
        reg2.push(items);
    else
        express.push(items);
}

void Supermarket::add_customer_smart(int items){
    if(items <= 5){
        express.push(items);
    }else if(reg1.size() < reg2.size()){
        reg1.push(items);
    }else{
        reg2.push(items);
    }
}

void Supermarket::simulate(){

    int reg1_avg = 0;
    int reg1_tot = 0;
    int reg1_count = 0;

    while(!reg1.empty()){
        int t = processing_time(reg1.front());
        reg1_tot += t;
        reg1_avg += reg1_tot;
        reg1.pop();
        reg1_count++;
    }

    int reg2_avg = 0;
    int reg2_tot = 0;
    int reg2_count = 0;

    while(!reg2.empty()){
        int t = processing_time(reg2.front());
        reg2_tot += t;
        reg2_avg += reg2_tot;
        reg2.pop();
        reg2_count++;
    }

    int exp_avg = 0;
    int exp_tot = 0;
    int exp_count = 0;

    while(!express.empty()){
        int t = processing_time(express.front());
        exp_tot += t;
        exp_avg += exp_tot;
        express.pop();
        exp_count++;
    }

    cout << "Average waiting time is: " << ((double)(reg1_avg + reg2_avg + exp_avg))/(reg1_count + reg2_count + exp_count) <<" second"<< endl;
    cout << "Time required to serve all customers: " << max(max(reg1_tot, reg2_tot), exp_tot) << " second"<<endl;

}
int Supermarket::processing_time(int items) {
    return items *3+45;
}