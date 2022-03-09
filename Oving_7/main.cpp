// Øving 7 Thomas Melkeraaen

#include "std_lib_facilities.h"
#include "Graph.h"
#include "AnimationWindow.h" 
#include <cmath>
#include <string>
#include "Oppgave1.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int valg = 0;
void menu(){
	switch(valg){

		case 0:{
			break;
		}

		case 1:{
			testAnimal();
			break;
		}

		case 2:{
			const Point tl{100, 100};
			const string win_label{"Emoji factory"};
			AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
			drawEmojis(tl, emojiRadius, win);
			win.wait_for_close();
			break;
		}
	}
}



int main(){

	srand(unsigned(time(nullptr)));

	string melding{"Velg funksjon som skal kjøre: (0-X) \n0: Avslutt \n1: testAnimal \n2: emoji_main "};

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

	return 0;
}
