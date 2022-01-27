#ifndef TOWER_DEFENSE_QUEUE_H
#define TOWER_DEFENSE_QUEUE_H

template<class T>
class Queue : private List<T> {
public:
    Queue() = default;

    ~Queue() override = default;

    void enqueue(T value) {
        this->insert(value, 0);
    }

    T dequeue() {
        int last_index = this->getLen() - 1;
        T value = this->take(last_index);
        this->remove(last_index);
        return value;
    }

    bool empty() {
        this->resetCurrent();
        return !this->hasNext();
    }

};

#endif //TOWER_DEFENSE_QUEUE_H
