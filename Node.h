//
// Created by marwa on 9/17/2026.
//
# pragma once

template <typename T>
class Node {

public:
    T *value;
    Node<T> *next;

    Node(T *value) {
        this->value = value;
        next = nullptr;
    }
    void print() {
        value->print();
    }
};