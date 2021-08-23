template<typename T, unsigned int N>
class MatrixArray : public IArray<T> {
public:
    MatrixArray() = default;

    virtual void add(T item, unsigned int index) override {
        if (index > _size)
            throw std::out_of_range("Index is out of range!");
        if (_size == array.size() * N) {
            std::array<T, N> newLine;
            std::fill(newLine.begin(), newLine.end(), 0);
            array.add(newLine, array.size());
        }
        for (unsigned int i = _size; i > index; --i)
            array[i / N][i % N] = std::move(array[(i - 1) / N][(i - 1) % N]);
        array[index / N][index % N] = std::move(item);
        ++_size;
    }

    virtual T remove(unsigned int index) override  // возвращает удаляемый элемент
    {
        if (index >= _size)
            throw std::out_of_range("Index is out of range!");
        T res = array[index / N][index % N];
        for (unsigned int i = index; i < _size - 1; ++i)
            array[i / N][i % N] = std::move(array[(i + 1) / N][(i + 1) % N]);
        array[(size() - 1) / N][(size() - 1) % N] = 0;
        --_size;
        if (_size % N == 0) {
            array.remove(array.size() - 1);
        }
        return res;
    }

    virtual unsigned int size() override { return _size; }

    virtual const T &operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index is out of range!");
        return array[index / N][index % N];
    }

    virtual T &operator[](unsigned int index) {
        return const_cast<T &>(const_cast<const MatrixArray &>(*this)[index]);
    }

    void print() {
        unsigned int rows = _size / N;
        _size % N != 0 ? rows += 1 : rows += 0;
        for (unsigned i = 0; i < rows; ++i) {
            auto row = array[i];
            for (const T &j: row) {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }
    }

    bool empty() override {
        return _size == 0;
    }

    T get(unsigned int index) override {
        return array[index / N][index % N];
    }

    void add(T item) override {
        add(item, size());
    }

private:
    FactorArray<std::array<T, N>> array;
    unsigned int _size = 0;
};