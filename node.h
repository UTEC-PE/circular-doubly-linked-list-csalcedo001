#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    void killSelf() {
        if (prev) {
            prev = nullptr;
            next->killSelf();

            delete this;
        }
    }
    void print_next(Node <T> *end) {
        if (next != end)
            next->print_next(end);

        cout << data << " ";
    }
};

#endif
