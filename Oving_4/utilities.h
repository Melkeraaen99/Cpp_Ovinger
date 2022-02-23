#include "string"
#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int num1, int num2);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student studentutskrift);

bool isInProgram(Student navn, string studie);

string randomizeString(int tegn, char lower, char upper);

string readInputToString(int n, char lower, char upper);

int countChar(string tekst, char bokstav);