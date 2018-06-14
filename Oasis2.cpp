//
// Created by Nitzan on 11/06/2018.
//

#include "Oasis2.h"
#include "Heap.h"
#include "Clan.h"

Oasis2::Oasis2(int n, int* clanIDs): players_tree(nullptr), heap(nullptr), hashTable(nullptr) {
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
            hashTable = new HashTable<Clan> (n,clan_ptrs_arr,clanIDs);
            try {
                heap = new Heap<Clan> (n,clan_ptrs_arr);
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

Oasis2::~Oasis2() {
    players_tree->deleteTree(true);
    delete players_tree;
    delete heap;
    delete hashTable;
}

void Oasis2::addClan (int clan_id) {
    try {
        int org_num_of_elm = heap->getNumOfElements();
        Clan* clan = new Clan(clan_id,org_num_of_elm+1);
        try {
            heap->insert(clan, false);
            try {
                hashTable->insertElement(clan, clan_id,CHECK_EXIST);
            } catch (std::exception& e) {
                heap->remove(clan->getIndex());
                delete clan;
                clan = nullptr;
                throw e;
            }
        } catch (std::exception& e) {
            delete clan;
            //heap->setNumOfElements(org_num_of_elm);
            throw e;
        }
    } catch (std::exception& e) {
        throw e;
    }
}

void Oasis2::addPlayer (int playerID, int score, int clan) {
    if (hashTable->findElement(clan) == nullptr) {
        throw std::exception();
    }
    Player* player = new Player(score,playerID);
    try {
        int* key = new int(playerID);
        try {
            players_tree->insert(*key, *player);
        } catch (std::exception& e) {
            delete player;
            player = nullptr;
            delete key;
            throw std::exception();
        }
    } catch (std::exception& e) {
        delete player;
        throw std::exception();
    }
    try {
        Pair* pair = new Pair(playerID,score);
        try {
            hashTable->findElement(clan)->addPlayerToClan(*player, *pair);
        } catch (std::exception& e){
            delete pair;
            //players_tree->remove();     //need to add remove again to tree and edit
            delete player;
            player = nullptr;
            throw std::exception();
        }
    } catch (std::exception& e){
        //players_tree->remove();     //need to add remove again to tree and edit
        delete player;
        throw std::exception();
    }
}

void Oasis2::clanFight(int clan1, int clan2, int k1, int k2){
    Clan* clan1_data = this->hashTable->findElement(clan1);
    Clan* clan2_data = this->hashTable->findElement(clan2);
    if (clan1_data == nullptr || clan2_data == nullptr){
        throw std::exception();
    }
    if (!clan1_data->getIsActive() || !clan1_data->getIsActive()){
        throw std::exception();
    }
    if (clan1_data->getNumOfPlayers() < k1 || clan2_data->getNumOfPlayers() < k2){
        throw std::exception();
    }
    Pair& key1 = clan1_data->getKBestPlayer(k1);
    Pair& key2 = clan2_data->getKBestPlayer(k2);
    int score1 = clan1_data->getSumOfBestK(key1);
    int score2 = clan1_data->getSumOfBestK(key2);
    if (score1 > score2){
        clan2_data->setNotActive();
        this->heap->remove(clan2_data->getIndex());
    } else if (score1 < score2){
        clan1_data->setNotActive();
        this->heap->remove(clan1_data->getIndex());
    } else {
        if (clan1 > clan2){
            clan1_data->setNotActive();
            this->heap->remove(clan1_data->getIndex());
        } else {
            clan2_data->setNotActive();
            this->heap->remove(clan2_data->getIndex());
        }
    }
}

void Oasis2::getMinClan(int* clan) {
    *clan = this->heap->findMin()->getId();
}

void Oasis2::delClanArr (Clan** clans_arr) {
    Clan** ptr = clans_arr;
    while (ptr != nullptr) {
        delete *ptr;
        ptr++;
    }
}


