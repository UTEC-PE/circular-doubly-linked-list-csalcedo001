#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator() {
            current = nullptr;
        };
        Iterator(Node<T>* node) {
            current = node;
        }

        Iterator<T> operator=(Iterator<T> node) {
            current = node.current;
            return current;
        }
        bool operator!=(Iterator<T> cmp) {
            return current != cmp.current;
        }
        Iterator<T> operator++() {
            if (current)
                current = current->next;

            return *this;
        }
        Iterator<T> operator--() {
            if (current)
                current = current->prev;

            return *this;
        }
        T operator*() {
            return current->data;
        }
};

#endif
