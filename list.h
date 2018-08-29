#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

        int nodes;

    public:
        List() {
            start = nullptr;
            nodes = 0;
        }

        T front() {
            if (!start)
                return -1;

            return start->data;
        }
        T back() {
            if (!start)
                return -1;

            return start->prev->data;
        }
        void push_front(T value) {
            Node <T> *temp = new Node <T>;

            temp->data = value;

            if (start) {
                temp->next = start;
                temp->prev = start->prev;
                temp->next->prev = temp;
                temp->prev->next = temp;
            } else {
                temp->next = temp;
                temp->prev = temp;
            }

            start = temp;

            nodes++;
        }
        void push_back(T value) {
            Node <T> *tmp = new Node <T>;

            tmp->data = value;

            if (start) {
                tmp->next = start;
                tmp->prev = start->prev;
                tmp->next->prev = tmp;
                tmp->prev->next = tmp;
            } else {
                tmp->next = tmp;
                tmp->prev = tmp;

                start = tmp;
            }

            nodes++;
        }
        void pop_front() {
            if (!start)
                return;

            if (start == start->next) {
                delete start;
                start = nullptr;
                nodes--;
                return;
            }

            Node <T> *tmp = start;

            start->prev->next = start->next;
            start->next->prev = start->prev;

            start = start->next;

            nodes--;

            delete tmp;
        }
        void pop_back() {
            if (!start)
                return;

            if (start == start->next) {
                delete start;
                start = nullptr;
                nodes--;
                return;
            }

            Node <T> *tmp = start->prev;

            start->prev->prev->next = start;
            start->prev = start->prev->prev;

            nodes--;

            delete tmp;
        }
        T get(int position) {
            Node <T> *tmp = start;

            if (position >= 0)
                while (position--)
                    tmp = tmp->next;
            else
                while (position++)
                    tmp = tmp->prev;

            return tmp->data;
        }
        void concat(List<T> &other) {
            int length = other.nodes;
            Node <T> *tmp_other = other.start;

            if (!start && length--) {
                start = new Node <T>;

                start->data = tmp_other->data;
                start->next = start;
                start->prev = start;

                tmp_other = tmp_other->next;
            }


            while (length--) {
                Node <T> *tmp = new Node <T>;

                tmp->data = tmp_other->data;

                tmp->prev = start->prev;
                start->prev->next = tmp;

                start->prev = tmp;
                tmp_other = tmp_other->next;
            }

            start->prev->next = start;

            nodes += other.nodes;
        }
        bool empty() {
            return !nodes;
        };
        int size() {
            return nodes;
        }
        void clear() {
            start->killSelf();
            start = nullptr;
            nodes = 0;
        }
        Iterator<T> begin() {
            return Iterator <T> (start);
        }
        Iterator<T> end() {
            return Iterator <T> (start);
        }

        ~List() {
            clear();
        };
};

#endif
