#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "utilities.h" 
#include "tests.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testString(){
    string grades = randomizeString(8,'A','F');
    cout<<grades<<endl;
    double snittKarakter = 0;
    string karakterer = "ABCDEF";
    vector<int> karaktererTall;
    for (int i = 5; i>=0; i--){
        karaktererTall.push_back(i);
    }
    vector<int> gradeCount;
    for (int i = 0; i<karakterer.length(); i++){
        for (int j = 0; j<grades.length(); j++){
            if (grades[j] == karakterer[i]){
                gradeCount.push_back(karaktererTall[i]);
                snittKarakter += karaktererTall[i];
            }
        }
    }
    cout<< "[";
    for (int j=0; j<gradeCount.size(); j++){
        cout<<gradeCount.at(j);
        if (j < gradeCount.size()-1) {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    cout<<"Snittkarakteren er: "<<(snittKarakter/grades.length())<<endl;
}