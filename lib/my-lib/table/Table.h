/**
 * @file
 * @brief
 * Заголовочный файл с описанием класса "Vector".
 * @details
 * Данный файл содержит в себе описание класса "Vector" и некоторых функций, дружественных классу.
 * @author Коломенский В.Г. [Б20-503]
 * @date 16.10.2021
 */
#ifndef TOWER_DEFENSE_TABLE_H
#define TOWER_DEFENSE_TABLE_H

#include <iostream>
#include <iterator>

template<class KeyType, class InfoType>
class TableIterator;

/**
 * @brief
 * Ячейка таблицы.
 * @details
 * Структура - ячейка таблицы, предназначена для хранения пары: ключ/информация.
 */
template<class KeyType, class InfoType>
struct Cell {
    KeyType key;
    InfoType info;
};

/**
 * @brief
 * Шаблонная таблица.
 * @details
 * Класс - таблица, предназначена для хранения пар значений: ключ/информация.
 */
template<class KeyType, class InfoType>
class Table {
private:
    Cell<KeyType, InfoType> **cells_;
    int current_size_;

    void deleteCells() {
        for (int i = 0; i < current_size_; i++) {
            delete cells_[i];
        }
        delete[] cells_;
        current_size_ = 0;
        cells_ = nullptr;
    }

public:
    /**
    * @brief
    * Получение итератора.
    * @details
    * Данный метод возвращает итератор типа "ввод", указывающий на первый элемент таблицы.\n
    */
    TableIterator<KeyType, InfoType> begin() const {
        return TableIterator<KeyType, InfoType>(cells_);
    }

    /**
    * @brief
    * Получение итератора.
    * @details
    * Данный метод возвращает итератор типа "ввод", указывающий на последний элемент таблицы.\n
    */
    TableIterator<KeyType, InfoType> end() const {
        return TableIterator<KeyType, InfoType>(cells_ + (current_size_ - 1));
    }

    /**
    * @brief
    * Конструктор.
    * @details
    * Данный конструктор создаёт экземпляр класса с инициализацией параметров по умолчанию.\n
    * Будет создана пустая таблица.
    */
    Table() {
        cells_ = nullptr;
        current_size_ = 0;
    }

    /**
    * @brief
    * Деструктор.
    * @details
    * Удаляет всю информацию из таблицы и саму таблицу.
    */
    ~Table() {
        deleteCells();
    }

    /**
    * @brief
    * Конструктор копирования.
    * @details
    * Данный конструктор выполняет грубокое копирование переданного экземпляра класса "Table".\n
    * Будет создана таблица, идентична переданной.
    */
    Table(const Table &table) {
        current_size_ = table.current_size_;
        cells_ = new Cell<KeyType, InfoType> *[current_size_];
        for (int i = 0; i < current_size_; i++) {
            auto *new_cell = new Cell<KeyType, InfoType>(*table.cells_[i]);
            //*new_cell = *table.cells_[i];
            cells_[i] = new_cell;
        }
    }

    /**
    * @brief
    * Оператор копирования "=".
    * @details
    * Данный оператор копирует экземпляр класса "Table", стоящий справа от оператора, в экзмепляр,
    * стоящий слева от оператора.\n
    * @param object - ссылка на экземпляр класса "Table".
    * @return Ссылка на экземпляр класса, в который производилось копирование.
    */
    Table<KeyType, InfoType> &operator=(const Table &table) {
        if (this == &table) { return *this; }
        deleteCells();
        current_size_ = table.current_size_;
        cells_ = new Cell<KeyType, InfoType> *[current_size_];
        for (int i = 0; i < current_size_; i++) {
            auto *new_cell = new Cell<KeyType, InfoType>(*table.cells_[i]);
            //*new_cell = *table.cells_[i];
            cells_[i] = new_cell;
        }
        return *this;
    }

    /**
    * @brief
    * Наличие ключа.
    * @details
    * Метод определяет, есть ли в таблице переданный ключ.\n
    * @param key - ключ типа "KeyType".
    * @return True - если переданный ключ присутствует в таблице и false - если нет.
    */
    bool hasKey(KeyType key) const {
        if (current_size_ == 0) { return false; }
        for (int i = 0; i < current_size_; i++) {
            if (cells_[i]->key == key) { return true; }
        }
        return false;
    }

    /**
    * @brief
    * Положить в таблицу.
    * @details
    * Метод помещает в таблицу пару значений: key/info.\n
    * @param key - ключ типа "KeyType".
    * @param info - информация типа "InfoType".
    */
    void put(KeyType key, InfoType info) {
        if (hasKey(key)) { throw std::invalid_argument("This key already exists"); }
        auto **new_cells = new Cell<KeyType, InfoType> *[current_size_ + 1];
        for (int i = 0; i < current_size_; i++) { new_cells[i] = cells_[i]; }
        current_size_++;
        auto *new_cell = new Cell<KeyType, InfoType>();
        new_cell->key = key;
        new_cell->info = info;
        new_cells[current_size_ - 1] = new_cell;
        delete[] cells_;
        cells_ = new_cells;
    }

