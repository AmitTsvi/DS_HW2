//
// Created by Nitzan on 11/06/2018.
//

#ifndef WET2_OASIS2_H
#define WET2_OASIS2_H

#include <new>
#include "Player.h"
#include "Clan.h"
#include "HashTable.h"
#include "Heap.h"
#include "library2.h"
#include "exception"

#define CHECK_EXIST 1

#define nullptr 0

class Oasis2 {
    Tree<Player>* players_tree;
    Heap<Clan>* heap;
    HashTable<Clan>* hashTable;

public:
    Oasis2(int n, int* clanIDs) {
        //players_tree = new Tree
        try {
            Clan** clan_ptrs_arr = new Clan*[n* sizeof(Clan*)];
            try {
                hashTable = new HashTable (n,???,clanIDs,clan_ptrs_arr);
                try {
                    heap = new Heap (n,clan_ptrs_arr);
                } catch (std::exception& e) {
                    delete hashTable;
                    delete[] clan_ptrs_arr;
                    throw e;
                }
            } catch (std::exception& e) {
                delete[] clan_ptrs_arr;
                throw e;
            }
        } catch (std::exception& e) {
            throw e;
        }
    }

    void addClan (int clan_id) {
        Clan* clan = new Clan(clan_id,-1);
        try {
            heap->insert(clan, 0);
            clan->setIndex(heap->getNumOfElements());
            try {
                hashTable->insertElement(clan, clan_id,CHECK_EXIST);
            } catch (std::exception& e) {
                heap->remove(heap->getNumOfElements());
                delete clan;
                throw e;    //is it okay to throw a generic e and deal with the real value
                // outside? will it know how to sort the exception outside?
                //throw bad_alloc();
            }
            /*} catch (std::exception& e) {
                throw std::exception();
            }*/
        } catch (std::exception& e) {
            delete clan;
            throw e;
        }
    }

    void getMinClan(int* clan) {
        *clan = this->heap->findMin()->getId();
    }
};



#endif //WET2_OASIS2_H
