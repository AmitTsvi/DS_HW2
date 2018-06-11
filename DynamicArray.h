//
// Created by Nitzan on 09/06/2018.
//

#ifndef WET2_DYNAMICARRAY_H
#define WET2_DYNAMICARRAY_H

#define nullptr 0

template <class T>
class DynamicArray {
    T* head;
    int size;

public:
    DynamicArray(int new_size):  head(nullptr), size(new_size) {
        head =  new T[new_size];
        for (T* ptr=head; ptr < head+size; ptr++) {
            *ptr = nullptr;
        }
    }

    ~DynamicArray() {

    }

    DynamicArray(const DynamicArray& arr) = delete;


};

#endif //WET2_DYNAMICARRAY_H
