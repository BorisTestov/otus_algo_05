#pragma once

#include "iarray.h"

template<class T>
class MatrixArray : public IArray<T> {
public:
    MatrixArray(unsigned int rowSize) {
        array = nullptr;
        _size = 0;
        _rowSize = rowSize;
    }

    unsigned int size() override {
        return _size;
    }

    bool empty() override {
        return _size == 0;
    }

    void add(T item) override {
        if (_size % _rowSize == 0) resize();
        array[size() / _rowSize][size() % _rowSize] = item;
        _size++;
    }

    void print() override {
        for (unsigned int i = 0; i <= (size() / _rowSize - (size() % _rowSize == 0)); ++i) {
            for (unsigned int j = 0; j < _rowSize; ++j) {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void add(T item, unsigned int index) override {
        if (index > size()) throw std::out_of_range("Index is out of range!");
        T **newArray = size() % _rowSize == 0 ? new T *[size() / _rowSize + 1] : new T *[size() / _rowSize];
        auto row = new T[_rowSize];
        for (unsigned int i = 0; i < _rowSize; ++i) row[i] = 0;
        unsigned int currentLength = 0;
        for (unsigned int i = 0; i < index; ++i) {
            row[currentLength % _rowSize] = array[i / _rowSize][i % _rowSize];
            ++currentLength;
            if (currentLength % _rowSize == 0) {
                newArray[currentLength / _rowSize - 1] = row;
                row = new T[_rowSize];
            }
        }
        row[currentLength % _rowSize] = item;
        ++currentLength;
        if (currentLength % _rowSize == 0) {
            newArray[currentLength / _rowSize - 1] = row;
            row = new T[_rowSize];
        }
        for (unsigned int i = index; i < size(); ++i) {
            row[currentLength % _rowSize] = array[i / _rowSize][i % _rowSize];
            ++currentLength;
            if (currentLength % _rowSize == 0) {
                newArray[currentLength / _rowSize - 1] = row;
                row = new T[_rowSize];
            }
        }
        if (currentLength % _rowSize != 0) newArray[currentLength / _rowSize] = row;
        delete[] array;
        array = newArray;
        _size++;
    }

    T get(unsigned int index) override {
        if (index > size() - 1) throw std::out_of_range("Index is out of range!");
        return array[index / _rowSize][index % _rowSize];
    }

    T remove(unsigned int index) override {
        if (index > size() - 1) throw std::out_of_range("Index is out of range!");
        T **newArray = size() % _rowSize == 1 ? new T *[size() / _rowSize - 1] : new T *[size() / _rowSize];
        auto row = new T[_rowSize];
        for (unsigned int i = 0; i < _rowSize; ++i) row[i] = 0;
        unsigned int currentLength = 0;
        for (unsigned int i = 0; i < size(); ++i) {
            if (i == index) continue;
            row[currentLength % _rowSize] = array[i / _rowSize][i % _rowSize];
            ++currentLength;
            if (currentLength % _rowSize == 0) {
                newArray[currentLength / _rowSize - 1] = row;
                row = new T[_rowSize];
            }
        }
        if (currentLength % _rowSize != 0) newArray[currentLength / _rowSize] = row;
        delete[] array;
        array = newArray;
        _size--;
        return array[index / _rowSize][index % _rowSize];
    }

private:
    void resize() {
        T **newArray = new T *[size() / _rowSize + 1];
        for (int i = 0; i < size() / _rowSize; ++i) {
            newArray[i] = array[i];
        }
        auto row = new T[_rowSize];
        for (unsigned int i = 0; i < _rowSize; ++i) row[i] = 0;
        newArray[size() / _rowSize] = row;
        delete[] array;
        array = newArray;
    }

    T **array;
    unsigned int _size;
    unsigned int _rowSize;
};