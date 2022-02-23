#pragma once
#include "std_lib_facilities.h"

int randomWithLimits(int min, int max);

class CardDeck{

private:
    vector<Card> cards;
    void swap(int startIndex, int endIndex);

public:
    CardDeck();
    void print();
    void shuffle();
    string drawCard();
};

