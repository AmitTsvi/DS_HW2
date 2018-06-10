//
// Created by Amit Tsvieli on 6/9/2018.
//

#ifndef WET2_HASHTABLE_H
#define WET2_HASHTABLE_H

#include <exception>
#include "List.h"

#define nullptr 0

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class DynamicArray; //MUST DELETE AFTER ARRAY IS FINISHED
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


template <class T>
class HashTable{
    int number_of_elements;
    int hash_size;
    DynamicArray<List<T>* >* array;

    HashTable& rehash(){
        DynamicArray<List<T>* >* new_array = DynamicArray<List<T>* >(3*hash_size);
        for (int i=0; i < hash_size; i++){
            for(List<T>::Iterator it = array[i].begin(); it != array[i].end(); i++){
                /*
                int index = it % (3*hash_size);

                 if(array[index] == nullptr){
                        array[index] = new List(*data);
                 }
                 array[index]->&insertFirst(*data);
                */
                hash_size = 3*hash_size;
                //delete array;
                array = new_array;
            }
        }
    }

public:
    HashTable(int n, T** data, int* original_keys): number_of_elements(0), hash_size(0), array(nullptr){
        array = new DynamicArray<T>(3*n);
        for (int i=0; i < n; i++){
            T* current_data = *(data+i);
            int current_key = *(original_keys+i);
            this->insertElement(current_data, current_key, false);
        }
    }

    ~HashTable()
    {
        for(int i=0; i < hash_size; i++){
            /*
            if (array[i] != nullptr){
                array[i]->deleteDataFromList();
                delete array[i];
                array[i] = nullptr;
            }
             */
        }
        delete array;
    }

    HashTable(const HashTable& list) = delete;

    class AlreadyInHash : public std::exception {};

    HashTable& insertElement(T* data, int original_key, bool check_existence){
        if (check_existence){
            T* found = this->findElement(original_key);
            if (found != nullptr){
                throw AlreadyInHash();
            }
        }
        int index = original_key % hash_size;
        /*
         if(array[index] == nullptr){
                array[index] = new List(*data);
         }
         array[index]->&insertFirst(*data);
        */
        number_of_elements++;
        if (number_of_elements > 3*hash_size){
            return this->rehash();
        } else {
            return *this;
        }
    }

    T* findElement(int original_key){
        int index = original_key % hash_size;
        //return array[new_key]->find(original_key);
    }

};


#endif //WET2_HASHTABLE_H
