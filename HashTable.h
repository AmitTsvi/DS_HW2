//
// Created by Amit Tsvieli on 6/9/2018.
//

#ifndef WET2_HASHTABLE_H
#define WET2_HASHTABLE_H

#define nullptr 0

template <class T>
class HashTable{
    int number_of_elements;
    int total_size;
    //DynamicArray array;

public:
    HashTable();
    ~HashTable();
    HashTable(const HashTable& list) = delete;
    void initHash(int n, T** data, int* original_keys);
    void insertElement(T* data, int* original_key);
    T* findElement(int original_key);
    HashTable& rehash();
    void deleteDateFromHash();
};


#endif //WET2_HASHTABLE_H
