#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "utilities.h" 
#include "string"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
        }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
        }
    return startValue;
}

void swapNumbers(int num1, int num2){
    int midlertidig = num1;
    num1 = num2;
    num2 = midlertidig;
    cout<<num1<<", "<<num2<<endl;
}

void printStudent(Student studentutskrift){
    cout<<"Name: "<<studentutskrift.name<<", Study program: "<<studentutskrift.studyProgram<<", Age: "<<studentutskrift.age<<endl;
}

bool isInProgram(Student navn, string studie){
    if (navn.studyProgram == studie){
        cout<<"Går den linja"<<endl;
        return true;
    }
    else{
        cout<<"Går ikke den linja"<<endl;
        return false;
    }
}

// 65 = A, 90 = Z 
// 97 = a, 122 = z
// int('a') = 97 
// char(97) = a

string randomizeString(int tegn, char lower, char upper){
    int count = 0;
    string generatedWord;
    while (count<tegn){
        int randomTall = rand();
        if (randomTall >= int(lower) && randomTall <= int(upper)){
            generatedWord += char(randomTall);
            count += 1;
        }
    }
    return generatedWord;
}

string readInputToString(int n, char lower, char upper){
    string stringLength_n;
    char tegn;
    int count = 0;
    while (count<n){
        cout<<"Anngi tegn: ";
        cin>>tegn;
        while (int(tegn)<int(lower) || int(tegn>int(upper))){
            cout<<"Utenfor grensene, anngi nytt tegn: ";
            cin>>tegn;
        }
        stringLength_n += tegn;
        count += 1;
    }
    return stringLength_n;
}

int countChar(string tekst, char bokstav){
    int count = 0;
    for (int i = 0; i<tekst.length(); i++){
        if(bokstav==tekst[i]){
            count+=1;
        }
    }
    cout<<"Det finnes "<<count<<" av denne bokstaven i stringen"<<endl;
    return count;
}