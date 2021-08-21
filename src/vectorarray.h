#pragma once

#include "iarray.h"

template<class T>
class VectorArray : public IArray<T> {
public:
    VectorArray(unsigned int step) {
        array = nullptr;
        _size = 0;
        _step = step;
    }

    unsigned int size() override {
        return _size;
    }

    unsigned int capacity() {
        return _capacity;
    }

    bool empty() override {
        return size() == 0;
    }

    void add(T item) override {
        if (size() == capacity()) resize();
        _size++;
        array[size() - 1] = item;
    }

    void add(T item, unsigned int index) override {
        if (index > capacity()) throw std::out_of_range("Index is out of range!");
        if (size() == capacity()) resize();
        _size++;
        T *newArray = new T[size() + 1];
        for (unsigned int i = 0; i < index; ++i) {
            newArray[i] = get(i);
        }
        newArray[index] = item;
        for (unsigned int i = index + 1; i < size(); ++i) {
            newArray[i] = get(i - 1);
        }
        delete[] array;
        array = newArray;
    }

    void print() override {
        for (unsigned int i = 0; i < size(); ++i) {
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }

    T get(unsigned int index) override {
        if (index > capacity() - 1) throw std::out_of_range("Index is out of range!");
        return array[index];
    }

    T remove(unsigned int index) override {
        if (index > capacity() - 1) throw std::out_of_range("Index is out of range!");
        T *newArray = new T[size() - 1];
        unsigned int newIndex = 0;
        for (unsigned int i = 0; i < size(); ++i) {
            if (i == index) continue;
            newArray[newIndex] = get(i);
            ++newIndex;
        }
        delete[] array;
        array = newArray;
        _size--;
    }

private:
    void resize() {
        T *newArray = new T[size() + _step];
        for (unsigned int i = 0; i < size(); ++i) {
            newArray[i] = get(i);
        }
        delete[] array;
        array = newArray;
        _capacity += _step;
    }

    T *array;

    unsigned int _size;
    unsigned int _capacity = 0;
    unsigned int _step = 10;
};