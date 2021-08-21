#pragma once

#include <ostream>
#include "linkedlist.h"

template<class T>
class SparseArray {
    /**
     * Разреженная матрица на базе односвязного списка. Элементы, которых нет в матрице, отсутствуют и в списке.
     * Добавление элемента происходит по индексам строки и столбца.
     * У каждой ноды списка свое значение строки и столбца.
     * Размер матрицы задает при инициализации.
     * Если попытаться добавить элемент с индексом больше, чем есть, то будет SIGABRT (assertion error)
     * Если добавить элемент с индексами, которые уже существуют, то запишется новый элемент поверх старого
     */
private:
    class Node {
    public:
        Node() = default;

        Node(unsigned int _row, unsigned int _column, T _data) {
            row = _row;
            column = _column;
            data = _data;
        }

        unsigned int row;
        unsigned int column;
        T data;

        friend std::ostream &operator<<(std::ostream &os, const Node &node) {
            os << "row: " << node.row << " column: " << node.column << " data: " << node.data << std::endl;
            return os;
        }
    };

public:
    SparseArray(unsigned int rows, unsigned int cols) {
        _maxRow = rows - 1;
        _maxColumn = cols - 1;
    }

    T get(unsigned int row, unsigned int col) {
        assert(row <= _maxRow);
        assert(col <= _maxColumn);
        for (auto iterator = matrix.begin(); iterator != matrix.end(); ++iterator) {
            Node n = *iterator;
            if (n.row == row && n.column == col) {
                return n.data;
            }
        }
        throw std::out_of_range("Not found!");
    }

    void add(unsigned int row, unsigned int col, T value) {
        assert(row <= _maxRow);
        assert(col <= _maxColumn);
        Node newNode = getNode(row, col, value);
        unsigned int indexToInsert = 0;
        for (auto iterator = matrix.begin(); iterator != matrix.end(); iterator++) {
            Node n = *iterator;
            if (n.row > row || (n.row == row && n.column > col)) {
                matrix.push(newNode, indexToInsert);
                return;
            }
            if (n.row == row && n.column == col) {
                matrix.pop(indexToInsert);
                matrix.push(newNode, indexToInsert);
                return;
            }
            ++indexToInsert;
        }
        matrix.push(newNode, indexToInsert); // push to the end
    }

    void remove(unsigned int row, unsigned int col) {
        assert(row <= _maxRow);
        assert(col <= _maxColumn);
        unsigned int indexToRemove = 0;
        for (auto iterator = matrix.begin(); iterator != matrix.end(); ++iterator) {
            Node n = *iterator;
            if (n.row == row && n.column == col) {
                matrix.pop(indexToRemove);
                return;
            }
            ++indexToRemove;
        }
    }

    unsigned int size() {
        return matrix.size();
    }

    bool empty() {
        return matrix.empty();
    }

    void print() {
        matrix.print();
    }

private:
    Node getNode(unsigned int row, unsigned int column, T data) {
        Node newNode(row, column, data);
        return newNode;
    }

    LinkedList<Node> matrix;
    unsigned int _maxRow;
    unsigned int _maxColumn;
};