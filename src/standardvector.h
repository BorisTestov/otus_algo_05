#pragma once

#include <vector>
#include "iarray.h"

template<class T>
class StandardVector : public IArray<T> {
public:
    StandardVector() = default;

    unsigned int size() override {
        return array.size();
    }

    bool empty() override {
        return array.empty();
    }

    void add(T item) override {
        array.push_back(item);
    }

    void add(T item, unsigned int index) override {
        if (index > size()) throw std::out_of_range("Index is out of range!");
        array.insert(array.begin() + index, item);
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
        array.erase(array.begin() + index);
    }

private:
    std::vector<T> array;
};