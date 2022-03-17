#pragma once
#include <iostream>
#include <utility>
using namespace std;

class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    int get() const { return *num; }
    Dummy(const Dummy &other);
    Dummy& operator = (Dummy rhs) {
        swap(num, rhs.num);
        return *this;
    }
    ~Dummy() {
        delete num;
    }
};



void dummyTest();