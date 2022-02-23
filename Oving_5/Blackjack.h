#pragma once
#include "std_lib_facilities.h"
#include "CardDeck.h"

class Blackjack{

private:
    vector<string> playerHand;
    vector<string> dealerHand;

public:
    Blackjack();
    int getHandScore(vector<string> cardString);
};