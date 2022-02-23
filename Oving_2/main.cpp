// Øving 2 Thomas Melkeraaen

#include "std_lib_facilities.h"
#include "funksjoner.h"  // Jeg har laget funksjonene utenfor main.cpp for at det skal være ryddig for meg
#include "Graph.h"
#include "AnimationWindow.h" 

int main() {

	// cout<<"Oppgave 1a)"<<endl;
	// inputAndPrintInteger();

	// cout<<"Oppgave 1b)"<<endl;
	// int number = inputInteger();
	// cout << "Du skrev: " << number<<endl;

	// cout<<"Oppgave 1c)"<<endl;
	// inputIntegersAndPrintSum();

	// 1d)
	// Jeg valgte å bruke inputInteger() siden man kun skulle skrive inn tall og ikke printe det ut senere.
	// Den hadde også en return som gjorde det lettere og naturlig å bruke den.

	// cout<<"Oppgave 1e)"<<endl;	
	// cout<<isOdd(0)<<endl;
	// cout<<(isOdd(5) ? "true" : "false")<<endl;

	// cout<<"Oppgave 1f)"<<endl;	
	// printHumanReadableTime(10000);

	// cout<<"Oppgave 2a)"<<endl;
	// cout<<sum_n_numbers()<<endl;	

	// cout<<"Oppgave 2b)"<<endl;
	// cout<<sum_n_numbers_not_zero()<<endl;

	// 2c)
	// For løkke for 2a og while for 2b, ganske selvforklarende siden 2b skal kjøre "while" tall ikke er 0

	// cout<<"Oppgave 2d)"<<endl;
	// cout<<inputDouble()<<endl;

	// cout<<"Oppgave 2e)"<<endl;
	// cout<<setprecision(5);
	// cout<<nok_to_euro()<<endl;

	// 2f)
	// Det er bedre å bruke inputDouble da det opereres med deismaltall

	// cout<<"Oppgave 3a)"<<endl;
	// meny();

	cout<<"Oppgave 3b)"<<endl;
	multiplicationTable();
	cout<<endl;

	// cout<<"Oppgave 4a)"<<endl;
	// cout<<discriminant(5,5,5)<<endl;

	// cout<<"Oppgave 4b)"<<endl;
	// printRealRoots(1,8,4);

	// cout<<"Oppgave 4c)"<<endl;
	// solveQuadraticEquation();

	// 4d)
	// Lagt til i testmenyen

	// 4e)
	// Fungerer som det skal

	// 5)
	// Hele oppgave 5 kjøres av linjen under
	// pythagoras();

	// cout<<"Oppgave 6a)"<<endl;
	// calculateBalance(5000, 3, 2);

	// cout<<"Oppgave 6b)"<<endl;
	// printBalance({ 5000, 6000, 7000, 8000 });

	// 6c)
	// SVAR

	// cout<<"Oppgave 6d)"<<endl;
	// vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// for (int i = 0; i <= v.size(); i++) {
	// 	cout << v[i] << endl;
	// }
	// Koden hadde ingen feilmelding da jeg kjørte den

	return 0;
}