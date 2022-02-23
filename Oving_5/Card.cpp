#include "Card.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"

map<Suit, string> s = { {Suit::clubs, "Clubs"},
                                {Suit::diamonds, "Diamonds"},
                                {Suit::hearts, "Hearts"},
                                {Suit::spades, "Spades"} };

string suitToString(Suit nameOfSuit){
    return s[nameOfSuit];
}

map<Rank, string> r = { {Rank::two, "Two"},
                                {Rank::three, "Three"},
                                {Rank::four, "Four"},
                                {Rank::five, "Five"},
                                {Rank::six, "Six"},
                                {Rank::seven, "Seven"},
                                {Rank::eight, "Eight"},
                                {Rank::nine, "Nine"},
                                {Rank::ten, "Ten"},
                                {Rank::jack, "Jack"},
                                {Rank::queen, "Queen"},
                                {Rank::king, "King"},
                                {Rank::ace, "Ace"} };

string rankToString(Rank nameOfRank){
    return r[nameOfRank];
}

string combinedString(CardStruct card){
    return rankToString(card.rank) + " of " + suitToString(card.suit) ;
}

Card::Card(){
    valid = false;
}

Card::Card(Suit suit, Rank rank){
    s = suit;
    r = rank;
    valid = true;
}

inline Suit Card::suit() {return s; }
inline Rank Card::rank() {return r; }
inline bool Card::isValid() {return valid; }

int Card::suitVal() {
    return int(s);
}

int Card::rankVal() {
    return int(r);
}

string Card::combinedString() {
    if (valid) {
        return rankToString(r) + " of " + suitToString(s);
    }
    else {
        return "Invalid card";
    }
}
