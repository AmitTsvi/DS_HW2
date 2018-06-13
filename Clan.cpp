//
// Created by Nitzan on 11/06/2018.
//

#include "Clan.h"

Clan::Clan(int clan_id, int index): id(clan_id), index_in_heap(index), num_of_players(0), is_active
        (true){
    players = new Tree<Player,Pair>();
}

Clan::~Clan() {
    players->deleteTree(true);
    delete players;
}

void Clan::addPlayerToClan () {

}

int Clan::getId () {
    return id;
}

void Clan::setId (int num) {
    id = num;
}

void Clan::setIndex (int num) {
    index_in_heap = num;
}

bool Clan::getIsActive() {
    return is_active;
}

void Clan::setNotActive() {
    is_active = false;
}

int Clan::getNumOfPlayers() {
    return num_of_players;
}