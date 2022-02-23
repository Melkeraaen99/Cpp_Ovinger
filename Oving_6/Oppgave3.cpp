#include "Oppgave3.h"
#include "std_lib_facilities.h"
#include <cmath>
#include "Graph.h"
#include "AnimationWindow.h"
#include "string"
#include "Oppgave1.h"

void CourseCatalog::addCourse(string emnekode, string emnenavn){
    courses.insert({emnekode, emnenavn});
}

void CourseCatalog::addCourseWithOperator(string emnekode, string emnenavn){ 
    courses[emnekode] = emnenavn; // Denne vil overskrive eventuelle tidligere emner dersom emnekoden er lik
}

void CourseCatalog::removeCourse(string emnekode){
    courses.erase(emnekode);
}

string CourseCatalog::getcourse(string emnekode){
    return courses[emnekode];
}

ostream& operator<<(ostream& os, const CourseCatalog& cc){
    string courseoutput;
    for (const auto& elem:cc.courses){
        courseoutput += elem.first + " " + elem.second + "\n";
    }
    return os << courseoutput;
}

void CourseCatalog::addToFile(string filename, CourseCatalog emnekatalog){
    ofstream myfile {filename};
    if (myfile.is_open()){
        myfile << emnekatalog;
        myfile.close();
    }
}

void CourseCatalog::getFromFile(string filename){
    fromFile(filename);
}