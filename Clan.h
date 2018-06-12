//
// Created by Nitzan on 11/06/2018.
//

#ifndef WET2_CLAN_H
#define WET2_CLAN_H

#include "Player.h"
#define nullptr 0

class Clan {
    int id;
    Tree<Player>* players;
    int index_in_heap;
    int num_of_players;

public:
    Clan(int clan_id, int index): id(clan_id), index_in_heap(index), num_of_players(0){
        //players = new Tree<Player>();     need to edit after tree is done
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
};

#endif //WET2_CLAN_H
