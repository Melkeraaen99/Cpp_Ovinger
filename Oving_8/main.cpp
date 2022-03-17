// Øving 8 Thomas Melkeraaen

#include "Graph.h"
#include "AnimationWindow.h" 
#include <cmath>
#include <string>
#include "Oppgave1.h"
#include "Oppgave2.h"
#include "dummy.h"
#include<iostream>


int valg = 0;
void menu(){
	switch(valg){

		case 0:{
			break;
		}

		case 1:{
			createFibonacci();
			cout<<endl;
			break;
		}

		case 2:{
			Matrix mx{3,4};
			cout << "Antall rader: " << mx.getRows() << "\n";
			cout << "Antall kolonner: " << mx.getColumns() << "\n";
			cout << "Nullmatrisen: \n" << mx << "\n";
			Matrix b{4};
			cout << "\n Antall rader: " << b.getRows() << "\n";
			cout << "Antall kolonner: " << b.getColumns() << "\n";
			cout << "Identitetsmatrisen: \n" << b << "\n";
			cout << "\n Setter inn 7 på rad 2, kolonne 3 i nullmatrisen" << "\n";
			mx.set(1,2,7);
			cout << "Nullmatrisen etter innsatt verdi: \n" << mx << "\n";
			cout << "\n Henter ut 7-tallet med get funksjonen: " << mx.get(1,2) <<"\n";
			Matrix test = Matrix(mx);
			cout << "\n Skriver ut en kopi: " << "\n" << test <<"\n";

			Matrix A{2,2};
			Matrix B{2,2};
			Matrix C{2,2};
			A.set(0,0,1); A.set(1,0,3); A.set(0,1,2); A.set(1,1,4);
			B.set(0,0,4); B.set(1,0,2); B.set(0,1,3); B.set(1,1,1); 
			C.set(0,0,1); C.set(1,0,1.5); C.set(0,1,3); C.set(1,1,2); 
			cout << "\n Matrix A: " << A << "\n";
			cout << "\n Matrix B: " << B << "\n";
			cout << "\n Matrix C: " << C << "\n";
			Matrix copyB = Matrix(B);
			A += (copyB + C);
			cout << "\n Matrix A += B + C: " << A << "\n";
			cout << "\n Matrix B: " << B << "\n";
			cout << "\n Matrix C: " << C << "\n";
			break;
		}

		case 3:{
			dummyTest();
			break;
		}

		case 4:{
			break;
		}

		case 5:{
			break;
		}

		case 6:{
			break;
		}

		case 7:{
			break;
		}

		case 8:{
			break;
		}
	}
}



int main(){

	srand(unsigned(time(nullptr)));

	string melding{"Velg funksjon som skal kjøre: (0-X) \n0: Avslutt \n1: Fibonacci \n2: Matrix \n3: Dummy"};

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
