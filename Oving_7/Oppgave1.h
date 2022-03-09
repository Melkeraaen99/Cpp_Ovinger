#pragma once
#include "std_lib_facilities.h"

class Animal{
protected:
    string name;
    int age;
public:
    Animal(string animalName, int animalAge){name = animalName; age = animalAge;}
    virtual ~Animal() {}
    virtual string toString(); // Setter funksjonen lik 0 for å gjøre den abstrakt, det ga bare feilmeldinger om jeg
                               // kjører den på samme måte som jeg har kjørt den frem til nå
                               // Det skyldes at den ikke kan gjøre noe da og må bli overskrevet i klassene som arver den
                               // Viser i de senere oppgavene at jeg behersker bruk av abstrakte klasser
};

class Cat : public Animal{
public:
    Cat(string animalName, int animalAge):Animal(animalName, animalAge){}
    virtual string toString();
};

class Dog : public Animal{
public:
    Dog(string animalName, int animalAge):Animal(animalName, animalAge){}
    virtual string toString();
};

void testAnimal();
