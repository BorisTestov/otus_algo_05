#include "tester.h"
#include "singlearray.h"
#include "vectorarray.h"
#include "factorarray.h"
#include "matrixarray.h"
#include "priorityqueue.h"
#include "priorityqueuelist.h"
#include <chrono>

int main() {
//    unsigned int elements = 100000;
//    {
//        std::cout << "========" << std::endl;
//        std::cout << "Single array" << std::endl;
//        SingleArray<int> single;
//        auto start = std::chrono::high_resolution_clock::now();
//        for (int i = 0; i < elements; ++i) {
//            single.add(i);
//        }
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
//        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
//    }
//    //
//    {
//        std::cout << "========" << std::endl;
//        std::cout << "Vector array" << std::endl;
//        VectorArray<int> vector(10);
//        auto start = std::chrono::high_resolution_clock::now();
//        for (int i = 0; i < elements; ++i) {
//            vector.add(i);
//        }
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
//        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
//    }
//    //
//    {
//        std::cout << "========" << std::endl;
//        std::cout << "Factor array" << std::endl;
//        FactorArray<int> factor;
//        auto start = std::chrono::high_resolution_clock::now();
//        for (int i = 0; i < elements; ++i) {
//            factor.add(i);
//        }
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
//        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
//    }
//    //
//    {
//        std::cout << "========" << std::endl;
//        std::cout << "Matrix array" << std::endl;
//        MatrixArray<int> matrix(10);
//        auto start = std::chrono::high_resolution_clock::now();
//        for (int i = 0; i < elements; ++i) {
//            matrix.add(i);
//        }
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
//        std::cout << elements << " add: " << elapsed << " ms" << std::endl;
//    }
    PriorityQueueList<int> p;
    p.enqueue(1, 2);
    p.enqueue(1, 3);
    p.enqueue(1, 4);
    p.enqueue(1000, 3);
    p.enqueue(2000, 4);
    p.enqueue(3000, 5);
    p.print();
    std::cout << p.dequeue() << std::endl;
    std::cout << p.dequeue() << std::endl;
    std::cout << p.dequeue() << std::endl;
    std::cout << p.dequeue() << std::endl;
    std::cout << p.dequeue() << std::endl;
    std::cout << p.dequeue() << std::endl;
    return 0;
}
