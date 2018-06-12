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
        head =  new T[size];
        for (T* ptr=head; ptr < head+size; ptr++) {
            *ptr = nullptr;
        }
    }

    ~DynamicArray() {
        delete[] head;
    }

    DynamicArray(const DynamicArray& arr) = delete;

    void resize () {
        T* new_head = new T[size*3];
        T* new_ptr = new_head;
        for (T* ptr=head; ptr < head+size; ptr++) {
            *new_ptr = *ptr;
            new_ptr++;
        }
        for (;new_ptr < (new_head+(size*2)); new_ptr++) {
            *new_ptr = nullptr;
        }
        delete[] head;  //should delete like that?
        head = new_head;
        size = size*3;
    }

    T& operator[](int index) {
        if (index >= size) {
            this->resize();
        }
        return *(head+index);
    }
};

#endif //WET2_DYNAMICARRAY_H
