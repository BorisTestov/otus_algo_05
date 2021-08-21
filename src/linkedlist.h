#pragma once

template<class T>
class node {
public:
    T data;
    node *next;
};

template<class T>
class LinkedList {
private:
    template<class N>
    class node {
        friend class LinkedList;

    public:
        node() = default;

        node(N _data) {
            data = _data;
        }

        N data;
        node *next;
    };

private:
    class iterator {
        friend class LinkedList;

    private:
        node<T> *nodePtr;

        iterator(node<T> *newPtr) : nodePtr(newPtr) {}

    public:
        iterator() : nodePtr(nullptr) {}

        bool operator!=(const iterator &other) const {
            return nodePtr != other.nodePtr;
        }

        T &operator*() const {
            return nodePtr->data;
        }

        iterator operator++(int) {
            iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }
    };

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

public:
    void push(T n) {
        auto newNode = new node<T>;
        newNode->data = n;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        _size++;
    }

    void push(T n, unsigned int index) {
        if (index > _size) throw std::out_of_range("Out of range");
        unsigned int current = 0;
        auto currentNode = head;
        while (current != index - 1) {
            currentNode = currentNode->next;
            ++current;
        }
        auto newNode = new node<T>;
        newNode->data = n;
        auto prevNext = currentNode->next;
        currentNode->next = newNode;
        newNode->next = prevNext;
        _size++;
    }

    T pop() {
        if (empty()) throw std::out_of_range("Empty list");
        if (size() == 1) {
            auto currentNode = head;
            head = nullptr;
            tail = nullptr;
            _size--;
            return currentNode->data;
        }
        auto last = tail;
        auto currentNode = head;
        while (currentNode->next != last) {
            currentNode = currentNode->next;
        }
        currentNode->next = nullptr;
        tail = currentNode;
        _size--;
        return last->data;
    }

    T pop(unsigned int index) {
        if (index > _size - 1) throw std::out_of_range("Out of range");
        if (index == 0) {
            auto toRemove = head;
            head = head->next;
            _size--;
            return toRemove->data;
        }
        unsigned int current = 0;
        auto currentNode = head;
        while (current != index - 1) {
            currentNode = currentNode->next;
            ++current;
        }
        auto toRemove = currentNode->next;
        currentNode->next = currentNode->next->next;
        _size--;
        return toRemove->data;
    }

    T get(unsigned int index) {
        if (index > _size - 1) throw std::out_of_range("Out of range");
        unsigned int current = 0;
        auto currentNode = head;
        while (current != index) {
            currentNode = currentNode->next;
            ++current;
        }
        return currentNode->data;
    }

    bool empty() {
        return _size == 0;
    }

    unsigned int size() {
        return _size;
    }

    void print() {
        auto currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }

private:
    node<T> *head;
    node<T> *tail;
    unsigned int _size;
};