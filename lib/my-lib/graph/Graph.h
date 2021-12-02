#ifndef TOWER_DEFENSE_GRAPH_H
#define TOWER_DEFENSE_GRAPH_H

#include "Lists_collection.h"

template<class T>
struct Vertex {
    T id_;
    List<Vertex<T> *> neighbor_vertexes_;

    friend bool operator==(const Vertex<T> &v1, const Vertex<T> &v2) {
        return v1.id_ == v2.id_;
    }

    friend bool operator!=(const Vertex<T> &v1, const Vertex<T> &v2) {
        return v1.id_ != v2.id_;
    }
};

template<class T>
class Graph {
private:
    List<Vertex<T>> vertexes_;

    int getIndexOfVertex(T id) {
        Vertex<T> vertex;
        vertex.id_ = id;
        return vertexes_.getValueIndex(vertex);
    }

    void calculateWays(T start_id, bool **used, int **parent) {
        int vertex_count = vertexes_.getLen();
        int start_index = getIndexOfVertex(start_id);
        Queue<int> queue;
        queue.enqueue(start_index);
        *used = new bool[vertex_count];
        for (int i = 0; i < vertex_count; i++) { (*used)[i] = false; }
        (*used)[start_index] = true;
        int distance[vertex_count];
        for (int i = 0; i < vertex_count; i++) { distance[i] = 0; }
        *parent = new int[vertex_count];
        for (int i = 0; i < vertex_count; i++) { (*parent)[i] = -1; }
        while (!queue.empty()) {
            int current_index = queue.dequeue();
            Vertex<T> current_vertex = vertexes_.take(current_index);
            current_vertex.neighbor_vertexes_.resetCurrent();
            while (current_vertex.neighbor_vertexes_.hasNext()) {
                current_vertex.neighbor_vertexes_.next();
                int neighbor_vertex_index = getIndexOfVertex(current_vertex.neighbor_vertexes_.getCurrent()->id_);
                if (!(*used)[neighbor_vertex_index]) {
                    (*used)[neighbor_vertex_index] = true;
                    queue.enqueue(neighbor_vertex_index);
                    distance[neighbor_vertex_index] = distance[current_index] + 1;
                    (*parent)[neighbor_vertex_index] = current_index;
                }
            }
        }
    }

public:
    Graph() = default;

    ~Graph() = default;

    void addVertex(T id) {
        if (hasVertex(id)) { throw std::invalid_argument("A vertex with this id already exists"); }
        Vertex<T> new_vertex;
        new_vertex.id_ = id;
        vertexes_.insert(new_vertex, 0);
    }

    void addEdge(T first_id, T second_id) {
        vertexes_.resetCurrent();
        if (!vertexes_.hasNext()) { throw std::invalid_argument("Graph is empty!"); }
        Vertex<T> *first_vertex = nullptr, *second_vertex = nullptr;
        do {
            vertexes_.next();
            Vertex<T> *current_vertex = vertexes_.getPtrToCurrent();
            if (current_vertex->id_ == first_id) { first_vertex = current_vertex; }
            if (current_vertex->id_ == second_id) { second_vertex = current_vertex; }
        } while (vertexes_.hasNext());
        if (first_vertex == nullptr || second_vertex == nullptr) {
            throw std::invalid_argument("These vertexes do not exist!");
        }
        first_vertex->neighbor_vertexes_.insert(second_vertex, 0);
        second_vertex->neighbor_vertexes_.insert(first_vertex, 0);
    }

    Vertex<T> *getVertexPtrById(T id) {
        vertexes_.resetCurrent();
        if (!vertexes_.hasNext()) { throw std::invalid_argument("Graph is empty!"); }
        do {
            vertexes_.next();
            Vertex<T> *vertex_ptr = vertexes_.getPtrToCurrent();
            if (vertex_ptr->id_ == id) { return vertex_ptr; }
        } while (vertexes_.hasNext());
        return nullptr;
    }

    Vertex<T> getVertexById(T id) const {
        vertexes_.resetCurrent();
        if (!vertexes_.hasNext()) { throw std::invalid_argument("Graph is empty!"); }
        do {
            vertexes_.next();
            Vertex<T> vertex_ptr = vertexes_.getCurrent();
            if (vertex_ptr.id_ == id) { return vertex_ptr; }
        } while (vertexes_.hasNext());
        throw std::invalid_argument("These vertexes do not exist!");
    }

    Vertex<T> getVertexByIndex(int index) const {
        return vertexes_.take(index);
    }

