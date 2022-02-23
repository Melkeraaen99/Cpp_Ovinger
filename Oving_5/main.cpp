// Øving 5 Thomas Melkeraaen

#include "std_lib_facilities.h"
#include "Graph.h"
#include "AnimationWindow.h" 
#include <cmath>
#include <string>
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

int valg = 0;
void menu(){
	switch(valg){

		case 0:{
			break;
		}

		case 1:{
			cout<<suitToString(Suit::hearts)<<endl;
			cout<<suitToString(Suit::spades)<<endl;
			cout<<suitToString(Suit::diamonds)<<endl;
			cout<<suitToString(Suit::clubs)<<endl;
			break;
		}

		case 2:{
			cout<<rankToString(Rank::ace)<<endl;
			break;
		}

		case 3:{
			cout<<combinedString({Suit::hearts, Rank::ace})<<endl;
			break;
		}

		case 4:{
			Card c{Suit::spades, Rank::ace};
			cout<<c.rankVal()<<endl;
			cout<<c.combinedString()<<endl;
			break;
		}

		case 5:{
			CardDeck cD = CardDeck();
			cD.print();
			cD.shuffle();
			cout<<""<<endl;
			cD.print();
			cout<<""<<endl;
			cD.drawCard();
			cD.drawCard();
			cD.drawCard();
			cD.drawCard();
			cout<<""<<endl;
			cD.print();
			break;
		}

		case 6:{
			Blackjack();
			break;
		}
	}
}


int main(){

	srand(unsigned(time(nullptr)));

	string melding{"Velg funksjon som skal kjøre: (0-X) \n0: Avslutt \n1: suitToString \n2: rankToString \n3: combinedString \n4: Test av Card konstruktøren \n5: CardDeck \n6: Blackjack"};

	bool keepLooping = true;
	while (keepLooping){
		cout<<melding<<endl;
		cin>>valg;
		cout<<endl;
		menu();
		if (valg==0){
			keepLooping = false;
		}
		cout<<endl;
	}

	// Oppgave 1e)
	// Det er lettere å lese koden slik

	return 0;
}

