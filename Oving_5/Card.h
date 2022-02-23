#pragma once
#include "std_lib_facilities.h"

enum class Suit { clubs, diamonds, hearts, spades };

enum class Rank { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

string suitToString(Suit nameOfSuit);

string rankToString(Rank nameOfRank);

struct CardStruct {
    Suit suit;
    Rank rank;
};

string combinedString(CardStruct card);


class Card{

private:
    Suit s;
    Rank r;
    bool valid;

public:
    Card();
    Card(Suit suit, Rank rank);
    Suit suit();
    Rank rank();
    int suitVal();
    int rankVal();
    bool isValid();
    string combinedString();
};