    bool hasVertex(T id) {
        vertexes_.resetCurrent();
        if (!vertexes_.hasNext()) { return false; }
        do {
            vertexes_.next();
            if (vertexes_.getCurrent().id_ == id) { return true; }
        } while (vertexes_.hasNext());
        return false;
    }

    bool hasEdge(T first_id, T second_id) const {
        Vertex<T> first_vertex;
        first_vertex = getVertexById(first_id);
        first_vertex.neighbor_vertexes_.resetCurrent();
        while (first_vertex.neighbor_vertexes_.hasNext()) {
            first_vertex.neighbor_vertexes_.next();
            if (first_vertex.neighbor_vertexes_.getCurrent()->id_ == second_id) { return true; }
        }
        return false;
    }

    void rmEdge(T first_id, T second_id) {
        if (!hasEdge(first_id, second_id)) { throw std::invalid_argument("This edge does not exist!"); }
        Vertex<T> *first_vertex, *second_vertex = nullptr;
        int first_edge_index = -1, second_edge_index = -1;
        first_vertex = getVertexPtrById(first_id);
        first_vertex->neighbor_vertexes_.resetCurrent();
        while (first_vertex->neighbor_vertexes_.hasNext()) {
            first_vertex->neighbor_vertexes_.next();
            first_edge_index++;
            if (first_vertex->neighbor_vertexes_.getCurrent()->id_ == second_id) {
                second_vertex = first_vertex->neighbor_vertexes_.getCurrent();
                break;
            }
        }
        second_vertex->neighbor_vertexes_.resetCurrent();
        while (second_vertex->neighbor_vertexes_.hasNext()) {
            second_vertex->neighbor_vertexes_.next();
            second_edge_index++;
            if (second_vertex->neighbor_vertexes_.getCurrent()->id_ == first_id) { break; }
        }
        first_vertex->neighbor_vertexes_.remove(first_edge_index);
        second_vertex->neighbor_vertexes_.remove(second_edge_index);
    }

    void rmVertex(T id) {
        Vertex<T> *vertex = nullptr;
        vertexes_.resetCurrent();
        int vertex_index = -1;
        while (vertexes_.hasNext()) {
            vertexes_.next();
            vertex_index++;
            if (vertexes_.getPtrToCurrent()->id_ == id) {
                vertex = vertexes_.getPtrToCurrent();
                break;
            }
        }
        if (vertex == nullptr) { throw std::invalid_argument("These vertexes do not exist!"); }
        vertex->neighbor_vertexes_.resetCurrent();
        while (vertex->neighbor_vertexes_.hasNext()) {
            vertex->neighbor_vertexes_.next();
            rmEdge(id, vertex->neighbor_vertexes_.getCurrent()->id_);
        }
        vertexes_.remove(vertex_index);
    }

    void print() {
        vertexes_.resetCurrent();
        while (vertexes_.hasNext()) {
            vertexes_.next();
            std::cout << vertexes_.getPtrToCurrent()->id_ << ": ";
            vertexes_.getPtrToCurrent()->neighbor_vertexes_.resetCurrent();
            while (vertexes_.getPtrToCurrent()->neighbor_vertexes_.hasNext()) {
                vertexes_.getPtrToCurrent()->neighbor_vertexes_.next();
                std::cout << vertexes_.getPtrToCurrent()->neighbor_vertexes_.getCurrent()->id_ << " ";
            }
            std::cout << std::endl;
        }
    }

    bool hasWay(T start_id, T end_id) {
        if (start_id == end_id) { return true; }
        bool result = false;
        bool *used = nullptr;
        int *parent = nullptr;
        calculateWays(start_id, &used, &parent);
        int end_index = getIndexOfVertex(end_id);
        if (used[end_index]) { result = true; }
        delete[] used;
        delete[] parent;
        return result;
    }

    List<int> getWay(T start_id, T end_id) {
        List<int> list;
        if (start_id == end_id) { return list; }
        bool *used = nullptr;
        int *parent = nullptr;
        calculateWays(start_id, &used, &parent);
        int start_index = getIndexOfVertex(start_id);
        int end_index = getIndexOfVertex(end_id);
        if (!used[end_index]) { return list; }
        for (int current_index = end_index; current_index != start_index; current_index = parent[current_index]) {
            list.insert(current_index, 0);
        }
        list.insert(start_index, 0);
        delete[] used;
        delete[] parent;
        return list;
    }

    int getNextStep(T start_id, T end_id) {
        List<int> list = getWay(start_id, end_id);
        if (list.getLen() == 0) { return -1; }
        return list.take(1);
    }

};

#endif //TOWER_DEFENSE_GRAPH_H
