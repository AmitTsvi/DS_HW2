//
// Created by Nitzan on 12/06/2018.
//

#include <new>
#include "library2.h"
#include "Oasis2.h"
#include "exception"

void* init(int n, int *clanIDs) {
    if (n<2) {
        return nullptr;
    }
    for (int i=0;i<n;i++) {
        if (clanIDs+i < 0) {
            return nullptr;
        }
    }
    try {
        Oasis2* oasis2 = new Oasis2 (n, clanIDs);
        return oasis2;
    } catch (std::exception& e) {
        return nullptr;
    }
}

StatusType addClan(void *DS, int clanID) {
    if (DS == nullptr || clanID < 0) {
        return INVALID_INPUT;
    }
    try {
        ((Oasis2 *) DS)->addClan(clanID);
    } catch (std::bad_alloc& e) {
        return ALLOCATION_ERROR;
    } catch (std::exception& e) {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType getMinClan(void *DS, int *clan) {
    if (DS == nullptr || clan == nullptr) {
        return INVALID_INPUT;
    }
    try {
        ((Oasis2*)DS)-> getMinClan(clan);
    } catch (std::exception& e) {
        return FAILURE;
    }
    return SUCCESS;
}