    /**
    * @brief
    * Удалить из таблицы.
    * @details
    * Метод удаляет из таблице записть, соответствующую переданному ключу.\n
    * @param key - ключ типа "KeyType".
    */
    void remove(KeyType key) {
        if (!hasKey(key)) { throw std::invalid_argument("This key does not exist"); }
        auto **new_cells = new Cell<KeyType, InfoType> *[current_size_ - 1];
        int number_of_copied = 0;
        for (int i = 0; i < current_size_; i++) {
            if (cells_[i]->key == key) {
                delete cells_[i];
                continue;
            }
            new_cells[number_of_copied] = cells_[i];
            number_of_copied++;
        }
        current_size_--;
        delete[] cells_;
        cells_ = new_cells;
    }

    /**
    * @brief
    * Получить информацию.
    * @details
    * Метод возвращает информацию из таблице по ключу.\n
    * @param key - ключ типа "KeyType".
    * @return информацию типа "InfoType".
    */
    InfoType getInfo(KeyType key) const {
        for (int i = 0; i < current_size_; i++) {
            if (cells_[i]->key == key) { return cells_[i]->info; }
        }
        throw std::invalid_argument("This key does not exist");
    }

    /**
    * @brief
    * Получить информацию.
    * @details
    * Метод возвращает информацию из таблице по индексу записи.\n
    * @param index - индекс записи типа "int".
    * @return информацию типа "InfoType".
    */
    InfoType getInfoByIndex(int index) const {
        if (index >= current_size_ || index < 0) {
            throw std::invalid_argument("Going beyond the boundaries of the table!");
        }
        return cells_[index]->info;
    }

    /**
    * @brief
    * Узнать размер таблицы.
    * @details
    * Метод возвращает число, равное текущему размеру таблицы.\n
    * @return размер - чисто типа "int".
    */
    int getCurrentSize() const {
        return current_size_;
    }

    /**
    * @brief
    * Вывод таблицы.
    * @details
    * Метод выводит таблицу в стандартный поток ввода/вывода.\n
    */
    void print() {
        for (int i = 0; i < current_size_; i++) {
            std::cout << cells_[i]->key << ": " << cells_[i]->info << std::endl;
        }
    }

};

/**
 * @brief
 * Итератор таблицы.
 * @details
 * Класс - итератор, обеспечивает доступ к элементам таблицы.
 */
template<class KeyType, class InfoType>
class TableIterator : public std::iterator<std::input_iterator_tag, Cell<KeyType, InfoType>> {
    friend class Table<KeyType, InfoType>;

private:
    explicit TableIterator(Cell<KeyType, InfoType> **ptrToCell) {
        ptrToCell_ = ptrToCell;
    }

    Cell<KeyType, InfoType> **ptrToCell_;
public:
    /**
    * @brief
    * Конструктор копирования.
    * @details
    * Данный конструктор выполняет копирование переданного экземпляра класса "TableIterator".\n
    * Будет создан итератор, идентичный переданному.
    */
    TableIterator(const TableIterator &object) {
        ptrToCell_ = object.ptrToCell_;
    }

    /**
    * @brief
    * Оператор "!=".
    * @details
    * Используется для сравнения итераторов.\n
    * @param v2 - ссылка на экземпляр класса "TableIterator".
    * @return false - итераторы указывают на одну запись в таблице, true если нет.
    */
    bool operator!=(TableIterator const &other) const {
        return ptrToCell_ != other.ptrToCell_;
    }

    /**
    * @brief
    * Оператор "!=".
    * @details
    * Используется для сравнения итераторов.\n
    * @param v2 - ссылка на экземпляр класса "TableIterator".
    * @return true - итераторы указывают на одну запись в таблице, false если нет.
    */
    bool operator==(TableIterator const &other) const {
        return ptrToCell_ == other.ptrToCell_;
    }

    /**
    * @brief
    * Оператор "*".
    * @details
    * Используется для получения информации, на которую указывает итератор.\n
    * @return ссылка на запись в таблице.
    */
    const Cell<KeyType, InfoType> &operator*() const {
        return **ptrToCell_;
    }

    /**
    * @brief
    * Оператор "++".
    * @details
    * Используется для перемещения итератора на следующую позицию.\n
    * @return ссылка на этот итератор.
    */
    TableIterator &operator++() {
        ++ptrToCell_;
        return *this;
    }

};

#endif //TOWER_DEFENSE_TABLE_H
