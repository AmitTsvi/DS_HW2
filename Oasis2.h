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
#include "Tree.h"

#define CHECK_EXIST 1

#define nullptr 0

class Oasis2 {
    Tree<Player,int>* players_tree;
    Heap<Clan>* heap;
    HashTable<Clan>* hashTable;

public:
    void delClanArr (Clan** clans_arr) {
        Clan** ptr = clans_arr;
        while (ptr != nullptr) {
            delete *ptr;
            ptr++;
        }
    }

    Oasis2(int n, int* clanIDs): players_tree(nullptr), heap(nullptr), hashTable(nullptr) {
        try {
            Clan** clan_ptrs_arr = new Clan*[n];
            try {
                int* IDs_ptr = clanIDs;
                int i=1;
                for (Clan** it = clan_ptrs_arr; it<clan_ptrs_arr+n;it++) {
                    try {
                        Clan* clan = new Clan(*IDs_ptr,i);
                        *it = clan;
                        IDs_ptr++;
                        i++;
                    } catch (std::exception& e) {
                        delClanArr(clan_ptrs_arr);
                        delete[] clan_ptrs_arr;
                        throw e;
                    }
                }
                hashTable = new HashTable (n,???,clanIDs,clan_ptrs_arr);    //need to finish
                try {
                    heap = new Heap (n,clan_ptrs_arr);
                    try {
                        players_tree = new Tree<Player,int>();
                    } catch (std::exception& e) {
                        delete heap;
                        delete hashTable;
                        delete[] clan_ptrs_arr;
                        throw e;
                    }
                } catch (std::exception& e) {
                    delete hashTable;
                    delete[] clan_ptrs_arr;
                    throw e;
                }
            } catch (std::exception& e) {
                delClanArr(clan_ptrs_arr);
                delete[] clan_ptrs_arr;
                throw e;
            }
        } catch (std::exception& e) {
            throw e;
        }
    }

    ~Oasis2() {
        players_tree->deleteTree(true);
        delete players_tree;
        delete heap;
        delete hashTable;
    }

    Oasis2 (const Oasis2& oasis2) = delete;

    void addClan (int clan_id) {
        try {
            Clan* clan = new Clan(clan_id,heap->getNumOfElements()+1);
            try {
                heap->insert(clan, false);
                try {
                    hashTable->insertElement(clan, clan_id,CHECK_EXIST);
                } catch (std::exception& e) {
                    heap->remove(heap->getNumOfElements());
                    delete clan;
                    throw e;
                }
            } catch (std::exception& e) {
                delete clan;
                heap->setNumOfElements(heap->getNumOfElements()-1);
                throw e;
            }
        } catch (std::exception& e) {
            throw e;
        }
    }

    void addPlayer (int playerID, int score, int clan) {
        if (hashTable->findElement(clan) == nullptr) {
            throw std::exception();
        }
        //need to add condition if player is in players tree and throw
        try {

            //add player to players tree
        } catch ()
    }

    void getMinClan(int* clan) {
        *clan = this->heap->findMin()->getId();
    }
};



#endif //WET2_OASIS2_H
