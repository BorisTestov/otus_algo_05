#pragma once

#include "iarray.h"

template<class T>
class VectorArray : public IArray<T> {
public:
    VectorArray() {
        _size = 0;
        array = nullptr;
    };

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
        if (index > capacity() - 1) throw std::out_of_range("Index is out of range!");
        return array[index];
    }

    T remove(unsigned int index) override {
        if (index > capacity() - 1) throw std::out_of_range("Index is out of range!");
        T *newArray = new T[size() - 1];
        unsigned int newIndex = 0;
        T removedData = array[index];
        std::copy(array, array + index, newArray);
        std::copy(array + index + 1, array + size(), newArray + index);
        delete[] array;
        array = newArray;
        _size--;
        return removedData;
    }

//    ~VectorArray() {
//        delete[] array;
//    }

private:
    void resize() {
        T *newArray = new T[size() + _step];
        std::copy(array, array + size(), newArray);
        delete[] array;
        array = newArray;
        _capacity += _step;
    }

    T *array;

    unsigned int _size;
    unsigned int _capacity = 0;
    unsigned int _step = 10;
};