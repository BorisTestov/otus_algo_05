#pragma once

template<class T>
class IArray {
public:
    /**
     * @brief Получить размер массива
     * @return Размер массива
     */
    virtual unsigned int size() = 0;

    /**
     * @brief Определяет, является ли массив пустым
     * @return true, если массив пустой
     */
    virtual bool empty() = 0;

    /**
     * @brief Добавляет элемент в конец массива
     * @param item - элемент для добавления
     */
    virtual void add(T item) = 0;

    /**
     * @brief Вставляет элемент на позицию с индексом index. Остальные элементы сдвигает влево
     * @param item - Элемент для вставки
     * @param index - Позиция нового элемента.
     */
    virtual void add(T item, unsigned int index) = 0;

    /**
     * @brief Получает значение элемента на позиции index
     * @param index - позиция элемента, значение которого нужно получить
     * @return Значение элемента
     */
    virtual T get(unsigned int index) = 0;

    /**
     * @brief Удаляет элемент на позиции index.
     * @param index - индекс элемента для удаления
     * @return
     */
    virtual T remove(unsigned int index) = 0;
};