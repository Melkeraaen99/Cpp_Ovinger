#include "dummy.h"
#include<iostream>
using namespace std;
#include <iomanip> 

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a: " << *a.num << '\n';
    cout << "b: " << *b.num << '\n';
    cout << "c: " << *c.num << '\n';
    *b.num = 3;
    *c.num = 5;
    cout << "a: " << *a.num << '\n';
    cout << "b: " << *b.num << '\n';
    cout << "c: " << *c.num << '\n';
}

Dummy::Dummy(const Dummy &other) : num{nullptr}{
    this->num = new int{};
    *num = other.get();
}

// Koden skriver ut 3 for b andre gang, i motsetning til 5 som den skrev ut først.

