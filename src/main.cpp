#include "tester.h"
#include "singlearray.h"
#include "vectorarray.h"
#include <chrono>

int main() {
    {
        std::cout << "========" << std::endl;
        std::cout << "Single array" << std::endl;
        SingleArray<int> single;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i) {
            single.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << "10 000 add: " << elapsed << " ms" << std::endl;
    }
    //
    {
        std::cout << "========" << std::endl;
        std::cout << "Vector array" << std::endl;
        VectorArray<int> vector;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i) {
            vector.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        std::cout << "10 000 add: " << elapsed << " ms" << std::endl;
    }
    return 0;
}
