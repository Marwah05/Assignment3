//
// Created by marwa on 9/17/2026.
//

#include "Data.h"
using namespace std;
#include <iostream>
#include <ostream>
#include <string>

class Data {
    public:
    int numID;
    string name;

    Data(int numID, string name) {
        this->numID = numID;
        this->name = name;
    }
    void print() {
        cout << name << " " << numID << endl;
    }
};
