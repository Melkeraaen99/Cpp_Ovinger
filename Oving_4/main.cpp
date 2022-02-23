// Øving 4 Thomas Melkeraaen

#include "std_lib_facilities.h"
#include "utilities.h" 
#include "tests.h" 
#include "Graph.h"
#include "AnimationWindow.h" 
#include <cmath>
#include <string>
#include "mastermind.h"

int valg = 0;
void menu(){
	switch(valg){
		case 0:{
			break;
		}

		case 1:{
			testCallByValue();
			break;
		}

		case 2:{
			testCallByReference();
			break;
		}

		case 3:{
			swapNumbers(5,7);
			break;
		}

		case 4:{
			Student Thomas {"Thomas Melkeraaen", "MTKJ", 22};
			printStudent(Thomas);
			break;
		}

		case 5:{
			Student Kasper {"Kasper Dybvad", "MTKJ", 22};
			isInProgram(Kasper, "MTKJ");
			break;
		}

		case 6:{
			cout<<randomizeString(7,'A','z')<<endl;
			break;
		}

		case 7:{
			testString();
			break;
		}

		case 8:{
			cout<<readInputToString(7,'a','z')<<endl;
			break;
		}

		case 9:{
			countChar("halla balla", 'a');
			break;
		}

		case 10:{
			playMastermind();
			break;
		}
		
	}
}


int main() {

	srand(unsigned(time(nullptr)));

	// Oppgave 1a)
	// Den skriver ut 5 da vO ikke endres noe

	string melding{"Velg funksjon som skal kjøre: (0-X) \n0: Avslutt \n1: testCallByValue \n2: testCallByReference \n3: swapNumbers \n4: printStudent \n5: isInProgram \n6: randomizeString \n7: Grades \n8: readInputToString \n9: countChar \n10: playMastermind"};

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

	// Oppgave 2e)
	// Struct student blir da inkludert to ganger til main og dermed feilmelding

	// Oppgave 4)
	// Hvorfor bruker vi constexpr og ikke const her?
	// Fordi constexpr ikke initialiserer før den kompilerer, tar arbeid av fra maskinen nå som vi skal lage noe litt større

	return 0;
}