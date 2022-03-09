// Forskjellen på public, private og protected 
// Public kan brukes utenfor og inni klassen
// Private kan kun brukes inni klassen
// Protected kan kun brukes inni klassen og ved å arve child klasser

#include "Oppgave1.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"

string Animal::toString(){
    string returnString = "Animal: ";
    returnString += name;
    returnString += ", ";
    returnString += to_string(age);
    return returnString;
}

string Cat::toString(){
    string returnString = "Cat: ";
    returnString += name;
    returnString += ", ";
    returnString += to_string(age);
    return returnString;
}

string Dog::toString(){
    string returnString = "Dog: ";
    returnString += name;
    returnString += ", ";
    returnString += to_string(age);
    return returnString;
}

void testAnimal(){
    Animal a = Animal("Rex", 12);
	cout<<a.toString()<<endl;
	Cat c = Cat("Pus", 7);
	cout<<c.toString()<<endl;
	Dog d = Dog("Hund", 10);
	cout<<d.toString()<<endl;
    cout<<endl<<"Vectorutskrift:"<<endl<<endl;
    vector<unique_ptr<Animal>> v;
    v.emplace_back(new Animal("Test Animal",17));
    v.emplace_back(new Animal("Test_2 Animal",16));
    v.emplace_back(new Cat("Test Cat",15));
    v.emplace_back(new Cat("Test_2 Cat",14));
    v.emplace_back(new Dog("Test Hund",13));
    v.emplace_back(new Dog("Test_2 Hund",12));
    for (int i = 0; i < v.size(); i++){
        cout<<v.at(i) -> toString()<<endl;
    }
}


