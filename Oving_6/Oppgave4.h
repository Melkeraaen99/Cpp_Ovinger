#pragma once
#include "std_lib_facilities.h"

struct Temps {
    double max, min;
};

istream& operator>>(istream& is, Temps& t);

void readTempsFromFile(vector<Temps> readTemps ,string filename);

vector<double> tempVector(string filename);

void tempStats(string filename);