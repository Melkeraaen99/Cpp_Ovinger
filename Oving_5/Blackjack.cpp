#include "Card.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"
#include "CardDeck.h"
#include "Blackjack.h"

int Blackjack::getHandScore(vector<string> cardString){
    int value = 0;
    for (int i = 0; i < cardString.size(); i++){
        string rankString;
        string card = cardString[i]+' ';
        for (int j = 0; j < card.size(); j++){
            rankString += tolower(card[j]);
            if (card[j] == ' '){
                j = card.size();
            }
        }
        if (rankString == "two "){
            value += 2;
        }
        else if (rankString == "three "){
            value += 3;
        }
        else if (rankString == "four "){
            value += 4;
        }
        else if (rankString == "five "){
            value += 5;
        }
        else if (rankString == "six "){
            value += 6;
        }
        else if (rankString == "seven "){
            value += 7;
        }
        else if (rankString == "eight "){
            value += 8;
        }
        else if (rankString == "nine "){
            value += 9;
        }
        else if (rankString == "ten " || rankString == "jack " || rankString == "queen " || rankString == "king "){
            value += 10;
        }
        else{
            value += 11;
            if (value > 21){
                value -= 10;
            }
        }
    }
    return value;
}

Blackjack::Blackjack(){
    CardDeck cD = CardDeck();
    cD.shuffle();

    for (int i = 0; i < 2; i++){
        string topCard = cD.drawCard();
        playerHand.push_back(topCard);
        topCard = cD.drawCard();
        dealerHand.push_back(topCard);
    }

    cout<<"Dine kort er: "<<endl;
    cout<< "[";
    for (int j=0; j<playerHand.size(); j++){
        cout<<playerHand.at(j);
        if (j < playerHand.size()-1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    int scorePlayer = getHandScore(playerHand);
    cout<<"Din score er: "<<scorePlayer<<endl;

    cout<<"Dealeren sitt ene kort er: "<<endl;
    cout<< "[";
    cout<<dealerHand.at(0);
    cout<<"]"<<endl;
    if (scorePlayer==21){
        cout<<"Blackjack, du vant!"<<endl;
    }
    else {
        char choice;
        cout<<"Trekke nytt kort? (Y/N): ";
        cin>>choice;

        while (choice == 'Y'){
            string topCard = cD.drawCard();
            playerHand.push_back(topCard);
            cout<<"Du trakk "<<topCard<<endl;
            scorePlayer = getHandScore(playerHand);
            cout<<"Ny score er: "<<scorePlayer<<endl;
            if (scorePlayer>21){
                cout<<"Beklager, du tapte!"<<endl;
                break;
            }
            else if (scorePlayer==21){
                cout<<"Blackjack, du vant!"<<endl;
                break;
            }
            cout<<"Trekke nytt kort? (Y/N): ";
            cin>>choice;
        }
    }

    int scoreDealer = getHandScore(dealerHand);
    if (scorePlayer<21){
        cout<<"Dealeren har "<<dealerHand.at(0)<<" , "<<dealerHand.at(1)<<endl;
        cout<<"Scoren er: "<<scoreDealer<<endl;
        while(scoreDealer<17){
            string topCard = cD.drawCard();
            dealerHand.push_back(topCard);
            cout<<"Dealer trakk "<<topCard<<endl;
            scoreDealer = getHandScore(dealerHand);
            cout<<"Ny score er: "<<scoreDealer<<endl;
        }
        if (scoreDealer < 22 && scoreDealer > scorePlayer){
            cout<<"Beklager du tapte! "<<endl;
        }
        else if (scoreDealer == scorePlayer){
            cout<<"Uavgjort!"<<endl;
        }
        else {
            cout<<"Gratulerer, du vant!"<<endl;
        }
    }
}

