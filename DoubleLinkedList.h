//
// Created by Maxim Dolzhenko on 02.03.2024.
//

#ifndef TASK3_DOUBLELINKEDLIST_H
#define TASK3_DOUBLELINKEDLIST_H

#include <iostream>
#include <vector>
#include <string>

template <class T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_back() {
        if (size == 0) {
            std::cout << "List is empty, cannot pop back" << std::endl;
        } else {
            Node* lastNode = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete lastNode;
            size--;
        }
    }

    void reversePrint() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif //TASK3_DOUBLELINKEDLIST_H
