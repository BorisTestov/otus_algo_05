#include "tester.h"
#include "singlearray.h"
#include "vectorarray.h"
#include "factorarray.h"
#include "matrixarray.h"
#include "priorityqueue.h"
#include "priorityqueuelist.h"
#include "sparsearray.h"
#include "standardvector.h"
#include <chrono>
#include <random>

int main() {
    unsigned int elements = 3200000;
    std::random_device rd;
    std::mt19937 gen(rd());
    {
        std::cout << "========" << std::endl;
        std::cout << "Single array" << std::endl;
        SingleArray<int> single;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            single.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        while (!single.empty()) {
            std::uniform_int_distribution<unsigned long long> distribution(0, single.size() - 1);
            auto index = distribution(gen);
            single.remove(index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " remove: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            std::uniform_int_distribution<unsigned long long> distribution(0, single.size());
            auto index = distribution(gen);
            single.add(i, index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " random add: " << elapsed << " ms" << std::endl;
    }
    {
        std::cout << "========" << std::endl;
        std::cout << "Vector array" << std::endl;
        VectorArray<int> vector(10);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            vector.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        while (!vector.empty()) {
            std::uniform_int_distribution<unsigned long long> distribution(0, vector.size() - 1);
            auto index = distribution(gen);
            vector.remove(index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " remove: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            std::uniform_int_distribution<unsigned long long> distribution(0, vector.size());
            auto index = distribution(gen);
            vector.add(i, index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " random add: " << elapsed << " ms" << std::endl;
    }
    //
    {
        std::cout << "========" << std::endl;
        std::cout << "Factor array" << std::endl;
        FactorArray<int> factor;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            factor.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        while (!factor.empty()) {
            std::uniform_int_distribution<unsigned long long> distribution(0, factor.size() - 1);
            auto index = distribution(gen);
            factor.remove(index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " remove: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            std::uniform_int_distribution<unsigned long long> distribution(0, factor.size());
            auto index = distribution(gen);
            factor.add(i, index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " random add: " << elapsed << " ms" << std::endl;
    }
    //
    {
        std::cout << "========" << std::endl;
        std::cout << "Matrix array" << std::endl;
        MatrixArray<int> matrix(3);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            matrix.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        while (!matrix.empty()) {
            std::uniform_int_distribution<unsigned long long> distribution(0, matrix.size() - 1);
            auto index = distribution(gen);
            matrix.remove(index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " remove: " << elapsed << " ms" << std::endl;
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            std::uniform_int_distribution<unsigned long long> distribution(0, matrix.size());
            auto index = distribution(gen);
            matrix.add(i, index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " random add: " << elapsed << " ms" << std::endl;
    }
    //
    {
        std::cout << "========" << std::endl;
        std::cout << "Standard vector" << std::endl;
        StandardVector<int> vector;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            vector.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        while (!vector.empty()) {
            std::uniform_int_distribution<unsigned long long> distribution(0, vector.size() - 1);
            auto index = distribution(gen);
            vector.remove(index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " remove: " << elapsed << " ms" << std::endl;
        //
        elapsed = 0;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < elements; ++i) {
            std::uniform_int_distribution<unsigned long long> distribution(0, vector.size());
            auto index = distribution(gen);
            vector.add(i, index);
        }
        stop = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << elements << " random add: " << elapsed << " ms" << std::endl;
    }
    return 0;
}
