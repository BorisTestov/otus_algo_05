# Домашнее задание 5

## Динамические массивы, неполный массив, очередь с приоритетом.

### Цель:

Создание разных алгоритмов для реализации Динамического массива и сравнение их производительности. <br>
Создание приоритетной очереди или неполного массива.

#### 1 задание. Динамические массивы.  (+3 байта)

Написать метод добавления и удаления элементов:

- [x] void add(T item); // Добавляет в конец массива
- [x] void add(T item, int index); // Вставка в указанное место со сдвигом остальных элементов
- [x] T remove(int index); // возвращает удаляемый элемент по индексу <br>

Во все варианты динамических массивов:

- [x] SingleArray
- [x] VectorArray
- [x] FactorArray
- [x] MatrixArray

#### 2 задание. Таблица сравнения производительности. (+3 байта)

- [x] Сравнить время выполнения разных операций для разных массивов с разным порядком значений.
- [x] сделать обёртку над ArrayList() и тоже сравнить. Составить таблицу и приложить её скриншот. <br>
  Сделать выводы и сформулировать их в нескольких предложениях.

#### 3 задание. Приоритетная очередь (на выбор).  (+4 байта)

- [x] Написать реализацию PriorityQueue - очередь с приоритетом. <br>
  Варианты реализации
- [x] список списков
- [x] массив списков Методы к реализации:
    - [x] enqueue(int priority, T item) - поместить элемент в очередь
    - [x] T dequeue() - выбрать элемент из очереди

#### 4 задание. Неполный массив (на выбор).  (+4 байта)

- [x] Написать Реализацию класса SpaceArray массив массивов с неполным заполнением. <br>
  Делать на основе одного из уже созданных массивов и/или списков.

Для реализации можно использовать только стандартные массивы [], созданные классы массивов и/или списков.<br>
Стандартные коллекции не используем!