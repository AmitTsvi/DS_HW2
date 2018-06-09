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
    List* next;     //shoudlnt we make a list class with head node class of data and next?


public:
    List(): data(nullptr), next(nullptr){}
    explicit List(T& t_data): data(&t_data), next(nullptr){}
    ~List(){
        data = nullptr;     //why not deleting data itself?
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
        while (current != nullptr){     //does this function deletes the data from list so you
            // can destroy the list with destructor as above?
            delete data;
            current = current->next;
        }
    }

    class Iterator{
        List* node_ptr;     //should we add a field List to compare if the iterator are in the
        // same list?
        //need to add begin and end funcs for iterator for iterating on a list
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
            return (rhs.node_ptr == this->node_ptr);    //i think you need to overload
            // operator== of list for this, or does it compare the memory segment each one points
            // to?
        }

        bool operator!=(Iterator& rhs) const{
            return !(*this == rhs);
        }
    };
};



#endif //WET2_LIST_H
