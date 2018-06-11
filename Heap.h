//
// Created by Nitzan on 09/06/2018.
//

#ifndef WET2_HEAP_H
#define WET2_HEAP_H

#include "DynamicArray.h"
#define nullptr 0
#define DELETE_INDEX -1

template <class T>
class Heap {
    DynamicArray<T*>* arr;
    int num_of_elements;

public:
    Heap(int size): arr(nullptr), num_of_elements(0) {
        arr = new DynamicArray<T*>(size);
    }
    //explicit Heap(DynamicArray<T>& new_arr): arr(&new_arr), num_of_elements(0){}
    ~Heap() {

    }
    Heap (const Heap& heap) = delete;

    void siftDown (int index) {

    }

    void siftUp(int index) {
        if (index == 1) {
            return;
        }
        if (arr[index].getId() < arr[index/2].getId()) {
            T* temp = arr[index];
            arr[index] = arr[index/2];
            arr[index/2] = arr->operator[](index);      //why it only let me like this???
        }
        return siftUp(index/2);
    }

    void Insert (T* data) {
        arr[num_of_elements] = data;
        siftUp(num_of_elements);
        num_of_elements++;
    }

    void decKey (int index, int new_key) {
        if (arr[index].getId() <= new_key) {
            return;
        }
        int org_key = arr[index].getId();
        arr[index].setId(new_key);
        siftUp(index);
        arr[0].setId(org_key);
    }

    T* findMin() {

    }
    void deleteMin() {
        T* temp = arr[0];
        arr[0] = arr[num_of_elements-1];
        arr[num_of_elements-1] = temp;
        delete arr[num_of_elements-1];      //is this correct??
        num_of_elements--;
        siftDown(0);
    }

    void remove(int index) {
        this->decKey(index,DELETE_INDEX);
        this->deleteMin();
    }
    //makeHeap should be outside
};

#endif //WET2_HEAP_H
