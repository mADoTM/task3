#include <iostream>

template <typename T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T newData, Node* newPrev = nullptr, Node* newNext = nullptr)
                : data(newData), prev(newPrev), next(newNext) {}
    };

    Node* head;
    Node* tail;

public:
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return current != other.current;
        }
    };

    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    DoubleLinkedList(const DoubleLinkedList& other) : head(nullptr), tail(nullptr) {
        for (Node* current = other.head; current != nullptr; current = current->next) {
            push_back(current->data);
        }
    }

    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(T data) {
        Node* newNode = new Node(data, tail, nullptr);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator rbegin() {
        return Iterator(tail);
    }

    Iterator rend() {
        return Iterator(nullptr);
    }
};