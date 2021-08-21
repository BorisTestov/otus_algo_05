#pragma once

#include "linkedlist.h"

template<class T>
class PriorityQueue {
public:
    PriorityQueue(unsigned int priorities) {
        _priorities = priorities;
        queue = new LinkedList<T>[priorities];
    }

    bool empty() {
        for (unsigned int i = 0; i < _priorities; ++i) {
            if (!queue[i].empty()) return false;
        }
        return true;
    }

    void print() {
        for (unsigned int i = 0; i < _priorities; ++i) {
            std::cout << i << " |";
            queue[i].print();
        }
    }

    void enqueue(unsigned int priority, T item) {
        if (priority > _priorities) throw std::out_of_range("Priority out of range");
        queue[priority].push(item);
    }

    T dequeue() {
        if (empty()) throw std::out_of_range("Priority queue is empty!");
        for (unsigned int i = 0; i < _priorities; ++i) {
            if (!queue[i].empty())
                return queue[i].pop(0);
        }
    }

private:
    unsigned int _priorities;
    LinkedList<T> *queue;
};