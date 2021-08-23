#pragma once

#include "iarray.h"
#include <algorithm>

template<class T>
class SingleArray : public IArray<T> {
public:
    SingleArray() {
        array = nullptr;
        _size = 0;
    }

    unsigned int size() override {
        return _size;
    }

    bool empty() override {
        return size() == 0;
    }

    void add(T item) override {
        resize();
        array[size() - 1] = item;
    }

    void add(T item, unsigned int index) override {
        if (index > size()) throw std::out_of_range("Index is out of range!");
        resize();
        T *newArray = new T[size() + 1];
        std::copy(array, array + index, newArray);
        newArray[index] = item;
        std::copy(array + index, array + size(), newArray + index + 1);
        delete[] array;
        array = newArray;
    }

    void print() {
        for (unsigned int i = 0; i < size(); ++i) {
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }

    T get(unsigned int index) override {
        if (index > size() - 1) throw std::out_of_range("Index is out of range!");
        return array[index];
    }

    T remove(unsigned int index) override {
        if (index > size() - 1) throw std::out_of_range("Index is out of range!");
        T *newArray = new T[size() - 1];
        T removedData = array[index];
        std::copy(array, array + index, newArray);
        std::copy(array + index + 1, array + size(), newArray + index);
        delete[] array;
        array = newArray;
        _size--;
        return removedData;
    }

private:
    void resize() {
        T *newArray = new T[size() + 1];
        std::copy(array, array + size(), newArray);
        delete[] array;
        array = newArray;
        _size++;
    }

    T *array;
    unsigned int _size;
};