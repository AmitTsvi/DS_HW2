//
// Created by Nitzan on 09/06/2018.
//

#ifndef WET2_HEAP_H
#define WET2_HEAP_H

#include "DynamicArray.h"
#define nullptr 0
#define DELETE_INDEX {-1}

template <class T>
class Heap {
    DynamicArray<T*>* arr;      //array starts in index 1
    int num_of_elements;

public:
    Heap(int size): arr(nullptr), num_of_elements(0) {
        arr = new DynamicArray<T*>(size+1);
    }
    //explicit Heap(DynamicArray<T>& new_arr): arr(&new_arr), num_of_elements(0){}
    ~Heap() {

    }
    Heap (const Heap& heap) = delete;

    int Min (int num1, int num2) {
        if (num1 > num2) {
            return num1;
        }
        return num2;
    }

    void swap (int index1, int index2) {
        T* temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = arr->operator[](index1);      //why it only let me like this???
    }

    void siftDown (int index) {
        if (index*4 <= num_of_elements) {
            siftDown(index*2);
            siftDown((index*2)+1);
        }
        int min = index*2;
        if (((index*2)+1) <= num_of_elements && arr[index*2].getId() > arr[(index*2)+1].getId()) {
            min = (index*2)+1;
        }
        if (arr[index].getId() > arr[min].getId()) {
            this->swap (index, min);
        }
    }

    void siftUp(int index) {
        if (index == 1) {
            return;
        }
        if (arr[index].getId() < arr[index/2].getId()) {
            this->swap(index, index/2);
        }
        return siftUp(index/2);
    }

    void Insert (T* data) {
        arr[num_of_elements+1] = data;
        num_of_elements++;
        siftUp(num_of_elements);
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
        return arr[1];
    }
    void deleteMin() {
        T* temp = arr[1];
        arr[1] = arr[num_of_elements];
        arr[num_of_elements] = temp;
        delete arr[num_of_elements];      //is this correct??
        num_of_elements--;
        this->siftDown(1);
    }

    void remove(int index) {
        this->decKey(index,DELETE_INDEX);
        this->deleteMin();
    }
    //makeHeap should be outside
};

#endif //WET2_HEAP_H
