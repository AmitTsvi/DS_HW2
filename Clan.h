//
// Created by Nitzan on 11/06/2018.
//

#ifndef WET2_CLAN_H
#define WET2_CLAN_H

#include "Player.h"
#include "Tree.h"
#include "Pair.h"

#define nullptr 0

class Clan {
    int id;
    Tree<Player, Pair>* players;
    int index_in_heap;
    int num_of_players;
    bool is_active;

public:
    Clan(int clan_id, int index): id(clan_id), index_in_heap(index), num_of_players(0), is_active
            (true){
        //players = new Tree<Player>();     need to edit after tree is done
    }

    ~Clan() {
        players->deleteTree(true);
        delete players;
    }

    Clan (const Clan& clan) = delete;

    void addPlayerToClan () {

    }

    int getId () {
        return id;
    }

    void setId (int num) {
        id = num;
    }

    void setIndex (int num) {
        index_in_heap = num;
    }

    bool getIsActive() {
        return is_active;
    }

    int getNumOfPlayers() {
        return num_of_players;
    }
};

#endif //WET2_CLAN_H
