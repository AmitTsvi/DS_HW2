//
// Created by Nitzan on 09/06/2018.
//

#ifndef WET2_HEAP_H
#define WET2_HEAP_H

#include "DynamicArray.h"
#define nullptr 0

template <class T>
class Heap {
    DynamicArray<T*>* arr;
    int num_of_elements;

public:
    Heap(): arr(nullptr){}
    explicit Heap(DynamicArray<T>& new_arr): arr(&new_arr){}
    ~Heap() {

    }
    Heap (const Heap& heap) = delete;
    void siftDown ()
};

#endif //WET2_HEAP_H
