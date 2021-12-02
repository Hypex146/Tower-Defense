#ifndef TOWER_DEFENSE_LIST_H
#define TOWER_DEFENSE_LIST_H

#include <iostream>

template<class T>
struct Node {
    T info_;
    Node<T> *next_;
};

template<class T>
class List {
private:
    Node<T> *head_;
    mutable Node<T> *current_ptr_;

    void deleteNodes() {
        Node<T> *current_element = head_->next_;
        while (current_element != nullptr) {
            Node<T> *next_element = current_element->next_;
            delete current_element;
            current_element = next_element;
        }
    }

public:
    List() {
        head_ = new Node<T>;
        head_->next_ = nullptr;
        current_ptr_ = head_;
    }

    List(const List<T> &list) : List() {
        list.resetCurrent();
        if (!list.hasNext()) { return; }
        int current_index = 0;
        do {
            list.next();
            insert(list.getCurrent(), current_index);
            current_index++;
        } while (list.hasNext());
    }

    List<T> &operator=(const List<T> &list) {
        if (this == &list) { return *this; }
        deleteNodes();
        list.resetCurrent();
        if (!list.hasNext()) { return *this; }
        int current_index = 0;
        do {
            list.next();
            insert(list.getCurrent(), current_index);
            current_index++;
        } while (list.hasNext());
        return *this;
    }

    virtual ~List() {
        deleteNodes();
        delete head_;
    }

    void insert(T value, int index) {
        int i = 0;
        Node<T> *current_element = this->head_;
        while (i < index && current_element->next_) {
            i++;
            current_element = current_element->next_;
        }
        auto *new_list_element = new Node<T>;
        new_list_element->info_ = value;
        new_list_element->next_ = current_element->next_;
        current_element->next_ = new_list_element;
    }

    void remove(int index) {
        if (this->head_->next_) {
            int i = 0;
            Node<T> *current_element = this->head_;
            while (i < index && current_element->next_->next_) {
                i++;
                current_element = current_element->next_;
            }
            Node<T> *for_del = current_element->next_;
            current_element->next_ = current_element->next_->next_;
            if (current_ptr_ == for_del) { resetCurrent(); }
            delete for_del;
        }
    }

    T take(int index) const {
        if (index < 0) { throw std::invalid_argument("[ERROR] Invalid index!"); }
        if (this->head_->next_) {
            int i = 0;
            Node<T> *current_element = this->head_;
            while (i <= index && current_element->next_) {
                i++;
                current_element = current_element->next_;
            }
            return current_element->info_;
        } else {
            throw std::invalid_argument("[ERROR] Empty list!");
        }
    }

    T *takePtr(int index) {
        if (this->head_->next_) {
            int i = 0;
            Node<T> *current_element = this->head_;
            while (i <= index && current_element->next_) {
                i++;
                current_element = current_element->next_;
            }
            return &(current_element->info_);
        } else {
            throw std::invalid_argument("[ERROR] Empty list!");
        }
    }

    void swap(int first, int second) {
        if (this->head_->next_) {
            T a, b;
            a = take(first);
            b = take(second);
            remove(first);
            insert(b, first);
            remove(second);
            insert(a, second);
        } else {
            throw std::invalid_argument("[ERROR] Empty list!");
        }
    }

    int getValueCount(T info) const {
        if (this->head_->next_) {
            int count = 0;
            Node<T> *current_element = this->head_->next_;
            while (current_element) {
                if (current_element->info_ == info) {
                    count++;
                }
                current_element = current_element->next_;
            }
            return count;
        } else {
            throw std::invalid_argument("[ERROR] Empty list!");
        }
    }

    int getValueIndex(T value) const {
        if (this->head_->next_) {
            int i = 0;
            Node<T> *current_element = this->head_->next_;
            while (current_element) {
                if (current_element->info_ == value) {
                    return i;
                }
                i++;
                current_element = current_element->next_;
            }
        } else {
            return -1;
        }
        return -1;
    }

    int getLen() const {
        int count = 0;
        Node<T> *current_element = this->head_;
        while (current_element->next_) {
            count++;
            current_element = current_element->next_;
        }
        return count;
    }

    int print() const {
        std::cout << "List:\n--->\n";
        if (this->head_->next_) {
            Node<T> *current_element = this->head_->next_;
            while (current_element) {
                std::cout << current_element->info_ << " ";
                current_element = current_element->next_;
            }
        }
        std::cout << "\n--->\n";
        return 0;
    }

    bool hasNext() const {
        if (!validCurrent()) { throw std::runtime_error("Invalid current ptr!"); }
        return current_ptr_->next_ != nullptr;
    }

    bool validCurrent() const {
        if (current_ptr_ != nullptr) { return true; }
        return false;
    }

    bool canGetCurrent() const {
        if (validCurrent() && current_ptr_ != head_) { return true; }
        return false;
    }

    void next() const {
        if (!hasNext()) { throw std::runtime_error("Has not next element!"); }
        current_ptr_ = current_ptr_->next_;
    }

    void resetCurrent() const {
        current_ptr_ = head_;
    }

    T getCurrent() const {
        if (!canGetCurrent()) { throw std::runtime_error("It is impossible to take this element!"); }
        return current_ptr_->info_;
    }

    T *getPtrToCurrent() {
        if (!canGetCurrent()) { throw std::runtime_error("It is impossible to take this element!"); }
        return &(current_ptr_->info_);
    }

};

#endif //TOWER_DEFENSE_LIST_H
