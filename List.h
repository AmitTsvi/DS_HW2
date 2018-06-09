//
// Created by Amit Tsvieli on 6/9/2018.
//

#ifndef WET2_LIST_H
#define WET2_LIST_H

#include <exception>

#define nullptr 0

template <class T>
class List {
    T* data;
    List* next;


public:
    List(): data(nullptr), next(nullptr){}
    explicit List(T& t_data): data(&t_data), next(nullptr){}
    ~List(){
        data = nullptr;
        delete next;
        next = nullptr;
    }
    List(const List& list) = delete;

    List& insertFirst(T& t_data){
        List* new_list = new List(t_data);
        new_list->next = this;
        return *new_list;
    }

    void deleteDataFromList(){
        List* current = this;
        while (current != nullptr){
            delete data;
            current = current->next;
        }
    }

    class Iterator{
        List* node_ptr;
    public:
        class NodeIsNull : public std::exception {};

        Iterator(): node_ptr(nullptr){};

        explicit Iterator(List* node){
            node_ptr = node;
        }

        ~iterator() = default;

        Iterator(const Iterator& iterator) = default;

        T& operator*() const{
            if (this->node_ptr == nullptr){
                throw NodeIsNull();
            }
            return *(node_ptr->data);
        }

        Iterator& operator++(){
            if (this->node_ptr == nullptr){
                throw NodeIsNull();
            }
            this->node_ptr = node_ptr->next;
            return *this;
        }

        bool operator==(Iterator& rhs) const{
            return (rhs.node_ptr == this->node_ptr);
        }

        bool operator!=(Iterator& rhs) const{
            return !(*this == rhs);
        }
    };
};



#endif //WET2_LIST_H
