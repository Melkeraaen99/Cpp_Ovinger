#include "Card.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"
#include "CardDeck.h"

int randomWithLimits(int min, int max)
{
	return rand() % (max - min + 1) + min;;
}

CardDeck::CardDeck(){
    // Legger til alle 52 kort i cardDeck
    for (int i = 0; i < 4; i++){
        for (int j = 2; j < 15; j++){
            cards.push_back(Card((Suit)i, (Rank)j));
        }
    }
}

void CardDeck::swap(int startIndex, int endIndex){
    Card swapCard = cards[startIndex];
    cards[startIndex] = cards[endIndex];
    cards[endIndex] = swapCard;
}

void CardDeck::print(){
    for (Card swapCard : cards){
        cout<<swapCard.combinedString()<<endl;
    }
}

void CardDeck::shuffle(){
    for (int i = 0; i<10000; i++){  // i<10000 bare for at den skal stokke mye
        swap(randomWithLimits(0, cards.size()-1), randomWithLimits(0, cards.size()-1));
    }
}

string CardDeck::drawCard(){
    string top_card = cards[0].combinedString();
    cards.erase(cards.begin());
    return top_card;
}
