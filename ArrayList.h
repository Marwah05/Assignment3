//
// Created by marwa on 9/15/2026.
//

# pragma once

#include <iostream>
using namespace std;

template <typename T>

class ArrayList {
public:
    ArrayList():size(0) {

    }
    void add(T item) { // O(n) - adds to the beginning of the list
        if (size>=CAPACITY) {
            cout<<"Array is full" <<endl;
            return;
        }
        for (int i=size;i>0;i--) { // describe what this loop does
            data[i]=data[i-1];
        }
        data[0]=item;
        size++;
    }
    void deleteFront() { // O(n) - deletes the front of the list
            if (size==0) {
                cout<<"Array is empty." <<endl;
                return;
            }
            for (int i=0;i<size-1;i++) {
                // figure out why it's size -1
                data[i]=data[i+1];
            }
            size--;
        }
    bool search(T item) { // O(n) - searches through the list
        if (size==0) {
            cout<<"Array is empty"<<endl;
            return false;
        }
        for (int i=0;i<size;i++) {
            if (data[i]==item) {
                return true;
            }
        }
        return false;
    }

    void addEnd(T item) { // O(1) - adds to the end of the list
        if (size==CAPACITY) {
            cout<<"Array is full." <<endl;
            return;
        }
        data[size] = item;
        size++;
    }

    void deleteEnd() { // O(1) - deletes the end of the list
        if (size==0) {
            cout<<"Array is empty." <<endl;
            return;
        }
        size--;
    }

    void printArray() {
        for (int i=0;i<size;i++) {
            cout<<data[i]<<",";
        }
        cout<<endl;
    }

private:
    static const int CAPACITY = 20;
    T data[CAPACITY];
    int size;
};