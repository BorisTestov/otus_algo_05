#pragma once

#include "linkedlist.h"

template<class T>
class PriorityQueueList {
private:
    template<class N>
    class PriorityQueueNode {
    public:
        PriorityQueueNode() = default;

        PriorityQueueNode(unsigned int _priority, N _data) {
            priority = _priority;
            data = _data;
        }

        unsigned int priority;
        N data;
    };

public:
    /**
     * Меньшие приоритеты - в начале списка.
     * При вытаскивании элемента берется тот, у которого наибольший (с конца, правый)
     * при добавлении нового события с уже существующим приоритетом новое считается более приоритетным
     * и добавляется левее
     */
    PriorityQueueList() = default;

    bool empty() {
        return queue.empty();
    }

    void print() {
        for (auto iterator = queue.begin(); iterator != queue.end(); iterator++) {
            PriorityQueueNode<T> node = *iterator;
            std::cout << "|" << node.priority << "_" << node.data;
        }
        std::cout << std::endl;
    }

    void enqueue(unsigned int priority, T item) {
        unsigned int position = 0;
        for (auto iterator = queue.begin(); iterator != queue.end(); iterator++) {
            PriorityQueueNode<T> node = *iterator;
            if (node.priority > priority) {
                PriorityQueueNode<T> nodeToInsert(priority, item);
                queue.push(nodeToInsert, position);
                return;
            }
            ++position;
        }
        PriorityQueueNode<T> nodeToInsert(priority, item);
        queue.push(nodeToInsert);
    }

    T dequeue() {
        auto extractedNode = queue.pop();
        return extractedNode.data;
    }

private:
    LinkedList<PriorityQueueNode<T>> queue;
};
