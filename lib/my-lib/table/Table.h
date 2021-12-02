#ifndef TOWER_DEFENSE_TABLE_H
#define TOWER_DEFENSE_TABLE_H

#include <iostream>

template<class KeyType, class InfoType>
struct Cell {
    KeyType key;
    InfoType info;
};

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
    Table() {
        cells_ = nullptr;
        current_size_ = 0;
    }

    ~Table() {
        deleteCells();
    }

    Table(const Table &table) {
        current_size_ = table.current_size_;
        cells_ = new Cell<KeyType, InfoType> *[current_size_];
        for (int i = 0; i < current_size_; i++) {
            auto *new_cell = new Cell<KeyType, InfoType>(*table.cells_[i]);
            //*new_cell = *table.cells_[i];
            cells_[i] = new_cell;
        }
    }

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

    bool hasKey(int key) const {
        if (current_size_ == 0) { return false; }
        for (int i = 0; i < current_size_; i++) {
            if (cells_[i]->key == key) { return true; }
        }
        return false;
    }

    void put(int key, InfoType info) {
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

    void remove(int key) {
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

    InfoType getInfo(int key) const {
        for (int i = 0; i < current_size_; i++) {
            if (cells_[i]->key == key) { return cells_[i]->info; }
        }
        throw std::invalid_argument("This key does not exist");
    }

    InfoType getInfoByIndex(int index) const {
        if (index >= current_size_ || index < 0) {
            throw std::invalid_argument("Going beyond the boundaries of the table!");
        }
        return cells_[index]->info;
    }

    void print() {
        for (int i = 0; i < current_size_; i++) {
            std::cout << cells_[i]->key << ": " << cells_[i]->info << std::endl;
        }
    }

};

#endif //TOWER_DEFENSE_TABLE_H
