#pragma once

#include "iarray.h"

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
        if (index > size() - 1) throw std::out_of_range("Index is out of range!");
        return array[index];
    }

    T remove(unsigned int index) override {
        if (index > size() - 1) throw std::out_of_range("Index is out of range!");
        T *newArray = new T[size() - 1];
        for (unsigned int i = 0; i < size(); ++i) {
            if (i == index) continue;
            newArray[i] = get(i);
        }
        delete[] array;
        array = newArray;
        _size--;
    }

private:
    void resize() {
        T *newArray = new T[size() + 1];
        for (unsigned int i = 0; i < size(); ++i) {
            newArray[i] = get(i);
        }
        if (size() != 0) delete[] array;
        array = newArray;
        _size++;
    }

    T *array;
    unsigned int _size;
};