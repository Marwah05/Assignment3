//
// Created by marwa on 9/17/2026.
//

#pragma once
#include "Node.h"

template <typename T>
class LinkedList {
public:
    Node<T>* head;
    Node<T> *tail;
    int size;

    LinkedList(T *value) {
        Node<T> *temp = new Node<T>(value); // trees and graphs cannot be empty (there has to be at least one node)
        head = temp;
        tail = temp;
        size = 1;
    }
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void print() {
        Node<T> *temp1 = head;
        while (temp1!=nullptr) {
            temp1->print(); // never move head pointer
            temp1 = temp1->next;
        }
    }

    void append(T *value) { // adds to the back using a tail, O(1)
        Node<T> *newnode = new Node<T>(value);
        if (head ==nullptr) {
            head =newnode;
            tail =newnode;
            size++;
            return;
        }
        tail->next =newnode;
        tail = tail->next; // tail = newnode - also correct
        size++;
    }

    void addEnd(T *value) { // adds to the back without using a tail, O(n)
        Node<T> *newnode = new Node<T>(value);
        if (head ==nullptr) {
            head =newnode;
            size++;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        size++;
    }

    void addFront(T *value) { // adds to the front without tail, O(1) (with tail is the same
        Node<T> *temp = new Node<T>(value); // because you don't need tail to add to the front
        if (head ==nullptr) {
            head =newnode;
            tail =newnode;
            size++;
            return;
        }
        newnode->next = head;
        head =newnode;
        size++;
    }

    void deleteFront() { // delete front without a tail, O(1) (with tail is the same
        if (head ==nullptr) { // becase you don't need tail to delete the front
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteBack() { // deletes the back without a tail, O(n)
        if (head ==nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            size--;
            return;
        }
    Node<T> *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        size--;
    }

    void deleteEnd() { // deletes the back with a tail, O(n)
        if (head ==nullptr) {
            return;
        }
        if (head ==tail) {
            delete head;
            head =nullptr;
            tail =nullptr;
            size--;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }


};
// delete at the end and front
// add to the front and end
// with tail and without