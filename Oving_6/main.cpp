// Øving 6 Thomas Melkeraaen

#include "std_lib_facilities.h"
#include "Graph.h"
#include "AnimationWindow.h" 
#include <cmath>
#include <string>
#include "Oppgave1.h"
#include "Oppgave2.h"
#include "Oppgave3.h"
#include "Oppgave4.h"

map<string, string> capitalsMap {
	{"Norway", "Oslo"},
	{"Sweden", "Stockholm"},
	{"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
	return capitalsMap[country];
}

int valg = 0;
void menu(){
	switch(valg){

		case 0:{
			break;
		}

		case 1:{
			toFile();
			break;
		}

		case 2:{
			fromFile("Oppgave1.txt");
			break;
		}

		case 3:{
			countCharFromFile("grunnlov.txt");
			break;
		}

		case 4:{
			cout << "Capitals:\n";
			for (auto& elem:capitalsMap) {
				cout << getCapital(elem.first) << endl;
			}
			break;
		}

		case 5:{
			CourseCatalog emnekatalog;
			emnekatalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
			emnekatalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
			emnekatalog.addCourse("TMA4100", "Matematikk 1");
			emnekatalog.addCourseWithOperator("TDT4102", "C++"); // Hadde jeg kjørt med insert ville ikke dette blitt lagt til siden TDT4102 finnes fra før
			cout<<emnekatalog.getcourse("TDT4110")<<endl;
			cout<<emnekatalog;
			break;
		}

		case 6:{
			CourseCatalog emnekatalog;
			emnekatalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
			emnekatalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
			emnekatalog.addCourse("TMA4100", "Matematikk 1");
			emnekatalog.addToFile("Oppgave3.txt", emnekatalog);
			emnekatalog.getFromFile("Oppgave3.txt");
			break;
		}

		case 7:{
			ifstream temp_file{"temperatures.txt"};
			Temps t;
			temp_file >> t;
			vector<Temps> temps;
			readTempsFromFile(temps, "temperatures.txt");
			break;
		}

		case 8:{
			tempStats("temperatures.txt");
			break;
		}
	}
}



int main(){

	srand(unsigned(time(nullptr)));

	string melding{"Velg funksjon som skal kjøre: (0-X) \n0: Avslutt \n1: toFile \n2: fromFile \n3: countCharFromFile \n4: Oppgave 2b) \n5: CourseCatalog \n6: File oppgave 3 \n7: Oppgave 4b) \n8: Statistikk temperatur"};

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
