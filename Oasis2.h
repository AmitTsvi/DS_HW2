//
// Created by Nitzan on 11/06/2018.
//

#ifndef WET2_OASIS2_H
#define WET2_OASIS2_H

#include "Player.h"
#include "Clan.h"
#include "HashTable.h"
#include "Heap.h"

#define nullptr 0

class Oasis2 {
    Tree<Player>* players_tree;
    Heap<Clan>* heap;
    HashTable<Clan>* hashTable;

};

#endif //WET2_OASIS2_H
